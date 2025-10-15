// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ImGuiToolkitWidget.h"
#include "ImGuiToolkitCheckbox.generated.h"

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnImGuiCheckboxClicked, UImGuiToolkitCheckbox*, Checkbox, bool, bIsChecked);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnImGuiCheckboxHovered, UImGuiToolkitCheckbox*, Checkbox, bool, bIsChecked);

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitCheckbox : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Widget")
	FText Tooltip;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Widget")
	bool bIsChecked = false;
	
	UPROPERTY(BlueprintAssignable, Category = "ImGui Toolkit Widget")
	FOnImGuiCheckboxClicked OnClicked;

	UPROPERTY(BlueprintAssignable, Category = "ImGui Toolkit Widget")
	FOnImGuiCheckboxHovered OnHovered;

};
