// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Tree/ImGuiToolkitTreePush.h"

void UImGuiToolkitTreePush::Render()
{
	if (!bEnabled)
		return;
	
	ImGui::TreePush(TCHAR_TO_UTF8(*Text.ToString()));
}
