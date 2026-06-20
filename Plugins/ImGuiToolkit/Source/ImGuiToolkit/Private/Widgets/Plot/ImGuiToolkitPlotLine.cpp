#include "Widgets/Plot/ImGuiToolkitPlotLine.h"

void UImGuiToolkitPlotLine::Render()
{
	if (!bEnabled || Values.IsEmpty())
		return;

	ImPlot::PlotLine(
		TCHAR_TO_UTF8(*UniqueWidgetLabel),
		Values.GetData(),
		Values.Num(),
		XScale,
		XStart,
		FImGuiToolkitUtils::CombineImPlotLineFlags(LineFlags) | FImGuiToolkitUtils::CombineImPlotItemFlags(ItemFlags)
	);
}
