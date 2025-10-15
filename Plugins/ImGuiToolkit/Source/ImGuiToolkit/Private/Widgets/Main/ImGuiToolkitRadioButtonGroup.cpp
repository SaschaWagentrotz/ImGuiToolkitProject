// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Main/ImGuiToolkitRadioButtonGroup.h"
#include "FImGuiToolkitUtils.h"

void UImGuiToolkitRadioButtonGroup::Render()
{
	if (!bEnabled)
		return;

	for (int32 i = 0; i < RadioItems.Num(); ++i)
	{
		ImGui::PushID(i);

		const FString RadioButtonItemString = RadioItems[i].ToString();
		
		ImGui::RadioButton(TCHAR_TO_UTF8(*RadioButtonItemString), &SelectedIndex, i);
		
		ImGui::PopID();

		if (Direction == Horizontal)
		{
			if (i + 1 < RadioItems.Num())
				ImGui::SameLine();
		}
	}

	if (SelectedIndex != PreviouslySelectedIndex)
	{
		OnClicked.Broadcast(this, SelectedIndex);
		PreviouslySelectedIndex = SelectedIndex;
	}
}
