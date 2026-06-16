#include "Containers/ImGuiToolkitBeginTabBar.h"

void UImGuiToolkitBeginTabBar::Render()
{
	if (!bEnabled)
		return;

	if (ImGui::BeginTabBar(TCHAR_TO_UTF8(*UniqueWidgetLabel)))
	{
		RenderChildren();
		ImGui::EndTabBar();
	}
}
