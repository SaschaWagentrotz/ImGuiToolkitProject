// Fill out your copyright notice in the Description page of Project Settings.


#include "Containers/ImGuiToolkitWindow.h"

UImGuiToolkitWindow::UImGuiToolkitWindow()
{
}

void UImGuiToolkitWindow::Render()
{
	if (!bIsOpen)
		return;

	if (bIsHosted)
	{
		ImGui::SetNextWindowSize(ImVec2(HostSize.X, HostSize.Y), true);
		ImGui::SetNextWindowPos(ImVec2(HostPosition.X, HostPosition.Y), true);
	}
	else
	{
		ImGui::SetNextWindowSize(ImVec2(InitialSize.X, InitialSize.Y), ImGuiCond_FirstUseEver);
		ImGui::SetNextWindowPos(ImVec2(InitialPosition.X, InitialPosition.Y), ImGuiCond_FirstUseEver);
	}

	int ImGuiWindowFlags = FImGuiToolkitUtils::CombineImGuiWindowFlags(WindowFlags);
	
	if (ImGui::Begin(TCHAR_TO_UTF8(*UniqueWidgetLabel), &bIsOpen, ImGuiWindowFlags))
	{
		for (UImGuiToolkitWidget* Widget : Widgets)
		{
			if (Widget)
			{
				Widget->Render();
			}
		}
	}
	ImGui::End();
}