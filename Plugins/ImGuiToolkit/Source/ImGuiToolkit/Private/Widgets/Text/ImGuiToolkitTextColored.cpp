// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Text/ImGuiToolkitTextColored.h"

#include "FImGuiToolkitUtils.h"

void UImGuiToolkitTextColored::Render()
{
	if (!bEnabled)
		return;
	
	const ImVec4 ImGuiColor = FImGuiToolkitUtils::LinearColorToImVec4(Color);
	
	ImGui::TextColored(ImGuiColor, "%s", TCHAR_TO_UTF8(*Text.ToString()));
}
