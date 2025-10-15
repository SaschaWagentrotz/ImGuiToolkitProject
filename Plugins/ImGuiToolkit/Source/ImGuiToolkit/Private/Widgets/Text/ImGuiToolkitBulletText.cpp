// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Text/ImGuiToolkitBulletText.h"

void UImGuiToolkitBulletText::Render()
{
	if (!bEnabled)
		return;

	ImGui::BulletText("%s", TCHAR_TO_UTF8(*Text.ToString()));
}
