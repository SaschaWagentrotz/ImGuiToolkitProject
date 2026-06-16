#include "Widgets/Layout/ImGuiToolkitPushTextWrapPos.h"

void UImGuiToolkitPushTextWrapPos::Render()
{
	if (!bEnabled)
		return;

	ImGui::PushTextWrapPos(WrapLocalPosX);
}
