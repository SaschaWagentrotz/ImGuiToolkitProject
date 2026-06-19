#pragma once

#include "CoreMinimal.h"
#include "ImGuiToolkitWidget.h"
#include "ImGuiToolkitInputVector4.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnImGuiInputVector4Changed, FVector4, InputVector4);

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitInputVector4 : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadOnly, Category = "ImGui Toolkit Widget")
	FVector4 InputVector4 = FVector4(0, 0, 0, 0);

	UPROPERTY(BlueprintReadOnly, Category = "ImGui Toolkit Widget")
	FString Format = "%.3f";

	UPROPERTY(BlueprintAssignable, Category = "ImGui Toolkit Widget")
	FOnImGuiInputVector4Changed OnVector4Changed;

	UFUNCTION()
	void SetPreviewVector4(FVector4 PreviewVector4);

	UFUNCTION()
	void SetFormat(FString InFormat);
};
