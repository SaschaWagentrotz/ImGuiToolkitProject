#pragma once

#include "CoreMinimal.h"
#include "ImGuiToolkitContainer.h"
#include "ImGuiToolkitBeginItemTooltip.generated.h"

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitBeginItemTooltip : public UImGuiToolkitContainer
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadOnly, Category = "ImGuiTK Tooltips")
	bool bIsOpen = false;
};
