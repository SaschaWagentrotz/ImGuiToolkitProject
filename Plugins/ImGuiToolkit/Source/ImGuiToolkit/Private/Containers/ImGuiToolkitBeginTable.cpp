#include "Containers/ImGuiToolkitBeginTable.h"

void UImGuiToolkitBeginTable::Render()
{
	if (!bEnabled)
	{
		bIsOpen = false;
		return;
	}

	const ImGuiTableFlags CombinedFlags = FImGuiToolkitUtils::CombineImGuiTableFlags(TableFlags);
	const ImVec2 TableOuterSize(OuterSize.X, OuterSize.Y);
	const int32 SafeColumnCount = FMath::Max(1, ColumnCount);

	bIsOpen = ImGui::BeginTable(TCHAR_TO_UTF8(*UniqueWidgetLabel), SafeColumnCount, CombinedFlags, TableOuterSize, InnerWidth);
	if (bIsOpen)
	{
		RenderChildren();
		ImGui::EndTable();
	}
}
