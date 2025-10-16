// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/MenuBar/ImGuiToolkitEndMenu.h"

void UImGuiToolkitEndMenu::Render()
{
	if (!bEnabled)
		return;

	ImGui::EndMenu();
}
