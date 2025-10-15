// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Layout/ImGuiToolkitNewLine.h"

void UImGuiToolkitNewLine::Render()
{
	if (!bEnabled)
		return;

	ImGui::NewLine();
}
