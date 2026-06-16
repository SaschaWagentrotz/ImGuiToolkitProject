#include "Containers/ImGuiToolkitWindow.h"

UImGuiToolkitWindow::UImGuiToolkitWindow()
{
}

const FString& UImGuiToolkitWindow::GetImGuiWindowName() const
{
	return UniqueWidgetLabel;
}

void UImGuiToolkitWindow::Render()
{
	if (!bIsOpen)
		return;

	if (!bSuppressNextWindowPlacement && bIsHosted)
	{
		ImGui::SetNextWindowSize(ImVec2(HostSize.X, HostSize.Y), true);
		ImGui::SetNextWindowPos(ImVec2(HostPosition.X, HostPosition.Y), true);
	}
	else if (!bSuppressNextWindowPlacement)
	{
		ImGui::SetNextWindowSize(ImVec2(InitialSize.X, InitialSize.Y), ImGuiCond_FirstUseEver);
		ImGui::SetNextWindowPos(ImVec2(InitialPosition.X, InitialPosition.Y), ImGuiCond_FirstUseEver);
	}

	int ImGuiWindowFlags = FImGuiToolkitUtils::CombineImGuiWindowFlags(WindowFlags);
	bool* OpenPtr = bIsHosted ? nullptr : &bIsOpen;
	
	if (ImGui::Begin(TCHAR_TO_UTF8(*UniqueWidgetLabel), OpenPtr, ImGuiWindowFlags))
	{
		for (UImGuiToolkitWidget* Widget : Widgets)
		{
			if (Widget)
			{
				Widget->Render();
			}
		}
	}
	ImGui::End();
}

void UImGuiToolkitWindow::RenderWithHostDockingPlacement()
{
	const bool bWasSuppressingPlacement = bSuppressNextWindowPlacement;
	bSuppressNextWindowPlacement = true;
	Render();
	bSuppressNextWindowPlacement = bWasSuppressingPlacement;
}
