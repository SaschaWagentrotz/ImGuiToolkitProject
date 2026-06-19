#pragma once

#include "CoreMinimal.h"
#include "ImGuiToolkitWidget.h"
#include "ImGuiToolkitInputDouble.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnImGuiInputDoubleChanged, double, InputDouble);

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitInputDouble : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadOnly, Category = "ImGui Toolkit Widget")
	double InputDouble = 0.0;

	UPROPERTY(BlueprintReadOnly, Category = "ImGui Toolkit Widget")
	FString DoubleFormat = "%.6f";

	UPROPERTY(BlueprintAssignable, Category = "ImGui Toolkit Widget")
	FOnImGuiInputDoubleChanged OnDoubleChanged;

	UFUNCTION()
	void SetPreviewDouble(double PreviewDouble);

	UFUNCTION()
	void SetFormat(FString Format);
};
