#include "Widgets/Layout/ImGuiToolkitSetNextItemWidth.h"

void UImGuiToolkitSetNextItemWidth::Render()
{
	if (!bEnabled)
		return;

	ImGui::SetNextItemWidth(ItemWidth);
}
