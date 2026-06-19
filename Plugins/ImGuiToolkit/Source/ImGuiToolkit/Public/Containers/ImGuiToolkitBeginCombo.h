#pragma once

#include "CoreMinimal.h"
#include "FImGuiToolkitUtils.h"
#include "ImGuiToolkitContainer.h"
#include "ImGuiToolkitBeginCombo.generated.h"

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitBeginCombo : public UImGuiToolkitContainer
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGuiTK Containers")
	FText PreviewValue;

	UPROPERTY(BlueprintReadWrite, Category = "ImGuiTK Containers")
	TArray<EImGuiComboFlag> ComboFlags;

	UPROPERTY(BlueprintReadOnly, Category = "ImGuiTK Containers")
	bool bIsOpen = false;
};
