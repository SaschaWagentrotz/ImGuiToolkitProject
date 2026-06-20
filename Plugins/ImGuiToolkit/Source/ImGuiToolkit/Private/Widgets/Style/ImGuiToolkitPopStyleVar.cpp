#include "Widgets/Style/ImGuiToolkitPopStyleVar.h"

void UImGuiToolkitPopStyleVar::Render()
{
	if (!bEnabled)
		return;

	ImGui::PopStyleVar(Count);
}
