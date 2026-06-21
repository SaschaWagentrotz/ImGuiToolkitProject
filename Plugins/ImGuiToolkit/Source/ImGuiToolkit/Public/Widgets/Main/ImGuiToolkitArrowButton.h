// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FImGuiToolkitUtils.h"
#include "ImGuiToolkitWidget.h"
#include "ImGuiToolkitArrowButton.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnImGuiArrowButtonClicked, UImGuiToolkitArrowButton*, ArrowButton);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnImGuiArrowButtonHovered, UImGuiToolkitArrowButton*, ArrowButton);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnImGuiArrowButtonUnhovered, UImGuiToolkitArrowButton*, ArrowButton);
/**
 * 
 */
UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitArrowButton : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	UImGuiToolkitArrowButton();

	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Widget")
	FText Tooltip;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Widget")
	EImGuiToolkitDir CardinalDirection = EImGuiToolkitDir::None;

	UPROPERTY(BlueprintAssignable, Category = "ImGui Toolkit Widget")
	FOnImGuiArrowButtonClicked OnClicked;

	UPROPERTY(BlueprintAssignable, Category = "ImGui Toolkit Widget")
	FOnImGuiArrowButtonHovered OnHovered;

	UPROPERTY(BlueprintAssignable, Category = "ImGui Toolkit Widget")
	FOnImGuiArrowButtonUnhovered OnUnhovered;

private:
	bool bIsCurrentlyHovered = false;
};
