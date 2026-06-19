#pragma once

#include "CoreMinimal.h"
#include "ImGuiToolkitWidget.h"
#include "ImGuiToolkitInputVector.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnImGuiInputVectorChanged, FVector, InputVector);

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitInputVector : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadOnly, Category = "ImGui Toolkit Widget")
	FVector InputVector = FVector::ZeroVector;

	UPROPERTY(BlueprintReadOnly, Category = "ImGui Toolkit Widget")
	FString Format = "%.3f";

	UPROPERTY(BlueprintAssignable, Category = "ImGui Toolkit Widget")
	FOnImGuiInputVectorChanged OnVectorChanged;

	UFUNCTION()
	void SetPreviewVector(FVector PreviewVector);

	UFUNCTION()
	void SetFormat(FString InFormat);
};
