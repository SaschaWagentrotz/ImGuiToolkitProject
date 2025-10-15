// Fill out your copyright notice in the Description page of Project Settings.


#include "Containers/ImGuiToolkitBeginTabBar.h"

void UImGuiToolkitBeginTabBar::Render()
{
	if (ImGui::BeginTabBar(TCHAR_TO_UTF8(*UniqueWidgetLabel)))
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
