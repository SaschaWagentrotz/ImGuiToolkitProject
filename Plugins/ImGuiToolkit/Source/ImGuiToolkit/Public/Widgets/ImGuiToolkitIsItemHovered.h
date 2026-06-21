// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ImGuiToolkitWidget.h"
#include "ImGuiToolkitIsItemHovered.generated.h"

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnImGuiItemHovered, UImGuiToolkitWidget*, Widget);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnImGuiItemUnhovered, UImGuiToolkitWidget*, Widget);

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitIsItemHovered : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintAssignable, Category = "ImGui Toolkit Widget")
	FOnImGuiItemHovered OnHovered;

	UPROPERTY(BlueprintAssignable, Category = "ImGui Toolkit Widget")
	FOnImGuiItemUnhovered OnUnhovered;

private:
	bool bIsCurrentlyHovered = false;
};
