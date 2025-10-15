// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Layout/ImGuiToolkitSameLine.h"

void UImGuiToolkitSameLine::Render()
{
	if (!bEnabled)
		return;
	
	ImGui::SameLine();
}
