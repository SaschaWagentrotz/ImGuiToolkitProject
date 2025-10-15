// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Sliders/ImGuiToolkitDragFloat.h"

void UImGuiToolkitDragFloat::Render()
{
	if (!bEnabled)
		return;

	if (ImGui::DragFloat(TCHAR_TO_UTF8(*UniqueWidgetLabel), &Value, Speed, MinValue, MaxValue))
	{
		OnChanged.Broadcast(Value);
	}
}
