// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ImGuiToolkitWidget.h"
#include "ImGuiToolkitTextWrapped.generated.h"

/**
 * 
 */
UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitTextWrapped : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Widget")
	FText Text = FText::FromString("Text");
};
