#include "Widgets/Plot/ImGuiToolkitPlotBarsXY.h"

void UImGuiToolkitPlotBarsXY::Render()
{
	if (!bEnabled || XValues.IsEmpty() || YValues.IsEmpty())
		return;

	const int32 Count = FMath::Min(XValues.Num(), YValues.Num());
	ImPlot::PlotBars(
		TCHAR_TO_UTF8(*UniqueWidgetLabel),
		XValues.GetData(),
		YValues.GetData(),
		Count,
		BarSize,
		FImGuiToolkitUtils::CombineImPlotBarsFlags(BarsFlags) | FImGuiToolkitUtils::CombineImPlotItemFlags(ItemFlags)
	);
}
