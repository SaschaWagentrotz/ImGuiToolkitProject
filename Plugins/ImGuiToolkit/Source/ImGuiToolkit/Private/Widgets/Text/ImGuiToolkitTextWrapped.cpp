// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Text/ImGuiToolkitTextWrapped.h"

void UImGuiToolkitTextWrapped::Render()
{
	if (!bEnabled)
		return;

	ImGui::TextWrapped("%s", TCHAR_TO_UTF8(*Text.ToString()));
}
