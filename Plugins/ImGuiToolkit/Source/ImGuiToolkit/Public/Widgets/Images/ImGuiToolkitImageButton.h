#pragma once

#include "CoreMinimal.h"
#include "ImGuiToolkitWidget.h"
#include "ImGuiToolkitImageButton.generated.h"

class UImGuiToolkitImageButton;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnImGuiImageButtonClicked, UImGuiToolkitImageButton*, ImageButton);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnImGuiImageButtonHovered, UImGuiToolkitImageButton*, ImageButton);

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitImageButton : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Image")
	UObject* ResourceObject = nullptr;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Image")
	FText Tooltip;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Image")
	FVector2D Size = FVector2D::ZeroVector;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Image")
	FVector2D UV0 = FVector2D(0.0f, 0.0f);

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Image")
	FVector2D UV1 = FVector2D(1.0f, 1.0f);

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Image")
	FLinearColor BackgroundColor = FLinearColor::Transparent;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Image")
	FLinearColor TintColor = FLinearColor::White;

	UPROPERTY(BlueprintAssignable, Category = "ImGui Toolkit Image")
	FOnImGuiImageButtonClicked OnClicked;

	UPROPERTY(BlueprintAssignable, Category = "ImGui Toolkit Image")
	FOnImGuiImageButtonHovered OnHovered;
};
