#include "Widgets/Sliders/ImGuiToolkitDragVector.h"

void UImGuiToolkitDragVector::Render()
{
	if (!bEnabled)
		return;

	float DragValue[3] = {
		static_cast<float>(Value.X),
		static_cast<float>(Value.Y),
		static_cast<float>(Value.Z)
	};

	if (ImGui::DragFloat3(TCHAR_TO_UTF8(*UniqueWidgetLabel), DragValue, Speed, MinValue, MaxValue, TCHAR_TO_UTF8(*Format)))
	{
		Value = FVector(DragValue[0], DragValue[1], DragValue[2]);
		OnChanged.Broadcast(Value);
	}
}
