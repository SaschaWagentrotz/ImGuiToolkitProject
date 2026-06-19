#include "Widgets/Sliders/ImGuiToolkitSliderAngle.h"

void UImGuiToolkitSliderAngle::Render()
{
	if (!bEnabled)
		return;

	float AngleRadians = FMath::DegreesToRadians(AngleDegrees);

	if (ImGui::SliderAngle(TCHAR_TO_UTF8(*UniqueWidgetLabel), &AngleRadians, MinDegrees, MaxDegrees, TCHAR_TO_UTF8(*Format)))
	{
		AngleDegrees = FMath::RadiansToDegrees(AngleRadians);
		OnChanged.Broadcast(AngleDegrees);
	}
}
