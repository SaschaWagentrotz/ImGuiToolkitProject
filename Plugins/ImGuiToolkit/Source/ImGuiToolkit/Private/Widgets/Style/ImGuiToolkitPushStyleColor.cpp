#include "Widgets/Style/ImGuiToolkitPushStyleColor.h"

void UImGuiToolkitPushStyleColor::Render()
{
	if (!bEnabled)
		return;

	ImGui::PushStyleColor(
		FImGuiToolkitUtils::UnrealStyleColorToImGuiCol(StyleColor),
		FImGuiToolkitUtils::LinearColorToImVec4(Color)
	);
}
