#pragma once

#include "CoreMinimal.h"
#include "FImGuiToolkitUtils.h"
#include "ImGuiToolkitWidget.h"
#include "ImGuiToolkitTableSetupColumn.generated.h"

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitTableSetupColumn : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Widget")
	FText Label;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Widget")
	TArray<EImGuiTableColumnFlag> ColumnFlags;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Widget")
	float InitialWidthOrWeight = 0.0f;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Widget")
	int32 UserID = 0;
};
