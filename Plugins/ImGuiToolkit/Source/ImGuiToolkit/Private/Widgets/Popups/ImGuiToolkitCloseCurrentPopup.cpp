#include "Widgets/Popups/ImGuiToolkitCloseCurrentPopup.h"

#include "Widgets/Popups/ImGuiToolkitPopupHelpers.h"

void UImGuiToolkitCloseCurrentPopup::Close()
{
	bCloseRequested = true;
}

void UImGuiToolkitCloseCurrentPopup::Render()
{
	if (!bEnabled)
		return;

	const bool bShouldClose = bCloseRequested || (bCloseWhenPreviousItemClicked && ImGui::IsItemClicked(ImGuiMouseButton_Left));
	bCloseRequested = false;

	if (bShouldClose)
	{
		ImGui::CloseCurrentPopup();
		ImGuiToolkitPopupHelpers::NotifyPopupClosed();
	}
}
