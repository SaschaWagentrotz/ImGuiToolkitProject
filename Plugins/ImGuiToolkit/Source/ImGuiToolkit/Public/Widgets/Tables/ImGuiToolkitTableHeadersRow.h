#pragma once

#include "CoreMinimal.h"
#include "ImGuiToolkitWidget.h"
#include "ImGuiToolkitTableHeadersRow.generated.h"

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitTableHeadersRow : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;
};
