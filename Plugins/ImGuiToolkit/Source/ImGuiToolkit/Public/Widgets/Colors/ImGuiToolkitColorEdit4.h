#pragma once

#include "CoreMinimal.h"
#include "FImGuiToolkitUtils.h"
#include "ImGuiToolkitWidget.h"
#include "ImGuiToolkitColorEdit4.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnImGuiColorEdit4Changed, UImGuiToolkitColorEdit4*, ColorEdit, FLinearColor, Color);

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitColorEdit4 : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Widget")
	FLinearColor Color = FLinearColor::White;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Widget")
	TArray<EImGuiColorEditFlag> ColorEditFlags;

	UPROPERTY(BlueprintAssignable, Category = "ImGui Toolkit Widget")
	FOnImGuiColorEdit4Changed OnChanged;
};
