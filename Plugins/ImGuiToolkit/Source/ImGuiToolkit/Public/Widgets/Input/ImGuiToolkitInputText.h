// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ImGuiToolkitWidget.h"
#include "ImGuiToolkitInputText.generated.h"

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnImGuiInputTextChanged, FString, InputText);

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitInputText : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadOnly, Category = "ImGui Toolkit Widget")
	FString InputText;

	UPROPERTY(BlueprintAssignable, Category = "ImGui Toolkit Widget")
	FOnImGuiInputTextChanged OnTextChanged;

	UFUNCTION()
	void SetPreviewText(FText PreviewText);
};
