// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ImGuiToolkitWidget.h"
#include "ImGuiToolkitSliderInt.generated.h"

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnImGuiSliderIntChanged, int32, Value);

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitSliderInt : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Widget")
	int32 Value = 0;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Widget")
	int32 MinValue = 0;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Widget")
	int32 MaxValue = 0;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Widget")
	FText Format = FText::FromString("%d");

	UPROPERTY(BlueprintAssignable, Category = "ImGui Toolkit Widget")
	FOnImGuiSliderIntChanged OnChanged;
};
