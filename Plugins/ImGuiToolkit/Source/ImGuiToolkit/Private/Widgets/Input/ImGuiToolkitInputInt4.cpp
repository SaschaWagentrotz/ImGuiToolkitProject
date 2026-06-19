#include "Widgets/Input/ImGuiToolkitInputInt4.h"

void UImGuiToolkitInputInt4::Render()
{
	if (!bEnabled)
		return;

	const FIntVector4 PreviousInt4 = InputInt4;
	int Value[4] = { InputInt4.X, InputInt4.Y, InputInt4.Z, InputInt4.W };

	if (ImGui::InputInt4(TCHAR_TO_UTF8(*UniqueWidgetLabel), Value))
	{
		InputInt4 = FIntVector4(Value[0], Value[1], Value[2], Value[3]);
	}

	if (PreviousInt4 != InputInt4)
	{
		OnInt4Changed.Broadcast(InputInt4);
	}
}

void UImGuiToolkitInputInt4::SetPreviewInt4(FIntVector4 PreviewInt4)
{
	InputInt4 = PreviewInt4;
}
