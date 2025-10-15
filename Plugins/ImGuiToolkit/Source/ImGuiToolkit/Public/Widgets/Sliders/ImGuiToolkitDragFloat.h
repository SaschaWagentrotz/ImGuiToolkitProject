// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ImGuiToolkitWidget.h"
#include "ImGuiToolkitDragFloat.generated.h"

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnImGuiDragFloatChanged, float, Value);

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitDragFloat : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Widget")
	float Value = 0;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Widget")
	float Speed = 1.0f;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Widget")
	float MinValue = 0;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Widget")
	float MaxValue = 0;

	UPROPERTY(BlueprintAssignable, Category = "ImGui Toolkit Widget")
	FOnImGuiDragFloatChanged OnChanged;
};
