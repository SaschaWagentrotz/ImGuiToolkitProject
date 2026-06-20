#pragma once

#include "CoreMinimal.h"
#include "FImGuiToolkitUtils.h"
#include "ImGuiToolkitWidget.h"
#include "ImGuiToolkitPlotScatter.generated.h"

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitPlotScatter : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<float> Values;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	double XScale = 1.0;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	double XStart = 0.0;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<EImPlotScatterFlag> ScatterFlags;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<EImPlotItemFlag> ItemFlags;
};
