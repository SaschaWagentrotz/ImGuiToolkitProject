#pragma once

#include "CoreMinimal.h"
#include "FImGuiToolkitUtils.h"
#include "ImGuiToolkitWidget.h"
#include "ImGuiToolkitPushStyleColor.generated.h"

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitPushStyleColor : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Style")
	EImGuiStyleColor StyleColor = EImGuiStyleColor::Text;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Style")
	FLinearColor Color = FLinearColor::White;
};
