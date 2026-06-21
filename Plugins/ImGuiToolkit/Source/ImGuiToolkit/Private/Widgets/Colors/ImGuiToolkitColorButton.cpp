#include "Widgets/Colors/ImGuiToolkitColorButton.h"

void UImGuiToolkitColorButton::Render()
{
	if (!bEnabled)
	{
		if (bIsCurrentlyHovered)
		{
			bIsCurrentlyHovered = false;
			OnUnhovered.Broadcast(this, Color);
		}
		return;
	}

	ImGuiColorEditFlags CombinedFlags = FImGuiToolkitUtils::CombineImGuiColorEditFlags(ColorEditFlags);
	CombinedFlags = (CombinedFlags & ~ImGuiColorEditFlags_InputMask_) | ImGuiColorEditFlags_InputRGB;
	const ImVec4 ImGuiColor = FImGuiToolkitUtils::LinearColorToImVec4(Color);
	const ImVec2 ButtonSize(Size.X, Size.Y);

	if (ImGui::ColorButton(TCHAR_TO_UTF8(*UniqueWidgetLabel), ImGuiColor, CombinedFlags, ButtonSize))
	{
		OnClicked.Broadcast(this, Color);
	}

	const bool bIsHovered = ImGui::IsItemHovered();
	if (bIsHovered)
	{
		if (!bIsCurrentlyHovered)
		{
			bIsCurrentlyHovered = true;
			OnHovered.Broadcast(this, Color);
		}
	}
	else if (bIsCurrentlyHovered)
	{
		bIsCurrentlyHovered = false;
		OnUnhovered.Broadcast(this, Color);
	}
}
