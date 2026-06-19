#include "Widgets/Sliders/ImGuiToolkitSliderVector.h"

void UImGuiToolkitSliderVector::Render()
{
	if (!bEnabled)
		return;

	float SliderValue[3] = {
		static_cast<float>(Value.X),
		static_cast<float>(Value.Y),
		static_cast<float>(Value.Z)
	};

	if (ImGui::SliderFloat3(TCHAR_TO_UTF8(*UniqueWidgetLabel), SliderValue, MinValue, MaxValue, TCHAR_TO_UTF8(*Format)))
	{
		Value = FVector(SliderValue[0], SliderValue[1], SliderValue[2]);
		OnChanged.Broadcast(Value);
	}
}
