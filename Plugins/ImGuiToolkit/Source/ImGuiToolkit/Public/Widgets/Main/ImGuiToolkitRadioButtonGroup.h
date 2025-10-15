// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ImGuiToolkitWidget.h"
#include "ImGuiToolkitRadioButtonGroup.generated.h"

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnImGuiRadioButtonClicked, UImGuiToolkitRadioButtonGroup*, RadioButtonGroup, int32, Index);

UENUM(BlueprintType)
enum EImGuiToolkitRadioButtonDirection
{
	Horizontal,
	Vertical
};

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitRadioButtonGroup : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Widget")
	TArray<FText> RadioItems;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Widget")
	TEnumAsByte<EImGuiToolkitRadioButtonDirection> Direction = Horizontal;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Widget")
	int32 SelectedIndex = 0;

	UPROPERTY(BlueprintReadOnly, Category = "ImGui Toolkit Widget")
	int32 PreviouslySelectedIndex = 0;

	UPROPERTY(BlueprintAssignable, Category = "ImGui Toolkit Widget")
	FOnImGuiRadioButtonClicked OnClicked;
};
