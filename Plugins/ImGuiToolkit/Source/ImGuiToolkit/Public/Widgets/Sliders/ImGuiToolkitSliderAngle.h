#pragma once

#include "CoreMinimal.h"
#include "ImGuiToolkitWidget.h"
#include "ImGuiToolkitSliderAngle.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnImGuiSliderAngleChanged, float, AngleDegrees);

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitSliderAngle : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Widget")
	float AngleDegrees = 0.0f;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Widget")
	float MinDegrees = -360.0f;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Widget")
	float MaxDegrees = 360.0f;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Widget")
	FString Format = "%.0f deg";

	UPROPERTY(BlueprintAssignable, Category = "ImGui Toolkit Widget")
	FOnImGuiSliderAngleChanged OnChanged;
};
