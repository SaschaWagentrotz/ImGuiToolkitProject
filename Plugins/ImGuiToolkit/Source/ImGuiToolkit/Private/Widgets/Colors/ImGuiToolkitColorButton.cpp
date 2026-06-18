#include "Widgets/Colors/ImGuiToolkitColorButton.h"

void UImGuiToolkitColorButton::Render()
{
	if (!bEnabled)
		return;

	ImGuiColorEditFlags CombinedFlags = FImGuiToolkitUtils::CombineImGuiColorEditFlags(ColorEditFlags);
	CombinedFlags = (CombinedFlags & ~ImGuiColorEditFlags_InputMask_) | ImGuiColorEditFlags_InputRGB;
	const ImVec4 ImGuiColor = FImGuiToolkitUtils::LinearColorToImVec4(Color);
	const ImVec2 ButtonSize(Size.X, Size.Y);

	if (ImGui::ColorButton(TCHAR_TO_UTF8(*UniqueWidgetLabel), ImGuiColor, CombinedFlags, ButtonSize))
	{
		OnClicked.Broadcast(this, Color);
	}

	if (ImGui::IsItemHovered())
	{
		OnHovered.Broadcast(this, Color);
	}
}
