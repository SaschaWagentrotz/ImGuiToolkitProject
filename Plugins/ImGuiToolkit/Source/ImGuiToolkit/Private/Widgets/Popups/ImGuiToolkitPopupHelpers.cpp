#include "Widgets/Popups/ImGuiToolkitPopupHelpers.h"

#include <imgui.h>

namespace
{
	int LastPopupCloseFrame = -1;
}

void ImGuiToolkitPopupHelpers::NotifyPopupClosed()
{
	LastPopupCloseFrame = ImGui::GetFrameCount();
}

bool ImGuiToolkitPopupHelpers::ShouldSuppressPopupAutoOpen()
{
	const int CurrentFrame = ImGui::GetFrameCount();
	return LastPopupCloseFrame >= 0 && CurrentFrame <= LastPopupCloseFrame + 1;
}
