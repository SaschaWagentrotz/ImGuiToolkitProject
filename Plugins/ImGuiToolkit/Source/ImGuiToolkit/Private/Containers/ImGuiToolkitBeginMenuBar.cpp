#include "Containers/ImGuiToolkitBeginMenuBar.h"

void UImGuiToolkitBeginMenuBar::Render()
{
	if (!bEnabled)
		return;

	if (ImGui::BeginMenuBar())
	{
		RenderChildren();
		ImGui::EndMenuBar();
	}
}
