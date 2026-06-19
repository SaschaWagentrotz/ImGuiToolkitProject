#pragma once

#include "CoreMinimal.h"
#include "ImGuiToolkitWidget.h"
#include "ImGuiToolkitInputInt4.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnImGuiInputInt4Changed, const FIntVector4&, InputInt4);

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitInputInt4 : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadOnly, Category = "ImGui Toolkit Widget")
	FIntVector4 InputInt4 = FIntVector4(0, 0, 0, 0);

	UPROPERTY(BlueprintAssignable, Category = "ImGui Toolkit Widget")
	FOnImGuiInputInt4Changed OnInt4Changed;

	UFUNCTION()
	void SetPreviewInt4(FIntVector4 PreviewInt4);
};
