#pragma once

#include "CoreMinimal.h"
#include "ImGuiToolkitWidget.h"
#include "ImGuiToolkitDragVector4.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnImGuiDragVector4Changed, FVector4, Value);

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitDragVector4 : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Widget")
	FVector4 Value = FVector4(0, 0, 0, 0);

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Widget")
	float Speed = 1.0f;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Widget")
	float MinValue = 0.0f;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Widget")
	float MaxValue = 0.0f;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Widget")
	FString Format = "%.3f";

	UPROPERTY(BlueprintAssignable, Category = "ImGui Toolkit Widget")
	FOnImGuiDragVector4Changed OnChanged;
};
