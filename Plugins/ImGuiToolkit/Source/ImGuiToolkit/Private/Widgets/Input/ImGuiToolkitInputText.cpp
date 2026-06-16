#include "Widgets/Input/ImGuiToolkitInputText.h"

#include "FImGuiToolkitUtils.h"

void UImGuiToolkitInputText::Render()
{
	if (!bEnabled)
		return;

	// Ensure buffer exists (at least 1 byte for a valid C-string)
	if (InputBuffer.Num() == 0)
	{
		InputBuffer.SetNumZeroed(1);
	}

	// Sync UE to ImGui when the source text changed externally.
	if (LastSyncedInputText != InputText)
	{
		FTCHARToUTF8 InputTextUtf8(*InputText);
		const int32 NeededBytes = InputTextUtf8.Length() + 1; // +1 for '\0'
		InputBuffer.SetNumUninitialized(NeededBytes);
		FCStringAnsi::Strncpy(InputBuffer.GetData(), InputTextUtf8.Get(), NeededBytes);
		InputBuffer[NeededBytes - 1] = '\0';

		LastSyncedInputText = InputText;
	}

	const bool bTextChanged = ImGui::InputText(
		TCHAR_TO_UTF8(*UniqueWidgetLabel),
		InputBuffer.GetData(),
		static_cast<size_t>(InputBuffer.Num()),
		ImGuiInputTextFlags_CallbackResize,
		FImGuiToolkitUtils::ImGuiResizeCallback,
		&InputBuffer
	);

	if (bTextChanged)
	{
		InputText = UTF8_TO_TCHAR(InputBuffer.GetData());
		LastSyncedInputText = InputText;
		OnTextChanged.Broadcast(InputText);
	}
}

void UImGuiToolkitInputText::SetPreviewText(FText PreviewText)
{
	InputText = PreviewText.ToString();
}
