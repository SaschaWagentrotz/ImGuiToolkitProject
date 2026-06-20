#pragma once

#include "CoreMinimal.h"
#include "FImGuiToolkitUtils.h"
#include "ImGuiToolkitWidget.h"
#include "ImGuiToolkitPlotBarsXY.generated.h"

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitPlotBarsXY : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<float> XValues;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<float> YValues;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	double BarSize = 0.67;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<EImPlotBarsFlag> BarsFlags;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<EImPlotItemFlag> ItemFlags;
};
