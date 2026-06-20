#pragma once

#include "CoreMinimal.h"
#include "ImGuiToolkitWidget.h"
#include "ImGuiToolkitImage.generated.h"

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitImage : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Image")
	UObject* ResourceObject = nullptr;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Image")
	FVector2D Size = FVector2D::ZeroVector;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Image")
	FVector2D UV0 = FVector2D(0.0f, 0.0f);

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Image")
	FVector2D UV1 = FVector2D(1.0f, 1.0f);

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Image")
	FLinearColor TintColor = FLinearColor::White;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Image")
	FLinearColor BorderColor = FLinearColor::Transparent;
};
