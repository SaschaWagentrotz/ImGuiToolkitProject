// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ImGuiToolkitWidget.h"
#include "ImGuiToolkitMenuItem.generated.h"

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnImGuiMenuItemClicked, UImGuiToolkitMenuItem*, MenuItem);

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitMenuItem : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Widget")
	FText Shortcut;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Widget")
	bool bIsSelected = false;

	UPROPERTY(BlueprintAssignable, Category = "ImGui Toolkit Widget")
	FOnImGuiMenuItemClicked OnClicked;
};
