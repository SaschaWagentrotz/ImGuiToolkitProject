#include "Widgets/Plot/ImGuiToolkitPlotBars.h"

void UImGuiToolkitPlotBars::Render()
{
	if (!bEnabled || Values.IsEmpty())
		return;

	ImPlot::PlotBars(
		TCHAR_TO_UTF8(*UniqueWidgetLabel),
		Values.GetData(),
		Values.Num(),
		BarSize,
		Shift,
		FImGuiToolkitUtils::CombineImPlotBarsFlags(BarsFlags) | FImGuiToolkitUtils::CombineImPlotItemFlags(ItemFlags)
	);
}
