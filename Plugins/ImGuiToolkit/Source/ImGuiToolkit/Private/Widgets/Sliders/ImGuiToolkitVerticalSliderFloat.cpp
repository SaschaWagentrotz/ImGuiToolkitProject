#include "Widgets/Sliders/ImGuiToolkitVerticalSliderFloat.h"

void UImGuiToolkitVerticalSliderFloat::Render()
{
	if (!bEnabled)
		return;

	const ImVec2 SliderSize(Size.X, Size.Y);
	if (ImGui::VSliderFloat(TCHAR_TO_UTF8(*UniqueWidgetLabel), SliderSize, &Value, MinValue, MaxValue, TCHAR_TO_UTF8(*Format)))
	{
		OnChanged.Broadcast(Value);
	}
}
