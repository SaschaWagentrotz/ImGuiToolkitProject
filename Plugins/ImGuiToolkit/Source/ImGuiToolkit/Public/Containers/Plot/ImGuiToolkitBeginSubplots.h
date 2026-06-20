#pragma once

#include "CoreMinimal.h"
#include "FImGuiToolkitUtils.h"
#include "ImGuiToolkitContainer.h"
#include "ImGuiToolkitBeginSubplots.generated.h"

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitBeginSubplots : public UImGuiToolkitContainer
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadOnly, Category = "ImGui Toolkit Plot")
	bool bIsOpen = false;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot", meta = (ClampMin = "1", UIMin = "1"))
	int32 Rows = 1;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot", meta = (ClampMin = "1", UIMin = "1"))
	int32 Columns = 1;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	FVector2D Size = FVector2D(0.0f, 0.0f);

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<EImPlotSubplotFlag> SubplotFlags;
};
