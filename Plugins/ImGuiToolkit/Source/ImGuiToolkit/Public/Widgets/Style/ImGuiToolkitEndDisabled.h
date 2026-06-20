#pragma once

#include "CoreMinimal.h"
#include "ImGuiToolkitWidget.h"
#include "ImGuiToolkitEndDisabled.generated.h"

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitEndDisabled : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;
};
