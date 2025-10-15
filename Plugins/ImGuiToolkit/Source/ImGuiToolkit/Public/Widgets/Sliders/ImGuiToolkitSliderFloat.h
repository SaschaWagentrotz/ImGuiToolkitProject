// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ImGuiToolkitWidget.h"
#include "ImGuiToolkitSliderFloat.generated.h"

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnImGuiSliderFloatChanged, float, Value);

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitSliderFloat : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Widget")
	float Value = 0;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Widget")
	float MinValue = 0;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Widget")
	float MaxValue = 0;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Widget")
	FText Format = FText::FromString("%.3f");

	UPROPERTY(BlueprintAssignable, Category = "ImGui Toolkit Widget")
	FOnImGuiSliderFloatChanged OnChanged;
};
