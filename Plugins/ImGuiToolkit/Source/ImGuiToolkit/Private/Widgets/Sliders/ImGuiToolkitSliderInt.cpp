// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Sliders/ImGuiToolkitSliderInt.h"

void UImGuiToolkitSliderInt::Render()
{
	if (!bEnabled)
		return;

	if (ImGui::SliderInt(TCHAR_TO_UTF8(*UniqueWidgetLabel), &Value, MinValue, MaxValue, TCHAR_TO_UTF8(*Format.ToString())))
	{
		OnChanged.Broadcast(Value);
	}
}
