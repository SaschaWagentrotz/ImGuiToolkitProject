// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Layout/ImGuiToolkitIndent.h"

void UImGuiToolkitIndent::Render()
{
	if (!bEnabled)
		return;
	
	ImGui::Indent();
}
