#pragma once

#include "CoreMinimal.h"
#include "FImGuiToolkitUtils.h"
#include "ImGuiToolkitContainer.h"
#include "ImGuiToolkitPopupButton.generated.h"

class UImGuiToolkitPopupButton;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnImGuiPopupButtonClicked, UImGuiToolkitPopupButton*, PopupButton);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnImGuiPopupButtonHovered, UImGuiToolkitPopupButton*, PopupButton);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnImGuiPopupButtonUnhovered, UImGuiToolkitPopupButton*, PopupButton);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnImGuiPopupButtonOpened, UImGuiToolkitPopupButton*, PopupButton);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnImGuiPopupButtonClosed, UImGuiToolkitPopupButton*, PopupButton);

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitPopupButton : public UImGuiToolkitContainer
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UFUNCTION(BlueprintCallable, Category = "ImGuiTK Popups")
	void Open();

	UFUNCTION(BlueprintCallable, Category = "ImGuiTK Popups")
	void Close();

	UPROPERTY(BlueprintReadWrite, Category = "ImGuiTK Popups")
	FText Tooltip;

	UPROPERTY(BlueprintReadWrite, Category = "ImGuiTK Popups")
	FVector2D Size = FVector2D(0, 0);

	UPROPERTY(BlueprintReadWrite, Category = "ImGuiTK Popups")
	TArray<EImGuiPopupFlag> PopupFlags;

	UPROPERTY(BlueprintReadWrite, Category = "ImGuiTK Popups")
	TArray<EImGuiWindowFlag> WindowFlags;

	UPROPERTY(BlueprintReadOnly, Category = "ImGuiTK Popups")
	bool bIsOpen = false;

	UPROPERTY(BlueprintAssignable, Category = "ImGuiTK Popups")
	FOnImGuiPopupButtonClicked OnClicked;

	UPROPERTY(BlueprintAssignable, Category = "ImGuiTK Popups")
	FOnImGuiPopupButtonHovered OnHovered;

	UPROPERTY(BlueprintAssignable, Category = "ImGuiTK Popups")
	FOnImGuiPopupButtonUnhovered OnUnhovered;

	UPROPERTY(BlueprintAssignable, Category = "ImGuiTK Popups")
	FOnImGuiPopupButtonOpened OnOpened;

	UPROPERTY(BlueprintAssignable, Category = "ImGuiTK Popups")
	FOnImGuiPopupButtonClosed OnClosed;

private:
	bool bOpenRequested = false;
	bool bCloseRequested = false;
	bool bIsCurrentlyHovered = false;
};
