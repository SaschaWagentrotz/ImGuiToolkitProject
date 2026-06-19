#include "Containers/ImGuiToolkitBeginCombo.h"

void UImGuiToolkitBeginCombo::Render()
{
	if (!bEnabled)
	{
		bIsOpen = false;
		return;
	}

	bIsOpen = ImGui::BeginCombo(
		TCHAR_TO_UTF8(*UniqueWidgetLabel),
		TCHAR_TO_UTF8(*PreviewValue.ToString()),
		FImGuiToolkitUtils::CombineImGuiComboFlags(ComboFlags)
	);

	if (bIsOpen)
	{
		RenderChildren();
		ImGui::EndCombo();
	}
}
