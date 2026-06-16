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
	const TArray<UImGuiToolkitWidget*> WidgetsToRender = Widgets;
	for (UImGuiToolkitWidget* Widget : WidgetsToRender)
	{
		if (IsValid(Widget) && Widgets.Contains(Widget) && Widget->bEnabled)
		{
			Widget->Render();
		}
	}
}
