// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ImGuiToolkitWidget.h"
#include "ImGuiToolkitCombo.generated.h"

/**
 * 
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnImGuiComboSelectionChanged, UImGuiToolkitCombo*, Combo, int32, CurrentItem);
	
UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitCombo : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Widget")
	TArray<FText> ComboItems;

	UPROPERTY(BlueprintReadOnly, Category = "ImGui Toolkit Widget")
	int32 SelectedIndex = 0;
	
	UPROPERTY(BlueprintAssignable, Category = "ImGui Toolkit Widget")
	FOnImGuiComboSelectionChanged OnSelectionChanged;
};
