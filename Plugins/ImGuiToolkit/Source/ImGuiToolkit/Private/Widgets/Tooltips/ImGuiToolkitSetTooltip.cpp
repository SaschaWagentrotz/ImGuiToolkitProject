#include "Widgets/Tooltips/ImGuiToolkitSetTooltip.h"

void UImGuiToolkitSetTooltip::Render()
{
	if (!bEnabled)
		return;

	ImGui::SetTooltip("%s", TCHAR_TO_UTF8(*Text.ToString()));
}
