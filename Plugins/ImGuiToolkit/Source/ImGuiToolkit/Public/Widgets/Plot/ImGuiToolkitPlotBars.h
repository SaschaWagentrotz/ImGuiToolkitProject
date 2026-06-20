#pragma once

#include "CoreMinimal.h"
#include "FImGuiToolkitUtils.h"
#include "ImGuiToolkitWidget.h"
#include "ImGuiToolkitPlotBars.generated.h"

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitPlotBars : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<float> Values;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	double BarSize = 0.67;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	double Shift = 0.0;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<EImPlotBarsFlag> BarsFlags;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<EImPlotItemFlag> ItemFlags;
};
