// Fill out your copyright notice in the Description page of Project Settings.


#include "Containers/ImGuiToolkitCollapsingHeader.h"

void UImGuiToolkitCollapsingHeader::Render()
{
	if (ImGui::CollapsingHeader(TCHAR_TO_UTF8(*UniqueWidgetLabel)))
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
