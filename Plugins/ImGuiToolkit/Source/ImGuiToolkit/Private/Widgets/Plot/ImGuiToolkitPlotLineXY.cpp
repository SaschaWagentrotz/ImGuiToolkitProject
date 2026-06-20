#include "Widgets/Plot/ImGuiToolkitPlotLineXY.h"

void UImGuiToolkitPlotLineXY::Render()
{
	if (!bEnabled || XValues.IsEmpty() || YValues.IsEmpty())
		return;

	const int32 Count = FMath::Min(XValues.Num(), YValues.Num());
	ImPlot::PlotLine(
		TCHAR_TO_UTF8(*UniqueWidgetLabel),
		XValues.GetData(),
		YValues.GetData(),
		Count,
		FImGuiToolkitUtils::CombineImPlotLineFlags(LineFlags) | FImGuiToolkitUtils::CombineImPlotItemFlags(ItemFlags)
	);
}
