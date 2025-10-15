// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ImGuiToolkitContainer.h"
#include "ImGuiToolkiBeginTabItem.generated.h"

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnImGuiTabItemSelectionChanged, UImGuiToolkiBeginTabItem*, TabItem, bool, bIsSelected);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnImGuiTabItemHovered, UImGuiToolkiBeginTabItem*, TabItem, bool, bIsSelected);


UCLASS()
class IMGUITOOLKIT_API UImGuiToolkiBeginTabItem : public UImGuiToolkitContainer
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Widget")
	bool bIsSelected = false;

	UPROPERTY(BlueprintAssignable, Category = "ImGui Toolkit Widget")
	FOnImGuiTabItemSelectionChanged OnSelectionChanged;

	UPROPERTY(BlueprintAssignable, Category = "ImGui Toolkit Widget")
	FOnImGuiTabItemHovered OnHovered;

};
