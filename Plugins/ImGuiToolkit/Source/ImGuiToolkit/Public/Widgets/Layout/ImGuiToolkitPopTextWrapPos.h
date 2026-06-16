#pragma once

#include "CoreMinimal.h"
#include "ImGuiToolkitWidget.h"
#include "ImGuiToolkitPopTextWrapPos.generated.h"

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitPopTextWrapPos : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;
};
