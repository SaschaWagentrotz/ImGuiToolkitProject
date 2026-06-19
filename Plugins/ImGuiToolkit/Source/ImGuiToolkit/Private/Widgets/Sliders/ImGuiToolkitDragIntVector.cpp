#include "Widgets/Sliders/ImGuiToolkitDragIntVector.h"

void UImGuiToolkitDragIntVector::Render()
{
	if (!bEnabled)
		return;

	int DragValue[3] = { Value.X, Value.Y, Value.Z };

	if (ImGui::DragInt3(TCHAR_TO_UTF8(*UniqueWidgetLabel), DragValue, Speed, MinValue, MaxValue, TCHAR_TO_UTF8(*Format)))
	{
		Value = FIntVector(DragValue[0], DragValue[1], DragValue[2]);
		OnChanged.Broadcast(Value);
	}
}
