#include "Widgets/Layout/ImGuiToolkitPopItemWidth.h"

void UImGuiToolkitPopItemWidth::Render()
{
	if (!bEnabled)
		return;

	ImGui::PopItemWidth();
}
