#include "Containers/Plot/ImGuiToolkitBeginSubplots.h"

void UImGuiToolkitBeginSubplots::Render()
{
	if (!bEnabled)
	{
		bIsOpen = false;
		return;
	}

	bIsOpen = ImPlot::BeginSubplots(
		TCHAR_TO_UTF8(*UniqueWidgetLabel),
		FMath::Max(1, Rows),
		FMath::Max(1, Columns),
		ImVec2(Size.X, Size.Y),
		FImGuiToolkitUtils::CombineImPlotSubplotFlags(SubplotFlags)
	);

	if (bIsOpen)
	{
		RenderChildren();
		ImPlot::EndSubplots();
	}
}
