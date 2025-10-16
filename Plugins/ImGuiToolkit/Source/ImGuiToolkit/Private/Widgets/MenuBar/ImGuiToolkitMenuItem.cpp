// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/MenuBar/ImGuiToolkitMenuItem.h"

void UImGuiToolkitMenuItem::Render()
{
	if (ImGui::MenuItem(
		TCHAR_TO_UTF8(*UniqueWidgetLabel),
		TCHAR_TO_UTF8(*Shortcut.ToString()),
			bIsSelected,
			bEnabled))
	{
		OnClicked.Broadcast(this);
	}
}
