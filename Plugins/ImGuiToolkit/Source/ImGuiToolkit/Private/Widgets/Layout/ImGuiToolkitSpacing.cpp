// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Layout/ImGuiToolkitSpacing.h"

void UImGuiToolkitSpacing::Render()
{
	if (!bEnabled)
		return;
	
	ImGui::Spacing();
}
