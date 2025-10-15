// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/TabBar/ImGuiToolkiBeginTabItem.h"

void UImGuiToolkiBeginTabItem::Render()
{
	bool bPreviousIselected = bIsSelected;

	if (ImGui::BeginTabItem(TCHAR_TO_UTF8(*UniqueWidgetLabel)))
	{
		bIsSelected = true;
		
		for (UImGuiToolkitWidget* Widget : Widgets)
		{
			if (Widget)
			{
				Widget->Render();
			}
		}
	}
	else
	{
		bIsSelected = false;
	}

	if (bPreviousIselected != bIsSelected)
		OnSelectionChanged.Broadcast(this, bIsSelected);

	if (ImGui::IsItemHovered())
		OnHovered.Broadcast(this, bIsSelected);
}
