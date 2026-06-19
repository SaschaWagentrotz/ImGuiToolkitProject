#include "Widgets/Input/ImGuiToolkitInputDouble.h"

void UImGuiToolkitInputDouble::Render()
{
	if (!bEnabled)
		return;

	const double PreviousDouble = InputDouble;

	ImGui::InputDouble(TCHAR_TO_UTF8(*UniqueWidgetLabel), &InputDouble, 0.0, 0.0, TCHAR_TO_UTF8(*DoubleFormat));

	if (PreviousDouble != InputDouble)
	{
		OnDoubleChanged.Broadcast(InputDouble);
	}
}

void UImGuiToolkitInputDouble::SetPreviewDouble(double PreviewDouble)
{
	InputDouble = PreviewDouble;
}

void UImGuiToolkitInputDouble::SetFormat(FString Format)
{
	DoubleFormat = Format;
}
