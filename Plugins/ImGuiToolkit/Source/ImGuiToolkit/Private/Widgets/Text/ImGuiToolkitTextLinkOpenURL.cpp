// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Text/ImGuiToolkitTextLinkOpenURL.h"

void UImGuiToolkitTextLinkOpenURL::Render()
{
	if (!bEnabled)
		return;

	ImGui::TextLinkOpenURL(TCHAR_TO_UTF8(*Text.ToString()), TCHAR_TO_UTF8(*URL));
}
