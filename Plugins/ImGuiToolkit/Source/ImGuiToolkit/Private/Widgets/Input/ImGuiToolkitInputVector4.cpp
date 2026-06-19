#include "Widgets/Input/ImGuiToolkitInputVector4.h"

void UImGuiToolkitInputVector4::Render()
{
	if (!bEnabled)
		return;

	const FVector4 PreviousVector4 = InputVector4;
	float Value[4] = {
		static_cast<float>(InputVector4.X),
		static_cast<float>(InputVector4.Y),
		static_cast<float>(InputVector4.Z),
		static_cast<float>(InputVector4.W)
	};

	if (ImGui::InputFloat4(TCHAR_TO_UTF8(*UniqueWidgetLabel), Value, TCHAR_TO_UTF8(*Format)))
	{
		InputVector4 = FVector4(Value[0], Value[1], Value[2], Value[3]);
	}

	if (!PreviousVector4.Equals(InputVector4))
	{
		OnVector4Changed.Broadcast(InputVector4);
	}
}

void UImGuiToolkitInputVector4::SetPreviewVector4(FVector4 PreviewVector4)
{
	InputVector4 = PreviewVector4;
}

void UImGuiToolkitInputVector4::SetFormat(FString InFormat)
{
	Format = InFormat;
}
