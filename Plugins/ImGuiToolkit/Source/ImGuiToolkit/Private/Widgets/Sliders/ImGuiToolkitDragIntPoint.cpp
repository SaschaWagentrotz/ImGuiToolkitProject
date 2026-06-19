#include "Widgets/Sliders/ImGuiToolkitDragIntPoint.h"

void UImGuiToolkitDragIntPoint::Render()
{
	if (!bEnabled)
		return;

	int DragValue[2] = { Value.X, Value.Y };

	if (ImGui::DragInt2(TCHAR_TO_UTF8(*UniqueWidgetLabel), DragValue, Speed, MinValue, MaxValue, TCHAR_TO_UTF8(*Format)))
	{
		Value = FIntPoint(DragValue[0], DragValue[1]);
		OnChanged.Broadcast(Value);
	}
}
