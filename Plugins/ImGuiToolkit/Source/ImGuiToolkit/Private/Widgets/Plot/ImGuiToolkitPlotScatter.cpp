#include "Widgets/Plot/ImGuiToolkitPlotScatter.h"

void UImGuiToolkitPlotScatter::Render()
{
	if (!bEnabled || Values.IsEmpty())
		return;

	ImPlot::PlotScatter(
		TCHAR_TO_UTF8(*UniqueWidgetLabel),
		Values.GetData(),
		Values.Num(),
		XScale,
		XStart,
		FImGuiToolkitUtils::CombineImPlotScatterFlags(ScatterFlags) | FImGuiToolkitUtils::CombineImPlotItemFlags(ItemFlags)
	);
}
