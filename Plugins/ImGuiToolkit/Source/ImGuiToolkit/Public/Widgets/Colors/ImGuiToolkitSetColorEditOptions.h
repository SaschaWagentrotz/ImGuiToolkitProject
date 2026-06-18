#pragma once

#include "CoreMinimal.h"
#include "FImGuiToolkitUtils.h"
#include "ImGuiToolkitWidget.h"
#include "ImGuiToolkitSetColorEditOptions.generated.h"

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitSetColorEditOptions : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Widget")
	TArray<EImGuiColorEditFlag> ColorEditFlags;
};
