// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Input/ImGuiToolkitInputTextMultiline.h"
#include "FImGuiToolkitUtils.h"


void UImGuiToolkitInputTextMultiline::Render()
{
	if (!bEnabled)
		return;

	// The code below contains AI-generated slop. It seems to work as it should, but this might need to be reworked.

	// Persistent per-widget state (keep as members if you prefer)
	TArray<char> InputBuffer;
	FString LastSyncedInputText;

	// Ensure buffer exists (at least 1 byte for a valid C-string)
	if (InputBuffer.Num() == 0)
	{
		InputBuffer.SetNumZeroed(1);
	}

	// Sync UE → ImGui when the source text changed externally
	if (LastSyncedInputText != InputText)
	{
		FTCHARToUTF8 InputTextUtf8(*InputText);
		const int32 NeededBytes = InputTextUtf8.Length() + 1; // +1 for '\0'
		InputBuffer.SetNumUninitialized(NeededBytes);
		FCStringAnsi::Strncpy(InputBuffer.GetData(), InputTextUtf8.Get(), NeededBytes);
		InputBuffer[NeededBytes - 1] = '\0';

		LastSyncedInputText = InputText;
	}

	ImVec2 TextBoxSize(Size.X, Size.Y);

	// Let ImGui grow/shrink the buffer as the user types.
	const bool bTextChanged = ImGui::InputTextMultiline(
		TCHAR_TO_UTF8(*UniqueWidgetLabel),			// caption
		InputBuffer.GetData(),						// buffer (UTF-8)
		static_cast<size_t>(InputBuffer.Num()),		// current capacity in bytes
		TextBoxSize,								// size of the text box
		ImGuiInputTextFlags_CallbackResize,			// enable resize callback
		FImGuiToolkitUtils::ImGuiResizeCallback,	// our callback
		&InputBuffer								// user data for callback
	);

	if (bTextChanged)
	{
		InputText = UTF8_TO_TCHAR(InputBuffer.GetData());
		LastSyncedInputText = InputText;
		OnTextChanged.Broadcast(InputText);
	}
}

void UImGuiToolkitInputTextMultiline::SetPreviewText(FText PreviewText)
{
	InputText = PreviewText.ToString();
}
