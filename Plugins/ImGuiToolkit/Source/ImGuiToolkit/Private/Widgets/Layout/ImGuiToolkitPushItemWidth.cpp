#include "Widgets/Layout/ImGuiToolkitPushItemWidth.h"

void UImGuiToolkitPushItemWidth::Render()
{
	if (!bEnabled)
		return;

	ImGui::PushItemWidth(ItemWidth);
}
