#pragma once

#include "CoreMinimal.h"
#include "ImGuiToolkitWidget.h"
#include "ImGuiToolkitCloseCurrentPopup.generated.h"

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitCloseCurrentPopup : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UFUNCTION(BlueprintCallable, Category = "ImGuiTK Popups")
	void Close();

	UPROPERTY(BlueprintReadWrite, Category = "ImGuiTK Popups")
	bool bCloseWhenPreviousItemClicked = true;

	UPROPERTY(BlueprintReadWrite, Category = "ImGuiTK Popups")
	bool bCloseRequested = false;
};
