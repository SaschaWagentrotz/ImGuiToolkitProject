#include "Widgets/Style/ImGuiToolkitEndDisabled.h"

void UImGuiToolkitEndDisabled::Render()
{
	if (!bEnabled)
		return;

	ImGui::EndDisabled();
}
