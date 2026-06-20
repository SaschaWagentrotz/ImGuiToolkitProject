#pragma once

#include "CoreMinimal.h"
#include "FImGuiToolkitUtils.h"
#include "ImGuiToolkitContainer.h"
#include "ImGuiToolkitBeginPlot.generated.h"

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitBeginPlot : public UImGuiToolkitContainer
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	FVector2D Size = FVector2D(-1.0f, 0.0f);

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<EImPlotFlag> PlotFlags;

	UPROPERTY(BlueprintReadOnly, Category = "ImGui Toolkit Plot")
	bool bIsOpen = false;
};
