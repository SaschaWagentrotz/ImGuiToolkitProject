#include "Widgets/Sliders/ImGuiToolkitDragVector2D.h"

void UImGuiToolkitDragVector2D::Render()
{
	if (!bEnabled)
		return;

	float DragValue[2] = {
		static_cast<float>(Value.X),
		static_cast<float>(Value.Y)
	};

	if (ImGui::DragFloat2(TCHAR_TO_UTF8(*UniqueWidgetLabel), DragValue, Speed, MinValue, MaxValue, TCHAR_TO_UTF8(*Format)))
	{
		Value = FVector2D(DragValue[0], DragValue[1]);
		OnChanged.Broadcast(Value);
	}
}
