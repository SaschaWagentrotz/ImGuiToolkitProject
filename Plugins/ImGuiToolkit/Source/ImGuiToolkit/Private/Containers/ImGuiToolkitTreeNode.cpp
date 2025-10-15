// Fill out your copyright notice in the Description page of Project Settings.


#include "Containers/ImGuiToolkitTreeNode.h"

void UImGuiToolkitTreeNode::Render()
{
	if (ImGui::TreeNode(TCHAR_TO_UTF8(*UniqueWidgetLabel)))
	{
		for (UImGuiToolkitWidget* Widget : Widgets)
		{
			if (Widget)
			{
				Widget->Render();
			}
		}
	}
}
