#include "Widgets/Colors/ImGuiToolkitSetColorEditOptions.h"

#include "Widgets/Colors/ImGuiToolkitColorHelpers.h"

void UImGuiToolkitSetColorEditOptions::Render()
{
	if (!bEnabled)
		return;

	ImGui::SetColorEditOptions(ImGuiToolkitColorHelpers::GetColorEditFlags(ColorEditFlags));
}
