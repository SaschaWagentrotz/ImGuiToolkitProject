#include "Widgets/Tooltips/ImGuiToolkitBeginTooltip.h"

void UImGuiToolkitBeginTooltip::Render()
{
	if (!bEnabled)
	{
		bIsOpen = false;
		return;
	}

	bIsOpen = ImGui::BeginTooltip();
	if (bIsOpen)
	{
		RenderChildren();
		ImGui::EndTooltip();
	}
}
