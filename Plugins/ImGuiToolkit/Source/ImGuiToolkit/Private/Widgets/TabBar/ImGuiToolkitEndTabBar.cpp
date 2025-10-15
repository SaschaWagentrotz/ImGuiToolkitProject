// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/TabBar/ImGuiToolkitEndTabBar.h"

void UImGuiToolkitEndTabBar::Render()
{
	if (!bEnabled)
		return;
	
	ImGui::EndTabBar();
}
