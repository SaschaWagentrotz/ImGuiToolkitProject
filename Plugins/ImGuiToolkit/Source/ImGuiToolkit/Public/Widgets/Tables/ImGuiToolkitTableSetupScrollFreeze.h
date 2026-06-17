#pragma once

#include "CoreMinimal.h"
#include "ImGuiToolkitWidget.h"
#include "ImGuiToolkitTableSetupScrollFreeze.generated.h"

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitTableSetupScrollFreeze : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Widget", meta = (ClampMin = "0", UIMin = "0"))
	int32 FrozenColumnCount = 0;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Widget", meta = (ClampMin = "0", UIMin = "0"))
	int32 FrozenRowCount = 0;
};
