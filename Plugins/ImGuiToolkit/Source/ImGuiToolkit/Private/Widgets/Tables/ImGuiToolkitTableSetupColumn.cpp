#include "Widgets/Tables/ImGuiToolkitTableSetupColumn.h"

void UImGuiToolkitTableSetupColumn::Render()
{
	if (!bEnabled)
	{
		return;
	}

	const FString LabelString = Label.ToString();
	const ImGuiTableColumnFlags CombinedFlags = FImGuiToolkitUtils::CombineImGuiTableColumnFlags(ColumnFlags);
	ImGui::TableSetupColumn(TCHAR_TO_UTF8(*LabelString), CombinedFlags, InitialWidthOrWeight, static_cast<ImGuiID>(UserID));
}
