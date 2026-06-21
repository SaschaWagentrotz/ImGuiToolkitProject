#include "Widgets/TabBar/ImGuiToolkiBeginTabItem.h"

void UImGuiToolkiBeginTabItem::Render()
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

	const bool bWasSelected = bIsSelected;

	if (ImGui::BeginTabItem(TCHAR_TO_UTF8(*UniqueWidgetLabel)))
	{
		bIsSelected = true;

		RenderChildren();
		ImGui::EndTabItem();
	}
	else
	{
		bIsSelected = false;
	}

	if (bWasSelected != bIsSelected)
		OnSelectionChanged.Broadcast(this, bIsSelected);

	const bool bIsHovered = ImGui::IsItemHovered();
	if (bIsHovered)
	{
		if (!bIsCurrentlyHovered)
		{
			bIsCurrentlyHovered = true;
			OnHovered.Broadcast(this, bIsSelected);
		}
	}
	else if (bIsCurrentlyHovered)
	{
		bIsCurrentlyHovered = false;
		OnUnhovered.Broadcast(this, bIsSelected);
	}
}
