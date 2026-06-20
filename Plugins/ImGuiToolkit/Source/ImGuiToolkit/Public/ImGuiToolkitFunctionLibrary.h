#pragma once

#include "CoreMinimal.h"
#include "Components/Widget.h"
#include "Engine/Texture2D.h"
#include "FImGuiToolkitUtils.h"
#include "Materials/MaterialInterface.h"
#include "Widgets/TabBar/ImGuiToolkiBeginTabItem.h"
#include "Containers/ImGuiToolkitBeginChild.h"
#include "Containers/ImGuiToolkitBeginCombo.h"
#include "Containers/ImGuiToolkitBeginGroup.h"
#include "Containers/ImGuiToolkitBeginListBox.h"
#include "Containers/ImGuiToolkitBeginTabBar.h"
#include "Containers/ImGuiToolkitBeginTable.h"
#include "Containers/ImGuiToolkitCollapsingHeader.h"
#include "Containers/ImGuiToolkitBeginMenu.h"
#include "Containers/ImGuiToolkitBeginMenuBar.h"
#include "Containers/ImGuiToolkitTreeNode.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Widgets/Text/ImGuiToolkitBulletText.h"
#include "Widgets/Main/ImGuiToolkitHelpMarker.h"
#include "Widgets/Layout/ImGuiToolkitIndent.h"
#include "Widgets/Layout/ImGuiToolkitUnindent.h"
#include "Widgets/Text/ImGuiToolkitLabelText.h"
#include "Widgets/Layout/ImGuiToolkitSameLine.h"
#include "Widgets/Text/ImGuiToolkitSeparatorText.h"
#include "Widgets/Main/ImGuiToolkitSetItemTooltip.h"
#include "Widgets/Layout/ImGuiToolkitSpacing.h"
#include "Widgets/Text/ImGuiToolkitText.h"
#include "Widgets/Text/ImGuiToolkitTextDisabled.h"
#include "Containers/ImGuiToolkitWindow.h"
#include "Widgets/Input/ImGuiToolkitInputFloat.h"
#include "Widgets/Input/ImGuiToolkitInputVector2D.h"
#include "Widgets/Input/ImGuiToolkitInputVector.h"
#include "Widgets/Input/ImGuiToolkitInputVector4.h"
#include "Widgets/Input/ImGuiToolkitInputInt.h"
#include "Widgets/Input/ImGuiToolkitInputInt2.h"
#include "Widgets/Input/ImGuiToolkitInputInt3.h"
#include "Widgets/Input/ImGuiToolkitInputInt4.h"
#include "Widgets/Input/ImGuiToolkitInputDouble.h"
#include "Widgets/Input/ImGuiToolkitInputText.h"
#include "Widgets/Input/ImGuiToolkitInputTextMultiline.h"
#include "Widgets/Input/ImGuiToolkitInputTextWithHint.h"
#include "Widgets/Images/ImGuiToolkitImage.h"
#include "Widgets/Images/ImGuiToolkitImageButton.h"
#include "Widgets/Layout/ImGuiToolkitAlignTextToFramePadding.h"
#include "Containers/Plot/ImGuiToolkitBeginPlot.h"
#include "Containers/Plot/ImGuiToolkitBeginSubplots.h"
#include "Widgets/Main/ImGuiToolkitButton.h"
#include "Widgets/Main/ImGuiToolkitCheckbox.h"
#include "Widgets/Main/ImGuiToolkitCombo.h"
#include "Widgets/Main/ImGuiToolkitEndListBox.h"
#include "Widgets/Colors/ImGuiToolkitColorButton.h"
#include "Widgets/Colors/ImGuiToolkitColorEdit3.h"
#include "Widgets/Colors/ImGuiToolkitColorEdit4.h"
#include "Widgets/Colors/ImGuiToolkitColorPicker3.h"
#include "Widgets/Colors/ImGuiToolkitColorPicker4.h"
#include "Widgets/Colors/ImGuiToolkitSetColorEditOptions.h"
#include "Widgets/Popups/ImGuiToolkitBeginPopup.h"
#include "Widgets/Popups/ImGuiToolkitBeginPopupContextItem.h"
#include "Widgets/Popups/ImGuiToolkitBeginPopupContextVoid.h"
#include "Widgets/Popups/ImGuiToolkitBeginPopupContextWindow.h"
#include "Widgets/Popups/ImGuiToolkitBeginPopupModal.h"
#include "Widgets/Popups/ImGuiToolkitCloseCurrentPopup.h"
#include "Widgets/Popups/ImGuiToolkitIsPopupOpen.h"
#include "Widgets/Popups/ImGuiToolkitOpenPopup.h"
#include "Widgets/Popups/ImGuiToolkitOpenPopupOnItemClick.h"
#include "Widgets/Popups/ImGuiToolkitPopupButton.h"
#include "Widgets/Plot/ImGuiToolkitPlotBars.h"
#include "Widgets/Plot/ImGuiToolkitPlotBarsXY.h"
#include "Widgets/Plot/ImGuiToolkitPlotLine.h"
#include "Widgets/Plot/ImGuiToolkitPlotLineXY.h"
#include "Widgets/Plot/ImGuiToolkitPlotScatter.h"
#include "Widgets/Plot/ImGuiToolkitPlotScatterXY.h"
#include "Widgets/Plot/ImGuiToolkitPlotExtras.h"
#include "Widgets/Plot/ImGuiToolkitSetupPlotAxis.h"
#include "Widgets/Plot/ImGuiToolkitSetupPlotAxisLimits.h"
#include "Widgets/Sliders/ImGuiToolkitDragFloat.h"
#include "Widgets/Sliders/ImGuiToolkitDragIntPoint.h"
#include "Widgets/Sliders/ImGuiToolkitDragIntVector.h"
#include "Widgets/Sliders/ImGuiToolkitDragIntVector4.h"
#include "Widgets/Sliders/ImGuiToolkitDragInt.h"
#include "Widgets/Sliders/ImGuiToolkitDragVector2D.h"
#include "Widgets/Sliders/ImGuiToolkitDragVector.h"
#include "Widgets/Sliders/ImGuiToolkitDragVector4.h"
#include "Widgets/Sliders/ImGuiToolkitSliderAngle.h"
#include "Widgets/Sliders/ImGuiToolkitSliderFloat.h"
#include "Widgets/Sliders/ImGuiToolkitSliderInt.h"
#include "Widgets/Sliders/ImGuiToolkitSliderVector2D.h"
#include "Widgets/Sliders/ImGuiToolkitSliderVector.h"
#include "Widgets/Sliders/ImGuiToolkitSliderVector4.h"
#include "Widgets/Sliders/ImGuiToolkitVerticalSliderFloat.h"
#include "Widgets/Sliders/ImGuiToolkitVerticalSliderInt.h"
#include "Widgets/Style/ImGuiToolkitBeginDisabled.h"
#include "Widgets/Style/ImGuiToolkitEndDisabled.h"
#include "Widgets/Style/ImGuiToolkitPopStyleColor.h"
#include "Widgets/Style/ImGuiToolkitPopStyleVar.h"
#include "Widgets/Style/ImGuiToolkitPushStyleColor.h"
#include "Widgets/Style/ImGuiToolkitPushStyleVar.h"
#include "Widgets/TabBar/ImGuiToolkitEndTabBar.h"
#include "Widgets/TabBar/ImGuiToolkitEndTabItem.h"
#include "Widgets/Tables/ImGuiToolkitTableHeader.h"
#include "Widgets/Tables/ImGuiToolkitTableHeadersRow.h"
#include "Widgets/Tables/ImGuiToolkitTableNextColumn.h"
#include "Widgets/Tables/ImGuiToolkitTableNextRow.h"
#include "Widgets/Tables/ImGuiToolkitTableSetColumnIndex.h"
#include "Widgets/Tables/ImGuiToolkitTableSetupColumn.h"
#include "Widgets/Tables/ImGuiToolkitTableSetupScrollFreeze.h"
#include "Widgets/Tree/ImGuiToolkitTreePop.h"
#include "Widgets/Tree/ImGuiToolkitTreePush.h"
#include "Widgets/Layout/ImGuiToolkitNewLine.h"
#include "Widgets/Layout/ImGuiToolkitPopItemWidth.h"
#include "Widgets/Layout/ImGuiToolkitPopTextWrapPos.h"
#include "Widgets/Layout/ImGuiToolkitPushItemWidth.h"
#include "Widgets/Layout/ImGuiToolkitPushTextWrapPos.h"
#include "Widgets/Layout/ImGuiToolkitSeparator.h"
#include "Widgets/Layout/ImGuiToolkitSetNextItemWidth.h"
#include "Widgets/Layout/ImGuiToolkitDummy.h"
#include "Widgets/Main/ImGuiToolkitArrowButton.h"
#include "Widgets/Main/ImGuiToolkitBullet.h"
#include "Widgets/Main/ImGuiToolkitListBox.h"
#include "Widgets/Main/ImGuiToolkitProgressBar.h"
#include "Widgets/Main/ImGuiToolkitRadioButtonGroup.h"
#include "Widgets/Main/ImGuiToolkitSelectable.h"
#include "Widgets/Main/ImGuiToolkitSmallButton.h"
#include "Widgets/MenuBar/ImGuiToolkitEndMenu.h"
#include "Widgets/MenuBar/ImGuiToolkitEndMenuBar.h"
#include "Widgets/MenuBar/ImGuiToolkitMenuItem.h"
#include "Widgets/MultiSelect/ImGuiToolkitMultiSelectListBox.h"
#include "Widgets/Text/ImGuiToolkitTextColored.h"
#include "Widgets/Text/ImGuiToolkitTextLinkOpenURL.h"
#include "Widgets/Text/ImGuiToolkitTextWrapped.h"
#include "Widgets/Tooltips/ImGuiToolkitBeginItemTooltip.h"
#include "Widgets/Tooltips/ImGuiToolkitBeginTooltip.h"
#include "Widgets/Tooltips/ImGuiToolkitSetTooltip.h"
#include "ImGuiToolkitFunctionLibrary.generated.h"

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	// Toggle the ImGui DemoWindow (needs to be called again to close it)
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit")
	static void ToggleImGuiDemoWindow();

	// Create a new ImGui window
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, HidePin = "WorldContextObject", ReturnDisplayName = "Container"))
	static UImGuiToolkitWindow* CreateImGuiWindow(UObject* WorldContextObject, FText WindowTitle, TArray<EImGuiWindowFlag> WindowFlags);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (ReturnDisplayName = "Container"))
	static UImGuiToolkitBeginChild* CreateImGuiBeginChild(FText Label, FVector2D Size, TArray<EImGuiChildFlag> ChildFlags, TArray<EImGuiWindowFlag> WindowFlags, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (ReturnDisplayName = "Container"))
	static UImGuiToolkitBeginGroup* CreateImGuiBeginGroup(UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (ReturnDisplayName = "Container"))
	static UImGuiToolkitBeginListBox* CreateImGuiBeginListBox(FText Label, FVector2D Size = FVector2D(0, 0), UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (DeprecatedFunction, DeprecationMessage = "End widgets are no longer required. ImGuiToolkit container widgets close themselves during Render.", ReturnDisplayName = "Element"))
	static UImGuiToolkitEndListBox* EndImGuiListBox(UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitListBox* CreateImGuiListBox(FText Label, TArray<FText> ListItems, int32 InitialIndex = 0, int32 HeightInItems = -1, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitPushItemWidth* CreateImGuiPushItemWidth(float ItemWidth, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitPopItemWidth* CreateImGuiPopItemWidth(UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitSetNextItemWidth* CreateImGuiSetNextItemWidth(float ItemWidth, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitPushTextWrapPos* CreateImGuiPushTextWrapPos(float WrapLocalPosX = 0.0f, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitPopTextWrapPos* CreateImGuiPopTextWrapPos(UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (ReturnDisplayName = "Position"))
	static FVector2D GetWidgetPosition(UWidget* Widget);

	// Destroy an ImGui window
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit")
	static void DestroyImGuiWindow(UImGuiToolkitWindow* Window);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|Docking", meta = (ClampMin = "0.05", ClampMax = "0.95", UIMin = "0.05", UIMax = "0.95"))
	static void DockImGuiWindow(UImGuiToolkitWindow* WindowToDock, UImGuiToolkitWindow* TargetWindow, EImGuiToolkitDockSplitDirection Direction = EImGuiToolkitDockSplitDirection::Center, float SplitRatio = 0.5f);

	// Create a SameLine
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitSameLine* CreateImGuiSameLine(float OffsetFromStartX = 0.0f, float Spacing = -1.0f, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (ToolTip = "", ReturnDisplayName = "Element"))
	static UImGuiToolkitButton* CreateImGuiButton(FText Label, FText Tooltip = FText::GetEmpty(), FVector2D Size = FVector2D(0, 0), UImGuiToolkitContainer* Container = nullptr);

	// Create a HelpMarker with a tooltip
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitHelpMarker* CreateImGuiHelpMarker(FText Text, UImGuiToolkitContainer* Container = nullptr);

	// Create a Tooltip
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|Tooltips", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitSetItemTooltip* CreateImGuiSetItemTooltip(FText Text, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|Tooltips", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitSetTooltip* CreateImGuiSetTooltip(FText Text, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|Tooltips", meta = (ReturnDisplayName = "Container"))
	static UImGuiToolkitBeginTooltip* CreateImGuiBeginTooltip(UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|Tooltips", meta = (ReturnDisplayName = "Container"))
	static UImGuiToolkitBeginItemTooltip* CreateImGuiBeginItemTooltip(UImGuiToolkitContainer* Container = nullptr);

	// Create a CollapsingHeader
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (ReturnDisplayName = "Container"))
	static UImGuiToolkitCollapsingHeader* CreateImGuiCollapsingHeader(FText Label, UImGuiToolkitContainer* Container = nullptr);

	// Create a Text
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitText* CreateImGuiText(FText Text, UImGuiToolkitContainer* Container = nullptr);

	// Use AlignTextToFramePadding() to align text baseline to the baseline of framed widgets elements, otherwise a Text+SameLine+Button sequence will have the text a little too high by default.
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitAlignTextToFramePadding* CreateImGuiAlignTextToFramePadding(UImGuiToolkitContainer* Container = nullptr);

	// Create a Text Disabled
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitTextDisabled* CreateImGuiTextDisabled(FText Text, UImGuiToolkitContainer* Container = nullptr);

	// Create a Separator Text
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitSeparatorText* CreateImGuiSeparatorText(FText Text, UImGuiToolkitContainer* Container = nullptr);

	// Create a Bullet Text
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitBulletText* CreateImGuiBulletText(FText Text, UImGuiToolkitContainer* Container = nullptr);

	// Create a Label Text
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitLabelText* CreateImGuiLabelText(FText LeftText, FText RightText, UImGuiToolkitContainer* Container = nullptr);

	// Create a Spacing
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitSpacing* CreateImGuiSpacing(UImGuiToolkitContainer* Container = nullptr);

	// Create an Indent
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitIndent* CreateImGuiIndent(UImGuiToolkitContainer* Container = nullptr);

	// Create an Unindent
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitUnindent* CreateImGuiUnindent(UImGuiToolkitContainer* Container = nullptr);

	// Create a TreeNode
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (ReturnDisplayName = "Container"))
	static UImGuiToolkitTreeNode* CreateImGuiTreeNode(FText Label, UImGuiToolkitContainer* Container = nullptr);

	// Create a TreePush
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitTreePush* CreateImGuiTreePush(FText Label, UImGuiToolkitContainer* Container = nullptr);

	// Create a TreePop
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitTreePop* CreateImGuiTreePop(UImGuiToolkitContainer* Container = nullptr);

	// Create a Checkbox
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitCheckbox* CreateImGuiCheckbox(FText Label, FText Tooltip, bool bIsChecked, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitSelectable* CreateImGuiSelectable(FText Label, bool bIsSelected, TArray<EImGuiSelectableFlag> SelectableFlags, FVector2D Size = FVector2D(0, 0), FText Tooltip = FText::GetEmpty(), UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|Multi Select", meta = (ReturnDisplayName = "Element", AdvancedDisplay = "Size,MultiSelectFlags,SelectableFlags"))
	static UImGuiToolkitMultiSelectListBox* CreateImGuiMultiSelectListBox(FText Label, TArray<FText> Items, TArray<int32> InitialSelectedIndices, FVector2D Size, TArray<EImGuiMultiSelectFlag> MultiSelectFlags, TArray<EImGuiSelectableFlag> SelectableFlags, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|Colors", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitColorEdit3* CreateImGuiColorEdit3(FText Label, FLinearColor Color, TArray<EImGuiColorEditFlag> ColorEditFlags, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|Colors", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitColorEdit4* CreateImGuiColorEdit4(FText Label, FLinearColor Color, TArray<EImGuiColorEditFlag> ColorEditFlags, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|Colors", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitColorPicker3* CreateImGuiColorPicker3(FText Label, FLinearColor Color, TArray<EImGuiColorEditFlag> ColorEditFlags, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|Colors", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitColorPicker4* CreateImGuiColorPicker4(FText Label, FLinearColor Color, TArray<EImGuiColorEditFlag> ColorEditFlags, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|Colors", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitColorButton* CreateImGuiColorButton(FText Label, FLinearColor Color, TArray<EImGuiColorEditFlag> ColorEditFlags, FVector2D Size = FVector2D(0, 0), UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|Colors", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitSetColorEditOptions* CreateImGuiSetColorEditOptions(TArray<EImGuiColorEditFlag> ColorEditFlags, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|Tables", meta = (ClampMin = "1", UIMin = "1", ReturnDisplayName = "Container"))
	static UImGuiToolkitBeginTable* CreateImGuiBeginTable(FText Label, int32 ColumnCount, TArray<EImGuiTableFlag> TableFlags, FVector2D OuterSize = FVector2D(0, 0), float InnerWidth = 0.0f, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|Tables", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitTableSetupColumn* CreateImGuiTableSetupColumn(FText Label, TArray<EImGuiTableColumnFlag> ColumnFlags, float InitialWidthOrWeight = 0.0f, int32 UserID = 0, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|Tables", meta = (ClampMin = "0", UIMin = "0", ReturnDisplayName = "Element"))
	static UImGuiToolkitTableSetupScrollFreeze* CreateImGuiTableSetupScrollFreeze(int32 FrozenColumnCount = 0, int32 FrozenRowCount = 0, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|Tables", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitTableHeadersRow* CreateImGuiTableHeadersRow(UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|Tables", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitTableHeader* CreateImGuiTableHeader(FText Label, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|Tables", meta = (ReturnDisplayName = "Container"))
	static UImGuiToolkitTableNextRow* CreateImGuiTableNextRow(TArray<EImGuiTableRowFlag> RowFlags, float MinimumRowHeight = 0.0f, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|Tables", meta = (ReturnDisplayName = "Container"))
	static UImGuiToolkitTableNextColumn* CreateImGuiTableNextColumn(UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|Tables", meta = (ClampMin = "0", UIMin = "0", ReturnDisplayName = "Container"))
	static UImGuiToolkitTableSetColumnIndex* CreateImGuiTableSetColumnIndex(int32 ColumnIndex, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|Popups", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitOpenPopup* CreateImGuiOpenPopup(FText PopupID, TArray<EImGuiPopupFlag> PopupFlags, bool bOpenOnCreate, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|Popups", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitOpenPopupOnItemClick* CreateImGuiOpenPopupOnItemClick(FText PopupID, EImGuiPopupMouseButton MouseButton, TArray<EImGuiPopupFlag> PopupFlags, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|Popups", meta = (ReturnDisplayName = "Container"))
	static UImGuiToolkitBeginPopup* CreateImGuiBeginPopup(FText PopupID, TArray<EImGuiWindowFlag> WindowFlags, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|Popups", meta = (ReturnDisplayName = "Container"))
	static UImGuiToolkitBeginPopupModal* CreateImGuiBeginPopupModal(FText PopupID, bool bShowCloseButton, TArray<EImGuiWindowFlag> WindowFlags, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|Popups", meta = (ReturnDisplayName = "Container"))
	static UImGuiToolkitBeginPopupContextItem* CreateImGuiBeginPopupContextItem(FText PopupID, bool bUsePreviousItemID, EImGuiPopupMouseButton MouseButton, TArray<EImGuiPopupFlag> PopupFlags, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|Popups", meta = (ReturnDisplayName = "Container"))
	static UImGuiToolkitBeginPopupContextWindow* CreateImGuiBeginPopupContextWindow(FText PopupID, EImGuiPopupMouseButton MouseButton, TArray<EImGuiPopupFlag> PopupFlags, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|Popups", meta = (ReturnDisplayName = "Container"))
	static UImGuiToolkitBeginPopupContextVoid* CreateImGuiBeginPopupContextVoid(FText PopupID, EImGuiPopupMouseButton MouseButton, TArray<EImGuiPopupFlag> PopupFlags, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|Popups", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitCloseCurrentPopup* CreateImGuiCloseCurrentPopup(bool bCloseOnCreate = false, bool bCloseWhenPreviousItemClicked = true, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|Popups", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitIsPopupOpen* CreateImGuiIsPopupOpen(FText PopupID, TArray<EImGuiPopupFlag> PopupFlags, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|Popups", meta = (ReturnDisplayName = "Container", AdvancedDisplay = "Tooltip,Size,PopupFlags,WindowFlags"))
	static UImGuiToolkitPopupButton* CreateImGuiPopupButton(FText Label, FText Tooltip, FVector2D Size, TArray<EImGuiPopupFlag> PopupFlags, TArray<EImGuiWindowFlag> WindowFlags, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|Images", meta = (ReturnDisplayName = "Element", AdvancedDisplay = "Size,UV0,UV1"))
	static UImGuiToolkitImage* CreateImGuiImage(UTexture2D* Texture, FVector2D Size = FVector2D(0.0f, 0.0f), FVector2D UV0 = FVector2D(0.0f, 0.0f), FVector2D UV1 = FVector2D(1.0f, 1.0f), UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|Images", meta = (ReturnDisplayName = "Element", AdvancedDisplay = "UV0,UV1"))
	static UImGuiToolkitImage* CreateImGuiMaterialImage(UMaterialInterface* Material, FVector2D Size = FVector2D(64.0f, 64.0f), FVector2D UV0 = FVector2D(0.0f, 0.0f), FVector2D UV1 = FVector2D(1.0f, 1.0f), UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|Images", meta = (ReturnDisplayName = "Element", AdvancedDisplay = "Tooltip,Size,UV0,UV1"))
	static UImGuiToolkitImageButton* CreateImGuiImageButton(FText ButtonID, UTexture2D* Texture, FText Tooltip = FText::GetEmpty(), FVector2D Size = FVector2D(0.0f, 0.0f), FVector2D UV0 = FVector2D(0.0f, 0.0f), FVector2D UV1 = FVector2D(1.0f, 1.0f), UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|Images", meta = (ReturnDisplayName = "Element", AdvancedDisplay = "Tooltip,UV0,UV1"))
	static UImGuiToolkitImageButton* CreateImGuiMaterialImageButton(FText ButtonID, UMaterialInterface* Material, FText Tooltip = FText::GetEmpty(), FVector2D Size = FVector2D(64.0f, 64.0f), FVector2D UV0 = FVector2D(0.0f, 0.0f), FVector2D UV1 = FVector2D(1.0f, 1.0f), UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|ImPlot", meta = (ReturnDisplayName = "Container", AdvancedDisplay = "Size,PlotFlags"))
	static UImGuiToolkitBeginPlot* CreateImPlotBeginPlot(FText Title, TArray<EImPlotFlag> PlotFlags, FVector2D Size = FVector2D(-1.0f, 0.0f), UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|ImPlot", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitSetupPlotAxis* CreateImPlotSetupAxis(EImPlotAxis Axis, FText Label, TArray<EImPlotAxisFlag> AxisFlags, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|ImPlot", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitSetupPlotAxisLimits* CreateImPlotSetupAxisLimits(EImPlotAxis Axis, double MinValue, double MaxValue, EImPlotCondition Condition = EImPlotCondition::Once, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|ImPlot", meta = (ReturnDisplayName = "Element", AdvancedDisplay = "XScale,XStart,LineFlags,ItemFlags"))
	static UImGuiToolkitPlotLine* CreateImPlotLine(FText Label, TArray<float> Values, TArray<EImPlotLineFlag> LineFlags, TArray<EImPlotItemFlag> ItemFlags, double XScale = 1.0, double XStart = 0.0, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|ImPlot", meta = (ReturnDisplayName = "Element", AdvancedDisplay = "LineFlags,ItemFlags"))
	static UImGuiToolkitPlotLineXY* CreateImPlotLineXY(FText Label, TArray<float> XValues, TArray<float> YValues, TArray<EImPlotLineFlag> LineFlags, TArray<EImPlotItemFlag> ItemFlags, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|ImPlot", meta = (ReturnDisplayName = "Element", AdvancedDisplay = "XScale,XStart,ScatterFlags,ItemFlags"))
	static UImGuiToolkitPlotScatter* CreateImPlotScatter(FText Label, TArray<float> Values, TArray<EImPlotScatterFlag> ScatterFlags, TArray<EImPlotItemFlag> ItemFlags, double XScale = 1.0, double XStart = 0.0, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|ImPlot", meta = (ReturnDisplayName = "Element", AdvancedDisplay = "ScatterFlags,ItemFlags"))
	static UImGuiToolkitPlotScatterXY* CreateImPlotScatterXY(FText Label, TArray<float> XValues, TArray<float> YValues, TArray<EImPlotScatterFlag> ScatterFlags, TArray<EImPlotItemFlag> ItemFlags, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|ImPlot", meta = (ReturnDisplayName = "Element", AdvancedDisplay = "BarSize,Shift,BarsFlags,ItemFlags"))
	static UImGuiToolkitPlotBars* CreateImPlotBars(FText Label, TArray<float> Values, TArray<EImPlotBarsFlag> BarsFlags, TArray<EImPlotItemFlag> ItemFlags, double BarSize = 0.67, double Shift = 0.0, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|ImPlot", meta = (ReturnDisplayName = "Element", AdvancedDisplay = "BarSize,BarsFlags,ItemFlags"))
	static UImGuiToolkitPlotBarsXY* CreateImPlotBarsXY(FText Label, TArray<float> XValues, TArray<float> YValues, TArray<EImPlotBarsFlag> BarsFlags, TArray<EImPlotItemFlag> ItemFlags, double BarSize = 0.67, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|ImPlot|Items", meta = (ReturnDisplayName = "Element", AdvancedDisplay = "GroupSize,Shift,BarGroupsFlags,ItemFlags"))
	static UImGuiToolkitPlotBarGroups* CreateImPlotBarGroups(TArray<FText> Labels, TArray<float> Values, int32 ItemCount, int32 GroupCount, TArray<EImPlotBarGroupsFlag> BarGroupsFlags, TArray<EImPlotItemFlag> ItemFlags, double GroupSize = 0.67, double Shift = 0.0, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|ImPlot|Subplots", meta = (ReturnDisplayName = "Container", AdvancedDisplay = "Size,SubplotFlags"))
	static UImGuiToolkitBeginSubplots* CreateImPlotBeginSubplots(FText Title, int32 Rows, int32 Columns, TArray<EImPlotSubplotFlag> SubplotFlags, FVector2D Size = FVector2D(0.0f, 0.0f), UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|ImPlot|Setup", meta = (ReturnDisplayName = "Element", AdvancedDisplay = "LegendFlags"))
	static UImGuiToolkitSetupPlotLegend* CreateImPlotSetupLegend(EImPlotLocation Location, TArray<EImPlotLegendFlag> LegendFlags, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|ImPlot|Setup", meta = (ReturnDisplayName = "Element", AdvancedDisplay = "MouseTextFlags"))
	static UImGuiToolkitSetupPlotMouseText* CreateImPlotSetupMouseText(EImPlotLocation Location, TArray<EImPlotMouseTextFlag> MouseTextFlags, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|ImPlot|Setup", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitSetupPlotAxisFormat* CreateImPlotSetupAxisFormat(EImPlotAxis Axis, FString Format = TEXT("%g"), UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|ImPlot|Setup", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitSetupPlotAxisScale* CreateImPlotSetupAxisScale(EImPlotAxis Axis, EImPlotScale Scale = EImPlotScale::Linear, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|ImPlot|Setup", meta = (ReturnDisplayName = "Element", AdvancedDisplay = "XAxisFlags,YAxisFlags"))
	static UImGuiToolkitSetupPlotAxes* CreateImPlotSetupAxes(FText XLabel, FText YLabel, TArray<EImPlotAxisFlag> XAxisFlags, TArray<EImPlotAxisFlag> YAxisFlags, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|ImPlot|Setup", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitSetupPlotAxesLimits* CreateImPlotSetupAxesLimits(FVector2D XLimits, FVector2D YLimits, EImPlotCondition Condition = EImPlotCondition::Once, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|ImPlot|Setup", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitSetupPlotAxisLimitsConstraints* CreateImPlotSetupAxisLimitsConstraints(EImPlotAxis Axis, double MinValue, double MaxValue, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|ImPlot|Setup", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitSetupPlotAxisZoomConstraints* CreateImPlotSetupAxisZoomConstraints(EImPlotAxis Axis, double MinZoom, double MaxZoom, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|ImPlot|Setup", meta = (ReturnDisplayName = "Element", AdvancedDisplay = "Labels,bKeepDefault"))
	static UImGuiToolkitSetupPlotAxisTicks* CreateImPlotSetupAxisTicks(EImPlotAxis Axis, TArray<float> Values, TArray<FText> Labels, bool bKeepDefault = false, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|ImPlot|Setup", meta = (ReturnDisplayName = "Element", AdvancedDisplay = "Labels,bKeepDefault"))
	static UImGuiToolkitSetupPlotAxisTicksRange* CreateImPlotSetupAxisTicksRange(EImPlotAxis Axis, double MinValue, double MaxValue, int32 TickCount, TArray<FText> Labels, bool bKeepDefault = false, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|ImPlot|Setup", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitSetupPlotFinish* CreateImPlotSetupFinish(UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|ImPlot|Setup", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitSetNextPlotAxisLimits* CreateImPlotSetNextAxisLimits(EImPlotAxis Axis, double MinValue, double MaxValue, EImPlotCondition Condition = EImPlotCondition::Once, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|ImPlot|Setup", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitSetNextPlotAxesLimits* CreateImPlotSetNextAxesLimits(FVector2D XLimits, FVector2D YLimits, EImPlotCondition Condition = EImPlotCondition::Once, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|ImPlot|Setup", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitSetNextPlotAxisToFit* CreateImPlotSetNextAxisToFit(EImPlotAxis Axis, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|ImPlot|Setup", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitSetNextPlotAxesToFit* CreateImPlotSetNextAxesToFit(UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|ImPlot|Setup", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitSetPlotAxis* CreateImPlotSetAxis(EImPlotAxis Axis, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|ImPlot|Setup", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitSetPlotAxes* CreateImPlotSetAxes(EImPlotAxis XAxis, EImPlotAxis YAxis, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|ImPlot|Setup", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitHideNextPlotItem* CreateImPlotHideNextItem(bool bHidden = true, EImPlotCondition Condition = EImPlotCondition::Once, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|ImPlot|Queries", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitPlotQuery* CreateImPlotQuery(EImPlotAxis XAxis = EImPlotAxis::X1, EImPlotAxis YAxis = EImPlotAxis::Y1, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|ImPlot|Queries", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitPlotAxisQuery* CreateImPlotAxisQuery(EImPlotAxis Axis, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|ImPlot|Queries", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitCancelPlotSelection* CreateImPlotCancelSelection(UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|ImPlot|Items", meta = (ReturnDisplayName = "Element", AdvancedDisplay = "XScale,XStart,StairsFlags,ItemFlags"))
	static UImGuiToolkitPlotStairs* CreateImPlotStairs(FText Label, TArray<float> Values, TArray<EImPlotStairsFlag> StairsFlags, TArray<EImPlotItemFlag> ItemFlags, double XScale = 1.0, double XStart = 0.0, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|ImPlot|Items", meta = (ReturnDisplayName = "Element", AdvancedDisplay = "StairsFlags,ItemFlags"))
	static UImGuiToolkitPlotStairsXY* CreateImPlotStairsXY(FText Label, TArray<float> XValues, TArray<float> YValues, TArray<EImPlotStairsFlag> StairsFlags, TArray<EImPlotItemFlag> ItemFlags, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|ImPlot|Items", meta = (ReturnDisplayName = "Element", AdvancedDisplay = "YReference,XScale,XStart,ItemFlags"))
	static UImGuiToolkitPlotShaded* CreateImPlotShaded(FText Label, TArray<float> Values, TArray<EImPlotItemFlag> ItemFlags, double YReference = 0.0, double XScale = 1.0, double XStart = 0.0, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|ImPlot|Items", meta = (ReturnDisplayName = "Element", AdvancedDisplay = "YReference,ItemFlags"))
	static UImGuiToolkitPlotShadedXY* CreateImPlotShadedXY(FText Label, TArray<float> XValues, TArray<float> YValues, TArray<EImPlotItemFlag> ItemFlags, double YReference = 0.0, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|ImPlot|Items", meta = (ReturnDisplayName = "Element", AdvancedDisplay = "ItemFlags"))
	static UImGuiToolkitPlotShadedBetweenXY* CreateImPlotShadedBetweenXY(FText Label, TArray<float> XValues, TArray<float> Y1Values, TArray<float> Y2Values, TArray<EImPlotItemFlag> ItemFlags, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|ImPlot|Items", meta = (ReturnDisplayName = "Element", AdvancedDisplay = "ErrorBarsFlags,ItemFlags"))
	static UImGuiToolkitPlotErrorBars* CreateImPlotErrorBars(FText Label, TArray<float> XValues, TArray<float> YValues, TArray<float> ErrorValues, TArray<EImPlotErrorBarsFlag> ErrorBarsFlags, TArray<EImPlotItemFlag> ItemFlags, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|ImPlot|Items", meta = (ReturnDisplayName = "Element", AdvancedDisplay = "ErrorBarsFlags,ItemFlags"))
	static UImGuiToolkitPlotErrorBarsNegPos* CreateImPlotErrorBarsNegPos(FText Label, TArray<float> XValues, TArray<float> YValues, TArray<float> NegativeErrorValues, TArray<float> PositiveErrorValues, TArray<EImPlotErrorBarsFlag> ErrorBarsFlags, TArray<EImPlotItemFlag> ItemFlags, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|ImPlot|Items", meta = (ReturnDisplayName = "Element", AdvancedDisplay = "Reference,XScale,XStart,StemsFlags,ItemFlags"))
	static UImGuiToolkitPlotStems* CreateImPlotStems(FText Label, TArray<float> Values, TArray<EImPlotStemsFlag> StemsFlags, TArray<EImPlotItemFlag> ItemFlags, double Reference = 0.0, double XScale = 1.0, double XStart = 0.0, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|ImPlot|Items", meta = (ReturnDisplayName = "Element", AdvancedDisplay = "Reference,StemsFlags,ItemFlags"))
	static UImGuiToolkitPlotStemsXY* CreateImPlotStemsXY(FText Label, TArray<float> XValues, TArray<float> YValues, TArray<EImPlotStemsFlag> StemsFlags, TArray<EImPlotItemFlag> ItemFlags, double Reference = 0.0, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|ImPlot|Items", meta = (ReturnDisplayName = "Element", AdvancedDisplay = "InfLinesFlags,ItemFlags"))
	static UImGuiToolkitPlotInfLines* CreateImPlotInfLines(FText Label, TArray<float> Values, TArray<EImPlotInfLinesFlag> InfLinesFlags, TArray<EImPlotItemFlag> ItemFlags, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|ImPlot|Items", meta = (ReturnDisplayName = "Element", AdvancedDisplay = "LabelFormat,Angle0,PieChartFlags,ItemFlags"))
	static UImGuiToolkitPlotPieChart* CreateImPlotPieChart(TArray<FText> Labels, TArray<float> Values, TArray<EImPlotPieChartFlag> PieChartFlags, TArray<EImPlotItemFlag> ItemFlags, FVector2D Center = FVector2D(0.0f, 0.0f), double Radius = 1.0, FString LabelFormat = TEXT("%.1f"), double Angle0 = 90.0, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|ImPlot|Items", meta = (ReturnDisplayName = "Element", AdvancedDisplay = "ScaleMin,ScaleMax,LabelFormat,BoundsMin,BoundsMax,HeatmapFlags,ItemFlags"))
	static UImGuiToolkitPlotHeatmap* CreateImPlotHeatmap(FText Label, TArray<float> Values, int32 Rows, int32 Columns, TArray<EImPlotHeatmapFlag> HeatmapFlags, TArray<EImPlotItemFlag> ItemFlags, double ScaleMin = 0.0, double ScaleMax = 0.0, FString LabelFormat = TEXT("%.1f"), FVector2D BoundsMin = FVector2D(0.0f, 0.0f), FVector2D BoundsMax = FVector2D(1.0f, 1.0f), UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|ImPlot|Items", meta = (ReturnDisplayName = "Element", AdvancedDisplay = "Bins,BarScale,bUseRange,Range,HistogramFlags,ItemFlags"))
	static UImGuiToolkitPlotHistogram* CreateImPlotHistogram(FText Label, TArray<float> Values, TArray<EImPlotHistogramFlag> HistogramFlags, TArray<EImPlotItemFlag> ItemFlags, int32 Bins = -2, double BarScale = 1.0, bool bUseRange = false, FVector2D Range = FVector2D(0.0f, 0.0f), UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|ImPlot|Items", meta = (ReturnDisplayName = "Element", AdvancedDisplay = "XBins,YBins,bUseRange,XRange,YRange,HistogramFlags,ItemFlags"))
	static UImGuiToolkitPlotHistogram2D* CreateImPlotHistogram2D(FText Label, TArray<float> XValues, TArray<float> YValues, TArray<EImPlotHistogramFlag> HistogramFlags, TArray<EImPlotItemFlag> ItemFlags, int32 XBins = -2, int32 YBins = -2, bool bUseRange = false, FVector2D XRange = FVector2D(0.0f, 0.0f), FVector2D YRange = FVector2D(0.0f, 0.0f), UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|ImPlot|Items", meta = (ReturnDisplayName = "Element", AdvancedDisplay = "ItemFlags"))
	static UImGuiToolkitPlotDigital* CreateImPlotDigital(FText Label, TArray<float> XValues, TArray<float> YValues, TArray<EImPlotItemFlag> ItemFlags, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|ImPlot|Items", meta = (ReturnDisplayName = "Element", AdvancedDisplay = "UV0,UV1,TintColor,ItemFlags"))
	static UImGuiToolkitPlotImage* CreateImPlotImage(FText Label, UTexture2D* Texture, FVector2D BoundsMin, FVector2D BoundsMax, TArray<EImPlotItemFlag> ItemFlags, FVector2D UV0 = FVector2D(0.0f, 0.0f), FVector2D UV1 = FVector2D(1.0f, 1.0f), FLinearColor TintColor = FLinearColor(1.0f, 1.0f, 1.0f, 1.0f), UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|ImPlot|Items", meta = (ReturnDisplayName = "Element", AdvancedDisplay = "UV0,UV1,TintColor,ItemFlags"))
	static UImGuiToolkitPlotImage* CreateImPlotMaterialImage(FText Label, UMaterialInterface* Material, FVector2D BoundsMin, FVector2D BoundsMax, TArray<EImPlotItemFlag> ItemFlags, FVector2D UV0 = FVector2D(0.0f, 0.0f), FVector2D UV1 = FVector2D(1.0f, 1.0f), FLinearColor TintColor = FLinearColor(1.0f, 1.0f, 1.0f, 1.0f), UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|ImPlot|Items", meta = (ReturnDisplayName = "Element", AdvancedDisplay = "PixelOffset,TextFlags,ItemFlags"))
	static UImGuiToolkitPlotText* CreateImPlotText(FText Text, FVector2D Position, TArray<EImPlotTextFlag> TextFlags, TArray<EImPlotItemFlag> ItemFlags, FVector2D PixelOffset = FVector2D(0.0f, 0.0f), UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|ImPlot|Items", meta = (ReturnDisplayName = "Element", AdvancedDisplay = "ItemFlags"))
	static UImGuiToolkitPlotDummy* CreateImPlotDummy(FText Label, TArray<EImPlotItemFlag> ItemFlags, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|ImPlot|Tools", meta = (ReturnDisplayName = "Element", AdvancedDisplay = "Size,DragToolFlags"))
	static UImGuiToolkitPlotDragPoint* CreateImPlotDragPoint(int32 ID, double X, double Y, FLinearColor Color, TArray<EImPlotDragToolFlag> DragToolFlags, float Size = 4.0f, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|ImPlot|Tools", meta = (ReturnDisplayName = "Element", AdvancedDisplay = "Thickness,DragToolFlags"))
	static UImGuiToolkitPlotDragLineX* CreateImPlotDragLineX(int32 ID, double X, FLinearColor Color, TArray<EImPlotDragToolFlag> DragToolFlags, float Thickness = 1.0f, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|ImPlot|Tools", meta = (ReturnDisplayName = "Element", AdvancedDisplay = "Thickness,DragToolFlags"))
	static UImGuiToolkitPlotDragLineY* CreateImPlotDragLineY(int32 ID, double Y, FLinearColor Color, TArray<EImPlotDragToolFlag> DragToolFlags, float Thickness = 1.0f, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|ImPlot|Tools", meta = (ReturnDisplayName = "Element", AdvancedDisplay = "DragToolFlags"))
	static UImGuiToolkitPlotDragRect* CreateImPlotDragRect(int32 ID, double X1, double Y1, double X2, double Y2, FLinearColor Color, TArray<EImPlotDragToolFlag> DragToolFlags, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|ImPlot|Annotations", meta = (ReturnDisplayName = "Element", AdvancedDisplay = "PixelOffset,bClamp,bRound"))
	static UImGuiToolkitPlotAnnotation* CreateImPlotAnnotation(FText Text, FVector2D Position, FLinearColor Color, FVector2D PixelOffset = FVector2D(0.0f, 0.0f), bool bClamp = false, bool bRound = false, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|ImPlot|Annotations", meta = (ReturnDisplayName = "Element", AdvancedDisplay = "Text,bRound"))
	static UImGuiToolkitPlotTagX* CreateImPlotTagX(double X, FLinearColor Color, FText Text = FText::GetEmpty(), bool bRound = false, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|ImPlot|Annotations", meta = (ReturnDisplayName = "Element", AdvancedDisplay = "Text,bRound"))
	static UImGuiToolkitPlotTagY* CreateImPlotTagY(double Y, FLinearColor Color, FText Text = FText::GetEmpty(), bool bRound = false, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|ImPlot|Style", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitPushPlotStyleColor* CreateImPlotPushStyleColor(EImPlotStyleColor StyleColor, FLinearColor Color, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|ImPlot|Style", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitPopPlotStyleColor* CreateImPlotPopStyleColor(int32 Count = 1, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|ImPlot|Style", meta = (ReturnDisplayName = "Element", AdvancedDisplay = "FloatValue,IntValue,Vector2DValue"))
	static UImGuiToolkitPushPlotStyleVar* CreateImPlotPushStyleVar(EImPlotStyleVar StyleVar, float FloatValue = 1.0f, int32 IntValue = 0, FVector2D Vector2DValue = FVector2D(1.0f, 1.0f), UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|ImPlot|Style", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitPopPlotStyleVar* CreateImPlotPopStyleVar(int32 Count = 1, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|ImPlot|Style", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitSetNextPlotLineStyle* CreateImPlotSetNextLineStyle(FLinearColor Color, float Weight = 1.0f, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|ImPlot|Style", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitSetNextPlotFillStyle* CreateImPlotSetNextFillStyle(FLinearColor Color, float AlphaMod = 1.0f, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|ImPlot|Style", meta = (ReturnDisplayName = "Element", AdvancedDisplay = "Size,Weight,OutlineColor"))
	static UImGuiToolkitSetNextPlotMarkerStyle* CreateImPlotSetNextMarkerStyle(EImPlotMarker Marker, FLinearColor FillColor, FLinearColor OutlineColor, float Size = 4.0f, float Weight = 1.0f, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|ImPlot|Style", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitSetNextPlotErrorBarStyle* CreateImPlotSetNextErrorBarStyle(FLinearColor Color, float Size = 5.0f, float Weight = 1.0f, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|ImPlot|Style", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitStylePlotColors* CreateImPlotStyleColors(EImPlotStylePreset Preset = EImPlotStylePreset::Auto, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|ImPlot|Colormap", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitPushPlotColormap* CreateImPlotPushColormap(EImPlotColormap Colormap, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|ImPlot|Colormap", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitPopPlotColormap* CreateImPlotPopColormap(int32 Count = 1, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|ImPlot|Colormap", meta = (ReturnDisplayName = "Element", AdvancedDisplay = "Size,Format,Colormap,ColormapScaleFlags"))
	static UImGuiToolkitPlotColormapScale* CreateImPlotColormapScale(FText Label, double ScaleMin, double ScaleMax, TArray<EImPlotColormapScaleFlag> ColormapScaleFlags, FVector2D Size = FVector2D(0.0f, 0.0f), FString Format = TEXT("%g"), EImPlotColormap Colormap = EImPlotColormap::Deep, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|ImPlot|Colormap", meta = (ReturnDisplayName = "Element", AdvancedDisplay = "Format,Colormap"))
	static UImGuiToolkitPlotColormapSlider* CreateImPlotColormapSlider(FText Label, float Value = 0.0f, FString Format = TEXT(""), EImPlotColormap Colormap = EImPlotColormap::Deep, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|ImPlot|Colormap", meta = (ReturnDisplayName = "Element", AdvancedDisplay = "Size,Colormap"))
	static UImGuiToolkitPlotColormapButton* CreateImPlotColormapButton(FText Label, FVector2D Size = FVector2D(0.0f, 0.0f), EImPlotColormap Colormap = EImPlotColormap::Deep, UImGuiToolkitContainer* Container = nullptr);

	// Create a TabBar
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (ReturnDisplayName = "Container"))
	static UImGuiToolkitBeginTabBar* CreateImGuiBeginTabBar(FText Label, UImGuiToolkitContainer* Container = nullptr);

	// End a TabBar
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (DeprecatedFunction, DeprecationMessage = "End widgets are no longer required. ImGuiToolkit container widgets close themselves during Render.", ReturnDisplayName = "Element"))
	static UImGuiToolkitEndTabBar* EndImGuiTabBar(UImGuiToolkitContainer* Container = nullptr);

	// Create a TabItem
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (ReturnDisplayName = "Container"))
	static UImGuiToolkiBeginTabItem* CreateImGuiBeginTabItem(FText Label, UImGuiToolkitContainer* Container = nullptr);

	// End a TabItem
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (DeprecatedFunction, DeprecationMessage = "End widgets are no longer required. ImGuiToolkit container widgets close themselves during Render.", ReturnDisplayName = "Element"))
	static UImGuiToolkitEndTabItem* EndImGuiTabItem(UImGuiToolkitContainer* Container = nullptr);

	// Create a ComboBox
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitCombo* CreateImGuiCombo(FText Label, TArray<FText> ComboItems, UImGuiToolkitContainer* Container);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (ReturnDisplayName = "Container"))
	static UImGuiToolkitBeginCombo* CreateImGuiBeginCombo(FText Label, FText PreviewValue, TArray<EImGuiComboFlag> ComboFlags, UImGuiToolkitContainer* Container = nullptr);

	// Create a DragInt
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitDragInt* CreateImGuiDragInt(FText Label, int32 InitialValue, int32 MinValue, int32 MaxValue, float Speed = 1.0f, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitDragIntPoint* CreateImGuiDragIntPoint(FText Label, FIntPoint InitialValue, int32 MinValue, int32 MaxValue, float Speed = 1.0f, FString Format = "%d", UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitDragIntVector* CreateImGuiDragIntVector(FText Label, FIntVector InitialValue, int32 MinValue, int32 MaxValue, float Speed = 1.0f, FString Format = "%d", UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitDragIntVector4* CreateImGuiDragIntVector4(FText Label, FIntVector4 InitialValue, int32 MinValue, int32 MaxValue, float Speed = 1.0f, FString Format = "%d", UImGuiToolkitContainer* Container = nullptr);

	// Create a Separator
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitSeparator* CreateImGuiSeparator(UImGuiToolkitContainer* Container = nullptr);

	// Create a NewLine
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitNewLine* CreateImGuiNewLine(UImGuiToolkitContainer* Container = nullptr);

	// Create a Dummy with a certain size
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitDummy* CreateImGuiDummy(FVector2D Size, UImGuiToolkitContainer* Container = nullptr);

	// Create a TextColored
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitTextColored* CreateImGuiTextColored(FLinearColor Color, FText Text, UImGuiToolkitContainer* Container = nullptr);

	// Create a TextWrapped
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitTextWrapped* CreateImGuiTextWrapped(FText Text, UImGuiToolkitContainer* Container = nullptr);

	// Create a SmallButton
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitSmallButton* CreateImGuiSmallButton(FText Label, FText Tooltip, UImGuiToolkitContainer* Container = nullptr);

	// Create an ArrowButton
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitArrowButton* CreateImGuiArrowButton(EImGuiToolkitDir CardinalDirection, UImGuiToolkitContainer* Container = nullptr);

	// Create a RadioButtons
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitRadioButtonGroup* CreateImGuiRadioButtonGroup(TArray<FText> RadioButtonLabels, int32 InitialIndex, EImGuiToolkitRadioButtonDirection Direction, UImGuiToolkitContainer* Container = nullptr);

	// Create a ProgressBar
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitProgressBar* CreateImGuiProgressBar(float Percent, FVector2D Size, UImGuiToolkitContainer* Container = nullptr);

	// Create a Bullet
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitBullet* CreateImGuiBullet(UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|Style", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitBeginDisabled* CreateImGuiBeginDisabled(bool bDisabled = true, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|Style", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitEndDisabled* CreateImGuiEndDisabled(UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|Style", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitPushStyleColor* CreateImGuiPushStyleColor(EImGuiStyleColor StyleColor, FLinearColor Color, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|Style", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitPopStyleColor* CreateImGuiPopStyleColor(int32 Count = 1, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|Style", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitPushStyleVar* CreateImGuiPushStyleVar(EImGuiStyleVar StyleVar, float FloatValue = 1.0f, FVector2D Vector2DValue = FVector2D(0.0f, 0.0f), UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|Style", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitPopStyleVar* CreateImGuiPopStyleVar(int32 Count = 1, UImGuiToolkitContainer* Container = nullptr);

	// Create a Text Link Open URL.
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitTextLinkOpenURL* CreateTextLinkOpenURL(FText Text, FString URL, UImGuiToolkitContainer* Container = nullptr);

	// Create a DragFloat
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitDragFloat* CreateImGuiDragFloat(FText Label, float InitialValue, float MinValue, float MaxValue, float Speed = 1.0f, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitDragVector2D* CreateImGuiDragVector2D(FText Label, FVector2D InitialValue, float MinValue, float MaxValue, float Speed = 1.0f, FString Format = "%.3f", UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitDragVector* CreateImGuiDragVector(FText Label, FVector InitialValue, float MinValue, float MaxValue, float Speed = 1.0f, FString Format = "%.3f", UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitDragVector4* CreateImGuiDragVector4(FText Label, FVector4 InitialValue, float MinValue, float MaxValue, float Speed = 1.0f, FString Format = "%.3f", UImGuiToolkitContainer* Container = nullptr);

	// Create a SliderFloat. Format example: "$ %.2f" = "$ 19.99" ($ Prefix + 2 decimals) "%.1f km" = "1.5 km"
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitSliderFloat* CreateImGuiSliderFloat(FText Label, float Value, float MinValue, float MaxValue, FString Format = "%.3f", UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitSliderVector2D* CreateImGuiSliderVector2D(FText Label, FVector2D Value, float MinValue, float MaxValue, FString Format = "%.3f", UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitSliderVector* CreateImGuiSliderVector(FText Label, FVector Value, float MinValue, float MaxValue, FString Format = "%.3f", UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitSliderVector4* CreateImGuiSliderVector4(FText Label, FVector4 Value, float MinValue, float MaxValue, FString Format = "%.3f", UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitSliderAngle* CreateImGuiSliderAngle(FText Label, float AngleDegrees, float MinDegrees, float MaxDegrees, FString Format = "%.0f deg", UImGuiToolkitContainer* Container = nullptr);

	// Create a SliderInt. Format example: "$ %d" = "$ 10" ($ Prefix) "%d km" = "5 km"
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitSliderInt* CreateImGuiSliderInt(FText Label, int32 Value, int32 MinValue, int32 MaxValue, FString Format = "%d", UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitVerticalSliderFloat* CreateImGuiVerticalSliderFloat(FText Label, float Value, float MinValue, float MaxValue, FVector2D Size = FVector2D(18.0f, 160.0f), FString Format = "%.3f", UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitVerticalSliderInt* CreateImGuiVerticalSliderInt(FText Label, int32 Value, int32 MinValue, int32 MaxValue, FVector2D Size = FVector2D(18.0f, 160.0f), FString Format = "%d", UImGuiToolkitContainer* Container = nullptr);

	// Create a MenuBar. Requires "MenuBar" WindowFlag for window that contains this MenuBar.
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (ReturnDisplayName = "Container"))
	static UImGuiToolkitBeginMenuBar* CreateImGuiBeginMenuBar(FText Label, UImGuiToolkitContainer* Container = nullptr);

	// Create a Menu
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (ReturnDisplayName = "Container"))
	static UImGuiToolkitBeginMenu* CreateImGuiBeginMenu(FText Label, UImGuiToolkitContainer* Container = nullptr);

	// Create a MenuItem
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitMenuItem* CreateImGuiMenuItem(FText Label, FText Shortcut, bool bIsSelected, UImGuiToolkitContainer* Container = nullptr);

	// End a MenuBar
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (DeprecatedFunction, DeprecationMessage = "End widgets are no longer required. ImGuiToolkit container widgets close themselves during Render.", ReturnDisplayName = "Element"))
	static UImGuiToolkitEndMenuBar* EndImGuiMenuBar(UImGuiToolkitContainer* Container = nullptr);

	// End a Menu
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (DeprecatedFunction, DeprecationMessage = "End widgets are no longer required. ImGuiToolkit container widgets close themselves during Render.", ReturnDisplayName = "Element"))
	static UImGuiToolkitEndMenu* EndImGuiMenu(UImGuiToolkitContainer* Container = nullptr);

	// Create an InputText
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitInputText* CreateImGuiInputText(FText Label, FText PreviewText, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitInputTextWithHint* CreateImGuiInputTextWithHint(FText Label, FText Hint, FText PreviewText, UImGuiToolkitContainer* Container = nullptr);

	// Create an InputTextMultiline
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitInputTextMultiline* CreateImGuiInputTextMultiline(FText Label, FText PreviewText, FVector2D TextBoxSize, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitInputFloat* CreateImGuiInputFloat(FText Label, float PreviewFloat, FString Format = "%.2f", UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitInputDouble* CreateImGuiInputDouble(FText Label, double PreviewDouble, FString Format = "%.6f", UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitInputVector2D* CreateImGuiInputVector2D(FText Label, FVector2D PreviewVector2D, FString Format = "%.3f", UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitInputVector* CreateImGuiInputVector(FText Label, FVector PreviewVector, FString Format = "%.3f", UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitInputVector4* CreateImGuiInputVector4(FText Label, FVector4 PreviewVector4, FString Format = "%.3f", UImGuiToolkitContainer* Container = nullptr);

	// Create an InputInt
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitInputInt* CreateImGuiInputInt(FText Label, int32 PreviewInt, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitInputInt2* CreateImGuiInputInt2(FText Label, FIntPoint PreviewInt2, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitInputInt3* CreateImGuiInputInt3(FText Label, FIntVector PreviewInt3, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitInputInt4* CreateImGuiInputInt4(FText Label, FIntVector4 PreviewInt4, UImGuiToolkitContainer* Container = nullptr);

	
private:
	// Uses the supplied owner when available, otherwise falls back to the engine subsystem for editor-time objects.
	static UObject* GetValidOuterObject(UObject* OuterCandidate);

};
