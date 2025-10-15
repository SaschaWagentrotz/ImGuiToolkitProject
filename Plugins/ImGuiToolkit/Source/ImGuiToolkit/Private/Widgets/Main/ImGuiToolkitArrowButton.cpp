// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Main/ImGuiToolkitArrowButton.h"

void UImGuiToolkitArrowButton::Render()
{
	if (!bEnabled)
		return;
    
	if (ImGui::ArrowButton(TCHAR_TO_UTF8(*UniqueWidgetLabel), FImGuiToolkitUtils::UnrealDirToImGuiDir(CardinalDirection)))
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
