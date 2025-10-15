// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Main/ImGuiToolkitButton.h"

void UImGuiToolkitButton::Render()
{
	if (!bEnabled)
		return;

	ImVec2 ButtonSize(Size.X, Size.Y);
    
	if (ImGui::Button(TCHAR_TO_UTF8(*UniqueWidgetLabel), ButtonSize))
	{
		OnClicked.Broadcast(this);
	}

	if (ImGui::IsItemHovered())
	{
		OnHovered.Broadcast(this);
		if (!Tooltip.IsEmpty())
		{
			ImGui::SetTooltip("%s", TCHAR_TO_UTF8(*Tooltip.ToString()));
		}
	}
}
