// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Text/ImGuiToolkitLabelText.h"

void UImGuiToolkitLabelText::Render()
{
	if (!bEnabled)
		return;
	
	ImGui::LabelText(TCHAR_TO_UTF8(*Label.ToString()), "%s", TCHAR_TO_UTF8(*Value.ToString()));
}
