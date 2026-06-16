#pragma once

#include "CoreMinimal.h"
#include "ImGuiToolkitWidget.h"
#include "ImGuiToolkitEndListBox.generated.h"

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitEndListBox : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;
};
