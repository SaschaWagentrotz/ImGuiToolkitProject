#include "Widgets/Plot/ImGuiToolkitSetupPlotAxis.h"

void UImGuiToolkitSetupPlotAxis::Render()
{
	if (!bEnabled)
		return;

	const FString LabelString = Label.ToString();
	ImPlot::SetupAxis(
		FImGuiToolkitUtils::UnrealPlotAxisToImPlotAxis(Axis),
		Label.IsEmpty() ? nullptr : TCHAR_TO_UTF8(*LabelString),
		FImGuiToolkitUtils::CombineImPlotAxisFlags(AxisFlags)
	);
}
