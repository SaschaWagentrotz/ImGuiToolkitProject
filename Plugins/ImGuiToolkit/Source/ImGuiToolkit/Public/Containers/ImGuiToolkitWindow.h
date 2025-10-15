// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ImGuiToolkitContainer.h"
#include "ImGuiToolkitWindow.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class IMGUITOOLKIT_API UImGuiToolkitWindow : public UImGuiToolkitContainer
{
	GENERATED_BODY()

public:
	UImGuiToolkitWindow();
	
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGuiTK Containers")
	bool bIsOpen = true;

	UPROPERTY(BlueprintReadWrite, Category = "ImGuiTK Containers")
	FVector2D InitialSize = FVector2D(400, 300);

	UPROPERTY(BlueprintReadWrite, Category = "ImGuiTK Containers")
	FVector2D InitialPosition = FVector2D(100, 100);

	UPROPERTY(BlueprintReadWrite, Category = "ImGuiTK Containers")
	bool bIsHosted = false;
	
	UPROPERTY(BlueprintReadWrite, Category = "ImGuiTK Containers")
	FVector2D HostSize = FVector2D(400, 300);

	UPROPERTY(BlueprintReadWrite, Category = "ImGuiTK Containers")
	FVector2D HostPosition = FVector2D(100, 100);
};