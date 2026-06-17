#include "Widgets/Tables/ImGuiToolkitTableSetColumnIndex.h"

void UImGuiToolkitTableSetColumnIndex::Render()
{
	if (!bEnabled)
	{
		bShouldRenderContents = false;
		return;
	}

	bShouldRenderContents = ImGui::TableSetColumnIndex(FMath::Max(0, ColumnIndex));
	if (bShouldRenderContents)
	{
		RenderChildren();
	}
}
