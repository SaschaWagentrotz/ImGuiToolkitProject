// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ImGuiToolkitWidget.h"
#include "ImGuiToolkitInputFloat.generated.h"

/**
 * 
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnImGuiInputFloatChanged, float, InputFloat);

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitInputFloat : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadOnly, Category = "ImGui Toolkit Widget")
	float InputFloat = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "ImGui Toolkit Widget")
	FString FloatFormat = "%.3f";

	UPROPERTY(BlueprintAssignable, Category = "ImGui Toolkit Widget")
	FOnImGuiInputFloatChanged OnFloatChanged;
	
	UFUNCTION()
	void SetPreviewFloat(float PreviewFloat);

	UFUNCTION()
	void SetFormat(FString Format);
};
