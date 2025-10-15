// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Main/ImGuiToolkitProgressBar.h"

void UImGuiToolkitProgressBar::Render()
{
	if (!bEnabled)
		return;

	ImVec2 ProgressBarSize(Size.X, Size.Y);
	
	ImGui::ProgressBar(Percent, ProgressBarSize);
}
