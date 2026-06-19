#pragma once

#include "CoreMinimal.h"
#include "ImGuiToolkitWidget.h"
#include "ImGuiToolkitSetTooltip.generated.h"

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitSetTooltip : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGuiTK Tooltips")
	FText Text;
};
