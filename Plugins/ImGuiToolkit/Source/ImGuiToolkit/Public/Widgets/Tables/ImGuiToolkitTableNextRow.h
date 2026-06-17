#pragma once

#include "CoreMinimal.h"
#include "FImGuiToolkitUtils.h"
#include "ImGuiToolkitContainer.h"
#include "ImGuiToolkitTableNextRow.generated.h"

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitTableNextRow : public UImGuiToolkitContainer
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Widget")
	TArray<EImGuiTableRowFlag> RowFlags;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Widget")
	float MinimumRowHeight = 0.0f;
};
