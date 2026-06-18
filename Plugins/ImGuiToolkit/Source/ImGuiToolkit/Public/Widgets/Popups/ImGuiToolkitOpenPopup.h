#pragma once

#include "CoreMinimal.h"
#include "FImGuiToolkitUtils.h"
#include "ImGuiToolkitWidget.h"
#include "ImGuiToolkitOpenPopup.generated.h"

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitOpenPopup : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UFUNCTION(BlueprintCallable, Category = "ImGuiTK Popups")
	void Open();

	UPROPERTY(BlueprintReadWrite, Category = "ImGuiTK Popups")
	FText PopupID;

	UPROPERTY(BlueprintReadWrite, Category = "ImGuiTK Popups")
	TArray<EImGuiPopupFlag> PopupFlags;

	UPROPERTY(BlueprintReadOnly, Category = "ImGuiTK Popups")
	bool bOpenRequested = false;
};
