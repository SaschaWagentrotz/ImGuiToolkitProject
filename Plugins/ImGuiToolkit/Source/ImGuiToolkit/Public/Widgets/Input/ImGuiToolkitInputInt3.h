#pragma once

#include "CoreMinimal.h"
#include "ImGuiToolkitWidget.h"
#include "ImGuiToolkitInputInt3.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnImGuiInputInt3Changed, const FIntVector&, InputInt3);

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitInputInt3 : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadOnly, Category = "ImGui Toolkit Widget")
	FIntVector InputInt3 = FIntVector::ZeroValue;

	UPROPERTY(BlueprintAssignable, Category = "ImGui Toolkit Widget")
	FOnImGuiInputInt3Changed OnInt3Changed;

	UFUNCTION()
	void SetPreviewInt3(FIntVector PreviewInt3);
};
