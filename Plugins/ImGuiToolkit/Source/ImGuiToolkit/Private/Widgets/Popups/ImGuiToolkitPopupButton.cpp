#include "Widgets/Popups/ImGuiToolkitPopupButton.h"

#include "Widgets/Popups/ImGuiToolkitPopupHelpers.h"

#include <cfloat>

void UImGuiToolkitPopupButton::Open()
{
	bOpenRequested = true;
	bCloseRequested = false;
}

void UImGuiToolkitPopupButton::Close()
{
	bCloseRequested = true;
}

void UImGuiToolkitPopupButton::Render()
{
	if (!bEnabled)
	{
		if (bIsOpen)
		{
			bIsOpen = false;
			OnClosed.Broadcast(this);
		}
		return;
	}

	const bool bUseDefaultFillSize = FMath::IsNearlyZero(Size.X) && FMath::IsNearlyZero(Size.Y);
	const ImVec2 ButtonSize = bUseDefaultFillSize
		? ImVec2(-FLT_MIN, 0.0f)
		: ImVec2(Size.X, Size.Y);

	if (ImGui::Button(TCHAR_TO_UTF8(*UniqueWidgetLabel), ButtonSize))
	{
		OnClicked.Broadcast(this);
		Open();
	}

	if (ImGui::IsItemHovered())
	{
		OnHovered.Broadcast(this);
		if (!Tooltip.IsEmpty())
		{
			ImGui::SetTooltip("%s", TCHAR_TO_UTF8(*Tooltip.ToString()));
		}
	}

	if (bOpenRequested)
	{
		bOpenRequested = false;
		ImGui::OpenPopup(TCHAR_TO_UTF8(*UniqueWidgetLabel), FImGuiToolkitUtils::CombineImGuiPopupFlags(PopupFlags));
	}

	const bool bWasOpen = bIsOpen;
	bool bPopupVisible = ImGui::BeginPopup(TCHAR_TO_UTF8(*UniqueWidgetLabel), FImGuiToolkitUtils::CombineImGuiWindowFlags(WindowFlags));
	if (bPopupVisible)
	{
		if (!bWasOpen)
		{
			OnOpened.Broadcast(this);
		}

		RenderChildren();

		if (bCloseRequested)
		{
			ImGui::CloseCurrentPopup();
			ImGuiToolkitPopupHelpers::NotifyPopupClosed();
			bPopupVisible = false;
			OnClosed.Broadcast(this);
		}

		ImGui::EndPopup();
	}
	else if (bWasOpen)
	{
		OnClosed.Broadcast(this);
	}

	bCloseRequested = false;
	bIsOpen = bPopupVisible;
}
