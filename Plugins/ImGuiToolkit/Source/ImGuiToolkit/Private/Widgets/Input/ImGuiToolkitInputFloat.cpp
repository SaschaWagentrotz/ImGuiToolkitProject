// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Input/ImGuiToolkitInputFloat.h"

void UImGuiToolkitInputFloat::Render()
{
	if (!bEnabled)
		return;

	float PreviousFloat = InputFloat;

	ImGui::InputFloat(TCHAR_TO_UTF8(*UniqueWidgetLabel), &InputFloat, 0, 0, TCHAR_TO_UTF8(*FloatFormat));

	if (PreviousFloat != InputFloat)
	{
		OnFloatChanged.Broadcast(InputFloat);
	}
}

void UImGuiToolkitInputFloat::SetPreviewFloat(float PreviewFloat)
{
	InputFloat = PreviewFloat;
}

void UImGuiToolkitInputFloat::SetFormat(FString Format)
{
	FloatFormat = Format;
}
