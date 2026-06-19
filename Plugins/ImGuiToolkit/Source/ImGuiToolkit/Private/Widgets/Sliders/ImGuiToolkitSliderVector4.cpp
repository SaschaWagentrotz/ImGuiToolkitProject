#include "Widgets/Sliders/ImGuiToolkitSliderVector4.h"

void UImGuiToolkitSliderVector4::Render()
{
	if (!bEnabled)
		return;

	float SliderValue[4] = {
		static_cast<float>(Value.X),
		static_cast<float>(Value.Y),
		static_cast<float>(Value.Z),
		static_cast<float>(Value.W)
	};

	if (ImGui::SliderFloat4(TCHAR_TO_UTF8(*UniqueWidgetLabel), SliderValue, MinValue, MaxValue, TCHAR_TO_UTF8(*Format)))
	{
		Value = FVector4(SliderValue[0], SliderValue[1], SliderValue[2], SliderValue[3]);
		OnChanged.Broadcast(Value);
	}
}
