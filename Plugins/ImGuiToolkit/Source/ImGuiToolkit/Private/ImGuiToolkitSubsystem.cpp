#include "ImGuiToolkitSubsystem.h"

#include "ImGuiToolkitHostWidget.h"
#include "Engine/Engine.h"
#include "Engine/World.h"
#include "ImGuiConfig.h"
#include "ImGuiToolkitSettings.h"

#include <imgui.h>
#include <imgui_internal.h>

namespace
{
	UWorld* GetObjectWorld(const UObject* Object)
	{
		for (const UObject* Current = Object; Current; Current = Current->GetOuter())
		{
			if (UWorld* World = Current->GetWorld())
			{
				return World;
			}

			if (const UWorld* World = Cast<UWorld>(Current))
			{
				return const_cast<UWorld*>(World);
			}
		}

		return nullptr;
	}

	int32 GetImGuiPieSessionId(const UObject* Object)
	{
		UWorld* World = GetObjectWorld(Object);
		if (!World || World->WorldType != EWorldType::PIE || !GEngine)
		{
			return INDEX_NONE;
		}

		if (const FWorldContext* WorldContext = GEngine->GetWorldContextFromWorld(World))
		{
			return WorldContext->PIEInstance;
		}

		return INDEX_NONE;
	}

	FString GetImGuiDisplayName(const UImGuiToolkitWindow* Window)
	{
		if (!Window)
		{
			return FString();
		}

		FString WindowName = Window->GetImGuiWindowName();
		FString DisplayName;
		if (WindowName.Split(TEXT("###"), &DisplayName, nullptr))
		{
			return DisplayName;
		}

		return WindowName;
	}
}

void UImGuiToolkitSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	TickHandle = FTSTicker::GetCoreTicker().AddTicker(FTickerDelegate::CreateUObject(this, &UImGuiToolkitSubsystem::OnTick), 0.0f);

	EndFrameHandle = FCoreDelegates::OnEndFrame.AddUObject(this, &UImGuiToolkitSubsystem::OnEndFrame);
}

void UImGuiToolkitSubsystem::Deinitialize()
{
	if (EndFrameHandle.IsValid())
		FCoreDelegates::OnEndFrame.Remove(EndFrameHandle);

	if (TickHandle.IsValid())
		FTSTicker::GetCoreTicker().RemoveTicker(TickHandle);

	Super::Deinitialize();
}

static inline ImVec4 ToImGuiColor(const FLinearColor& Color)
{
	const FColor SRGBColor = Color.ToFColorSRGB();
	return ImVec4(
		SRGBColor.R / 255.0f,
		SRGBColor.G / 255.0f,
		SRGBColor.B / 255.0f,
		SRGBColor.A / 255.0f
	);
}

void UImGuiToolkitSubsystem::SetImGuiToolkitStyle()
{
	const UImGuiToolkitSettings* Settings = GetDefault<UImGuiToolkitSettings>();
	if (!Settings)
	{
		return;
	}

	ImGuiStyle* dst_style = NULL;
	ImGuiStyle& style = dst_style ? *dst_style : ImGui::GetStyle();
	style = ImGuiStyle();
    ImVec4* colors = style.Colors;

    // ---- Assignments ----
    colors[ImGuiCol_Text]                   = ToImGuiColor(Settings->Text);
    colors[ImGuiCol_TextDisabled]           = ToImGuiColor(Settings->TextDisabled);

    colors[ImGuiCol_WindowBg]               = ToImGuiColor(Settings->WindowBg);
    colors[ImGuiCol_ChildBg]                = ToImGuiColor(Settings->ChildBg);
    colors[ImGuiCol_PopupBg]                = ToImGuiColor(Settings->PopupBg);

    colors[ImGuiCol_Border]                 = ToImGuiColor(Settings->Border);
    colors[ImGuiCol_BorderShadow]           = ToImGuiColor(Settings->BorderShadow);

    colors[ImGuiCol_FrameBg]                = ToImGuiColor(Settings->FrameBg);
    colors[ImGuiCol_FrameBgHovered]         = ToImGuiColor(Settings->FrameBgHovered);
    colors[ImGuiCol_FrameBgActive]          = ToImGuiColor(Settings->FrameBgActive);

    // Buttons (UE behavior)
    colors[ImGuiCol_Button]                 = ToImGuiColor(Settings->Button);
    colors[ImGuiCol_ButtonHovered]          = ToImGuiColor(Settings->ButtonHovered);
    colors[ImGuiCol_ButtonActive]           = ToImGuiColor(Settings->ButtonActive);

    // Sliders / checks use accent to signal interaction
    colors[ImGuiCol_CheckMark]              = ToImGuiColor(Settings->CheckMark);
    colors[ImGuiCol_SliderGrab]             = ToImGuiColor(Settings->SliderGrab);
    colors[ImGuiCol_SliderGrabActive]       = ToImGuiColor(Settings->SliderGrabActive);

    // Headers stay neutral (not blue)
    colors[ImGuiCol_Header]                 = ToImGuiColor(Settings->Header);
    colors[ImGuiCol_HeaderHovered]          = ToImGuiColor(Settings->HeaderHovered);
    colors[ImGuiCol_HeaderActive]           = ToImGuiColor(Settings->HeaderActive);

    // Separators / grips
    colors[ImGuiCol_Separator]              = ToImGuiColor(Settings->Separator);
    colors[ImGuiCol_SeparatorHovered]       = ToImGuiColor(Settings->SeparatorHovered);
    colors[ImGuiCol_SeparatorActive]        = ToImGuiColor(Settings->SeparatorActive);

    colors[ImGuiCol_ResizeGrip]             = ToImGuiColor(Settings->ResizeGrip);
    colors[ImGuiCol_ResizeGripHovered]      = ToImGuiColor(Settings->ResizeGripHovered);
    colors[ImGuiCol_ResizeGripActive]       = ToImGuiColor(Settings->ResizeGripActive);

    // Tabs
    colors[ImGuiCol_Tab]                    = ToImGuiColor(Settings->Tab);
    colors[ImGuiCol_TabHovered]             = ToImGuiColor(Settings->TabHovered);
    colors[ImGuiCol_TabSelected]            = ToImGuiColor(Settings->TabSelected);
    colors[ImGuiCol_TabSelectedOverline]    = ToImGuiColor(Settings->TabSelectedOverline);
    colors[ImGuiCol_TabDimmed]              = ToImGuiColor(Settings->TabDimmed);
    colors[ImGuiCol_TabDimmedSelected]      = ToImGuiColor(Settings->TabDimmedSelected);
    colors[ImGuiCol_TabDimmedSelectedOverline] = ToImGuiColor(Settings->TabDimmedSelectedOverline);

    // Docking
    colors[ImGuiCol_DockingPreview]         = ToImGuiColor(Settings->DockingPreview);
    colors[ImGuiCol_DockingEmptyBg]         = ToImGuiColor(Settings->DockingEmptyBg);

    // Scrollbars
    colors[ImGuiCol_ScrollbarBg]            = ToImGuiColor(Settings->ScrollbarBg);
    colors[ImGuiCol_ScrollbarGrab]          = ToImGuiColor(Settings->ScrollbarGrab);
    colors[ImGuiCol_ScrollbarGrabHovered]   = ToImGuiColor(Settings->ScrollbarGrabHovered);
    colors[ImGuiCol_ScrollbarGrabActive]    = ToImGuiColor(Settings->ScrollbarGrabActive);

    // Tables / plots
    colors[ImGuiCol_TableHeaderBg]          = ToImGuiColor(Settings->TableHeaderBg);
    colors[ImGuiCol_TableBorderStrong]      = ToImGuiColor(Settings->TableBorderStrong);
    colors[ImGuiCol_TableBorderLight]       = ToImGuiColor(Settings->TableBorderLight);
    colors[ImGuiCol_TableRowBg]             = ToImGuiColor(Settings->TableRowBg);
    colors[ImGuiCol_TableRowBgAlt]          = ToImGuiColor(Settings->TableRowBgAlt);

    colors[ImGuiCol_PlotLines]              = ToImGuiColor(Settings->PlotLines);
    colors[ImGuiCol_PlotLinesHovered]       = ToImGuiColor(Settings->PlotLinesHovered);
    colors[ImGuiCol_PlotHistogram]          = ToImGuiColor(Settings->PlotHistogram);
    colors[ImGuiCol_PlotHistogramHovered]   = ToImGuiColor(Settings->PlotHistogramHovered);

    // Links / selection / nav / modals
    colors[ImGuiCol_TextLink]               = ToImGuiColor(Settings->TextLink);
    colors[ImGuiCol_TextSelectedBg]         = ToImGuiColor(Settings->TextSelectedBg);
    colors[ImGuiCol_DragDropTarget]         = ToImGuiColor(Settings->DragDropTarget);
    colors[ImGuiCol_NavCursor]              = ToImGuiColor(Settings->NavCursor);
    colors[ImGuiCol_NavWindowingHighlight]  = ToImGuiColor(Settings->NavWindowingHighlight);
    colors[ImGuiCol_NavWindowingDimBg]      = ToImGuiColor(Settings->NavWindowingDimBg);
    colors[ImGuiCol_ModalWindowDimBg]       = ToImGuiColor(Settings->ModalWindowDimBg);

    colors[ImGuiCol_TitleBg]                = ToImGuiColor(Settings->TitleBg);
    colors[ImGuiCol_TitleBgActive]          = ToImGuiColor(Settings->TitleBgActive);
    colors[ImGuiCol_TitleBgCollapsed]       = ToImGuiColor(Settings->TitleBgCollapsed);
    colors[ImGuiCol_MenuBarBg]              = ToImGuiColor(Settings->MenuBarBg);

    // ---- Layout / metrics ----
    style.FramePadding            = ImVec2(8.0f, 5.0f);
    style.ItemSpacing             = ImVec2(8.0f, 6.0f);
    style.ItemInnerSpacing        = ImVec2(6.0f, 5.0f);
    style.CellPadding             = ImVec2(6.0f, 4.0f);

    style.ScrollbarSize           = 14.0f;
    style.GrabMinSize             = 10.0f;

    style.WindowRounding          = 3.0f;
    style.ChildRounding           = 3.0f;
    style.FrameRounding           = 3.0f;
    style.PopupRounding           = 3.0f;
    style.ScrollbarRounding       = 3.0f;
    style.GrabRounding            = 3.0f;
    style.TabRounding             = 3.0f;

    style.WindowBorderSize        = 1.0f;
    style.ChildBorderSize         = 1.0f;
    style.PopupBorderSize         = 1.0f;
    style.FrameBorderSize         = 1.0f;
    style.TabBorderSize           = 1.0f;

    style.WindowTitleAlign        = ImVec2(0.0f, 0.5f);
    style.ColorButtonPosition     = ImGuiDir_Right;
    style.ButtonTextAlign         = ImVec2(0.5f, 0.5f);
    style.SelectableTextAlign     = ImVec2(0.0f, 0.5f);

    style.TabBarBorderSize        = 1.0f;
    style.TabBarOverlineSize      = 2.0f;
    style.SeparatorTextPadding    = ImVec2(18.0f, 3.0f);
}

void UImGuiToolkitSubsystem::SetShowImGuiDemoWindow(bool bNewShow)
{
	bShowDemoWindow = bNewShow;
}

void UImGuiToolkitSubsystem::ShowImGuiDemoWindow(bool bShow)
{
	if (bShow)
	{
		ImGui::ShowDemoWindow();
	}
}

void UImGuiToolkitSubsystem::RegisterWindow(UImGuiToolkitWindow* Window)
{
	if (!Window)
	{
		return;
	}

	const FString NewWindowDisplayName = GetImGuiDisplayName(Window);
	for (int32 WindowIndex = RegisteredWindows.Num() - 1; WindowIndex >= 0; --WindowIndex)
	{
		UImGuiToolkitWindow* RegisteredWindow = RegisteredWindows[WindowIndex];
		if (!RegisteredWindow || RegisteredWindow == Window)
		{
			continue;
		}

		if (GetImGuiDisplayName(RegisteredWindow) == NewWindowDisplayName)
		{
			RemoveWindowReferences(RegisteredWindow);
			RegisteredWindows.RemoveAtSwap(WindowIndex);
		}
	}

	RegisteredWindows.AddUnique(Window);
}

void UImGuiToolkitSubsystem::UnregisterWindow(UImGuiToolkitWindow* Window)
{
	RemoveWindowReferences(Window);
	RegisteredWindows.Remove(Window);
}

void UImGuiToolkitSubsystem::RegisterHostWidget(UImGuiToolkitHostWidget* HostWidget)
{
	if (HostWidget)
	{
		RegisteredHostWidgets.AddUnique(TWeakObjectPtr<UImGuiToolkitHostWidget>(HostWidget));
		RegisterPendingDockRequestsForHost(HostWidget->GetHostedWindow());
	}
}

void UImGuiToolkitSubsystem::UnregisterHostWidget(UImGuiToolkitHostWidget* HostWidget)
{
	UImGuiToolkitWindow* HostedWindow = HostWidget ? HostWidget->GetHostedWindow() : nullptr;

	RegisteredHostWidgets.RemoveAllSwap([HostWidget](const TWeakObjectPtr<UImGuiToolkitHostWidget>& RegisteredHostWidget)
	{
		return !RegisteredHostWidget.IsValid() || RegisteredHostWidget.Get() == HostWidget;
	});

	if (HostedWindow && !IsWindowHostedByRegisteredHost(HostedWindow))
	{
		HostedWindow->bIsHosted = false;
		RemovePendingDockRequestsForHost(HostedWindow);
	}
}

bool UImGuiToolkitSubsystem::IsWindowHostedByRegisteredHost(UImGuiToolkitWindow* Window) const
{
	if (!Window)
	{
		return false;
	}

	return RegisteredHostWidgets.ContainsByPredicate([Window](const TWeakObjectPtr<UImGuiToolkitHostWidget>& RegisteredHostWidget)
	{
		UImGuiToolkitHostWidget* HostWidget = RegisteredHostWidget.Get();
		return HostWidget && HostWidget->GetHostedWindow() == Window;
	});
}

void UImGuiToolkitSubsystem::QueueDockWindow(UImGuiToolkitWindow* WindowToDock, UImGuiToolkitWindow* TargetWindow,
	EImGuiToolkitDockSplitDirection Direction, float SplitRatio)
{
	if (!WindowToDock || !TargetWindow || WindowToDock == TargetWindow)
	{
		return;
	}

	FPendingDockRequest Request;
	Request.WindowToDock = WindowToDock;
	Request.TargetWindow = TargetWindow;
	Request.Direction = Direction;
	Request.SplitRatio = FMath::Clamp(SplitRatio, 0.05f, 0.95f);
	PendingDockRequests.Add(Request);

	if (IsWindowHostedByRegisteredHost(TargetWindow))
	{
		RegisterHostedDockRequest(Request);
	}
}

bool UImGuiToolkitSubsystem::OnTick(float DeltaTime)
{
	for (int32 HostIndex = RegisteredHostWidgets.Num() - 1; HostIndex >= 0; --HostIndex)
	{
		UImGuiToolkitHostWidget* HostWidget = RegisteredHostWidgets[HostIndex].Get();
		if (!HostWidget)
		{
			RegisteredHostWidgets.RemoveAtSwap(HostIndex);
			continue;
		}

		HostWidget->RenderHost();
	}

	// This runs every frame in both editor and game.
	for (UImGuiToolkitWindow* Window : RegisteredWindows)
	{
		const bool bIsAssignedToHost = IsWindowHostedByRegisteredHost(Window);

		if (!Window || Window->bIsHosted || bIsAssignedToHost || IsRenderedByHostDocking(Window))
		{
			continue;
		}

		const ImGui::FScopedContext ScopedContext(GetImGuiPieSessionId(Window));
		if (ScopedContext)
		{
			ApplyStyleToCurrentContext();
			Window->Render();
			ApplyPendingDockRequests();
		}
	}

	const ImGui::FScopedContext ScopedContext;
	if (ScopedContext)
	{
		ApplyStyleToCurrentContext();
		ShowImGuiDemoWindow(bShowDemoWindow);
		ApplyPendingDockRequests();

		// Broadcast delegate
		OnImGuiRender.Broadcast();
	} 
	
	return true; // Keep ticking
}

void UImGuiToolkitSubsystem::OnEndFrame()
{
	ApplyStyleToCurrentContext();
}

void UImGuiToolkitSubsystem::ApplyStyleToCurrentContext()
{
	ImGuiContext* Context = ImGui::GetCurrentContext();
	if (!Context)
	{
		return;
	}

	const UImGuiToolkitSettings* Settings = GetDefault<UImGuiToolkitSettings>();
	const float Scale = FMath::Clamp(Settings ? Settings->Scale : 1.0f, 0.25f, 4.0f);

	ImGuiIO& IO = ImGui::GetIO();
	IO.FontGlobalScale = 1.0f;

	SetImGuiToolkitStyle();
	ImGui::GetStyle().ScaleAllSizes(Scale);
}

void UImGuiToolkitSubsystem::ApplyPendingDockRequests(UImGuiToolkitWindow* HostWindow)
{
	for (int32 RequestIndex = PendingDockRequests.Num() - 1; RequestIndex >= 0; --RequestIndex)
	{
		const FPendingDockRequest Request = PendingDockRequests[RequestIndex];
		if (!Request.WindowToDock.IsValid() || !Request.TargetWindow.IsValid())
		{
			PendingDockRequests.RemoveAtSwap(RequestIndex);
			continue;
		}

		UImGuiToolkitWindow* TargetWindow = Request.TargetWindow.Get();
		const bool bTargetIsCurrentHost = HostWindow && TargetWindow == HostWindow;
		const bool bTargetHasHostedDocking = HostedDockedWindows.Contains(TargetWindow) || HostedDockRequests.Contains(TargetWindow);
		if ((IsWindowHostedByRegisteredHost(TargetWindow) || bTargetHasHostedDocking) && !bTargetIsCurrentHost)
		{
			RegisterHostedDockRequest(Request);
			PendingDockRequests.RemoveAtSwap(RequestIndex);
			continue;
		}

		if ((!HostWindow || bTargetIsCurrentHost) && ApplyDockRequest(Request))
		{
			PendingDockRequests.RemoveAtSwap(RequestIndex);
		}
	}
}

void UImGuiToolkitSubsystem::ApplyHostedDockRequests(UImGuiToolkitWindow* HostWindow)
{
	if (!HostWindow)
	{
		return;
	}

	TArray<FPendingDockRequest>* DockRequests = HostedDockRequests.Find(HostWindow);
	if (!DockRequests)
	{
		return;
	}

	for (int32 RequestIndex = DockRequests->Num() - 1; RequestIndex >= 0; --RequestIndex)
	{
		const FPendingDockRequest& Request = (*DockRequests)[RequestIndex];
		if (!Request.WindowToDock.IsValid() || !Request.TargetWindow.IsValid())
		{
			DockRequests->RemoveAtSwap(RequestIndex);
			continue;
		}

		ApplyDockRequest(Request);
	}
}

void UImGuiToolkitSubsystem::RenderWindowsDockedToHost(UImGuiToolkitWindow* HostWindow)
{
	if (!HostWindow)
	{
		return;
	}

	TArray<TWeakObjectPtr<UImGuiToolkitWindow>>* DockedWindows = HostedDockedWindows.Find(HostWindow);
	if (!DockedWindows)
	{
		return;
	}

	for (int32 WindowIndex = DockedWindows->Num() - 1; WindowIndex >= 0; --WindowIndex)
	{
		UImGuiToolkitWindow* DockedWindow = (*DockedWindows)[WindowIndex].Get();
		if (!DockedWindow)
		{
			DockedWindows->RemoveAtSwap(WindowIndex);
			continue;
		}

		DockedWindow->RenderWithHostDockingPlacement();
	}
}

bool UImGuiToolkitSubsystem::HasWindowsDockedToHost(UImGuiToolkitWindow* HostWindow) const
{
	const TArray<TWeakObjectPtr<UImGuiToolkitWindow>>* DockedWindows = HostedDockedWindows.Find(HostWindow);
	if (!DockedWindows)
	{
		return false;
	}

	for (const TWeakObjectPtr<UImGuiToolkitWindow>& DockedWindow : *DockedWindows)
	{
		if (DockedWindow.IsValid())
		{
			return true;
		}
	}

	return false;
}

bool UImGuiToolkitSubsystem::UpdateHostedDockNodeBounds(UImGuiToolkitWindow* HostWindow, const FVector2D& HostPosition, const FVector2D& HostSize)
{
	if (!HostWindow || HostSize.X <= 0.0 || HostSize.Y <= 0.0)
	{
		return false;
	}

	const FTCHARToUTF8 HostWindowName(*HostWindow->GetImGuiWindowName());
	ImGuiWindow* HostImGuiWindow = ImGui::FindWindowByName(HostWindowName.Get());
	if (!HostImGuiWindow || !HostImGuiWindow->DockNode)
	{
		return false;
	}

	ImGuiDockNode* RootDockNode = ImGui::DockNodeGetRootNode(HostImGuiWindow->DockNode);
	if (!RootDockNode)
	{
		return false;
	}

	ImGui::DockBuilderSetNodePos(RootDockNode->ID, ImVec2(HostPosition.X, HostPosition.Y));
	ImGui::DockBuilderSetNodeSize(RootDockNode->ID, ImVec2(HostSize.X, HostSize.Y));
	return true;
}

bool UImGuiToolkitSubsystem::ApplyDockRequest(const FPendingDockRequest& Request)
{
	UImGuiToolkitWindow* WindowToDock = Request.WindowToDock.Get();
	UImGuiToolkitWindow* TargetWindow = Request.TargetWindow.Get();
	if (!WindowToDock || !TargetWindow || WindowToDock == TargetWindow)
	{
		return true;
	}

	const FTCHARToUTF8 WindowToDockName(*WindowToDock->GetImGuiWindowName());
	const FTCHARToUTF8 TargetWindowName(*TargetWindow->GetImGuiWindowName());

	ImGuiWindow* TargetImGuiWindow = ImGui::FindWindowByName(TargetWindowName.Get());
	if (!TargetImGuiWindow || !TargetImGuiWindow->WasActive)
	{
		return false;
	}

	ImGuiID RootDockNodeId = TargetImGuiWindow->DockNode ? TargetImGuiWindow->DockNode->ID : 0;
	if (RootDockNodeId == 0)
	{
		RootDockNodeId = ImGui::DockBuilderAddNode(0);
		ImGui::DockBuilderSetNodePos(RootDockNodeId, TargetImGuiWindow->Pos);
		ImGui::DockBuilderSetNodeSize(RootDockNodeId, TargetImGuiWindow->SizeFull);
	}

	const ImGuiDir SplitDirection = FImGuiToolkitUtils::UnrealDockSplitDirectionToImGuiDir(Request.Direction);
	if (Request.Direction == EImGuiToolkitDockSplitDirection::Center)
	{
		ImGui::DockBuilderDockWindow(TargetWindowName.Get(), RootDockNodeId);
		ImGui::DockBuilderDockWindow(WindowToDockName.Get(), RootDockNodeId);
		ImGui::DockBuilderFinish(RootDockNodeId);
		return true;
	}

	if (SplitDirection == ImGuiDir_None)
	{
		return true;
	}

	ImGuiID DockedNodeId = 0;
	ImGuiID TargetNodeId = 0;
	ImGui::DockBuilderSplitNode(RootDockNodeId, SplitDirection, Request.SplitRatio, &DockedNodeId, &TargetNodeId);
	ImGui::DockBuilderDockWindow(TargetWindowName.Get(), TargetNodeId);
	ImGui::DockBuilderDockWindow(WindowToDockName.Get(), DockedNodeId);
	ImGui::DockBuilderFinish(RootDockNodeId);

	return true;
}

void UImGuiToolkitSubsystem::RegisterHostedDockRequest(const FPendingDockRequest& Request)
{
	UImGuiToolkitWindow* WindowToDock = Request.WindowToDock.Get();
	UImGuiToolkitWindow* TargetWindow = Request.TargetWindow.Get();
	if (!WindowToDock || !TargetWindow || WindowToDock == TargetWindow)
	{
		return;
	}

	const FString TargetDisplayName = GetImGuiDisplayName(TargetWindow);
	const FString WindowToDockDisplayName = GetImGuiDisplayName(WindowToDock);
	TArray<UImGuiToolkitWindow*> StaleWindows;

	for (const TPair<TWeakObjectPtr<UImGuiToolkitWindow>, TArray<TWeakObjectPtr<UImGuiToolkitWindow>>>& HostedDockedWindowPair : HostedDockedWindows)
	{
		UImGuiToolkitWindow* ExistingTargetWindow = HostedDockedWindowPair.Key.Get();
		if (!ExistingTargetWindow || GetImGuiDisplayName(ExistingTargetWindow) != TargetDisplayName)
		{
			continue;
		}

		for (const TWeakObjectPtr<UImGuiToolkitWindow>& ExistingDockedWindow : HostedDockedWindowPair.Value)
		{
			UImGuiToolkitWindow* ExistingDockedWindowPtr = ExistingDockedWindow.Get();
			if (ExistingDockedWindowPtr && ExistingDockedWindowPtr != WindowToDock && GetImGuiDisplayName(ExistingDockedWindowPtr) == WindowToDockDisplayName)
			{
				StaleWindows.AddUnique(ExistingDockedWindowPtr);
			}
		}
	}

	for (UImGuiToolkitWindow* StaleWindow : StaleWindows)
	{
		RemoveWindowReferences(StaleWindow);
		RegisteredWindows.Remove(StaleWindow);
	}

	TArray<TWeakObjectPtr<UImGuiToolkitWindow>>& DockedWindows = HostedDockedWindows.FindOrAdd(TargetWindow);
	DockedWindows.AddUnique(TWeakObjectPtr<UImGuiToolkitWindow>(WindowToDock));

	TArray<FPendingDockRequest>& DockRequests = HostedDockRequests.FindOrAdd(TargetWindow);
	DockRequests.RemoveAllSwap([WindowToDock](const FPendingDockRequest& ExistingRequest)
	{
		return ExistingRequest.WindowToDock.Get() == WindowToDock;
	});
	DockRequests.Add(Request);
}

void UImGuiToolkitSubsystem::RegisterPendingDockRequestsForHost(UImGuiToolkitWindow* HostWindow)
{
	if (!HostWindow)
	{
		return;
	}

	for (int32 RequestIndex = PendingDockRequests.Num() - 1; RequestIndex >= 0; --RequestIndex)
	{
		const FPendingDockRequest Request = PendingDockRequests[RequestIndex];
		if (!Request.WindowToDock.IsValid() || !Request.TargetWindow.IsValid())
		{
			PendingDockRequests.RemoveAtSwap(RequestIndex);
			continue;
		}

		if (Request.TargetWindow.Get() == HostWindow)
		{
			RegisterHostedDockRequest(Request);
			PendingDockRequests.RemoveAtSwap(RequestIndex);
		}
	}
}

void UImGuiToolkitSubsystem::RemovePendingDockRequestsForHost(UImGuiToolkitWindow* HostWindow)
{
	if (!HostWindow)
	{
		return;
	}

	PendingDockRequests.RemoveAllSwap([HostWindow](const FPendingDockRequest& Request)
	{
		return Request.TargetWindow.Get() == HostWindow;
	});
}

void UImGuiToolkitSubsystem::RemoveWindowReferences(UImGuiToolkitWindow* Window)
{
	if (!Window)
	{
		return;
	}

	PendingDockRequests.RemoveAllSwap([Window](const FPendingDockRequest& Request)
	{
		return Request.WindowToDock.Get() == Window || Request.TargetWindow.Get() == Window;
	});

	for (auto It = HostedDockRequests.CreateIterator(); It; ++It)
	{
		if (It.Key().Get() == Window)
		{
			It.RemoveCurrent();
			continue;
		}

		It.Value().RemoveAllSwap([Window](const FPendingDockRequest& Request)
		{
			return Request.WindowToDock.Get() == Window || Request.TargetWindow.Get() == Window;
		});

		if (It.Value().IsEmpty())
		{
			It.RemoveCurrent();
		}
	}

	for (auto It = HostedDockedWindows.CreateIterator(); It; ++It)
	{
		if (It.Key().Get() == Window)
		{
			for (const TWeakObjectPtr<UImGuiToolkitWindow>& DockedWindow : It.Value())
			{
				if (UImGuiToolkitWindow* DockedWindowPtr = DockedWindow.Get())
				{
					RegisteredWindows.Remove(DockedWindowPtr);
				}
			}

			It.RemoveCurrent();
			continue;
		}

		It.Value().RemoveAllSwap([Window](const TWeakObjectPtr<UImGuiToolkitWindow>& DockedWindow)
		{
			return !DockedWindow.IsValid() || DockedWindow.Get() == Window;
		});

		if (It.Value().IsEmpty())
		{
			It.RemoveCurrent();
		}
	}
}

bool UImGuiToolkitSubsystem::IsRenderedByHostDocking(UImGuiToolkitWindow* Window) const
{
	if (!Window)
	{
		return false;
	}

	for (const TPair<TWeakObjectPtr<UImGuiToolkitWindow>, TArray<TWeakObjectPtr<UImGuiToolkitWindow>>>& HostedDockedWindowPair : HostedDockedWindows)
	{
		UImGuiToolkitWindow* HostWindow = HostedDockedWindowPair.Key.Get();
		if (!HostWindow)
		{
			continue;
		}

		for (const TWeakObjectPtr<UImGuiToolkitWindow>& DockedWindow : HostedDockedWindowPair.Value)
		{
			if (DockedWindow.Get() == Window)
			{
				return true;
			}
		}
	}

	return false;
}
