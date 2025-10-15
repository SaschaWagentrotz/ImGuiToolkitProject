// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ImGuiToolkitWidget.h"
#include "ImGuiToolkitLabelText.generated.h"

/**
 * 
 */
UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitLabelText : public UImGuiToolkitWidget
{
	GENERATED_BODY()
	
public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Widget")
	FText Label = FText::FromString("Label");

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Widget")
	FText Value = FText::FromString("Value");
};
