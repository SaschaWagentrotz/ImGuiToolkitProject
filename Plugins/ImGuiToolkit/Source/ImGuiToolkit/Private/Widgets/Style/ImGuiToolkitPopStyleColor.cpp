#include "Widgets/Style/ImGuiToolkitPopStyleColor.h"

void UImGuiToolkitPopStyleColor::Render()
{
	if (!bEnabled)
		return;

	ImGui::PopStyleColor(Count);
}
