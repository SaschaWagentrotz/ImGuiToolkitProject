// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Text/ImGuiToolkitTextDisabled.h"

void UImGuiToolkitTextDisabled::Render()
{
	if (!bEnabled)
		return;

	ImGui::TextDisabled("%s", TCHAR_TO_UTF8(*Text.ToString()));
}
