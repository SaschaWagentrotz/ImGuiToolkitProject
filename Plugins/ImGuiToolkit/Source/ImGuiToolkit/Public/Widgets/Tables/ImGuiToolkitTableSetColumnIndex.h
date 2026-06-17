#pragma once

#include "CoreMinimal.h"
#include "ImGuiToolkitContainer.h"
#include "ImGuiToolkitTableSetColumnIndex.generated.h"

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitTableSetColumnIndex : public UImGuiToolkitContainer
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Widget", meta = (ClampMin = "0", UIMin = "0"))
	int32 ColumnIndex = 0;

	UPROPERTY(BlueprintReadOnly, Category = "ImGui Toolkit Widget")
	bool bShouldRenderContents = false;
};
