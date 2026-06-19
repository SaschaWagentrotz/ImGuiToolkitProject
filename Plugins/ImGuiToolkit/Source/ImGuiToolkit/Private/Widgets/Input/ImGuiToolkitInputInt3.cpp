#include "Widgets/Input/ImGuiToolkitInputInt3.h"

void UImGuiToolkitInputInt3::Render()
{
	if (!bEnabled)
		return;

	const FIntVector PreviousInt3 = InputInt3;
	int Value[3] = { InputInt3.X, InputInt3.Y, InputInt3.Z };

	if (ImGui::InputInt3(TCHAR_TO_UTF8(*UniqueWidgetLabel), Value))
	{
		InputInt3 = FIntVector(Value[0], Value[1], Value[2]);
	}

	if (PreviousInt3 != InputInt3)
	{
		OnInt3Changed.Broadcast(InputInt3);
	}
}

void UImGuiToolkitInputInt3::SetPreviewInt3(FIntVector PreviewInt3)
{
	InputInt3 = PreviewInt3;
}
