#pragma once

#include "CoreMinimal.h"
#include "FImGuiToolkitUtils.h"
#include "ImGuiToolkitWidget.h"
#include "ImGuiToolkitSetupPlotAxis.generated.h"

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitSetupPlotAxis : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	EImPlotAxis Axis = EImPlotAxis::X1;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	FText Label;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<EImPlotAxisFlag> AxisFlags;
};
