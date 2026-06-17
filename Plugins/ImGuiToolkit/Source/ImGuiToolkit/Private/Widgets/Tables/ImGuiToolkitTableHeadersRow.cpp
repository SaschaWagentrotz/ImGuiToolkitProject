#include "Widgets/Tables/ImGuiToolkitTableHeadersRow.h"

void UImGuiToolkitTableHeadersRow::Render()
{
	if (!bEnabled)
	{
		return;
	}

	ImGui::TableHeadersRow();
}
