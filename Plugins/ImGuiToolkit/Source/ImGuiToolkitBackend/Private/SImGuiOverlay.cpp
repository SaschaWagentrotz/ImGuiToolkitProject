#include "SImGuiOverlay.h"

#include <Containers/StringConv.h>
#include <CoreGlobals.h>
#include <Framework/Application/SlateApplication.h>
#include <HAL/PlatformApplicationMisc.h>
#include <Layout/WidgetPath.h>
#include <limits>

#include "ImGuiContext.h"

THIRD_PARTY_INCLUDES_START
#include <imgui_internal.h>
THIRD_PARTY_INCLUDES_END

FImGuiDrawList::FImGuiDrawList(ImDrawList* Source)
{
	VtxBuffer.swap(Source->VtxBuffer);
	IdxBuffer.swap(Source->IdxBuffer);
	CmdBuffer.swap(Source->CmdBuffer);
	Flags = Source->Flags;
}

FImGuiDrawData::FImGuiDrawData(const ImDrawData* Source)
{
	bValid = Source->Valid;

	TotalIdxCount = Source->TotalIdxCount;
	TotalVtxCount = Source->TotalVtxCount;

	ImGui::CopyArray(Source->CmdLists, DrawLists);

	DisplayPos = Source->DisplayPos;
	DisplaySize = Source->DisplaySize;
	FrameBufferScale = Source->FramebufferScale;
}

class FImGuiInputProcessor : public IInputProcessor
{
public:
	explicit FImGuiInputProcessor(SImGuiOverlay* InOwner)
	{
		Owner = InOwner;

		FSlateApplication::Get().OnApplicationActivationStateChanged().AddRaw(this, &FImGuiInputProcessor::OnApplicationActivationChanged);
	}

	virtual ~FImGuiInputProcessor() override
	{
		if (FSlateApplication::IsInitialized())
		{
			FSlateApplication::Get().OnApplicationActivationStateChanged().RemoveAll(this);
		}
	}

	void OnApplicationActivationChanged(bool bIsActive)
	{
		ImGui::FScopedContext ScopedContext(Owner->GetContext());

		ImGuiIO& IO = ImGui::GetIO();

		IO.AddFocusEvent(bIsActive);

		if (!bIsActive)
		{
			ResetModifierState();
		}
	}

	void AddModifierKeyEvents(ImGuiIO& IO, const FModifierKeysState& ModifierKeys) const
	{
		const bool bCommandDown = bLeftCommandDown || bRightCommandDown || ModifierKeys.IsCommandDown();
		const bool bControlDown = bLeftControlDown || bRightControlDown || ModifierKeys.IsControlDown();
		const bool bEffectiveControlDown = bControlDown || (IO.ConfigMacOSXBehaviors && bCommandDown);

		IO.AddKeyEvent(ImGuiMod_Ctrl, bEffectiveControlDown);
		IO.AddKeyEvent(ImGuiMod_Shift, bLeftShiftDown || bRightShiftDown || ModifierKeys.IsShiftDown());
		IO.AddKeyEvent(ImGuiMod_Alt, bLeftAltDown || bRightAltDown || ModifierKeys.IsAltDown());
		IO.AddKeyEvent(ImGuiMod_Super, bCommandDown);

		if (IO.ConfigMacOSXBehaviors)
		{
			IO.AddKeyEvent(ImGuiKey_LeftCtrl, bEffectiveControlDown);
		}
	}

	void UpdateModifierStateFromKey(const FKey& Key, const bool bIsDown)
	{
		if (Key == EKeys::LeftControl)
		{
			bLeftControlDown = bIsDown;
		}
		else if (Key == EKeys::RightControl)
		{
			bRightControlDown = bIsDown;
		}
		else if (Key == EKeys::LeftShift)
		{
			bLeftShiftDown = bIsDown;
		}
		else if (Key == EKeys::RightShift)
		{
			bRightShiftDown = bIsDown;
		}
		else if (Key == EKeys::LeftAlt)
		{
			bLeftAltDown = bIsDown;
		}
		else if (Key == EKeys::RightAlt)
		{
			bRightAltDown = bIsDown;
		}
		else if (Key == EKeys::LeftCommand)
		{
			bLeftCommandDown = bIsDown;
		}
		else if (Key == EKeys::RightCommand)
		{
			bRightCommandDown = bIsDown;
		}
	}

	void ResetModifierState()
	{
		bLeftControlDown = false;
		bRightControlDown = false;
		bLeftShiftDown = false;
		bRightShiftDown = false;
		bLeftAltDown = false;
		bRightAltDown = false;
		bLeftCommandDown = false;
		bRightCommandDown = false;
	}

	void AddCommandAsControlKeyEvent(ImGuiIO& IO, const FKey& Key, const bool bIsDown) const
	{
		if (!IO.ConfigMacOSXBehaviors)
		{
			return;
		}

		if (Key == EKeys::LeftCommand)
		{
			IO.AddKeyEvent(ImGuiKey_LeftCtrl, bIsDown);
		}
		else if (Key == EKeys::RightCommand)
		{
			IO.AddKeyEvent(ImGuiKey_RightCtrl, bIsDown);
		}
	}

	bool IsEffectiveControlDown(const ImGuiIO& IO, const FModifierKeysState& ModifierKeys) const
	{
		const bool bCommandDown = bLeftCommandDown || bRightCommandDown || ModifierKeys.IsCommandDown();
		const bool bControlDown = bLeftControlDown || bRightControlDown || ModifierKeys.IsControlDown();
		return bControlDown || (IO.ConfigMacOSXBehaviors && bCommandDown);
	}

	bool IsTextEditShortcut(const ImGuiIO& IO, const FKey& Key, const FModifierKeysState& ModifierKeys) const
	{
		if (!IsEffectiveControlDown(IO, ModifierKeys))
		{
			return false;
		}

		return Key == EKeys::A
			|| Key == EKeys::C
			|| Key == EKeys::V
			|| Key == EKeys::X
			|| Key == EKeys::Y
			|| Key == EKeys::Z;
	}

	virtual void Tick(const float DeltaTime, FSlateApplication& SlateApp, TSharedRef<ICursor> SlateCursor) override
	{
		if (!Owner || !Owner->CanProcessKeyboardInput(SlateApp))
		{
			return;
		}

		ImGui::FScopedContext ScopedContext(Owner->GetContext());

		ImGuiIO& IO = ImGui::GetIO();

		const bool bHasGamepad = (IO.BackendFlags & ImGuiBackendFlags_HasGamepad);
		if (bHasGamepad != SlateApp.IsGamepadAttached())
		{
			IO.BackendFlags ^= ImGuiBackendFlags_HasGamepad;
		}

		if (IO.WantSetMousePos)
		{
			FVector2f Position = IO.MousePos;
			if (!(IO.ConfigFlags & ImGuiConfigFlags_ViewportsEnable))
			{
				// Mouse position for single viewport mode is in client space
				Position += Owner->GetTickSpaceGeometry().AbsolutePosition;
			}

			SlateCursor->SetPosition(Position.X, Position.Y);
		}

		if (IO.WantTextInput && !Owner->HasKeyboardFocus())
		{
			// No HandleKeyCharEvent so punt focus to the widget for it to receive OnKeyChar events
			SlateApp.SetKeyboardFocus(Owner->AsShared());
		}
	}

	virtual bool HandleKeyDownEvent(FSlateApplication& SlateApp, const FKeyEvent& Event) override
	{
		if (!ShouldHandleEvent(SlateApp, Event))
		{
			return false;
		}

		ImGui::FScopedContext ScopedContext(Owner->GetContext());

		ImGuiIO& IO = ImGui::GetIO();

		const FKey Key = Event.GetKey();
		UpdateModifierStateFromKey(Key, true);
		AddModifierKeyEvents(IO, Event.GetModifierKeys());
		if (HandleTextEditShortcutFallback(IO, Key, Event.GetModifierKeys()))
		{
			return true;
		}

		IO.AddKeyEvent(ImGui::ConvertKey(Key), true);
		AddCommandAsControlKeyEvent(IO, Key, true);

		return IO.WantCaptureKeyboard || (IO.WantTextInput && IsTextEditShortcut(IO, Key, Event.GetModifierKeys()));
	}

	virtual bool HandleKeyUpEvent(FSlateApplication& SlateApp, const FKeyEvent& Event) override
	{
		if (!ShouldHandleEvent(SlateApp, Event))
		{
			return false;
		}

		ImGui::FScopedContext ScopedContext(Owner->GetContext());

		ImGuiIO& IO = ImGui::GetIO();

		const FKey Key = Event.GetKey();
		AddModifierKeyEvents(IO, Event.GetModifierKeys());
		IO.AddKeyEvent(ImGui::ConvertKey(Key), false);
		AddCommandAsControlKeyEvent(IO, Key, false);
		UpdateModifierStateFromKey(Key, false);

		return IO.WantCaptureKeyboard || (IO.WantTextInput && IsTextEditShortcut(IO, Key, Event.GetModifierKeys()));
	}

	virtual bool HandleAnalogInputEvent(FSlateApplication& SlateApp, const FAnalogInputEvent& Event) override
	{
		if (!ShouldHandleEvent(SlateApp, Event))
		{
			return false;
		}

		ImGui::FScopedContext ScopedContext(Owner->GetContext());

		ImGuiIO& IO = ImGui::GetIO();

		const float Value = Event.GetAnalogValue();
		IO.AddKeyAnalogEvent(ImGui::ConvertKey(Event.GetKey()), FMath::Abs(Value) > 0.1f, Value);

		return IO.WantCaptureKeyboard;
	}

	virtual bool HandleMouseMoveEvent(FSlateApplication& SlateApp, const FPointerEvent& Event) override
	{
		if (!ShouldHandlePointerEvent(SlateApp, Event))
		{
			return false;
		}

		ImGui::FScopedContext ScopedContext(Owner->GetContext());

		ImGuiIO& IO = ImGui::GetIO();

		if (SlateApp.HasAnyMouseCaptor())
		{
			IO.AddMousePosEvent(-FLT_MAX, -FLT_MAX);
			return false;
		}

		FVector2f Position = Event.GetScreenSpacePosition();
		if (!(IO.ConfigFlags & ImGuiConfigFlags_ViewportsEnable))
		{
			// Mouse position for single viewport mode is in client space
			Position -= Owner->GetTickSpaceGeometry().AbsolutePosition;
		}

		IO.AddMousePosEvent(Position.X, Position.Y);

		return IO.WantCaptureMouse;
	}

	virtual bool HandleMouseButtonDownEvent(FSlateApplication& SlateApp, const FPointerEvent& Event) override
	{
		if (!ShouldHandlePointerEvent(SlateApp, Event))
		{
			return false;
		}

		ImGui::FScopedContext ScopedContext(Owner->GetContext());

		ImGuiIO& IO = ImGui::GetIO();

		const FKey Button = Event.GetEffectingButton();
		if (Button == EKeys::LeftMouseButton)
		{
			IO.AddMouseButtonEvent(ImGuiMouseButton_Left, true);
		}
		else if (Button == EKeys::RightMouseButton)
		{
			IO.AddMouseButtonEvent(ImGuiMouseButton_Right, true);
		}
		else if (Button == EKeys::MiddleMouseButton)
		{
			IO.AddMouseButtonEvent(ImGuiMouseButton_Middle, true);
		}

		return IO.WantCaptureMouse;
	}

	virtual bool HandleMouseButtonUpEvent(FSlateApplication& SlateApp, const FPointerEvent& Event) override
	{
		if (!ShouldHandlePointerEvent(SlateApp, Event))
		{
			return false;
		}

		ImGui::FScopedContext ScopedContext(Owner->GetContext());

		ImGuiIO& IO = ImGui::GetIO();

		const FKey Button = Event.GetEffectingButton();
		if (Button == EKeys::LeftMouseButton)
		{
			IO.AddMouseButtonEvent(ImGuiMouseButton_Left, false);
		}
		else if (Button == EKeys::RightMouseButton)
		{
			IO.AddMouseButtonEvent(ImGuiMouseButton_Right, false);
		}
		else if (Button == EKeys::MiddleMouseButton)
		{
			IO.AddMouseButtonEvent(ImGuiMouseButton_Middle, false);
		}

		return false;
	}

	virtual bool HandleMouseButtonDoubleClickEvent(FSlateApplication& SlateApp, const FPointerEvent& Event) override
	{
		// Treat as mouse down, ImGui handles double click internally
		return HandleMouseButtonDownEvent(SlateApp, Event);
	}

	virtual bool HandleMouseWheelOrGestureEvent(FSlateApplication& SlateApp, const FPointerEvent& Event, const FPointerEvent* GestureEvent) override
	{
		if (!ShouldHandlePointerEvent(SlateApp, Event))
		{
			return false;
		}

		ImGui::FScopedContext ScopedContext(Owner->GetContext());

		ImGuiIO& IO = ImGui::GetIO();

		IO.AddMouseWheelEvent(0.0f, Event.GetWheelDelta());

		return IO.WantCaptureMouse;
	}

	bool HandleTextEditShortcutFallback(ImGuiIO& IO, const FKey& Key, const FModifierKeysState& ModifierKeys) const
	{
		if (!IsEffectiveControlDown(IO, ModifierKeys))
		{
			return false;
		}

		ImGuiContext* Context = ImGui::GetCurrentContext();
		ImGuiInputTextState* State = Context ? ImGui::GetInputTextState(Context->ActiveId) : nullptr;
		if (!State)
		{
			return false;
		}

		if (Key == EKeys::A)
		{
			State->SelectAll();
			State->CursorFollow = true;
			return true;
		}

		if (Key == EKeys::C)
		{
			CopyInputTextSelection(*State);
			return true;
		}

		if (Key == EKeys::V)
		{
			PasteClipboardText(*State);
			return true;
		}

		return false;
	}

	void CopyInputTextSelection(const ImGuiInputTextState& State) const
	{
		if (State.Flags & ImGuiInputTextFlags_Password)
		{
			return;
		}

		if (!State.HasSelection() && (State.Flags & ImGuiInputTextFlags_Multiline))
		{
			return;
		}

		const int32 SelectionStart = State.HasSelection() ? FMath::Min(State.GetSelectionStart(), State.GetSelectionEnd()) : 0;
		const int32 SelectionEnd = State.HasSelection() ? FMath::Max(State.GetSelectionStart(), State.GetSelectionEnd()) : State.TextLen;
		if (SelectionEnd <= SelectionStart || !State.TextA.Data)
		{
			return;
		}

		const FUTF8ToTCHAR SelectedText(State.TextA.Data + SelectionStart, SelectionEnd - SelectionStart);
		const FString ClipboardText(SelectedText.Length(), SelectedText.Get());
		FPlatformApplicationMisc::ClipboardCopy(*ClipboardText);
	}

	void PasteClipboardText(ImGuiInputTextState& State) const
	{
		if (State.Flags & ImGuiInputTextFlags_ReadOnly)
		{
			return;
		}

		FString ClipboardText;
		FPlatformApplicationMisc::ClipboardPaste(ClipboardText);
		if (ClipboardText.IsEmpty())
		{
			return;
		}

		const FTCHARToUTF8 ClipboardTextUtf8(*ClipboardText);
		const bool bIsMultiline = (State.Flags & ImGuiInputTextFlags_Multiline) != 0;
		const char* PreviousTextSrc = State.TextSrc;
		State.TextSrc = State.TextA.Data;

		const char* Text = ClipboardTextUtf8.Get();
		const char* TextEnd = Text + ClipboardTextUtf8.Length();
		while (Text < TextEnd)
		{
			unsigned int Codepoint = 0;
			const int32 BytesRead = ImTextCharFromUtf8(&Codepoint, Text, TextEnd);
			if (BytesRead <= 0)
			{
				++Text;
				continue;
			}

			Text += BytesRead;
			if (Codepoint != 0 && (bIsMultiline || (Codepoint != '\n' && Codepoint != '\r')))
			{
				State.OnCharPressed(Codepoint);
			}
		}

		State.TextSrc = PreviousTextSrc;
	}

	bool ShouldHandleEvent(FSlateApplication& SlateApp, const FInputEvent& InEvent) const
	{
		(void)InEvent;

#if WITH_EDITORONLY_DATA
		if (GIntraFrameDebuggingGameThread)
		{
			// Discard input events when the game thread is paused for debugging
			return false;
		}
#endif

		return Owner && Owner->CanProcessKeyboardInput(SlateApp);
	}

	bool ShouldHandlePointerEvent(FSlateApplication& SlateApp, const FPointerEvent& Event) const
	{
#if WITH_EDITORONLY_DATA
		if (GIntraFrameDebuggingGameThread)
		{
			// Discard input events when the game thread is paused for debugging
			return false;
		}
#endif

		return Owner && Owner->CanProcessPointerEvent(SlateApp, Event);
	}

private:
	SImGuiOverlay* Owner = nullptr;
	bool bLeftControlDown = false;
	bool bRightControlDown = false;
	bool bLeftShiftDown = false;
	bool bRightShiftDown = false;
	bool bLeftAltDown = false;
	bool bRightAltDown = false;
	bool bLeftCommandDown = false;
	bool bRightCommandDown = false;
};

void SImGuiOverlay::Construct(const FArguments& Args)
{
	SetVisibility(EVisibility::HitTestInvisible);
	ForceVolatile(true);

	Context = Args._Context.IsValid() ? Args._Context : FImGuiContext::Create();
	OwnerWindow = Args._OwnerWindow;
	if (Args._HandleInput)
	{
		InputProcessor = MakeShared<FImGuiInputProcessor>(this);
		FSlateApplication::Get().RegisterInputPreProcessor(InputProcessor.ToSharedRef(), 0);
	}
}

SImGuiOverlay::~SImGuiOverlay()
{
	if (FSlateApplication::IsInitialized() && InputProcessor.IsValid())
	{
		FSlateApplication::Get().UnregisterInputPreProcessor(InputProcessor);
	}
}

int32 SImGuiOverlay::OnPaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const
{
	LastPaintFrameNumber = GFrameCounter;

	if (!DrawData.bValid)
	{
		return LayerId;
	}

	const FSlateRenderTransform Transform(AllottedGeometry.GetAccumulatedRenderTransform().GetTranslation() - FVector2d(DrawData.DisplayPos));

	TArray<FSlateVertex> Vertices;
	TArray<FSlateVertex> CommandVertices;
	TArray<SlateIndex> CommandIndices;
	FSlateBrush TextureBrush;

	for (const FImGuiDrawList& DrawList : DrawData.DrawLists)
	{
		Vertices.SetNumUninitialized(DrawList.VtxBuffer.Size);

		ImDrawVert* SrcVertex = DrawList.VtxBuffer.Data;
		FSlateVertex* DstVertex = Vertices.GetData();

		for (int32 BufferIdx = 0; BufferIdx < Vertices.Num(); ++BufferIdx, ++SrcVertex, ++DstVertex)
		{
			DstVertex->TexCoords[0] = SrcVertex->uv.x;
			DstVertex->TexCoords[1] = SrcVertex->uv.y;
			DstVertex->TexCoords[2] = 1;
			DstVertex->TexCoords[3] = 1;
			DstVertex->Position = TransformPoint(Transform, FVector2f(SrcVertex->pos));
			DstVertex->Color.Bits = SrcVertex->col;
		}

		for (const ImDrawCmd& DrawCmd : DrawList.CmdBuffer)
		{
			if (DrawCmd.UserCallback != nullptr || DrawCmd.ElemCount == 0)
			{
				continue;
			}

			if (DrawCmd.VtxOffset > static_cast<unsigned int>(Vertices.Num()) ||
				DrawCmd.IdxOffset > static_cast<unsigned int>(DrawList.IdxBuffer.Size) ||
				DrawCmd.ElemCount > static_cast<unsigned int>(DrawList.IdxBuffer.Size) - DrawCmd.IdxOffset)
			{
				continue;
			}

			constexpr uint64 MaxSlateIndex = static_cast<uint64>(std::numeric_limits<SlateIndex>::max());
			uint64 MinIndex = std::numeric_limits<uint64>::max();
			uint64 MaxIndex = 0;
			bool bIndicesValid = true;
			for (unsigned int ElementIdx = 0; ElementIdx < DrawCmd.ElemCount; ++ElementIdx)
			{
				const uint64 LocalIndex = static_cast<uint64>(DrawList.IdxBuffer.Data[DrawCmd.IdxOffset + ElementIdx]);
				MinIndex = FMath::Min(MinIndex, LocalIndex);
				MaxIndex = FMath::Max(MaxIndex, LocalIndex);
			}

			const uint64 RequiredVertexCount = MaxIndex - MinIndex + 1;
			const uint64 VertexOffset = static_cast<uint64>(DrawCmd.VtxOffset) + MinIndex;
			if (RequiredVertexCount > MaxSlateIndex + 1 ||
				VertexOffset > static_cast<uint64>(Vertices.Num()) ||
				RequiredVertexCount > static_cast<uint64>(Vertices.Num()) - VertexOffset)
			{
				continue;
			}

			CommandIndices.Reset(static_cast<int32>(DrawCmd.ElemCount));
			for (unsigned int ElementIdx = 0; ElementIdx < DrawCmd.ElemCount; ++ElementIdx)
			{
				const uint64 RebasedIndex = static_cast<uint64>(DrawList.IdxBuffer.Data[DrawCmd.IdxOffset + ElementIdx]) - MinIndex;
				if (RebasedIndex > MaxSlateIndex)
				{
					bIndicesValid = false;
					break;
				}

				CommandIndices.Add(static_cast<SlateIndex>(RebasedIndex));
			}

			if (!bIndicesValid)
			{
				continue;
			}

			const int32 VertexStart = static_cast<int32>(VertexOffset);
			const int32 VertexCount = static_cast<int32>(RequiredVertexCount);
			CommandVertices.SetNumUninitialized(VertexCount);
			FMemory::Memcpy(CommandVertices.GetData(), Vertices.GetData() + VertexStart, static_cast<SIZE_T>(VertexCount) * sizeof(FSlateVertex));

#if WITH_ENGINE
			UTexture* Texture = DrawCmd.GetTexID();
			if (TextureBrush.GetResourceObject() != Texture)
			{
				TextureBrush.SetResourceObject(Texture);
				if (IsValid(Texture))
				{
					TextureBrush.ImageSize.X = Texture->GetSurfaceWidth();
					TextureBrush.ImageSize.Y = Texture->GetSurfaceHeight();
					TextureBrush.ImageType = ESlateBrushImageType::FullColor;
					TextureBrush.DrawAs = ESlateBrushDrawType::Image;
				}
				else
				{
					TextureBrush.ImageSize.X = 0;
					TextureBrush.ImageSize.Y = 0;
					TextureBrush.ImageType = ESlateBrushImageType::NoImage;
					TextureBrush.DrawAs = ESlateBrushDrawType::NoDrawType;
				}
			}
#else
			FSlateBrush* Texture = DrawCmd.GetTexID();
			if (Texture)
			{
				TextureBrush = *Texture;
			}
			else
			{
				TextureBrush.ImageSize.X = 0;
				TextureBrush.ImageSize.Y = 0;
				TextureBrush.ImageType = ESlateBrushImageType::NoImage;
				TextureBrush.DrawAs = ESlateBrushDrawType::NoDrawType;
			}
#endif

			FSlateRect ClipRect(DrawCmd.ClipRect.x, DrawCmd.ClipRect.y, DrawCmd.ClipRect.z, DrawCmd.ClipRect.w);
			ClipRect = TransformRect(Transform, ClipRect);

			OutDrawElements.PushClip(FSlateClippingZone(ClipRect));

			FSlateDrawElement::MakeCustomVerts(
				OutDrawElements, LayerId, TextureBrush.GetRenderingResource(),
				CommandVertices,
				CommandIndices,
				nullptr, 0, 0
			);

			OutDrawElements.PopClip();
		}
	}

	return LayerId;
}

FVector2D SImGuiOverlay::ComputeDesiredSize(float LayoutScaleMultiplier) const
{
	return FVector2D::ZeroVector;
}

bool SImGuiOverlay::SupportsKeyboardFocus() const
{
	return true;
}

FReply SImGuiOverlay::OnKeyChar(const FGeometry& MyGeometry, const FCharacterEvent& Event)
{
	if (!FSlateApplication::IsInitialized() || !CanProcessKeyboardInput(FSlateApplication::Get()))
	{
		return FReply::Unhandled();
	}

	ImGui::FScopedContext ScopedContext(Context);

	ImGuiIO& IO = ImGui::GetIO();

	IO.AddInputCharacter(static_cast<unsigned int>(Event.GetCharacter()));

	return IO.WantTextInput ? FReply::Handled() : FReply::Unhandled();
}

TSharedPtr<FImGuiContext> SImGuiOverlay::GetContext() const
{
	return Context;
}

void SImGuiOverlay::SetDrawData(const ImDrawData* InDrawData)
{
	DrawData = FImGuiDrawData(InDrawData);
}

void SImGuiOverlay::SetOwnerWindow(TWeakPtr<SWindow> InOwnerWindow)
{
	OwnerWindow = InOwnerWindow;
}

bool SImGuiOverlay::CanProcessInput() const
{
	if (!Context.IsValid() || !GetVisibility().IsVisible() || !WasRecentlyPainted())
	{
		return false;
	}

	const FVector2D LocalSize = GetTickSpaceGeometry().GetLocalSize();
	return LocalSize.X > 0.0 && LocalSize.Y > 0.0;
}

bool SImGuiOverlay::CanProcessKeyboardInput(FSlateApplication& SlateApp) const
{
	if (!CanProcessInput())
	{
		return false;
	}

	return IsSlateWindowOwnedByContext(SlateApp.GetActiveTopLevelWindow());
}

void SImGuiOverlay::ClearPointerInput() const
{
	ImGui::FScopedContext ScopedContext(Context);
	if (!ScopedContext.IsValid())
	{
		return;
	}

	ImGuiIO& IO = ImGui::GetIO();
	IO.AddMousePosEvent(-FLT_MAX, -FLT_MAX);
	for (int32 ButtonIndex = 0; ButtonIndex < IM_ARRAYSIZE(IO.MouseDown); ++ButtonIndex)
	{
		IO.AddMouseButtonEvent(ButtonIndex, false);
	}
}

bool SImGuiOverlay::CanProcessPointerEvent(FSlateApplication& SlateApp, const FPointerEvent& Event) const
{
	if (!CanProcessInput())
	{
		return false;
	}

	if (!GetTickSpaceGeometry().IsUnderLocation(Event.GetScreenSpacePosition()))
	{
		return false;
	}

	const FWidgetPath WidgetsUnderCursor = SlateApp.LocateWindowUnderMouse(
		Event.GetScreenSpacePosition(),
		SlateApp.GetInteractiveTopLevelWindows()
	);

	if (WidgetsUnderCursor.IsValid())
	{
		const bool bIsOwnedWindow = IsSlateWindowOwnedByContext(WidgetsUnderCursor.GetWindow().ToSharedPtr());
		const bool bCanReceivePointer = bIsOwnedWindow && IsWidgetPathWithinOverlayBranch(SlateApp, WidgetsUnderCursor);
		if (!bCanReceivePointer)
		{
			ClearPointerInput();
		}

		return bCanReceivePointer;
	}

	return IsSlateWindowOwnedByContext(SlateApp.GetActiveTopLevelWindow());
}

bool SImGuiOverlay::WasRecentlyPainted() const
{
	return LastPaintFrameNumber != 0 && GFrameCounter - LastPaintFrameNumber <= 1;
}

TSharedPtr<SWindow> SImGuiOverlay::GetOwnerWindow() const
{
	TSharedPtr<SWindow> Window = OwnerWindow.Pin();
	if (FSlateApplication::IsInitialized())
	{
		if (const TSharedPtr<SWindow> CurrentWidgetWindow = FSlateApplication::Get().FindWidgetWindow(AsShared()))
		{
			Window = CurrentWidgetWindow;
			OwnerWindow = Window;
		}
	}

	return Window;
}

bool SImGuiOverlay::IsSlateWindowOwnedByContext(const TSharedPtr<SWindow>& Window) const
{
	if (!Window.IsValid())
	{
		return false;
	}

	if (Window == GetOwnerWindow())
	{
		return true;
	}

	ImGui::FScopedContext ScopedContext(Context);
	if (!ScopedContext.IsValid())
	{
		return false;
	}

	ImGuiPlatformIO& PlatformIO = ImGui::GetPlatformIO();
	for (ImGuiViewport* Viewport : PlatformIO.Viewports)
	{
		if (const FImGuiViewportData* ViewportData = static_cast<FImGuiViewportData*>(Viewport->PlatformUserData))
		{
			if (ViewportData->Window.Pin() == Window)
			{
				return true;
			}
		}
	}

	return false;
}

bool SImGuiOverlay::IsWidgetPathWithinOverlayBranch(FSlateApplication& SlateApp, const FWidgetPath& WidgetsUnderCursor) const
{
	FWidgetPath OverlayPath;
	if (!SlateApp.FindPathToWidget(AsShared(), OverlayPath, EVisibility::All) || !OverlayPath.IsValid())
	{
		return true;
	}

	if (OverlayPath.Widgets.Num() < 2)
	{
		return true;
	}

	// The overlay is hit-test invisible, so the cursor path will usually stop at its parent.
	const TSharedRef<SWidget> OverlayParent = OverlayPath.Widgets[OverlayPath.Widgets.Num() - 2].Widget;
	return WidgetsUnderCursor.ContainsWidget(&OverlayParent.Get());
}
