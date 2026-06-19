#include "Widgets/Input/ImGuiToolkitInputVector2D.h"

void UImGuiToolkitInputVector2D::Render()
{
	if (!bEnabled)
		return;

	const FVector2D PreviousVector2D = InputVector2D;
	float Value[2] = { static_cast<float>(InputVector2D.X), static_cast<float>(InputVector2D.Y) };

	if (ImGui::InputFloat2(TCHAR_TO_UTF8(*UniqueWidgetLabel), Value, TCHAR_TO_UTF8(*Format)))
	{
		InputVector2D = FVector2D(Value[0], Value[1]);
	}

	if (!PreviousVector2D.Equals(InputVector2D))
	{
		OnVector2DChanged.Broadcast(InputVector2D);
	}
}

void UImGuiToolkitInputVector2D::SetPreviewVector2D(FVector2D PreviewVector2D)
{
	InputVector2D = PreviewVector2D;
}

void UImGuiToolkitInputVector2D::SetFormat(FString InFormat)
{
	Format = InFormat;
}
