#include "Widgets/Main/ImGuiToolkitSelectable.h"

void UImGuiToolkitSelectable::Render()
{
	if (!bEnabled)
		return;

	const ImGuiSelectableFlags CombinedFlags = FImGuiToolkitUtils::CombineImGuiSelectableFlags(SelectableFlags);
	const ImVec2 SelectableSize(Size.X, Size.Y);

	if (ImGui::Selectable(TCHAR_TO_UTF8(*UniqueWidgetLabel), &bIsSelected, CombinedFlags, SelectableSize))
	{
		OnClicked.Broadcast(this, bIsSelected);
	}

	if (ImGui::IsItemHovered())
	{
		OnHovered.Broadcast(this, bIsSelected);
		if (!Tooltip.IsEmpty())
		{
			ImGui::SetTooltip("%s", TCHAR_TO_UTF8(*Tooltip.ToString()));
		}
	}
}
