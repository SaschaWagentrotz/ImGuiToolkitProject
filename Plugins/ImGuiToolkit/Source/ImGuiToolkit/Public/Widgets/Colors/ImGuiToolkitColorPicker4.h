#pragma once

#include "CoreMinimal.h"
#include "FImGuiToolkitUtils.h"
#include "ImGuiToolkitWidget.h"
#include "ImGuiToolkitColorPicker4.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnImGuiColorPicker4Changed, UImGuiToolkitColorPicker4*, ColorPicker, FLinearColor, Color);

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitColorPicker4 : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Widget")
	FLinearColor Color = FLinearColor::White;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Widget")
	TArray<EImGuiColorEditFlag> ColorEditFlags;

	UPROPERTY(BlueprintAssignable, Category = "ImGui Toolkit Widget")
	FOnImGuiColorPicker4Changed OnChanged;
};
