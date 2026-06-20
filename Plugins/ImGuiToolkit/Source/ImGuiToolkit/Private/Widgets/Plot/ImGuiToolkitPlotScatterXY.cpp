#include "Widgets/Plot/ImGuiToolkitPlotScatterXY.h"

void UImGuiToolkitPlotScatterXY::Render()
{
	if (!bEnabled || XValues.IsEmpty() || YValues.IsEmpty())
		return;

	const int32 Count = FMath::Min(XValues.Num(), YValues.Num());
	ImPlot::PlotScatter(
		TCHAR_TO_UTF8(*UniqueWidgetLabel),
		XValues.GetData(),
		YValues.GetData(),
		Count,
		FImGuiToolkitUtils::CombineImPlotScatterFlags(ScatterFlags) | FImGuiToolkitUtils::CombineImPlotItemFlags(ItemFlags)
	);
}
