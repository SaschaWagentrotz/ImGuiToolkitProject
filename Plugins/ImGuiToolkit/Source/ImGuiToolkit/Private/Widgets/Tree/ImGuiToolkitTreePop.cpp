// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Tree/ImGuiToolkitTreePop.h"

void UImGuiToolkitTreePop::Render()
{
	if (!bEnabled)
		return;
	
	ImGui::TreePop();
}
