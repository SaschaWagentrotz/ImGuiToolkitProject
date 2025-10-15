// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ImGuiToolkitWidget.h"
#include "ImGuiToolkitContainer.generated.h"

/**
 * 
 */
UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitContainer : public UImGuiToolkitWidget
{
	GENERATED_BODY()
	
public:
	UImGuiToolkitContainer();

	// Add a child widget to this container
	UFUNCTION(BlueprintCallable, Category = "ImGuiTK Containers")
	virtual void AddWidget(UImGuiToolkitWidget* Widget);

	// Remove a child widget from this container
	UFUNCTION(BlueprintCallable, Category = "ImGuiTK Containers")
	virtual void RemoveWidget(UImGuiToolkitWidget* Widget);

	// Clear all child widgets
	UFUNCTION(BlueprintCallable, Category = "ImGuiTK Containers")
	virtual void ClearWidgets();

	// Get all child widgets
	UFUNCTION(BlueprintCallable, Category = "ImGuiTK Containers")
	TArray<UImGuiToolkitWidget*> GetWidgets();

protected:
	// Render all child widgets
	virtual void RenderChildren();

	UPROPERTY(BlueprintReadWrite, Category = "ImGuiTK Containers")
	TArray<UImGuiToolkitWidget*> Widgets;
};
