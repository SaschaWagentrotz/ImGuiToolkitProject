// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Main/ImGuiToolkitBullet.h"

void UImGuiToolkitBullet::Render()
{
	if (!bEnabled)
		return;

	ImGui::Bullet();
}
