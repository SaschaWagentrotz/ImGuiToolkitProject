#pragma once

#include "CoreMinimal.h"
#include "FImGuiToolkitUtils.h"
#include "ImGuiToolkitWidget.h"
#include "ImGuiToolkitColorEdit3.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnImGuiColorEdit3Changed, UImGuiToolkitColorEdit3*, ColorEdit, FLinearColor, Color);

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitColorEdit3 : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Widget")
	FLinearColor Color = FLinearColor::White;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Widget")
	TArray<EImGuiColorEditFlag> ColorEditFlags;

	UPROPERTY(BlueprintAssignable, Category = "ImGui Toolkit Widget")
	FOnImGuiColorEdit3Changed OnChanged;
};
