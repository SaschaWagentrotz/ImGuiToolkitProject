#pragma once

#include "CoreMinimal.h"
#include "ImGuiToolkitContainer.h"
#include "ImGuiToolkitBeginTooltip.generated.h"

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitBeginTooltip : public UImGuiToolkitContainer
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadOnly, Category = "ImGuiTK Tooltips")
	bool bIsOpen = false;
};
