#include "Widgets/Sliders/ImGuiToolkitSliderVector2D.h"

void UImGuiToolkitSliderVector2D::Render()
{
	if (!bEnabled)
		return;

	float SliderValue[2] = {
		static_cast<float>(Value.X),
		static_cast<float>(Value.Y)
	};

	if (ImGui::SliderFloat2(TCHAR_TO_UTF8(*UniqueWidgetLabel), SliderValue, MinValue, MaxValue, TCHAR_TO_UTF8(*Format)))
	{
		Value = FVector2D(SliderValue[0], SliderValue[1]);
		OnChanged.Broadcast(Value);
	}
}
