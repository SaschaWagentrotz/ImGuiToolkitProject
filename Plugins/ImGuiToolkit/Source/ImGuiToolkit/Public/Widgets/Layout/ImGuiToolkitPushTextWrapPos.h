#pragma once

#include "CoreMinimal.h"
#include "ImGuiToolkitWidget.h"
#include "ImGuiToolkitPushTextWrapPos.generated.h"

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitPushTextWrapPos : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Widget")
	float WrapLocalPosX = 0.0f;
};
