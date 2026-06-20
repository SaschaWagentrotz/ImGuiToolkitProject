#pragma once

#include "CoreMinimal.h"
#include "FImGuiToolkitUtils.h"
#include "ImGuiToolkitWidget.h"
#include "ImGuiToolkitPlotScatterXY.generated.h"

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitPlotScatterXY : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<float> XValues;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<float> YValues;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<EImPlotScatterFlag> ScatterFlags;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<EImPlotItemFlag> ItemFlags;
};
