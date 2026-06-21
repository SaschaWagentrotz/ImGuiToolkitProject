// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Main/ImGuiToolkitButton.h"

#include <cfloat>

void UImGuiToolkitButton::Render()
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

	const bool bUseDefaultFillSize = FMath::IsNearlyZero(Size.X) && FMath::IsNearlyZero(Size.Y);
	const ImVec2 ButtonSize = bUseDefaultFillSize
		? ImVec2(-FLT_MIN, 0.0f)
		: ImVec2(Size.X, Size.Y);
    
	if (ImGui::Button(TCHAR_TO_UTF8(*UniqueWidgetLabel), ButtonSize))
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
