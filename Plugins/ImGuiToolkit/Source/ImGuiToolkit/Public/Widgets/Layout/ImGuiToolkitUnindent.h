// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ImGuiToolkitWidget.h"
#include "ImGuiToolkitUnindent.generated.h"

/**
 * 
 */
UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitUnindent : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;
};
