// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/MenuBar/ImGuiToolkitEndMainMenuBar.h"

void UImGuiToolkitEndMainMenuBar::Render()
{
	if (!bEnabled)
		return;

	ImGui::EndMainMenuBar();
}
