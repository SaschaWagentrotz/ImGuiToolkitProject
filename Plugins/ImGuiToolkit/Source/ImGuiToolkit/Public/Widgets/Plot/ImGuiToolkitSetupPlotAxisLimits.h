#pragma once

#include "CoreMinimal.h"
#include "FImGuiToolkitUtils.h"
#include "ImGuiToolkitWidget.h"
#include "ImGuiToolkitSetupPlotAxisLimits.generated.h"

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitSetupPlotAxisLimits : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	EImPlotAxis Axis = EImPlotAxis::X1;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	double MinValue = 0.0;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	double MaxValue = 1.0;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	EImPlotCondition Condition = EImPlotCondition::Once;
};
