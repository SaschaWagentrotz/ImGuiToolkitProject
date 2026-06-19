#include "Widgets/Input/ImGuiToolkitInputVector.h"

void UImGuiToolkitInputVector::Render()
{
	if (!bEnabled)
		return;

	const FVector PreviousVector = InputVector;
	float Value[3] = {
		static_cast<float>(InputVector.X),
		static_cast<float>(InputVector.Y),
		static_cast<float>(InputVector.Z)
	};

	if (ImGui::InputFloat3(TCHAR_TO_UTF8(*UniqueWidgetLabel), Value, TCHAR_TO_UTF8(*Format)))
	{
		InputVector = FVector(Value[0], Value[1], Value[2]);
	}

	if (!PreviousVector.Equals(InputVector))
	{
		OnVectorChanged.Broadcast(InputVector);
	}
}

void UImGuiToolkitInputVector::SetPreviewVector(FVector PreviewVector)
{
	InputVector = PreviewVector;
}

void UImGuiToolkitInputVector::SetFormat(FString InFormat)
{
	Format = InFormat;
}
