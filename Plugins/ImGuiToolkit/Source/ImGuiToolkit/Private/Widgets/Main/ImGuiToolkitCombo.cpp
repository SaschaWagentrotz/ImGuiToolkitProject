// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Main/ImGuiToolkitCombo.h"

void UImGuiToolkitCombo::Render()
{
	if (!bEnabled)
		return;
	
	static int CurrentItem = 0;
	
	const char* ComboItemsSeparatedByZeros = ConvertFTextArrayToCharBuffer(ComboItems);

	int32 PreviousItem = CurrentItem;

	ImGui::Combo(TCHAR_TO_UTF8(*UniqueWidgetLabel), &CurrentItem, ComboItemsSeparatedByZeros);
	
	if (PreviousItem != CurrentItem)
		OnSelectionChanged.Broadcast(this, CurrentItem);

	SelectedIndex = CurrentItem;
}
