// Fill out your copyright notice in the Description page of Project Settings.


#include "Containers/ImGuiToolkitBeginMainMenuBar.h"

void UImGuiToolkitBeginMainMenuBar::Render()
{
	if (!bEnabled)
		return;
	
	if (ImGui::BeginMainMenuBar())
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
