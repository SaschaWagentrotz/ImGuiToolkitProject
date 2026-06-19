#include "Widgets/Input/ImGuiToolkitInputTextWithHint.h"

#include "FImGuiToolkitUtils.h"

void UImGuiToolkitInputTextWithHint::Render()
{
	if (!bEnabled)
		return;

	if (InputBuffer.Num() == 0)
	{
		InputBuffer.SetNumZeroed(1);
	}

	if (LastSyncedInputText != InputText)
	{
		FTCHARToUTF8 InputTextUtf8(*InputText);
		const int32 NeededBytes = InputTextUtf8.Length() + 1;
		InputBuffer.SetNumUninitialized(NeededBytes);
		FCStringAnsi::Strncpy(InputBuffer.GetData(), InputTextUtf8.Get(), NeededBytes);
		InputBuffer[NeededBytes - 1] = '\0';

		LastSyncedInputText = InputText;
	}

	const bool bTextChanged = ImGui::InputTextWithHint(
		TCHAR_TO_UTF8(*UniqueWidgetLabel),
		TCHAR_TO_UTF8(*Hint.ToString()),
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

void UImGuiToolkitInputTextWithHint::SetPreviewText(FText PreviewText)
{
	InputText = PreviewText.ToString();
}

void UImGuiToolkitInputTextWithHint::SetHint(FText InHint)
{
	Hint = InHint;
}
