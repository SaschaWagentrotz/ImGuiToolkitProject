// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "imgui.h"
#include "ImGuiToolkitWidget.h"
#include "ImGuiToolkitSameLine.generated.h"

/**
 * 
 */
UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitSameLine : public UImGuiToolkitWidget
{
	GENERATED_BODY()
	
public:
	void Render();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ImGui")
	float OffsetFromStartX = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ImGui")
	float Spacing = -1.0f;
};
