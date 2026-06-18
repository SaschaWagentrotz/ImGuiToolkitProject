#pragma once

#include "CoreMinimal.h"
#include "Components/Widget.h"
#include "FImGuiToolkitUtils.h"
#include "Widgets/TabBar/ImGuiToolkiBeginTabItem.h"
#include "Containers/ImGuiToolkitBeginChild.h"
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
#include "Widgets/Input/ImGuiToolkitInputInt.h"
#include "Widgets/Input/ImGuiToolkitInputText.h"
#include "Widgets/Input/ImGuiToolkitInputTextMultiline.h"
#include "Widgets/Layout/ImGuiToolkitAlignTextToFramePadding.h"
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
#include "Widgets/Sliders/ImGuiToolkitDragInt.h"
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
#include "Widgets/Text/ImGuiToolkitTextColored.h"
#include "Widgets/Text/ImGuiToolkitTextLinkOpenURL.h"
#include "Widgets/Text/ImGuiToolkitTextWrapped.h"
#include "Widgets/Sliders/ImGuiToolkitDragFloat.h"
#include "Widgets/Sliders/ImGuiToolkitSliderFloat.h"
#include "Widgets/Sliders/ImGuiToolkitSliderInt.h"
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
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitSetItemTooltip* CreateImGuiSetItemTooltip(FText Text, UImGuiToolkitContainer* Container = nullptr);

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

	// Create a DragInt
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitDragInt* CreateImGuiDragInt(FText Label, int32 InitialValue, int32 MinValue, int32 MaxValue, float Speed = 1.0f, UImGuiToolkitContainer* Container = nullptr);

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

	// Create a Text Link Open URL.
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitTextLinkOpenURL* CreateTextLinkOpenURL(FText Text, FString URL, UImGuiToolkitContainer* Container = nullptr);

	// Create a DragFloat
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitDragFloat* CreateImGuiDragFloat(FText Label, float InitialValue, float MinValue, float MaxValue, float Speed = 1.0f, UImGuiToolkitContainer* Container = nullptr);

	// Create a SliderFloat. Format example: "$ %.2f" = "$ 19.99" ($ Prefix + 2 decimals) "%.1f km" = "1.5 km"
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitSliderFloat* CreateImGuiSliderFloat(FText Label, float Value, float MinValue, float MaxValue, FText Format, UImGuiToolkitContainer* Container = nullptr);

	// Create a SliderInt. Format example: "$ %d" = "$ 10" ($ Prefix) "%d km" = "5 km"
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitSliderInt* CreateImGuiSliderInt(FText Label, int32 Value, int32 MinValue, int32 MaxValue, FText Format, UImGuiToolkitContainer* Container = nullptr);

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

	// Create an InputTextMultiline
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitInputTextMultiline* CreateImGuiInputTextMultiline(FText Label, FText PreviewText, FVector2D TextBoxSize, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitInputFloat* CreateImGuiInputFloat(FText Label, float PreviewFloat, FString Format = "%.2f", UImGuiToolkitContainer* Container = nullptr);

	// Create an InputInt
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (ReturnDisplayName = "Element"))
	static UImGuiToolkitInputInt* CreateImGuiInputInt(FText Label, int32 PreviewInt, UImGuiToolkitContainer* Container = nullptr);

	
private:
	// Uses the supplied owner when available, otherwise falls back to the engine subsystem for editor-time objects.
	static UObject* GetValidOuterObject(UObject* OuterCandidate);

};
