// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Text/ImGuiToolkitSeparatorText.h"

void UImGuiToolkitSeparatorText::Render()
{
	if (!bEnabled)
		return;

	ImGui::SeparatorText(TCHAR_TO_UTF8(*Text.ToString()));
}
