// Fill out your copyright notice in the Description page of Project Settings.

#include "ImGuiToolkitContainer.h"

UImGuiToolkitContainer::UImGuiToolkitContainer()
{
}

void UImGuiToolkitContainer::AddWidget(UImGuiToolkitWidget* Widget)
{
	if (Widget)
	{
		Widgets.Add(Widget);
	}
}

void UImGuiToolkitContainer::RemoveWidget(UImGuiToolkitWidget* Widget)
{
	if (Widget)
	{
		Widgets.Remove(Widget);
	}
}

void UImGuiToolkitContainer::ClearWidgets()
{
	Widgets.Empty();
}

TArray<UImGuiToolkitWidget*> UImGuiToolkitContainer::GetWidgets()
{
	return Widgets;
}

void UImGuiToolkitContainer::RenderChildren()
{
	for (UImGuiToolkitWidget* Widget : Widgets)
	{
		if (Widget && Widget->bEnabled)
		{
			Widget->Render();
		}
	}
}
