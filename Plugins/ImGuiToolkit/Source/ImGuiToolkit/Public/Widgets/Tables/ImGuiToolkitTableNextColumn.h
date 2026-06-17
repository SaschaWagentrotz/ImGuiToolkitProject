#pragma once

#include "CoreMinimal.h"
#include "ImGuiToolkitContainer.h"
#include "ImGuiToolkitTableNextColumn.generated.h"

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitTableNextColumn : public UImGuiToolkitContainer
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadOnly, Category = "ImGui Toolkit Widget")
	bool bShouldRenderContents = false;
};
