// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/TabBar/ImGuiToolkitEndTabItem.h"

void UImGuiToolkitEndTabItem::Render()
{
	if (!bEnabled)
		return;
	
	ImGui::EndTabItem();
}
