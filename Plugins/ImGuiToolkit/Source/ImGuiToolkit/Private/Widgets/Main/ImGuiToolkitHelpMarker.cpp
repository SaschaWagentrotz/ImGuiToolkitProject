// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Main/ImGuiToolkitHelpMarker.h"

void UImGuiToolkitHelpMarker::Render()
{
	if (!bEnabled)
		return;

	ImGui::TextDisabled("(?)");
	if (ImGui::BeginItemTooltip())
	{
		ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
		ImGui::TextUnformatted(TCHAR_TO_UTF8(*Text.ToString()));
		ImGui::PopTextWrapPos();
		ImGui::EndTooltip();
	}
}
