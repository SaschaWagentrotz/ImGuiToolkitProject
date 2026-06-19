#pragma once

#include "CoreMinimal.h"
#include "ImGuiToolkitWidget.h"
#include "ImGuiToolkitSliderVector2D.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnImGuiSliderVector2DChanged, FVector2D, Value);

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitSliderVector2D : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Widget")
	FVector2D Value = FVector2D::ZeroVector;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Widget")
	float MinValue = 0.0f;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Widget")
	float MaxValue = 1.0f;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Widget")
	FString Format = "%.3f";

	UPROPERTY(BlueprintAssignable, Category = "ImGui Toolkit Widget")
	FOnImGuiSliderVector2DChanged OnChanged;
};
