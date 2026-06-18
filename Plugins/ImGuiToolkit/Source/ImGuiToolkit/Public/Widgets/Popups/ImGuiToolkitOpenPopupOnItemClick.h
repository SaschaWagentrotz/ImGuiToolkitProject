#pragma once

#include "CoreMinimal.h"
#include "FImGuiToolkitUtils.h"
#include "ImGuiToolkitWidget.h"
#include "ImGuiToolkitOpenPopupOnItemClick.generated.h"

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitOpenPopupOnItemClick : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGuiTK Popups")
	FText PopupID;

	UPROPERTY(BlueprintReadWrite, Category = "ImGuiTK Popups")
	EImGuiPopupMouseButton MouseButton = EImGuiPopupMouseButton::Right;

	UPROPERTY(BlueprintReadWrite, Category = "ImGuiTK Popups")
	TArray<EImGuiPopupFlag> PopupFlags;
};
