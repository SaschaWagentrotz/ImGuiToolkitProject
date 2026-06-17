#include "Widgets/Tables/ImGuiToolkitTableNextRow.h"

void UImGuiToolkitTableNextRow::Render()
{
	if (!bEnabled)
	{
		return;
	}

	const ImGuiTableRowFlags CombinedFlags = FImGuiToolkitUtils::CombineImGuiTableRowFlags(RowFlags);
	ImGui::TableNextRow(CombinedFlags, MinimumRowHeight);
	RenderChildren();
}
