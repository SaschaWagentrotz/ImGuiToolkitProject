#pragma once

#include "CoreMinimal.h"
#include "ImGuiToolkitWidget.h"
#include "ImGuiToolkitSetNextItemWidth.generated.h"

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitSetNextItemWidth : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Widget")
	float ItemWidth = 0.0f;
};
