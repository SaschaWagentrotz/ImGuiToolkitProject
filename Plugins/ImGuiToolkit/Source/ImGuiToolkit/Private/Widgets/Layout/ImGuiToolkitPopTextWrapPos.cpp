#include "Widgets/Layout/ImGuiToolkitPopTextWrapPos.h"

void UImGuiToolkitPopTextWrapPos::Render()
{
	if (!bEnabled)
		return;

	ImGui::PopTextWrapPos();
}
