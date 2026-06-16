#pragma once

#include "CoreMinimal.h"
#include "ImGuiToolkitWidget.h"
#include "ImGuiToolkitPopItemWidth.generated.h"

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitPopItemWidth : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;
};
