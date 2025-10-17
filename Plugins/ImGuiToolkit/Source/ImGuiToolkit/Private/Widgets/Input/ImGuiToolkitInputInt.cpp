// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Input/ImGuiToolkitInputInt.h"

void UImGuiToolkitInputInt::Render()
{
	if (!bEnabled)
		return;

	int32 PreviousInt = InputInt;

	ImGui::InputInt(TCHAR_TO_UTF8(*UniqueWidgetLabel), &InputInt);

	if (PreviousInt != InputInt)
	{
		OnIntChanged.Broadcast(InputInt);
	}
}

void UImGuiToolkitInputInt::SetPreviewInt(float PreviewInt)
{
	InputInt = PreviewInt;
}
