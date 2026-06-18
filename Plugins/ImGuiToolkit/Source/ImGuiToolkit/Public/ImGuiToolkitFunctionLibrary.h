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
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, HidePin = "WorldContextObject"))
	static UImGuiToolkitWindow* CreateImGuiWindow(UObject* WorldContextObject, FText WindowTitle, TArray<EImGuiWindowFlag> WindowFlags);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, HidePin = "WorldContextObject"))
	static UImGuiToolkitBeginChild* CreateImGuiBeginChild(UObject* WorldContextObject, FText Label, FVector2D Size, TArray<EImGuiChildFlag> ChildFlags, TArray<EImGuiWindowFlag> WindowFlags, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, HidePin = "WorldContextObject"))
	static UImGuiToolkitBeginGroup* CreateImGuiBeginGroup(UObject* WorldContextObject, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, HidePin = "WorldContextObject"))
	static UImGuiToolkitBeginListBox* CreateImGuiBeginListBox(UObject* WorldContextObject, FText Label, FVector2D Size = FVector2D(0, 0), UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, HidePin = "WorldContextObject", DeprecatedFunction, DeprecationMessage = "End widgets are no longer required. ImGuiToolkit container widgets close themselves during Render."))
	static UImGuiToolkitEndListBox* EndImGuiListBox(UObject* WorldContextObject, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, HidePin = "WorldContextObject"))
	static UImGuiToolkitListBox* CreateImGuiListBox(UObject* WorldContextObject, FText Label, TArray<FText> ListItems, int32 InitialIndex = 0, int32 HeightInItems = -1, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, HidePin = "WorldContextObject"))
	static UImGuiToolkitPushItemWidth* CreateImGuiPushItemWidth(UObject* WorldContextObject, float ItemWidth, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, HidePin = "WorldContextObject"))
	static UImGuiToolkitPopItemWidth* CreateImGuiPopItemWidth(UObject* WorldContextObject, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, HidePin = "WorldContextObject"))
	static UImGuiToolkitSetNextItemWidth* CreateImGuiSetNextItemWidth(UObject* WorldContextObject, float ItemWidth, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, HidePin = "WorldContextObject"))
	static UImGuiToolkitPushTextWrapPos* CreateImGuiPushTextWrapPos(UObject* WorldContextObject, float WrapLocalPosX = 0.0f, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, HidePin = "WorldContextObject"))
	static UImGuiToolkitPopTextWrapPos* CreateImGuiPopTextWrapPos(UObject* WorldContextObject, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, HidePin = "WorldContextObject"))
	static FVector2D GetWidgetPosition(UObject* WorldContextObject, UWidget* Widget);

	// Destroy an ImGui window
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, HidePin = "WorldContextObject"))
	static void DestroyImGuiWindow(UObject* WorldContextObject, UImGuiToolkitWindow* Window);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|Docking", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, HidePin = "WorldContextObject", ClampMin = "0.05", ClampMax = "0.95", UIMin = "0.05", UIMax = "0.95"))
	static void DockImGuiWindow(UObject* WorldContextObject, UImGuiToolkitWindow* WindowToDock, UImGuiToolkitWindow* TargetWindow, EImGuiToolkitDockSplitDirection Direction = EImGuiToolkitDockSplitDirection::Center, float SplitRatio = 0.5f);

	// Create a SameLine
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, HidePin = "WorldContextObject"))
	static UImGuiToolkitSameLine* CreateImGuiSameLine(UObject* WorldContextObject, float OffsetFromStartX = 0.0f, float Spacing = -1.0f, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, HidePin = "WorldContextObject", ToolTip = ""))
	static UImGuiToolkitButton* CreateImGuiButton(UObject* WorldContextObject, FText Label, FText Tooltip = FText::GetEmpty(), FVector2D Size = FVector2D(0, 0), UImGuiToolkitContainer* Container = nullptr);

	// Create a HelpMarker with a tooltip
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, HidePin = "WorldContextObject"))
	static UImGuiToolkitHelpMarker* CreateImGuiHelpMarker(UObject* WorldContextObject, FText Text, UImGuiToolkitContainer* Container = nullptr);

	// Create a Tooltip
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, HidePin = "WorldContextObject"))
	static UImGuiToolkitSetItemTooltip* CreateImGuiSetItemTooltip(UObject* WorldContextObject, FText Text, UImGuiToolkitContainer* Container = nullptr);
	
	// Create a CollapsingHeader
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, HidePin = "WorldContextObject"))
	static UImGuiToolkitCollapsingHeader* CreateImGuiCollapsingHeader(UObject* WorldContextObject, FText Label, UImGuiToolkitContainer* Container = nullptr);

	// Create a Text
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, HidePin = "WorldContextObject"))
	static UImGuiToolkitText* CreateImGuiText(UObject* WorldContextObject, FText Text, UImGuiToolkitContainer* Container = nullptr);

	// Use AlignTextToFramePadding() to align text baseline to the baseline of framed widgets elements, otherwise a Text+SameLine+Button sequence will have the text a little too high by default.
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, HidePin = "WorldContextObject"))
	static UImGuiToolkitAlignTextToFramePadding* CreateImGuiAlignTextToFramePadding(UObject* WorldContextObject, UImGuiToolkitContainer* Container = nullptr);
	
	// Create a Text Disabled
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, HidePin = "WorldContextObject"))
	static UImGuiToolkitTextDisabled* CreateImGuiTextDisabled(UObject* WorldContextObject, FText Text, UImGuiToolkitContainer* Container = nullptr);
	
	// Create a Separator Text
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, HidePin = "WorldContextObject"))
	static UImGuiToolkitSeparatorText* CreateImGuiSeparatorText(UObject* WorldContextObject, FText Text, UImGuiToolkitContainer* Container = nullptr);

	// Create a Bullet Text
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, HidePin = "WorldContextObject"))
	static UImGuiToolkitBulletText* CreateImGuiBulletText(UObject* WorldContextObject, FText Text, UImGuiToolkitContainer* Container = nullptr);

	// Create a Label Text
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, HidePin = "WorldContextObject"))
	static UImGuiToolkitLabelText* CreateImGuiLabelText(UObject* WorldContextObject, FText LeftText, FText RightText, UImGuiToolkitContainer* Container = nullptr);
	
	// Create a Spacing
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, HidePin = "WorldContextObject"))
	static UImGuiToolkitSpacing* CreateImGuiSpacing(UObject* WorldContextObject, UImGuiToolkitContainer* Container = nullptr);

	// Create an Indent
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, HidePin = "WorldContextObject"))
	static UImGuiToolkitIndent* CreateImGuiIndent(UObject* WorldContextObject, UImGuiToolkitContainer* Container = nullptr);

	// Create an Unindent
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, HidePin = "WorldContextObject"))
	static UImGuiToolkitUnindent* CreateImGuiUnindent(UObject* WorldContextObject, UImGuiToolkitContainer* Container = nullptr);

	// Create a TreeNode
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, HidePin = "WorldContextObject"))
	static UImGuiToolkitTreeNode* CreateImGuiTreeNode(UObject* WorldContextObject, FText Label, UImGuiToolkitContainer* Container = nullptr);

	// Create a TreePush
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, HidePin = "WorldContextObject"))
	static UImGuiToolkitTreePush* CreateImGuiTreePush(UObject* WorldContextObject, FText Label, UImGuiToolkitContainer* Container = nullptr);

	// Create a TreePop
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, HidePin = "WorldContextObject"))
	static UImGuiToolkitTreePop* CreateImGuiTreePop(UObject* WorldContextObject, UImGuiToolkitContainer* Container = nullptr);

	// Create a Checkbox
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, HidePin = "WorldContextObject"))
	static UImGuiToolkitCheckbox* CreateImGuiCheckbox(UObject* WorldContextObject, FText Label, FText Tooltip, bool bIsChecked, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, HidePin = "WorldContextObject"))
	static UImGuiToolkitSelectable* CreateImGuiSelectable(UObject* WorldContextObject, FText Label, bool bIsSelected, TArray<EImGuiSelectableFlag> SelectableFlags, FVector2D Size = FVector2D(0, 0), FText Tooltip = FText::GetEmpty(), UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|Tables", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, HidePin = "WorldContextObject", ClampMin = "1", UIMin = "1"))
	static UImGuiToolkitBeginTable* CreateImGuiBeginTable(UObject* WorldContextObject, FText Label, int32 ColumnCount, TArray<EImGuiTableFlag> TableFlags, FVector2D OuterSize = FVector2D(0, 0), float InnerWidth = 0.0f, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|Tables", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, HidePin = "WorldContextObject"))
	static UImGuiToolkitTableSetupColumn* CreateImGuiTableSetupColumn(UObject* WorldContextObject, FText Label, TArray<EImGuiTableColumnFlag> ColumnFlags, float InitialWidthOrWeight = 0.0f, int32 UserID = 0, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|Tables", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, HidePin = "WorldContextObject", ClampMin = "0", UIMin = "0"))
	static UImGuiToolkitTableSetupScrollFreeze* CreateImGuiTableSetupScrollFreeze(UObject* WorldContextObject, int32 FrozenColumnCount = 0, int32 FrozenRowCount = 0, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|Tables", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, HidePin = "WorldContextObject"))
	static UImGuiToolkitTableHeadersRow* CreateImGuiTableHeadersRow(UObject* WorldContextObject, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|Tables", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, HidePin = "WorldContextObject"))
	static UImGuiToolkitTableHeader* CreateImGuiTableHeader(UObject* WorldContextObject, FText Label, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|Tables", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, HidePin = "WorldContextObject"))
	static UImGuiToolkitTableNextRow* CreateImGuiTableNextRow(UObject* WorldContextObject, TArray<EImGuiTableRowFlag> RowFlags, float MinimumRowHeight = 0.0f, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|Tables", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, HidePin = "WorldContextObject"))
	static UImGuiToolkitTableNextColumn* CreateImGuiTableNextColumn(UObject* WorldContextObject, UImGuiToolkitContainer* Container = nullptr);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit|Tables", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, HidePin = "WorldContextObject", ClampMin = "0", UIMin = "0"))
	static UImGuiToolkitTableSetColumnIndex* CreateImGuiTableSetColumnIndex(UObject* WorldContextObject, int32 ColumnIndex, UImGuiToolkitContainer* Container = nullptr);

	// Create a TabBar
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext , HidePin = "WorldContextObject"))
	static UImGuiToolkitBeginTabBar* CreateImGuiBeginTabBar(UObject* WorldContextObject, FText Label, UImGuiToolkitContainer* Container = nullptr);

	// End a TabBar
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, HidePin = "WorldContextObject", DeprecatedFunction, DeprecationMessage = "End widgets are no longer required. ImGuiToolkit container widgets close themselves during Render."))
	static UImGuiToolkitEndTabBar* EndImGuiTabBar(UObject* WorldContextObject, UImGuiToolkitContainer* Container = nullptr);

	// Create a TabItem
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, HidePin = "WorldContextObject"))
	static UImGuiToolkiBeginTabItem* CreateImGuiBeginTabItem(UObject* WorldContextObject, FText Label, UImGuiToolkitContainer* Container = nullptr);

	// End a TabItem
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, HidePin = "WorldContextObject", DeprecatedFunction, DeprecationMessage = "End widgets are no longer required. ImGuiToolkit container widgets close themselves during Render."))
	static UImGuiToolkitEndTabItem* EndImGuiTabItem(UObject* WorldContextObject, UImGuiToolkitContainer* Container = nullptr);

	// Create a ComboBox
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, HidePin = "WorldContextObject"))
	static UImGuiToolkitCombo* CreateImGuiCombo(UObject* WorldContextObject, FText Label, TArray<FText> ComboItems, UImGuiToolkitContainer* Container);

	// Create a DragInt
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, HidePin = "WorldContextObject"))
	static UImGuiToolkitDragInt* CreateImGuiDragInt(UObject* WorldContextObject, FText Label, int32 InitialValue, int32 MinValue, int32 MaxValue, float Speed = 1.0f, UImGuiToolkitContainer* Container = nullptr);

	// Create a Separator
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, HidePin = "WorldContextObject"))
	static UImGuiToolkitSeparator* CreateImGuiSeparator(UObject* WorldContextObject, UImGuiToolkitContainer* Container = nullptr);

	// Create a NewLine
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, HidePin = "WorldContextObject"))
	static UImGuiToolkitNewLine* CreateImGuiNewLine(UObject* WorldContextObject, UImGuiToolkitContainer* Container = nullptr);

	// Create a Dummy with a certain size
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, HidePin = "WorldContextObject"))
	static UImGuiToolkitDummy* CreateImGuiDummy(UObject* WorldContextObject, FVector2D Size, UImGuiToolkitContainer* Container = nullptr);

	// Create a TextColored
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, HidePin = "WorldContextObject"))
	static UImGuiToolkitTextColored* CreateImGuiTextColored(UObject* WorldContextObject, FLinearColor Color, FText Text, UImGuiToolkitContainer* Container = nullptr);

	// Create a TextWrapped
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, HidePin = "WorldContextObject"))
	static UImGuiToolkitTextWrapped* CreateImGuiTextWrapped(UObject* WorldContextObject, FText Text, UImGuiToolkitContainer* Container = nullptr);

	// Create a SmallButton
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, HidePin = "WorldContextObject"))
	static UImGuiToolkitSmallButton* CreateImGuiSmallButton(UObject* WorldContextObject, FText Label, FText Tooltip, UImGuiToolkitContainer* Container = nullptr);

	// Create an ArrowButton
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, HidePin = "WorldContextObject"))
	static UImGuiToolkitArrowButton* CreateImGuiArrowButton(UObject* WorldContextObject, EImGuiToolkitDir CardinalDirection, UImGuiToolkitContainer* Container = nullptr);

	// Create a RadioButtons
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, HidePin = "WorldContextObject"))
	static UImGuiToolkitRadioButtonGroup* CreateImGuiRadioButtonGroup(UObject* WorldContextObject, TArray<FText> RadioButtonLabels, int32 InitialIndex, EImGuiToolkitRadioButtonDirection Direction, UImGuiToolkitContainer* Container = nullptr);
	
	// Create a ProgressBar
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, HidePin = "WorldContextObject"))
	static UImGuiToolkitProgressBar* CreateImGuiProgressBar(UObject* WorldContextObject, float Percent, FVector2D Size, UImGuiToolkitContainer* Container = nullptr);

	// Create a Bullet
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, HidePin = "WorldContextObject"))
	static UImGuiToolkitBullet* CreateImGuiBullet(UObject* WorldContextObject, UImGuiToolkitContainer* Container = nullptr);

	// Create a Text Link Open URL.
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, HidePin = "WorldContextObject"))
	static UImGuiToolkitTextLinkOpenURL* CreateTextLinkOpenURL(UObject* WorldContextObject, FText Text, FString URL, UImGuiToolkitContainer* Container = nullptr);

	// Create a DragFloat
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, HidePin = "WorldContextObject"))
	static UImGuiToolkitDragFloat* CreateImGuiDragFloat(UObject* WorldContextObject, FText Label, float InitialValue, float MinValue, float MaxValue, float Speed = 1.0f, UImGuiToolkitContainer* Container = nullptr);

	// Create a SliderFloat. Format example: "$ %.2f" = "$ 19.99" ($ Prefix + 2 decimals) "%.1f km" = "1.5 km"
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, HidePin = "WorldContextObject"))
	static UImGuiToolkitSliderFloat* CreateImGuiSliderFloat(UObject* WorldContextObject, FText Label, float Value, float MinValue, float MaxValue, FText Format, UImGuiToolkitContainer* Container = nullptr);

	// Create a SliderInt. Format example: "$ %d" = "$ 10" ($ Prefix) "%d km" = "5 km"
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, HidePin = "WorldContextObject"))
	static UImGuiToolkitSliderInt* CreateImGuiSliderInt(UObject* WorldContextObject, FText Label, int32 Value, int32 MinValue, int32 MaxValue, FText Format, UImGuiToolkitContainer* Container = nullptr);

	// Create a MenuBar. Requires "MenuBar" WindowFlag for window that contains this MenuBar.
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, HidePin = "WorldContextObject"))
	static UImGuiToolkitBeginMenuBar* CreateImGuiBeginMenuBar(UObject* WorldContextObject, FText Label, UImGuiToolkitContainer* Container = nullptr);

	// Create a Menu
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, HidePin = "WorldContextObject"))
	static UImGuiToolkitBeginMenu* CreateImGuiBeginMenu(UObject* WorldContextObject, FText Label, UImGuiToolkitContainer* Container = nullptr);

	// Create a MenuItem
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, HidePin = "WorldContextObject"))
	static UImGuiToolkitMenuItem* CreateImGuiMenuItem(UObject* WorldContextObject, FText Label, FText Shortcut, bool bIsSelected, UImGuiToolkitContainer* Container = nullptr);

	// End a MenuBar
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, HidePin = "WorldContextObject", DeprecatedFunction, DeprecationMessage = "End widgets are no longer required. ImGuiToolkit container widgets close themselves during Render."))
	static UImGuiToolkitEndMenuBar* EndImGuiMenuBar(UObject* WorldContextObject, UImGuiToolkitContainer* Container = nullptr);

	// End a Menu
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, HidePin = "WorldContextObject", DeprecatedFunction, DeprecationMessage = "End widgets are no longer required. ImGuiToolkit container widgets close themselves during Render."))
	static UImGuiToolkitEndMenu* EndImGuiMenu(UObject* WorldContextObject, UImGuiToolkitContainer* Container = nullptr);

	// Create an InputText
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, HidePin = "WorldContextObject"))
	static UImGuiToolkitInputText* CreateImGuiInputText(UObject* WorldContextObject, FText Label, FText PreviewText, UImGuiToolkitContainer* Container = nullptr);

	// Create an InputTextMultiline
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, HidePin = "WorldContextObject"))
	static UImGuiToolkitInputTextMultiline* CreateImGuiInputTextMultiline(UObject* WorldContextObject, FText Label, FText PreviewText, FVector2D TextBoxSize, UImGuiToolkitContainer* Container = nullptr);
	
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, HidePin = "WorldContextObject"))
	static UImGuiToolkitInputFloat* CreateImGuiInputFloat(UObject* WorldContextObject, FText Label, float PreviewFloat, FString Format = "%.2f", UImGuiToolkitContainer* Container = nullptr);

	// Create an InputInt
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, HidePin = "WorldContextObject"))
	static UImGuiToolkitInputInt* CreateImGuiInputInt(UObject* WorldContextObject, FText Label, int32 PreviewInt, UImGuiToolkitContainer* Container = nullptr);

	
private:
	// Helper function to get a valid outer object for creating ImGui objects. This function allows us to have different behaviors for ImGui objects spawned at runtime or in the editor. When spawned at runtime, the ImGui objects only stay active until the WorldContext becomes invalid (EndPlay), while ImGui elements spawned during editor-time stay active as long as the editor is valid.
	static UObject* GetValidOuterObject(UObject* WorldContextObject);

};
