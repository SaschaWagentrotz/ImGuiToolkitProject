#pragma once

#include "CoreMinimal.h"
#include "ImGuiToolkitWidget.h"
#include "ImGuiToolkitPopStyleVar.generated.h"

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitPopStyleVar : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Style")
	int32 Count = 1;
};
