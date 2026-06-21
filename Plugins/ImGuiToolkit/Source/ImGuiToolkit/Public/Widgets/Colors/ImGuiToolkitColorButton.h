#pragma once

#include "CoreMinimal.h"
#include "FImGuiToolkitUtils.h"
#include "ImGuiToolkitWidget.h"
#include "ImGuiToolkitColorButton.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnImGuiColorButtonClicked, UImGuiToolkitColorButton*, ColorButton, FLinearColor, Color);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnImGuiColorButtonHovered, UImGuiToolkitColorButton*, ColorButton, FLinearColor, Color);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnImGuiColorButtonUnhovered, UImGuiToolkitColorButton*, ColorButton, FLinearColor, Color);

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitColorButton : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Widget")
	FLinearColor Color = FLinearColor::White;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Widget")
	TArray<EImGuiColorEditFlag> ColorEditFlags;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Widget")
	FVector2D Size = FVector2D(0, 0);

	UPROPERTY(BlueprintAssignable, Category = "ImGui Toolkit Widget")
	FOnImGuiColorButtonClicked OnClicked;

	UPROPERTY(BlueprintAssignable, Category = "ImGui Toolkit Widget")
	FOnImGuiColorButtonHovered OnHovered;

	UPROPERTY(BlueprintAssignable, Category = "ImGui Toolkit Widget")
	FOnImGuiColorButtonUnhovered OnUnhovered;

private:
	bool bIsCurrentlyHovered = false;
};
