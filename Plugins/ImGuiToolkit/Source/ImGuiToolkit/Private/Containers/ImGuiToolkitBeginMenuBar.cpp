// Fill out your copyright notice in the Description page of Project Settings.


#include "Containers/ImGuiToolkitBeginMenuBar.h"

void UImGuiToolkitBeginMenuBar::Render()
{
	if (!bEnabled)
		return;

	if (ImGui::BeginMenuBar())
	{
		for (UImGuiToolkitWidget* Widget : Widgets)
		{
			if (Widget)
			{
				Widget->Render();
			}
		}
	}
}
