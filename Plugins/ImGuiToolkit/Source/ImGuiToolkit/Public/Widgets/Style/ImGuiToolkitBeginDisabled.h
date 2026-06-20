#pragma once

#include "CoreMinimal.h"
#include "ImGuiToolkitWidget.h"
#include "ImGuiToolkitBeginDisabled.generated.h"

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitBeginDisabled : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Style")
	bool bDisabled = true;
};
