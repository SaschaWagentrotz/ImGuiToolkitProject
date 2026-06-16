#include "Containers/ImGuiToolkitBeginListBox.h"

void UImGuiToolkitBeginListBox::Render()
{
	if (!bEnabled)
	{
		return;
	}

	const ImVec2 ListBoxSize(Size.X, Size.Y);
	if (ImGui::BeginListBox(TCHAR_TO_UTF8(*UniqueWidgetLabel), ListBoxSize))
	{
		RenderChildren();
		ImGui::EndListBox();
	}
}
