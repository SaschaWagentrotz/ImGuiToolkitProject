// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "imgui.h"
#include "ImGuiToolkitWidget.generated.h"

/**
 * 
 */
UCLASS(Abstract, BlueprintType)
class IMGUITOOLKIT_API UImGuiToolkitWidget : public UObject
{
	GENERATED_BODY()

public:
	UImGuiToolkitWidget();
	
	virtual void Render();
	
	void CreateUniqueWidgetLabel(FText Label);
    
	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit")
	bool bEnabled = true;

	UFUNCTION(BlueprintCallable, Category = "ImGui Toolkit")
	void Destroy();

	static const char* ConvertFTextArrayToCharBuffer(const TArray<FText>& TextArray);
	
	// Get unique widget identifier for ImGui
	FString GetUniqueWidgetLabel(const FText& Label) const;

protected:
	// Unique ID to differentiate widgets with the same label
	FGuid UniqueID;

	UPROPERTY(BlueprintReadOnly, Category = "ImGui Toolkit")
	FText WidgetLabel;

	UPROPERTY(BlueprintReadOnly, Category = "ImGui Toolkit")
	FString UniqueWidgetLabel;

};

