#pragma once

#include "CoreMinimal.h"
#include "ImGuiToolkitWidget.h"
#include "ImGuiToolkitInputVector2D.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnImGuiInputVector2DChanged, FVector2D, InputVector2D);

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitInputVector2D : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadOnly, Category = "ImGui Toolkit Widget")
	FVector2D InputVector2D = FVector2D::ZeroVector;

	UPROPERTY(BlueprintReadOnly, Category = "ImGui Toolkit Widget")
	FString Format = "%.3f";

	UPROPERTY(BlueprintAssignable, Category = "ImGui Toolkit Widget")
	FOnImGuiInputVector2DChanged OnVector2DChanged;

	UFUNCTION()
	void SetPreviewVector2D(FVector2D PreviewVector2D);

	UFUNCTION()
	void SetFormat(FString InFormat);
};
