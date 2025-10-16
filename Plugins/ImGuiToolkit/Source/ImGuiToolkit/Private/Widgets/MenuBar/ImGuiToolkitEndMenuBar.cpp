// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/MenuBar/ImGuiToolkitEndMenuBar.h"

void UImGuiToolkitEndMenuBar::Render()
{
	if (!bEnabled)
		return;

	ImGui::EndMenuBar();
}
