// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Layout/ImGuiToolkitAlignTextToFramePadding.h"

void UImGuiToolkitAlignTextToFramePadding::Render()
{
	if (!bEnabled)
		return;
	
	ImGui::AlignTextToFramePadding();
}
