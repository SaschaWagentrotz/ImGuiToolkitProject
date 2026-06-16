#include "Containers/ImGuiToolkitCollapsingHeader.h"

void UImGuiToolkitCollapsingHeader::Render()
{
	if (!bEnabled)
		return;

	if (ImGui::CollapsingHeader(TCHAR_TO_UTF8(*UniqueWidgetLabel)))
	{
		RenderChildren();
	}
}
