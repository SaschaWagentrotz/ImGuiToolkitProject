#include "Widgets/Plot/ImGuiToolkitSetupPlotAxisLimits.h"

void UImGuiToolkitSetupPlotAxisLimits::Render()
{
	if (!bEnabled)
		return;

	ImPlot::SetupAxisLimits(
		FImGuiToolkitUtils::UnrealPlotAxisToImPlotAxis(Axis),
		MinValue,
		MaxValue,
		FImGuiToolkitUtils::UnrealPlotConditionToImPlotCond(Condition)
	);
}
