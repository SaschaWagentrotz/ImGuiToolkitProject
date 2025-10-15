// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Main/ImGuiToolkitSmallButton.h"

void UImGuiToolkitSmallButton::Render()
{
	if (!bEnabled)
		return;
    
	if (ImGui::SmallButton(TCHAR_TO_UTF8(*UniqueWidgetLabel)))
	{
		OnClicked.Broadcast(this);
	}

	if (ImGui::IsItemHovered())
	{
		OnHovered.Broadcast(this);
		if (!Tooltip.IsEmpty())
		{
			ImGui::SetTooltip("%s", TCHAR_TO_UTF8(*Tooltip.ToString()));
		}
	}
}
