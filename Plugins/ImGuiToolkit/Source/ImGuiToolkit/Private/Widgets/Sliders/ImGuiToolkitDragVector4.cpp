#include "Widgets/Sliders/ImGuiToolkitDragVector4.h"

void UImGuiToolkitDragVector4::Render()
{
	if (!bEnabled)
		return;

	float DragValue[4] = {
		static_cast<float>(Value.X),
		static_cast<float>(Value.Y),
		static_cast<float>(Value.Z),
		static_cast<float>(Value.W)
	};

	if (ImGui::DragFloat4(TCHAR_TO_UTF8(*UniqueWidgetLabel), DragValue, Speed, MinValue, MaxValue, TCHAR_TO_UTF8(*Format)))
	{
		Value = FVector4(DragValue[0], DragValue[1], DragValue[2], DragValue[3]);
		OnChanged.Broadcast(Value);
	}
}
