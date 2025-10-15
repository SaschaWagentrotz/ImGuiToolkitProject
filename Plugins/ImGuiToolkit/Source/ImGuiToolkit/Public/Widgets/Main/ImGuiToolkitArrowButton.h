// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FImGuiToolkitUtils.h"
#include "Containers/ImGuiToolkitWindow.h"
#include "ImGuiToolkitArrowButton.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnImGuiArrowButtonClicked, UImGuiToolkitArrowButton*, ArrowButton);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnImGuiArrowButtonHovered, UImGuiToolkitArrowButton*, ArrowButton);
/**
 * 
 */
UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitArrowButton : public UImGuiToolkitWindow
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Widget")
	FText Tooltip;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Widget")
	EImGuiToolkitDir CardinalDirection = EImGuiToolkitDir::None;

	UPROPERTY(BlueprintAssignable, Category = "ImGui Toolkit Widget")
	FOnImGuiArrowButtonClicked OnClicked;

	UPROPERTY(BlueprintAssignable, Category = "ImGui Toolkit Widget")
	FOnImGuiArrowButtonHovered OnHovered;
};
