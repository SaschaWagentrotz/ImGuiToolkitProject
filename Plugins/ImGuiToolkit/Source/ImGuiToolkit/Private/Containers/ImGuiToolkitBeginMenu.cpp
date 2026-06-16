#include "Containers/ImGuiToolkitBeginMenu.h"

void UImGuiToolkitBeginMenu::Render()
{
	if (!bEnabled)
		return;

	if (ImGui::BeginMenu(TCHAR_TO_UTF8(*UniqueWidgetLabel)))
	{
		RenderChildren();
		ImGui::EndMenu();
	}
}
