// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ImGuiToolkitWidget.h"
#include "ImGuiToolkitButton.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnImGuiButtonClicked, UImGuiToolkitButton*, Button);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnImGuiButtonHovered, UImGuiToolkitButton*, Button);

/**
 * 
 */
UCLASS(BlueprintType)
class IMGUITOOLKIT_API UImGuiToolkitButton : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Widget")
	FText Tooltip;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Widget")
	FVector2D Size = FVector2D(0, 0);

	UPROPERTY(BlueprintAssignable, Category = "ImGui Toolkit Widget")
	FOnImGuiButtonClicked OnClicked;

	UPROPERTY(BlueprintAssignable, Category = "ImGui Toolkit Widget")
	FOnImGuiButtonHovered OnHovered;

};
