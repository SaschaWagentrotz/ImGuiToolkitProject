#pragma once

#include "CoreMinimal.h"
#include "ImGuiToolkitWidget.h"
#include "ImGuiToolkitInputInt2.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnImGuiInputInt2Changed, FIntPoint, InputInt2);

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitInputInt2 : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadOnly, Category = "ImGui Toolkit Widget")
	FIntPoint InputInt2 = FIntPoint::ZeroValue;

	UPROPERTY(BlueprintAssignable, Category = "ImGui Toolkit Widget")
	FOnImGuiInputInt2Changed OnInt2Changed;

	UFUNCTION()
	void SetPreviewInt2(FIntPoint PreviewInt2);
};
