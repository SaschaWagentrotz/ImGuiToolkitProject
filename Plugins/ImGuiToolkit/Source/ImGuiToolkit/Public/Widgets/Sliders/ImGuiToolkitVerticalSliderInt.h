#pragma once

#include "CoreMinimal.h"
#include "ImGuiToolkitWidget.h"
#include "ImGuiToolkitVerticalSliderInt.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnImGuiVerticalSliderIntChanged, int32, Value);

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitVerticalSliderInt : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Widget")
	int32 Value = 0;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Widget")
	int32 MinValue = 0;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Widget")
	int32 MaxValue = 1;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Widget")
	FVector2D Size = FVector2D(18.0f, 160.0f);

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Widget")
	FString Format = "%d";

	UPROPERTY(BlueprintAssignable, Category = "ImGui Toolkit Widget")
	FOnImGuiVerticalSliderIntChanged OnChanged;
};
