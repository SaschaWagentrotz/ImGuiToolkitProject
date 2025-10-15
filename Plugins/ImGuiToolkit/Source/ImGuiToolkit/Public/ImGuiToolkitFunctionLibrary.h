// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Widget.h"
#include "Widgets/TabBar/ImGuiToolkiBeginTabItem.h"
#include "Containers/ImGuiToolkitBeginTabBar.h"
#include "Containers/ImGuiToolkitCollapsingHeader.h"
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
#include "Widgets/Layout/ImGuiToolkitAlignTextToFramePadding.h"
#include "Widgets/Main/ImGuiToolkitButton.h"
#include "Widgets/Main/ImGuiToolkitCheckbox.h"
#include "Widgets/Main/ImGuiToolkitCombo.h"
#include "Widgets/DragSliders/ImGuiToolkitDragInt.h"
#include "Widgets/TabBar/ImGuiToolkitEndTabBar.h"
#include "Widgets/TabBar/ImGuiToolkitEndTabItem.h"
#include "Widgets/Tree/ImGuiToolkitTreePop.h"
#include "Widgets/Tree/ImGuiToolkitTreePush.h"
#include "Widgets/Layout/ImGuiToolkitNewLine.h"
#include "Widgets/Layout/ImGuiToolkitSeparator.h"
#include "Widgets/Layout/ImGuiToolkitDummy.h"
#include "Widgets/Main/ImGuiToolkitArrowButton.h"
#include "Widgets/Main/ImGuiToolkitBullet.h"
#include "Widgets/Main/ImGuiToolkitProgressBar.h"
#include "Widgets/Main/ImGuiToolkitRadioButtonGroup.h"
#include "Widgets/Main/ImGuiToolkitSmallButton.h"
#include "Widgets/Text/ImGuiToolkitTextColored.h"
#include "Widgets/Text/ImGuiToolkitTextLinkOpenURL.h"
#include "Widgets/Text/ImGuiToolkitTextWrapped.h"
#include "ImGuiToolkitFunctionLibrary.generated.h"

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	// TODO: Tidy all these functions up by grouping them together in a logical way
	// TODO: Improve comments (function tooltips) to be more descriptive
	
	// Toggle the ImGui DemoWindow (needs to be called again to close it)
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit")
	static void ToggleImGuiDemoWindow();

	// Create a new ImGui window
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, HidePin = "WorldContextObject"))
	static UImGuiToolkitWindow* CreateImGuiWindow(UObject* WorldContextObject, FText WindowTitle);

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, HidePin = "WorldContextObject"))
	static FVector2D GetWidgetPosition(UObject* WorldContextObject, UWidget* Widget);

	// Destroy an ImGui window
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, HidePin = "WorldContextObject"))
	static void DestroyImGuiWindow(UObject* WorldContextObject, UImGuiToolkitWindow* Window);

	// Create a SameLine
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, HidePin = "WorldContextObject"))
	static UImGuiToolkitSameLine* CreateImGuiSameLine(UObject* WorldContextObject, float OffsetFromStartX = 0.0f, float Spacing = -1.0f, UImGuiToolkitContainer* Container = nullptr);

	// Create a Button
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, HidePin = "WorldContextObject"))
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
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, HidePin = "WorldContextObject", HidePin = "WorldContextObject"))
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

	// Create a TabBar
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext , HidePin = "WorldContextObject"))
	static UImGuiToolkitBeginTabBar* CreateImGuiBeginTabBar(UObject* WorldContextObject, FText Label, UImGuiToolkitContainer* Container = nullptr);

	// End a TabBar
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, HidePin = "WorldContextObject"))
	static UImGuiToolkitEndTabBar* EndImGuiTabBar(UObject* WorldContextObject, UImGuiToolkitContainer* Container = nullptr);

	// Create a TabItem
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, HidePin = "WorldContextObject"))
	static UImGuiToolkiBeginTabItem* CreateImGuiBeginTabItem(UObject* WorldContextObject, FText Label, UImGuiToolkitContainer* Container = nullptr);

	// End a TabItem
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, HidePin = "WorldContextObject"))
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

	// Create a Text Link Open URL. TODO: This displays as a link, but clicking it does not open the browser. Needs investigation.
	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit", meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, HidePin = "WorldContextObject"))
	static UImGuiToolkitTextLinkOpenURL* CreateTextLinkOpenURL(UObject* WorldContextObject, FText Text, FString URL, UImGuiToolkitContainer* Container = nullptr);
	
private:
	// Helper function to get a valid outer object for creating ImGui objects.This function allows us to have different behaviors for ImGui objects spawned at runtime or in the editor. When spawned at runtime, the ImGui objects only stay active until the WorldContext becomes invalid (EndPlay), while ImGui elements spawned during editor-time stay active as long as the editor is valid.
	static UObject* GetValidOuterObject(UObject* WorldContextObject);

};