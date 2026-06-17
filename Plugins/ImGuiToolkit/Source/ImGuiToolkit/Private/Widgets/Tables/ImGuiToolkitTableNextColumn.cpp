#include "Widgets/Tables/ImGuiToolkitTableNextColumn.h"

void UImGuiToolkitTableNextColumn::Render()
{
	if (!bEnabled)
	{
		bShouldRenderContents = false;
		return;
	}

	bShouldRenderContents = ImGui::TableNextColumn();
	if (bShouldRenderContents)
	{
		RenderChildren();
	}
}
