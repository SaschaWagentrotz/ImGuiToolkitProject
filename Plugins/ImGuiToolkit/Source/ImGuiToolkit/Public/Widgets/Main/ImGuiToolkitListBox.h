#pragma once

#include "CoreMinimal.h"
#include "ImGuiToolkitWidget.h"
#include "ImGuiToolkitListBox.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnImGuiListBoxSelectionChanged, UImGuiToolkitListBox*, ListBox, int32, CurrentItem);

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitListBox : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Widget")
	TArray<FText> ListItems;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Widget")
	int32 SelectedIndex = 0;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Widget")
	int32 HeightInItems = -1;

	UPROPERTY(BlueprintAssignable, Category = "ImGui Toolkit Widget")
	FOnImGuiListBoxSelectionChanged OnSelectionChanged;
};
