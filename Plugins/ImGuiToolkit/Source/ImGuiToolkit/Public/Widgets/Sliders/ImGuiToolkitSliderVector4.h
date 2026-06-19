#pragma once

#include "CoreMinimal.h"
#include "ImGuiToolkitWidget.h"
#include "ImGuiToolkitSliderVector4.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnImGuiSliderVector4Changed, FVector4, Value);

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitSliderVector4 : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Widget")
	FVector4 Value = FVector4(0, 0, 0, 0);

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Widget")
	float MinValue = 0.0f;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Widget")
	float MaxValue = 1.0f;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Widget")
	FString Format = "%.3f";

	UPROPERTY(BlueprintAssignable, Category = "ImGui Toolkit Widget")
	FOnImGuiSliderVector4Changed OnChanged;
};
