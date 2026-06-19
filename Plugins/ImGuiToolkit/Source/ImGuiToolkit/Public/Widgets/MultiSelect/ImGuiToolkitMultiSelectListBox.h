#pragma once

#include "CoreMinimal.h"
#include "FImGuiToolkitUtils.h"
#include "ImGuiToolkitWidget.h"
#include "ImGuiToolkitMultiSelectListBox.generated.h"

class UImGuiToolkitMultiSelectListBox;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnImGuiMultiSelectListBoxSelectionChanged, UImGuiToolkitMultiSelectListBox*, ListBox, const TArray<int32>&, SelectedIndices);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnImGuiMultiSelectListBoxItemClicked, UImGuiToolkitMultiSelectListBox*, ListBox, int32, ItemIndex, bool, bIsSelected);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnImGuiMultiSelectListBoxItemHovered, UImGuiToolkitMultiSelectListBox*, ListBox, int32, ItemIndex, bool, bIsSelected);

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitMultiSelectListBox : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UFUNCTION(BlueprintCallable, Category = "ImGuiTK Multi Select")
	void ClearSelection();

	UFUNCTION(BlueprintCallable, Category = "ImGuiTK Multi Select")
	void SelectAll();

	UFUNCTION(BlueprintCallable, Category = "ImGuiTK Multi Select")
	void SetSelectedIndices(const TArray<int32>& InSelectedIndices);

	UPROPERTY(BlueprintReadWrite, Category = "ImGuiTK Multi Select")
	TArray<FText> Items;

	UPROPERTY(BlueprintReadWrite, Category = "ImGuiTK Multi Select")
	TArray<int32> SelectedIndices;

	UPROPERTY(BlueprintReadWrite, Category = "ImGuiTK Multi Select")
	TArray<EImGuiMultiSelectFlag> MultiSelectFlags;

	UPROPERTY(BlueprintReadWrite, Category = "ImGuiTK Multi Select")
	TArray<EImGuiSelectableFlag> SelectableFlags;

	UPROPERTY(BlueprintReadWrite, Category = "ImGuiTK Multi Select")
	FVector2D Size = FVector2D(0, 0);

	UPROPERTY(BlueprintReadOnly, Category = "ImGuiTK Multi Select")
	int32 LastClickedIndex = INDEX_NONE;

	UPROPERTY(BlueprintReadOnly, Category = "ImGuiTK Multi Select")
	int32 LastHoveredIndex = INDEX_NONE;

	UPROPERTY(BlueprintAssignable, Category = "ImGuiTK Multi Select")
	FOnImGuiMultiSelectListBoxSelectionChanged OnSelectionChanged;

	UPROPERTY(BlueprintAssignable, Category = "ImGuiTK Multi Select")
	FOnImGuiMultiSelectListBoxItemClicked OnItemClicked;

	UPROPERTY(BlueprintAssignable, Category = "ImGuiTK Multi Select")
	FOnImGuiMultiSelectListBoxItemHovered OnItemHovered;

private:
	TArray<int32> NormalizeSelectedIndices(const TArray<int32>& InSelectedIndices) const;
	void ApplySelectionRequests(ImGuiMultiSelectIO* MultiSelectIO, TSet<int32>& SelectionSet) const;
	void UpdateSelectedIndicesFromSet(const TSet<int32>& SelectionSet);
};
