#include "Containers/ImGuiToolkitBeginGroup.h"

void UImGuiToolkitBeginGroup::Render()
{
	if (!bEnabled)
	{
		return;
	}

	ImGui::BeginGroup();
	RenderChildren();
	ImGui::EndGroup();
}
