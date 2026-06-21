// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Main/ImGuiToolkitArrowButton.h"

UImGuiToolkitArrowButton::UImGuiToolkitArrowButton()
{
	CreateUniqueWidgetLabel(FText::FromString(TEXT("ArrowButton")));
}

void UImGuiToolkitArrowButton::Render()
{
	if (!bEnabled)
	{
		if (bIsCurrentlyHovered)
		{
			bIsCurrentlyHovered = false;
			OnUnhovered.Broadcast(this);
		}
		return;
	}
    
	if (ImGui::ArrowButton(TCHAR_TO_UTF8(*UniqueWidgetLabel), FImGuiToolkitUtils::UnrealDirToImGuiDir(CardinalDirection)))
	{
		OnClicked.Broadcast(this);
	}

	const bool bIsHovered = ImGui::IsItemHovered();
	if (bIsHovered)
	{
		if (!bIsCurrentlyHovered)
		{
			bIsCurrentlyHovered = true;
			OnHovered.Broadcast(this);
		}
		if (!Tooltip.IsEmpty())
		{
			ImGui::SetTooltip("%s", TCHAR_TO_UTF8(*Tooltip.ToString()));
		}
	}
	else if (bIsCurrentlyHovered)
	{
		bIsCurrentlyHovered = false;
		OnUnhovered.Broadcast(this);
	}
}
