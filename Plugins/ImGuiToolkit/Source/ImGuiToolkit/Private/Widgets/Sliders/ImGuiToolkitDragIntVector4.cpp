#include "Widgets/Sliders/ImGuiToolkitDragIntVector4.h"

void UImGuiToolkitDragIntVector4::Render()
{
	if (!bEnabled)
		return;

	int DragValue[4] = { Value.X, Value.Y, Value.Z, Value.W };

	if (ImGui::DragInt4(TCHAR_TO_UTF8(*UniqueWidgetLabel), DragValue, Speed, MinValue, MaxValue, TCHAR_TO_UTF8(*Format)))
	{
		Value = FIntVector4(DragValue[0], DragValue[1], DragValue[2], DragValue[3]);
		OnChanged.Broadcast(Value);
	}
}
