#include "Widgets/TabBar/ImGuiToolkiBeginTabItem.h"

void UImGuiToolkiBeginTabItem::Render()
{
	if (!bEnabled)
		return;

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

	if (ImGui::IsItemHovered())
		OnHovered.Broadcast(this, bIsSelected);
}
