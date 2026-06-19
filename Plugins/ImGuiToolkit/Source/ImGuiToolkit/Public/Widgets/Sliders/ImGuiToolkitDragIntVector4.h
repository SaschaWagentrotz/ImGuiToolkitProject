#pragma once

#include "CoreMinimal.h"
#include "ImGuiToolkitWidget.h"
#include "ImGuiToolkitDragIntVector4.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnImGuiDragIntVector4Changed, FIntVector4, Value);

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitDragIntVector4 : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Widget")
	FIntVector4 Value = FIntVector4(0, 0, 0, 0);

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Widget")
	float Speed = 1.0f;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Widget")
	int32 MinValue = 0;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Widget")
	int32 MaxValue = 0;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Widget")
	FString Format = "%d";

	UPROPERTY(BlueprintAssignable, Category = "ImGui Toolkit Widget")
	FOnImGuiDragIntVector4Changed OnChanged;
};
