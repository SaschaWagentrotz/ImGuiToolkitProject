// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/DragSliders/ImGuiToolkitDragInt.h"

void UImGuiToolkitDragInt::Render()
{
	if (!bEnabled)
		return;
	
	ImGui::DragInt(TCHAR_TO_UTF8(*UniqueWidgetLabel), &Value, Speed, MinValue, MaxValue);
}
