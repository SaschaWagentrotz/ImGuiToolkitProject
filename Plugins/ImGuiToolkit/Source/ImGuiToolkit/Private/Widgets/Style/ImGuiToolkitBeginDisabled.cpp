#include "Widgets/Style/ImGuiToolkitBeginDisabled.h"

void UImGuiToolkitBeginDisabled::Render()
{
	if (!bEnabled)
		return;

	ImGui::BeginDisabled(bDisabled);
}
