#include "Widgets/Tables/ImGuiToolkitTableSetupScrollFreeze.h"

void UImGuiToolkitTableSetupScrollFreeze::Render()
{
	if (!bEnabled)
	{
		return;
	}

	ImGui::TableSetupScrollFreeze(FMath::Max(0, FrozenColumnCount), FMath::Max(0, FrozenRowCount));
}
