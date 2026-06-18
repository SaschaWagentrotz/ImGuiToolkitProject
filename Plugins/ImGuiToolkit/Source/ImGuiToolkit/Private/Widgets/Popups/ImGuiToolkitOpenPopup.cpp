#include "Widgets/Popups/ImGuiToolkitOpenPopup.h"

void UImGuiToolkitOpenPopup::Open()
{
	bOpenRequested = true;
}

void UImGuiToolkitOpenPopup::Render()
{
	if (!bEnabled || !bOpenRequested)
		return;

	bOpenRequested = false;

	const FString PopupIDString = PopupID.ToString();
	if (PopupIDString.IsEmpty())
		return;

	ImGui::OpenPopup(TCHAR_TO_UTF8(*PopupIDString), FImGuiToolkitUtils::CombineImGuiPopupFlags(PopupFlags));
}
