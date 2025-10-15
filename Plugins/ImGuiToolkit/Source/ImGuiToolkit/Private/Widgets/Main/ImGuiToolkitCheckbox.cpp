// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Main/ImGuiToolkitCheckbox.h"

void UImGuiToolkitCheckbox::Render()
{
	if (!bEnabled)
		return;
	
	if (ImGui::Checkbox(TCHAR_TO_UTF8(*UniqueWidgetLabel), &bIsChecked))
	{
		OnClicked.Broadcast(this, bIsChecked);
	}

	if (ImGui::IsItemHovered())
	{
		OnHovered.Broadcast(this, bIsChecked);
		if (!Tooltip.IsEmpty())
		{
			ImGui::SetTooltip("%s", TCHAR_TO_UTF8(*Tooltip.ToString()));
		}
	}
}
