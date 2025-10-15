// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Text/ImGuiToolkitText.h"

void UImGuiToolkitText::Render()
{
	if (!bEnabled)
		return;

	ImGui::Text("%s", TCHAR_TO_UTF8(*Text.ToString()));
}
