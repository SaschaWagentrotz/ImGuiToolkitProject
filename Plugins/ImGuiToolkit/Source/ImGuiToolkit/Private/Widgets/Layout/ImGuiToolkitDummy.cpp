// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Layout/ImGuiToolkitDummy.h"

void UImGuiToolkitDummy::Render()
{
	if (!bEnabled)
		return;

	ImVec2 ImGuiSize = ImVec2(Size.X, Size.Y);
	ImGui::Dummy(ImGuiSize);
}
