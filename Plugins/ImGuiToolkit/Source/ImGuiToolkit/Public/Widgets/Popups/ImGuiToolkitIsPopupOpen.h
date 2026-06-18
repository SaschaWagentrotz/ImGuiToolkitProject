#pragma once

#include "CoreMinimal.h"
#include "FImGuiToolkitUtils.h"
#include "ImGuiToolkitWidget.h"
#include "ImGuiToolkitIsPopupOpen.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnImGuiPopupOpenStateChanged, UImGuiToolkitIsPopupOpen*, Widget, bool, bIsOpen);

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitIsPopupOpen : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGuiTK Popups")
	FText PopupID;

	UPROPERTY(BlueprintReadWrite, Category = "ImGuiTK Popups")
	TArray<EImGuiPopupFlag> PopupFlags;

	UPROPERTY(BlueprintReadOnly, Category = "ImGuiTK Popups")
	bool bIsOpen = false;

	UPROPERTY(BlueprintAssignable, Category = "ImGuiTK Popups")
	FOnImGuiPopupOpenStateChanged OnOpenStateChanged;
};
