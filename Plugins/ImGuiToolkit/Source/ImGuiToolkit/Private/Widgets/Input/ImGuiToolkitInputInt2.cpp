#include "Widgets/Input/ImGuiToolkitInputInt2.h"

void UImGuiToolkitInputInt2::Render()
{
	if (!bEnabled)
		return;

	const FIntPoint PreviousInt2 = InputInt2;
	int Value[2] = { InputInt2.X, InputInt2.Y };

	if (ImGui::InputInt2(TCHAR_TO_UTF8(*UniqueWidgetLabel), Value))
	{
		InputInt2 = FIntPoint(Value[0], Value[1]);
	}

	if (PreviousInt2 != InputInt2)
	{
		OnInt2Changed.Broadcast(InputInt2);
	}
}

void UImGuiToolkitInputInt2::SetPreviewInt2(FIntPoint PreviewInt2)
{
	InputInt2 = PreviewInt2;
}
