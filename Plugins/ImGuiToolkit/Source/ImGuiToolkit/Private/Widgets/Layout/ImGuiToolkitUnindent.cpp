// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Layout/ImGuiToolkitUnindent.h"

void UImGuiToolkitUnindent::Render()
{
	if (!bEnabled)
		return;
	
	ImGui::Unindent();
}
