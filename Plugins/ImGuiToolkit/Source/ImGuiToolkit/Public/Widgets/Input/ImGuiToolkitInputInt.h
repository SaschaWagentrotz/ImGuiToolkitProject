// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ImGuiToolkitWidget.h"
#include "ImGuiToolkitInputInt.generated.h"

/**
 * 
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnImGuiInputIntChanged, int32, InputInt);

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitInputInt : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadOnly, Category = "ImGui Toolkit Widget")
	int32 InputInt = 0;

	UPROPERTY(BlueprintReadOnly, Category = "ImGui Toolkit Widget")
	FString FloatFormat = "%d";

	UPROPERTY(BlueprintAssignable, Category = "ImGui Toolkit Widget")
	FOnImGuiInputIntChanged OnIntChanged;
	
	UFUNCTION()
	void SetPreviewInt(float PreviewInt);
};
