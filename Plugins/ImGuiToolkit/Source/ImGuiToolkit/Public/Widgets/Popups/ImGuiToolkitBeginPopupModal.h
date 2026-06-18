#pragma once

#include "CoreMinimal.h"
#include "FImGuiToolkitUtils.h"
#include "ImGuiToolkitContainer.h"
#include "ImGuiToolkitBeginPopupModal.generated.h"

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitBeginPopupModal : public UImGuiToolkitContainer
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGuiTK Popups")
	FText PopupID;

	UPROPERTY(BlueprintReadWrite, Category = "ImGuiTK Popups")
	bool bShowCloseButton = false;

	UPROPERTY(BlueprintReadWrite, Category = "ImGuiTK Popups")
	bool bModalOpen = true;

	UPROPERTY(BlueprintReadWrite, Category = "ImGuiTK Popups")
	TArray<EImGuiWindowFlag> WindowFlags;

	UPROPERTY(BlueprintReadOnly, Category = "ImGuiTK Popups")
	bool bIsOpen = false;
};
