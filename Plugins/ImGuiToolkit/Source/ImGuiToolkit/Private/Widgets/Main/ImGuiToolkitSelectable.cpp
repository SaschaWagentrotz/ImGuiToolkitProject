#include "Widgets/Main/ImGuiToolkitSelectable.h"

void UImGuiToolkitSelectable::Render()
{
	if (!bEnabled)
	{
		if (bIsCurrentlyHovered)
		{
			bIsCurrentlyHovered = false;
			OnUnhovered.Broadcast(this, bIsSelected);
		}
		return;
	}

	const ImGuiSelectableFlags CombinedFlags = FImGuiToolkitUtils::CombineImGuiSelectableFlags(SelectableFlags);
	const ImVec2 SelectableSize(Size.X, Size.Y);

	if (ImGui::Selectable(TCHAR_TO_UTF8(*UniqueWidgetLabel), &bIsSelected, CombinedFlags, SelectableSize))
	{
		OnClicked.Broadcast(this, bIsSelected);
	}

	const bool bIsHovered = ImGui::IsItemHovered();
	if (bIsHovered)
	{
		if (!bIsCurrentlyHovered)
		{
			bIsCurrentlyHovered = true;
			OnHovered.Broadcast(this, bIsSelected);
		}
		if (!Tooltip.IsEmpty())
		{
			ImGui::SetTooltip("%s", TCHAR_TO_UTF8(*Tooltip.ToString()));
		}
	}
	else if (bIsCurrentlyHovered)
	{
		bIsCurrentlyHovered = false;
		OnUnhovered.Broadcast(this, bIsSelected);
	}
}
