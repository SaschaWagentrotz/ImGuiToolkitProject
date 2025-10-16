// Fill out your copyright notice in the Description page of Project Settings.


#include "Containers/ImGuiToolkitBeginMenu.h"

#include "Serialization/ShaderKeyGenerator.h"

void UImGuiToolkitBeginMenu::Render()
{
	if (!bEnabled)
		return;

	if (ImGui::BeginMenu(TCHAR_TO_UTF8(*UniqueWidgetLabel)))
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
