#include "Containers/Plot/ImGuiToolkitBeginPlot.h"

void UImGuiToolkitBeginPlot::Render()
{
	if (!bEnabled)
	{
		bIsOpen = false;
		return;
	}

	const ImPlotFlags CombinedFlags = FImGuiToolkitUtils::CombineImPlotFlags(PlotFlags);
	bIsOpen = ImPlot::BeginPlot(TCHAR_TO_UTF8(*UniqueWidgetLabel), ImVec2(Size.X, Size.Y), CombinedFlags);
	if (bIsOpen)
	{
		RenderChildren();
		ImPlot::EndPlot();
	}
}
