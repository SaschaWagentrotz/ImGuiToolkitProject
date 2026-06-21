// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/ImGuiToolkitIsItemHovered.h"

void UImGuiToolkitIsItemHovered::Render()
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

	const bool bIsHovered = ImGui::IsItemHovered();
	if (bIsHovered)
	{
		if (!bIsCurrentlyHovered)
		{
			bIsCurrentlyHovered = true;
			OnHovered.Broadcast(this);
		}
	}
	else if (bIsCurrentlyHovered)
	{
		bIsCurrentlyHovered = false;
		OnUnhovered.Broadcast(this);
	}
}
