// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ImGuiToolkitWidget.h"
#include "ImGuiToolkitSmallButton.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnImGuiSmallButtonClicked, UImGuiToolkitSmallButton*, SmallButton);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnImGuiSmallButtonHovered, UImGuiToolkitSmallButton*, SmallButton);

/**
 * 
 */
UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitSmallButton : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Widget")
	FText Tooltip;

	UPROPERTY(BlueprintAssignable, Category = "ImGui Toolkit Widget")
	FOnImGuiSmallButtonClicked OnClicked;

	UPROPERTY(BlueprintAssignable, Category = "ImGui Toolkit Widget")
	FOnImGuiSmallButtonHovered OnHovered;
};
