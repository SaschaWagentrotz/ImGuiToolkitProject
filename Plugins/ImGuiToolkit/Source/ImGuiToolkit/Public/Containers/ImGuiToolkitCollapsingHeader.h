// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ImGuiToolkitContainer.h"
#include "ImGuiToolkitCollapsingHeader.generated.h"

/**
 * 
 */
UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitCollapsingHeader : public UImGuiToolkitContainer
{
	GENERATED_BODY()

public:
	virtual void Render() override;
};
