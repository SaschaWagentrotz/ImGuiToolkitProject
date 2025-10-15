// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Main/ImGuiToolkitSetItemTooltip.h"

void UImGuiToolkitSetItemTooltip::Render()
{
	if (!bEnabled)
		return;

	ImGui::SetItemTooltip("%s", TCHAR_TO_UTF8(*Text.ToString()));
}
