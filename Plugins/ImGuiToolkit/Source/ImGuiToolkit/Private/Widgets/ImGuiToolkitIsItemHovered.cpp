// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/ImGuiToolkitIsItemHovered.h"

void UImGuiToolkitIsItemHovered::Render()
{
	if (!bEnabled)
		return;

	if (ImGui::IsItemHovered())
	{
		OnHovered.Broadcast(this);
	}
}
