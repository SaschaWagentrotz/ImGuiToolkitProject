// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Main/ImGuiToolkitCheckbox.h"

void UImGuiToolkitCheckbox::Render()
{
	if (!bEnabled)
	{
		if (bIsCurrentlyHovered)
		{
			bIsCurrentlyHovered = false;
			OnUnhovered.Broadcast(this, bIsChecked);
		}
		return;
	}
	
	if (ImGui::Checkbox(TCHAR_TO_UTF8(*UniqueWidgetLabel), &bIsChecked))
	{
		OnClicked.Broadcast(this, bIsChecked);
	}

	const bool bIsHovered = ImGui::IsItemHovered();
	if (bIsHovered)
	{
		if (!bIsCurrentlyHovered)
		{
			bIsCurrentlyHovered = true;
			OnHovered.Broadcast(this, bIsChecked);
		}
		if (!Tooltip.IsEmpty())
		{
			ImGui::SetTooltip("%s", TCHAR_TO_UTF8(*Tooltip.ToString()));
		}
	}
	else if (bIsCurrentlyHovered)
	{
		bIsCurrentlyHovered = false;
		OnUnhovered.Broadcast(this, bIsChecked);
	}
}
