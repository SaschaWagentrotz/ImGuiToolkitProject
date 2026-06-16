#pragma once

#include "CoreMinimal.h"
#include "ImGuiToolkitContainer.h"
#include "ImGuiToolkitBeginGroup.generated.h"

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitBeginGroup : public UImGuiToolkitContainer
{
	GENERATED_BODY()

public:
	virtual void Render() override;
};
