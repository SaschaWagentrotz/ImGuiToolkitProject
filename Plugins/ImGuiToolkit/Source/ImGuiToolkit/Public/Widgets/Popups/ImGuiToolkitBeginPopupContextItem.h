#pragma once

#include "CoreMinimal.h"
#include "FImGuiToolkitUtils.h"
#include "ImGuiToolkitContainer.h"
#include "ImGuiToolkitBeginPopupContextItem.generated.h"

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitBeginPopupContextItem : public UImGuiToolkitContainer
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGuiTK Popups")
	FText PopupID;

	UPROPERTY(BlueprintReadWrite, Category = "ImGuiTK Popups")
	bool bUsePreviousItemID = true;

	UPROPERTY(BlueprintReadWrite, Category = "ImGuiTK Popups")
	EImGuiPopupMouseButton MouseButton = EImGuiPopupMouseButton::Right;

	UPROPERTY(BlueprintReadWrite, Category = "ImGuiTK Popups")
	TArray<EImGuiPopupFlag> PopupFlags;

	UPROPERTY(BlueprintReadOnly, Category = "ImGuiTK Popups")
	bool bIsOpen = false;
};
