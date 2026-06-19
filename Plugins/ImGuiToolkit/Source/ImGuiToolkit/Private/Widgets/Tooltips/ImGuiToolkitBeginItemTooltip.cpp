#include "Widgets/Tooltips/ImGuiToolkitBeginItemTooltip.h"

void UImGuiToolkitBeginItemTooltip::Render()
{
	if (!bEnabled)
	{
		bIsOpen = false;
		return;
	}

	bIsOpen = ImGui::BeginItemTooltip();
	if (bIsOpen)
	{
		RenderChildren();
		ImGui::EndTooltip();
	}
}
