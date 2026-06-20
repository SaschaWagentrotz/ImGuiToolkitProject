#include "ImGuiToolkitFunctionLibrary.h"

#include "Containers/ImGuiToolkitWindow.h"
#include "Widgets/Main/ImGuiToolkitButton.h"
#include "Widgets/Layout/ImGuiToolkitSameLine.h"
#include "ImGuiToolkitSubsystem.h"
#include "Components/Widget.h"
#include "Containers/ImGuiToolkitCollapsingHeader.h"
#include "Widgets/Text/ImGuiToolkitText.h"

void UImGuiToolkitFunctionLibrary::ToggleImGuiDemoWindow()
{
	if (UImGuiToolkitSubsystem* Subsystem = GEngine->GetEngineSubsystem<UImGuiToolkitSubsystem>())
	{
		Subsystem->SetShowImGuiDemoWindow(!Subsystem->GetShowImGuiDemoWindow());
	}
}

UImGuiToolkitWindow* UImGuiToolkitFunctionLibrary::CreateImGuiWindow(UObject* WorldContextObject, FText WindowTitle, TArray<EImGuiWindowFlag> WindowFlags)
{
	UObject* OuterObject = GetValidOuterObject(WorldContextObject);
	if (!OuterObject)
		return nullptr;

	// Use GEngine directly instead of GetEngine()
	if (!GEngine)
		return nullptr;

	// Create window with WorldContextObject as outer so it gets cleaned up with the world
	UImGuiToolkitWindow* Window = NewObject<UImGuiToolkitWindow>(OuterObject);
	Window->CreateUniqueWidgetLabel(WindowTitle);
	Window->WindowFlags = WindowFlags;

	// Auto-register with subsystem
	if (UImGuiToolkitSubsystem* Subsystem = GEngine->GetEngineSubsystem<UImGuiToolkitSubsystem>())
	{
		Subsystem->RegisterWindow(Window);
	}

	return Window;
}

UImGuiToolkitBeginChild* UImGuiToolkitFunctionLibrary::CreateImGuiBeginChild(FText Label, FVector2D Size,
	TArray<EImGuiChildFlag> ChildFlags, TArray<EImGuiWindowFlag> WindowFlags, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitBeginChild* BeginChild = NewObject<UImGuiToolkitBeginChild>(OuterObject);
	BeginChild->CreateUniqueWidgetLabel(Label);
	BeginChild->Size = Size;
	BeginChild->ChildFlags = ChildFlags;
	BeginChild->WindowFlags = WindowFlags;

	if (Container)
		Container->AddWidget(BeginChild);

	return BeginChild;
}

UImGuiToolkitBeginGroup* UImGuiToolkitFunctionLibrary::CreateImGuiBeginGroup(UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitBeginGroup* BeginGroup = NewObject<UImGuiToolkitBeginGroup>(OuterObject);

	if (Container)
		Container->AddWidget(BeginGroup);

	return BeginGroup;
}

UImGuiToolkitBeginListBox* UImGuiToolkitFunctionLibrary::CreateImGuiBeginListBox(FText Label, FVector2D Size, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitBeginListBox* BeginListBox = NewObject<UImGuiToolkitBeginListBox>(OuterObject);
	BeginListBox->CreateUniqueWidgetLabel(Label);
	BeginListBox->Size = Size;

	if (Container)
		Container->AddWidget(BeginListBox);

	return BeginListBox;
}

UImGuiToolkitEndListBox* UImGuiToolkitFunctionLibrary::EndImGuiListBox(UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitEndListBox* EndListBox = NewObject<UImGuiToolkitEndListBox>(OuterObject);

	if (Container)
		Container->AddWidget(EndListBox);

	return EndListBox;
}

UImGuiToolkitListBox* UImGuiToolkitFunctionLibrary::CreateImGuiListBox(FText Label,
	TArray<FText> ListItems, int32 InitialIndex, int32 HeightInItems, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitListBox* ListBox = NewObject<UImGuiToolkitListBox>(OuterObject);
	ListBox->CreateUniqueWidgetLabel(Label);
	ListBox->ListItems = ListItems;
	ListBox->SelectedIndex = InitialIndex;
	ListBox->HeightInItems = HeightInItems;

	if (Container)
		Container->AddWidget(ListBox);

	return ListBox;
}

UImGuiToolkitPushItemWidth* UImGuiToolkitFunctionLibrary::CreateImGuiPushItemWidth(float ItemWidth, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitPushItemWidth* PushItemWidth = NewObject<UImGuiToolkitPushItemWidth>(OuterObject);
	PushItemWidth->ItemWidth = ItemWidth;

	if (Container)
		Container->AddWidget(PushItemWidth);

	return PushItemWidth;
}

UImGuiToolkitPopItemWidth* UImGuiToolkitFunctionLibrary::CreateImGuiPopItemWidth(UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitPopItemWidth* PopItemWidth = NewObject<UImGuiToolkitPopItemWidth>(OuterObject);

	if (Container)
		Container->AddWidget(PopItemWidth);

	return PopItemWidth;
}

UImGuiToolkitSetNextItemWidth* UImGuiToolkitFunctionLibrary::CreateImGuiSetNextItemWidth(float ItemWidth, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitSetNextItemWidth* SetNextItemWidth = NewObject<UImGuiToolkitSetNextItemWidth>(OuterObject);
	SetNextItemWidth->ItemWidth = ItemWidth;

	if (Container)
		Container->AddWidget(SetNextItemWidth);

	return SetNextItemWidth;
}

UImGuiToolkitPushTextWrapPos* UImGuiToolkitFunctionLibrary::CreateImGuiPushTextWrapPos(float WrapLocalPosX, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitPushTextWrapPos* PushTextWrapPos = NewObject<UImGuiToolkitPushTextWrapPos>(OuterObject);
	PushTextWrapPos->WrapLocalPosX = WrapLocalPosX;

	if (Container)
		Container->AddWidget(PushTextWrapPos);

	return PushTextWrapPos;
}

UImGuiToolkitPopTextWrapPos* UImGuiToolkitFunctionLibrary::CreateImGuiPopTextWrapPos(UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitPopTextWrapPos* PopTextWrapPos = NewObject<UImGuiToolkitPopTextWrapPos>(OuterObject);

	if (Container)
		Container->AddWidget(PopTextWrapPos);

	return PopTextWrapPos;
}

FVector2D UImGuiToolkitFunctionLibrary::GetWidgetPosition(UWidget* Widget)
{
	const FGeometry& Geo = Widget->GetCachedGeometry();
	const FVector2D AbsTopLeft = Geo.GetAbsolutePosition();

	const float Scale = FSlateApplication::Get().GetApplicationScale();
	const FVector2D ScreenPos = AbsTopLeft / Scale;
	
	return ScreenPos;
}

void UImGuiToolkitFunctionLibrary::DestroyImGuiWindow(UImGuiToolkitWindow* Window)
{
	// Use GEngine directly instead of GetEngine()
	if (!GEngine)
		return;

	if (UImGuiToolkitSubsystem* Subsystem = GEngine->GetEngineSubsystem<UImGuiToolkitSubsystem>())
	{
		Subsystem->UnregisterWindow(Window);
	}
}

void UImGuiToolkitFunctionLibrary::DockImGuiWindow(UImGuiToolkitWindow* WindowToDock,
	UImGuiToolkitWindow* TargetWindow, EImGuiToolkitDockSplitDirection Direction, float SplitRatio)
{
	if (!GEngine)
	{
		return;
	}

	if (UImGuiToolkitSubsystem* Subsystem = GEngine->GetEngineSubsystem<UImGuiToolkitSubsystem>())
	{
		Subsystem->QueueDockWindow(WindowToDock, TargetWindow, Direction, SplitRatio);
	}
}

UImGuiToolkitSameLine* UImGuiToolkitFunctionLibrary::CreateImGuiSameLine(float OffsetFromStartX, float Spacing, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitSameLine* SameLine = NewObject<UImGuiToolkitSameLine>(OuterObject);
	SameLine->OffsetFromStartX = OffsetFromStartX;
	SameLine->Spacing = Spacing;

	if (Container)
		Container->AddWidget(SameLine);
	
	return SameLine;
}


UImGuiToolkitButton* UImGuiToolkitFunctionLibrary::CreateImGuiButton(FText Label, FText Tooltip, FVector2D Size, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitButton* Button = NewObject<UImGuiToolkitButton>(OuterObject);
	Button->CreateUniqueWidgetLabel(Label);
	Button->Tooltip = Tooltip;
	Button->Size = Size;

	if (Container)
		Container->AddWidget(Button);

	return Button;
}

UImGuiToolkitHelpMarker* UImGuiToolkitFunctionLibrary::CreateImGuiHelpMarker(FText Text, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitHelpMarker* HelpMarker = NewObject<UImGuiToolkitHelpMarker>(OuterObject);
	HelpMarker->Text = Text;

	if (Container)
		Container->AddWidget(HelpMarker);

	return HelpMarker;
}

UImGuiToolkitSetItemTooltip* UImGuiToolkitFunctionLibrary::CreateImGuiSetItemTooltip(FText Text, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitSetItemTooltip* Tooltip = NewObject<UImGuiToolkitSetItemTooltip>(OuterObject);
	Tooltip->Text = Text;

	if (Container)
		Container->AddWidget(Tooltip);

	return Tooltip;
}

UImGuiToolkitSetTooltip* UImGuiToolkitFunctionLibrary::CreateImGuiSetTooltip(FText Text, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitSetTooltip* Tooltip = NewObject<UImGuiToolkitSetTooltip>(OuterObject);
	Tooltip->Text = Text;

	if (Container)
		Container->AddWidget(Tooltip);

	return Tooltip;
}

UImGuiToolkitBeginTooltip* UImGuiToolkitFunctionLibrary::CreateImGuiBeginTooltip(UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitBeginTooltip* Tooltip = NewObject<UImGuiToolkitBeginTooltip>(OuterObject);

	if (Container)
		Container->AddWidget(Tooltip);

	return Tooltip;
}

UImGuiToolkitBeginItemTooltip* UImGuiToolkitFunctionLibrary::CreateImGuiBeginItemTooltip(UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitBeginItemTooltip* Tooltip = NewObject<UImGuiToolkitBeginItemTooltip>(OuterObject);

	if (Container)
		Container->AddWidget(Tooltip);

	return Tooltip;
}

UImGuiToolkitCollapsingHeader* UImGuiToolkitFunctionLibrary::CreateImGuiCollapsingHeader(FText Label, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitCollapsingHeader* CollapsingHeader = NewObject<UImGuiToolkitCollapsingHeader>(OuterObject);
	CollapsingHeader->CreateUniqueWidgetLabel(Label);

	if (Container)
		Container->AddWidget(CollapsingHeader);

	return CollapsingHeader;
}

UImGuiToolkitText* UImGuiToolkitFunctionLibrary::CreateImGuiText(FText Text, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitText* TextBlock = NewObject<UImGuiToolkitText>(OuterObject);
	TextBlock->Text = Text;

	if (Container)
		Container->AddWidget(TextBlock);

	return TextBlock;
}

UImGuiToolkitAlignTextToFramePadding* UImGuiToolkitFunctionLibrary::CreateImGuiAlignTextToFramePadding(
	UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitAlignTextToFramePadding* AlignTextToFramePadding = NewObject<UImGuiToolkitAlignTextToFramePadding>(OuterObject);

	if (Container)
		Container->AddWidget(AlignTextToFramePadding);
	
	return AlignTextToFramePadding;
}

UImGuiToolkitTextDisabled* UImGuiToolkitFunctionLibrary::CreateImGuiTextDisabled(FText Text, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitTextDisabled* TextBlock = NewObject<UImGuiToolkitTextDisabled>(OuterObject);
	TextBlock->Text = Text;

	if (Container)
		Container->AddWidget(TextBlock);

	return TextBlock;
}

UImGuiToolkitSeparatorText* UImGuiToolkitFunctionLibrary::CreateImGuiSeparatorText(FText Text, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitSeparatorText* SeparatorText = NewObject<UImGuiToolkitSeparatorText>(OuterObject);
	SeparatorText->Text = Text;

	if (Container)
		Container->AddWidget(SeparatorText);

	return SeparatorText;
}

UImGuiToolkitBulletText* UImGuiToolkitFunctionLibrary::CreateImGuiBulletText(FText Text, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitBulletText* BulletText = NewObject<UImGuiToolkitBulletText>(OuterObject);
	BulletText->Text = Text;

	if (Container)
		Container->AddWidget(BulletText);

	return BulletText;
}

UImGuiToolkitLabelText* UImGuiToolkitFunctionLibrary::CreateImGuiLabelText(FText LeftText, FText RightText, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitLabelText* LabelText = NewObject<UImGuiToolkitLabelText>(OuterObject);
	LabelText->Label = RightText;
	LabelText->Value = LeftText;

	if (Container)
		Container->AddWidget(LabelText);

	return LabelText;
}

UImGuiToolkitSpacing* UImGuiToolkitFunctionLibrary::CreateImGuiSpacing(UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitSpacing* Spacing = NewObject<UImGuiToolkitSpacing>(OuterObject);

	if (Container)
		Container->AddWidget(Spacing);
	
	return Spacing;
}

UImGuiToolkitIndent* UImGuiToolkitFunctionLibrary::CreateImGuiIndent(UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitIndent* Indent = NewObject<UImGuiToolkitIndent>(OuterObject);

	if (Container)
		Container->AddWidget(Indent);
	
	return Indent;
}

UImGuiToolkitUnindent* UImGuiToolkitFunctionLibrary::CreateImGuiUnindent(UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitUnindent* Unindent = NewObject<UImGuiToolkitUnindent>(OuterObject);

	if (Container)
		Container->AddWidget(Unindent);
	
	return Unindent;
}

UImGuiToolkitTreeNode* UImGuiToolkitFunctionLibrary::CreateImGuiTreeNode(FText Label, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitTreeNode* TreeNode = NewObject<UImGuiToolkitTreeNode>(OuterObject);
	TreeNode->CreateUniqueWidgetLabel(Label);

	if (Container)
		Container->AddWidget(TreeNode);

	return TreeNode;
}

UImGuiToolkitTreePush* UImGuiToolkitFunctionLibrary::CreateImGuiTreePush(FText Label,
	UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitTreePush* TreePush = NewObject<UImGuiToolkitTreePush>(OuterObject);
	TreePush->Text = Label;

	if (Container)
		Container->AddWidget(TreePush);

	return TreePush;
}

UImGuiToolkitTreePop* UImGuiToolkitFunctionLibrary::CreateImGuiTreePop(UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitTreePop* TreePop = NewObject<UImGuiToolkitTreePop>(OuterObject);

	if (Container)
		Container->AddWidget(TreePop);

	return TreePop;
}

UImGuiToolkitCheckbox* UImGuiToolkitFunctionLibrary::CreateImGuiCheckbox(FText Label,
	FText Tooltip, bool bIsChecked, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitCheckbox* Checkbox = NewObject<UImGuiToolkitCheckbox>(OuterObject);
	Checkbox->CreateUniqueWidgetLabel(Label);
	Checkbox->Tooltip = Tooltip;
	Checkbox->bIsChecked = bIsChecked;

	if (Container)
		Container->AddWidget(Checkbox);

	return Checkbox;
}

UImGuiToolkitSelectable* UImGuiToolkitFunctionLibrary::CreateImGuiSelectable(FText Label,
	bool bIsSelected, TArray<EImGuiSelectableFlag> SelectableFlags, FVector2D Size, FText Tooltip, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitSelectable* Selectable = NewObject<UImGuiToolkitSelectable>(OuterObject);
	Selectable->CreateUniqueWidgetLabel(Label);
	Selectable->bIsSelected = bIsSelected;
	Selectable->SelectableFlags = SelectableFlags;
	Selectable->Size = Size;
	Selectable->Tooltip = Tooltip;

	if (Container)
		Container->AddWidget(Selectable);

	return Selectable;
}

UImGuiToolkitMultiSelectListBox* UImGuiToolkitFunctionLibrary::CreateImGuiMultiSelectListBox(FText Label,
	TArray<FText> Items, TArray<int32> InitialSelectedIndices, FVector2D Size, TArray<EImGuiMultiSelectFlag> MultiSelectFlags, TArray<EImGuiSelectableFlag> SelectableFlags, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitMultiSelectListBox* MultiSelectListBox = NewObject<UImGuiToolkitMultiSelectListBox>(OuterObject);
	MultiSelectListBox->CreateUniqueWidgetLabel(Label);
	MultiSelectListBox->Items = Items;
	MultiSelectListBox->SelectedIndices = InitialSelectedIndices;
	MultiSelectListBox->Size = Size;
	MultiSelectListBox->MultiSelectFlags = MultiSelectFlags;
	MultiSelectListBox->SelectableFlags = SelectableFlags;

	if (Container)
		Container->AddWidget(MultiSelectListBox);

	return MultiSelectListBox;
}

UImGuiToolkitColorEdit3* UImGuiToolkitFunctionLibrary::CreateImGuiColorEdit3(FText Label, FLinearColor Color,
	TArray<EImGuiColorEditFlag> ColorEditFlags, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitColorEdit3* ColorEdit = NewObject<UImGuiToolkitColorEdit3>(OuterObject);
	ColorEdit->CreateUniqueWidgetLabel(Label);
	ColorEdit->Color = Color;
	ColorEdit->ColorEditFlags = ColorEditFlags;

	if (Container)
		Container->AddWidget(ColorEdit);

	return ColorEdit;
}

UImGuiToolkitColorEdit4* UImGuiToolkitFunctionLibrary::CreateImGuiColorEdit4(FText Label, FLinearColor Color,
	TArray<EImGuiColorEditFlag> ColorEditFlags, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitColorEdit4* ColorEdit = NewObject<UImGuiToolkitColorEdit4>(OuterObject);
	ColorEdit->CreateUniqueWidgetLabel(Label);
	ColorEdit->Color = Color;
	ColorEdit->ColorEditFlags = ColorEditFlags;

	if (Container)
		Container->AddWidget(ColorEdit);

	return ColorEdit;
}

UImGuiToolkitColorPicker3* UImGuiToolkitFunctionLibrary::CreateImGuiColorPicker3(FText Label, FLinearColor Color,
	TArray<EImGuiColorEditFlag> ColorEditFlags, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitColorPicker3* ColorPicker = NewObject<UImGuiToolkitColorPicker3>(OuterObject);
	ColorPicker->CreateUniqueWidgetLabel(Label);
	ColorPicker->Color = Color;
	ColorPicker->ColorEditFlags = ColorEditFlags;

	if (Container)
		Container->AddWidget(ColorPicker);

	return ColorPicker;
}

UImGuiToolkitColorPicker4* UImGuiToolkitFunctionLibrary::CreateImGuiColorPicker4(FText Label, FLinearColor Color,
	TArray<EImGuiColorEditFlag> ColorEditFlags, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitColorPicker4* ColorPicker = NewObject<UImGuiToolkitColorPicker4>(OuterObject);
	ColorPicker->CreateUniqueWidgetLabel(Label);
	ColorPicker->Color = Color;
	ColorPicker->ColorEditFlags = ColorEditFlags;

	if (Container)
		Container->AddWidget(ColorPicker);

	return ColorPicker;
}

UImGuiToolkitColorButton* UImGuiToolkitFunctionLibrary::CreateImGuiColorButton(FText Label, FLinearColor Color,
	TArray<EImGuiColorEditFlag> ColorEditFlags, FVector2D Size, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitColorButton* ColorButton = NewObject<UImGuiToolkitColorButton>(OuterObject);
	ColorButton->CreateUniqueWidgetLabel(Label);
	ColorButton->Color = Color;
	ColorButton->ColorEditFlags = ColorEditFlags;
	ColorButton->Size = Size;

	if (Container)
		Container->AddWidget(ColorButton);

	return ColorButton;
}

UImGuiToolkitSetColorEditOptions* UImGuiToolkitFunctionLibrary::CreateImGuiSetColorEditOptions(
	TArray<EImGuiColorEditFlag> ColorEditFlags, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitSetColorEditOptions* SetColorEditOptions = NewObject<UImGuiToolkitSetColorEditOptions>(OuterObject);
	SetColorEditOptions->ColorEditFlags = ColorEditFlags;

	if (Container)
		Container->AddWidget(SetColorEditOptions);

	return SetColorEditOptions;
}

UImGuiToolkitBeginTable* UImGuiToolkitFunctionLibrary::CreateImGuiBeginTable(FText Label,
	int32 ColumnCount, TArray<EImGuiTableFlag> TableFlags, FVector2D OuterSize, float InnerWidth, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitBeginTable* BeginTable = NewObject<UImGuiToolkitBeginTable>(OuterObject);
	BeginTable->CreateUniqueWidgetLabel(Label);
	BeginTable->ColumnCount = FMath::Max(1, ColumnCount);
	BeginTable->TableFlags = TableFlags;
	BeginTable->OuterSize = OuterSize;
	BeginTable->InnerWidth = InnerWidth;

	if (Container)
		Container->AddWidget(BeginTable);

	return BeginTable;
}

UImGuiToolkitTableSetupColumn* UImGuiToolkitFunctionLibrary::CreateImGuiTableSetupColumn(FText Label, TArray<EImGuiTableColumnFlag> ColumnFlags, float InitialWidthOrWeight, int32 UserID, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitTableSetupColumn* TableSetupColumn = NewObject<UImGuiToolkitTableSetupColumn>(OuterObject);
	TableSetupColumn->Label = Label;
	TableSetupColumn->ColumnFlags = ColumnFlags;
	TableSetupColumn->InitialWidthOrWeight = InitialWidthOrWeight;
	TableSetupColumn->UserID = UserID;

	if (Container)
		Container->AddWidget(TableSetupColumn);

	return TableSetupColumn;
}

UImGuiToolkitTableSetupScrollFreeze* UImGuiToolkitFunctionLibrary::CreateImGuiTableSetupScrollFreeze(
	int32 FrozenColumnCount, int32 FrozenRowCount, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitTableSetupScrollFreeze* TableSetupScrollFreeze = NewObject<UImGuiToolkitTableSetupScrollFreeze>(OuterObject);
	TableSetupScrollFreeze->FrozenColumnCount = FMath::Max(0, FrozenColumnCount);
	TableSetupScrollFreeze->FrozenRowCount = FMath::Max(0, FrozenRowCount);

	if (Container)
		Container->AddWidget(TableSetupScrollFreeze);

	return TableSetupScrollFreeze;
}

UImGuiToolkitTableHeadersRow* UImGuiToolkitFunctionLibrary::CreateImGuiTableHeadersRow(UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitTableHeadersRow* TableHeadersRow = NewObject<UImGuiToolkitTableHeadersRow>(OuterObject);

	if (Container)
		Container->AddWidget(TableHeadersRow);

	return TableHeadersRow;
}

UImGuiToolkitTableHeader* UImGuiToolkitFunctionLibrary::CreateImGuiTableHeader(FText Label,
	UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitTableHeader* TableHeader = NewObject<UImGuiToolkitTableHeader>(OuterObject);
	TableHeader->Label = Label;

	if (Container)
		Container->AddWidget(TableHeader);

	return TableHeader;
}

UImGuiToolkitTableNextRow* UImGuiToolkitFunctionLibrary::CreateImGuiTableNextRow(TArray<EImGuiTableRowFlag> RowFlags, float MinimumRowHeight, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitTableNextRow* TableNextRow = NewObject<UImGuiToolkitTableNextRow>(OuterObject);
	TableNextRow->RowFlags = RowFlags;
	TableNextRow->MinimumRowHeight = MinimumRowHeight;

	if (Container)
		Container->AddWidget(TableNextRow);

	return TableNextRow;
}

UImGuiToolkitTableNextColumn* UImGuiToolkitFunctionLibrary::CreateImGuiTableNextColumn(UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitTableNextColumn* TableNextColumn = NewObject<UImGuiToolkitTableNextColumn>(OuterObject);

	if (Container)
		Container->AddWidget(TableNextColumn);

	return TableNextColumn;
}

UImGuiToolkitTableSetColumnIndex* UImGuiToolkitFunctionLibrary::CreateImGuiTableSetColumnIndex(int32 ColumnIndex, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitTableSetColumnIndex* TableSetColumnIndex = NewObject<UImGuiToolkitTableSetColumnIndex>(OuterObject);
	TableSetColumnIndex->ColumnIndex = FMath::Max(0, ColumnIndex);

	if (Container)
		Container->AddWidget(TableSetColumnIndex);

	return TableSetColumnIndex;
}

UImGuiToolkitOpenPopup* UImGuiToolkitFunctionLibrary::CreateImGuiOpenPopup(FText PopupID,
	TArray<EImGuiPopupFlag> PopupFlags, bool bOpenOnCreate, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitOpenPopup* OpenPopup = NewObject<UImGuiToolkitOpenPopup>(OuterObject);
	OpenPopup->PopupID = PopupID;
	OpenPopup->PopupFlags = PopupFlags;
	OpenPopup->bOpenRequested = bOpenOnCreate;

	if (Container)
		Container->AddWidget(OpenPopup);

	return OpenPopup;
}

UImGuiToolkitOpenPopupOnItemClick* UImGuiToolkitFunctionLibrary::CreateImGuiOpenPopupOnItemClick(
	FText PopupID, EImGuiPopupMouseButton MouseButton, TArray<EImGuiPopupFlag> PopupFlags, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitOpenPopupOnItemClick* OpenPopupOnItemClick = NewObject<UImGuiToolkitOpenPopupOnItemClick>(OuterObject);
	OpenPopupOnItemClick->PopupID = PopupID;
	OpenPopupOnItemClick->MouseButton = MouseButton;
	OpenPopupOnItemClick->PopupFlags = PopupFlags;

	if (Container)
		Container->AddWidget(OpenPopupOnItemClick);

	return OpenPopupOnItemClick;
}

UImGuiToolkitBeginPopup* UImGuiToolkitFunctionLibrary::CreateImGuiBeginPopup(FText PopupID,
	TArray<EImGuiWindowFlag> WindowFlags, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitBeginPopup* BeginPopup = NewObject<UImGuiToolkitBeginPopup>(OuterObject);
	BeginPopup->PopupID = PopupID;
	BeginPopup->WindowFlags = WindowFlags;

	if (Container)
		Container->AddWidget(BeginPopup);

	return BeginPopup;
}

UImGuiToolkitBeginPopupModal* UImGuiToolkitFunctionLibrary::CreateImGuiBeginPopupModal(FText PopupID,
	bool bShowCloseButton, TArray<EImGuiWindowFlag> WindowFlags, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitBeginPopupModal* BeginPopupModal = NewObject<UImGuiToolkitBeginPopupModal>(OuterObject);
	BeginPopupModal->PopupID = PopupID;
	BeginPopupModal->bShowCloseButton = bShowCloseButton;
	BeginPopupModal->WindowFlags = WindowFlags;

	if (Container)
		Container->AddWidget(BeginPopupModal);

	return BeginPopupModal;
}

UImGuiToolkitBeginPopupContextItem* UImGuiToolkitFunctionLibrary::CreateImGuiBeginPopupContextItem(
	FText PopupID, bool bUsePreviousItemID, EImGuiPopupMouseButton MouseButton, TArray<EImGuiPopupFlag> PopupFlags, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitBeginPopupContextItem* BeginPopupContextItem = NewObject<UImGuiToolkitBeginPopupContextItem>(OuterObject);
	BeginPopupContextItem->PopupID = PopupID;
	BeginPopupContextItem->bUsePreviousItemID = bUsePreviousItemID;
	BeginPopupContextItem->MouseButton = MouseButton;
	BeginPopupContextItem->PopupFlags = PopupFlags;

	if (Container)
		Container->AddWidget(BeginPopupContextItem);

	return BeginPopupContextItem;
}

UImGuiToolkitBeginPopupContextWindow* UImGuiToolkitFunctionLibrary::CreateImGuiBeginPopupContextWindow(
	FText PopupID, EImGuiPopupMouseButton MouseButton, TArray<EImGuiPopupFlag> PopupFlags, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitBeginPopupContextWindow* BeginPopupContextWindow = NewObject<UImGuiToolkitBeginPopupContextWindow>(OuterObject);
	BeginPopupContextWindow->PopupID = PopupID;
	BeginPopupContextWindow->MouseButton = MouseButton;
	BeginPopupContextWindow->PopupFlags = PopupFlags;

	if (Container)
		Container->AddWidget(BeginPopupContextWindow);

	return BeginPopupContextWindow;
}

UImGuiToolkitBeginPopupContextVoid* UImGuiToolkitFunctionLibrary::CreateImGuiBeginPopupContextVoid(
	FText PopupID, EImGuiPopupMouseButton MouseButton, TArray<EImGuiPopupFlag> PopupFlags, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitBeginPopupContextVoid* BeginPopupContextVoid = NewObject<UImGuiToolkitBeginPopupContextVoid>(OuterObject);
	BeginPopupContextVoid->PopupID = PopupID;
	BeginPopupContextVoid->MouseButton = MouseButton;
	BeginPopupContextVoid->PopupFlags = PopupFlags;

	if (Container)
		Container->AddWidget(BeginPopupContextVoid);

	return BeginPopupContextVoid;
}

UImGuiToolkitCloseCurrentPopup* UImGuiToolkitFunctionLibrary::CreateImGuiCloseCurrentPopup(bool bCloseOnCreate,
	bool bCloseWhenPreviousItemClicked, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitCloseCurrentPopup* CloseCurrentPopup = NewObject<UImGuiToolkitCloseCurrentPopup>(OuterObject);
	CloseCurrentPopup->bCloseRequested = bCloseOnCreate;
	CloseCurrentPopup->bCloseWhenPreviousItemClicked = bCloseWhenPreviousItemClicked;

	if (Container)
		Container->AddWidget(CloseCurrentPopup);

	return CloseCurrentPopup;
}

UImGuiToolkitIsPopupOpen* UImGuiToolkitFunctionLibrary::CreateImGuiIsPopupOpen(FText PopupID,
	TArray<EImGuiPopupFlag> PopupFlags, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitIsPopupOpen* IsPopupOpen = NewObject<UImGuiToolkitIsPopupOpen>(OuterObject);
	IsPopupOpen->PopupID = PopupID;
	IsPopupOpen->PopupFlags = PopupFlags;

	if (Container)
		Container->AddWidget(IsPopupOpen);

	return IsPopupOpen;
}

UImGuiToolkitPopupButton* UImGuiToolkitFunctionLibrary::CreateImGuiPopupButton(FText Label, FText Tooltip,
	FVector2D Size, TArray<EImGuiPopupFlag> PopupFlags, TArray<EImGuiWindowFlag> WindowFlags, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitPopupButton* PopupButton = NewObject<UImGuiToolkitPopupButton>(OuterObject);
	PopupButton->CreateUniqueWidgetLabel(Label);
	PopupButton->Tooltip = Tooltip;
	PopupButton->Size = Size;
	PopupButton->PopupFlags = PopupFlags;
	PopupButton->WindowFlags = WindowFlags;

	if (Container)
		Container->AddWidget(PopupButton);

	return PopupButton;
}

UImGuiToolkitImage* UImGuiToolkitFunctionLibrary::CreateImGuiImage(UTexture2D* Texture, FVector2D Size,
	FVector2D UV0, FVector2D UV1, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitImage* Image = NewObject<UImGuiToolkitImage>(OuterObject);
	Image->ResourceObject = Texture;
	Image->Size = Size;
	Image->UV0 = UV0;
	Image->UV1 = UV1;

	if (Container)
		Container->AddWidget(Image);

	return Image;
}

UImGuiToolkitImage* UImGuiToolkitFunctionLibrary::CreateImGuiMaterialImage(UMaterialInterface* Material,
	FVector2D Size, FVector2D UV0, FVector2D UV1, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitImage* Image = NewObject<UImGuiToolkitImage>(OuterObject);
	Image->ResourceObject = Material;
	Image->Size = Size;
	Image->UV0 = UV0;
	Image->UV1 = UV1;

	if (Container)
		Container->AddWidget(Image);

	return Image;
}

UImGuiToolkitImageButton* UImGuiToolkitFunctionLibrary::CreateImGuiImageButton(FText ButtonID, UTexture2D* Texture,
	FText Tooltip, FVector2D Size, FVector2D UV0, FVector2D UV1, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitImageButton* ImageButton = NewObject<UImGuiToolkitImageButton>(OuterObject);
	ImageButton->CreateUniqueWidgetLabel(ButtonID);
	ImageButton->ResourceObject = Texture;
	ImageButton->Tooltip = Tooltip;
	ImageButton->Size = Size;
	ImageButton->UV0 = UV0;
	ImageButton->UV1 = UV1;

	if (Container)
		Container->AddWidget(ImageButton);

	return ImageButton;
}

UImGuiToolkitImageButton* UImGuiToolkitFunctionLibrary::CreateImGuiMaterialImageButton(FText ButtonID,
	UMaterialInterface* Material, FText Tooltip, FVector2D Size, FVector2D UV0, FVector2D UV1,
	UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitImageButton* ImageButton = NewObject<UImGuiToolkitImageButton>(OuterObject);
	ImageButton->CreateUniqueWidgetLabel(ButtonID);
	ImageButton->ResourceObject = Material;
	ImageButton->Tooltip = Tooltip;
	ImageButton->Size = Size;
	ImageButton->UV0 = UV0;
	ImageButton->UV1 = UV1;

	if (Container)
		Container->AddWidget(ImageButton);

	return ImageButton;
}

UImGuiToolkitBeginPlot* UImGuiToolkitFunctionLibrary::CreateImPlotBeginPlot(FText Title,
	TArray<EImPlotFlag> PlotFlags, FVector2D Size, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitBeginPlot* BeginPlot = NewObject<UImGuiToolkitBeginPlot>(OuterObject);
	BeginPlot->CreateUniqueWidgetLabel(Title);
	BeginPlot->Size = Size;
	BeginPlot->PlotFlags = PlotFlags;

	if (Container)
		Container->AddWidget(BeginPlot);

	return BeginPlot;
}

UImGuiToolkitSetupPlotAxis* UImGuiToolkitFunctionLibrary::CreateImPlotSetupAxis(EImPlotAxis Axis, FText Label,
	TArray<EImPlotAxisFlag> AxisFlags, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitSetupPlotAxis* SetupAxis = NewObject<UImGuiToolkitSetupPlotAxis>(OuterObject);
	SetupAxis->Axis = Axis;
	SetupAxis->Label = Label;
	SetupAxis->AxisFlags = AxisFlags;

	if (Container)
		Container->AddWidget(SetupAxis);

	return SetupAxis;
}

UImGuiToolkitSetupPlotAxisLimits* UImGuiToolkitFunctionLibrary::CreateImPlotSetupAxisLimits(EImPlotAxis Axis,
	double MinValue, double MaxValue, EImPlotCondition Condition, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitSetupPlotAxisLimits* SetupAxisLimits = NewObject<UImGuiToolkitSetupPlotAxisLimits>(OuterObject);
	SetupAxisLimits->Axis = Axis;
	SetupAxisLimits->MinValue = MinValue;
	SetupAxisLimits->MaxValue = MaxValue;
	SetupAxisLimits->Condition = Condition;

	if (Container)
		Container->AddWidget(SetupAxisLimits);

	return SetupAxisLimits;
}

UImGuiToolkitPlotLine* UImGuiToolkitFunctionLibrary::CreateImPlotLine(FText Label, TArray<float> Values,
	TArray<EImPlotLineFlag> LineFlags, TArray<EImPlotItemFlag> ItemFlags, double XScale, double XStart,
	UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitPlotLine* PlotLine = NewObject<UImGuiToolkitPlotLine>(OuterObject);
	PlotLine->CreateUniqueWidgetLabel(Label);
	PlotLine->Values = Values;
	PlotLine->LineFlags = LineFlags;
	PlotLine->ItemFlags = ItemFlags;
	PlotLine->XScale = XScale;
	PlotLine->XStart = XStart;

	if (Container)
		Container->AddWidget(PlotLine);

	return PlotLine;
}

UImGuiToolkitPlotLineXY* UImGuiToolkitFunctionLibrary::CreateImPlotLineXY(FText Label, TArray<float> XValues,
	TArray<float> YValues, TArray<EImPlotLineFlag> LineFlags, TArray<EImPlotItemFlag> ItemFlags,
	UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitPlotLineXY* PlotLine = NewObject<UImGuiToolkitPlotLineXY>(OuterObject);
	PlotLine->CreateUniqueWidgetLabel(Label);
	PlotLine->XValues = XValues;
	PlotLine->YValues = YValues;
	PlotLine->LineFlags = LineFlags;
	PlotLine->ItemFlags = ItemFlags;

	if (Container)
		Container->AddWidget(PlotLine);

	return PlotLine;
}

UImGuiToolkitPlotScatter* UImGuiToolkitFunctionLibrary::CreateImPlotScatter(FText Label, TArray<float> Values,
	TArray<EImPlotScatterFlag> ScatterFlags, TArray<EImPlotItemFlag> ItemFlags, double XScale, double XStart,
	UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitPlotScatter* PlotScatter = NewObject<UImGuiToolkitPlotScatter>(OuterObject);
	PlotScatter->CreateUniqueWidgetLabel(Label);
	PlotScatter->Values = Values;
	PlotScatter->ScatterFlags = ScatterFlags;
	PlotScatter->ItemFlags = ItemFlags;
	PlotScatter->XScale = XScale;
	PlotScatter->XStart = XStart;

	if (Container)
		Container->AddWidget(PlotScatter);

	return PlotScatter;
}

UImGuiToolkitPlotScatterXY* UImGuiToolkitFunctionLibrary::CreateImPlotScatterXY(FText Label, TArray<float> XValues,
	TArray<float> YValues, TArray<EImPlotScatterFlag> ScatterFlags, TArray<EImPlotItemFlag> ItemFlags,
	UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitPlotScatterXY* PlotScatter = NewObject<UImGuiToolkitPlotScatterXY>(OuterObject);
	PlotScatter->CreateUniqueWidgetLabel(Label);
	PlotScatter->XValues = XValues;
	PlotScatter->YValues = YValues;
	PlotScatter->ScatterFlags = ScatterFlags;
	PlotScatter->ItemFlags = ItemFlags;

	if (Container)
		Container->AddWidget(PlotScatter);

	return PlotScatter;
}

UImGuiToolkitPlotBars* UImGuiToolkitFunctionLibrary::CreateImPlotBars(FText Label, TArray<float> Values,
	TArray<EImPlotBarsFlag> BarsFlags, TArray<EImPlotItemFlag> ItemFlags, double BarSize, double Shift,
	UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitPlotBars* PlotBars = NewObject<UImGuiToolkitPlotBars>(OuterObject);
	PlotBars->CreateUniqueWidgetLabel(Label);
	PlotBars->Values = Values;
	PlotBars->BarsFlags = BarsFlags;
	PlotBars->ItemFlags = ItemFlags;
	PlotBars->BarSize = BarSize;
	PlotBars->Shift = Shift;

	if (Container)
		Container->AddWidget(PlotBars);

	return PlotBars;
}

UImGuiToolkitPlotBarsXY* UImGuiToolkitFunctionLibrary::CreateImPlotBarsXY(FText Label, TArray<float> XValues,
	TArray<float> YValues, TArray<EImPlotBarsFlag> BarsFlags, TArray<EImPlotItemFlag> ItemFlags,
	double BarSize, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitPlotBarsXY* PlotBars = NewObject<UImGuiToolkitPlotBarsXY>(OuterObject);
	PlotBars->CreateUniqueWidgetLabel(Label);
	PlotBars->XValues = XValues;
	PlotBars->YValues = YValues;
	PlotBars->BarsFlags = BarsFlags;
	PlotBars->ItemFlags = ItemFlags;
	PlotBars->BarSize = BarSize;

	if (Container)
		Container->AddWidget(PlotBars);

	return PlotBars;
}

UImGuiToolkitPlotBarGroups* UImGuiToolkitFunctionLibrary::CreateImPlotBarGroups(TArray<FText> Labels,
	TArray<float> Values, int32 ItemCount, int32 GroupCount, TArray<EImPlotBarGroupsFlag> BarGroupsFlags,
	TArray<EImPlotItemFlag> ItemFlags, double GroupSize, double Shift, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitPlotBarGroups* PlotBarGroups = NewObject<UImGuiToolkitPlotBarGroups>(OuterObject);
	PlotBarGroups->Labels = Labels;
	PlotBarGroups->Values = Values;
	PlotBarGroups->ItemCount = ItemCount;
	PlotBarGroups->GroupCount = GroupCount;
	PlotBarGroups->BarGroupsFlags = BarGroupsFlags;
	PlotBarGroups->ItemFlags = ItemFlags;
	PlotBarGroups->GroupSize = GroupSize;
	PlotBarGroups->Shift = Shift;

	if (Container)
		Container->AddWidget(PlotBarGroups);

	return PlotBarGroups;
}

UImGuiToolkitBeginSubplots* UImGuiToolkitFunctionLibrary::CreateImPlotBeginSubplots(FText Title, int32 Rows,
	int32 Columns, TArray<EImPlotSubplotFlag> SubplotFlags, FVector2D Size, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitBeginSubplots* BeginSubplots = NewObject<UImGuiToolkitBeginSubplots>(OuterObject);
	BeginSubplots->CreateUniqueWidgetLabel(Title);
	BeginSubplots->Rows = Rows;
	BeginSubplots->Columns = Columns;
	BeginSubplots->SubplotFlags = SubplotFlags;
	BeginSubplots->Size = Size;

	if (Container)
		Container->AddWidget(BeginSubplots);

	return BeginSubplots;
}

UImGuiToolkitSetupPlotLegend* UImGuiToolkitFunctionLibrary::CreateImPlotSetupLegend(EImPlotLocation Location,
	TArray<EImPlotLegendFlag> LegendFlags, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitSetupPlotLegend* SetupLegend = NewObject<UImGuiToolkitSetupPlotLegend>(OuterObject);
	SetupLegend->Location = Location;
	SetupLegend->LegendFlags = LegendFlags;

	if (Container)
		Container->AddWidget(SetupLegend);

	return SetupLegend;
}

UImGuiToolkitSetupPlotMouseText* UImGuiToolkitFunctionLibrary::CreateImPlotSetupMouseText(EImPlotLocation Location,
	TArray<EImPlotMouseTextFlag> MouseTextFlags, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitSetupPlotMouseText* SetupMouseText = NewObject<UImGuiToolkitSetupPlotMouseText>(OuterObject);
	SetupMouseText->Location = Location;
	SetupMouseText->MouseTextFlags = MouseTextFlags;

	if (Container)
		Container->AddWidget(SetupMouseText);

	return SetupMouseText;
}

UImGuiToolkitSetupPlotAxisFormat* UImGuiToolkitFunctionLibrary::CreateImPlotSetupAxisFormat(EImPlotAxis Axis,
	FString Format, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitSetupPlotAxisFormat* SetupAxisFormat = NewObject<UImGuiToolkitSetupPlotAxisFormat>(OuterObject);
	SetupAxisFormat->Axis = Axis;
	SetupAxisFormat->Format = Format;

	if (Container)
		Container->AddWidget(SetupAxisFormat);

	return SetupAxisFormat;
}

UImGuiToolkitSetupPlotAxisScale* UImGuiToolkitFunctionLibrary::CreateImPlotSetupAxisScale(EImPlotAxis Axis,
	EImPlotScale Scale, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitSetupPlotAxisScale* SetupAxisScale = NewObject<UImGuiToolkitSetupPlotAxisScale>(OuterObject);
	SetupAxisScale->Axis = Axis;
	SetupAxisScale->Scale = Scale;

	if (Container)
		Container->AddWidget(SetupAxisScale);

	return SetupAxisScale;
}

UImGuiToolkitSetupPlotAxes* UImGuiToolkitFunctionLibrary::CreateImPlotSetupAxes(FText XLabel, FText YLabel,
	TArray<EImPlotAxisFlag> XAxisFlags, TArray<EImPlotAxisFlag> YAxisFlags, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitSetupPlotAxes* SetupAxes = NewObject<UImGuiToolkitSetupPlotAxes>(OuterObject);
	SetupAxes->XLabel = XLabel;
	SetupAxes->YLabel = YLabel;
	SetupAxes->XAxisFlags = XAxisFlags;
	SetupAxes->YAxisFlags = YAxisFlags;

	if (Container)
		Container->AddWidget(SetupAxes);

	return SetupAxes;
}

UImGuiToolkitSetupPlotAxesLimits* UImGuiToolkitFunctionLibrary::CreateImPlotSetupAxesLimits(FVector2D XLimits,
	FVector2D YLimits, EImPlotCondition Condition, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitSetupPlotAxesLimits* SetupAxesLimits = NewObject<UImGuiToolkitSetupPlotAxesLimits>(OuterObject);
	SetupAxesLimits->XLimits = XLimits;
	SetupAxesLimits->YLimits = YLimits;
	SetupAxesLimits->Condition = Condition;

	if (Container)
		Container->AddWidget(SetupAxesLimits);

	return SetupAxesLimits;
}

UImGuiToolkitSetupPlotAxisLimitsConstraints* UImGuiToolkitFunctionLibrary::CreateImPlotSetupAxisLimitsConstraints(
	EImPlotAxis Axis, double MinValue, double MaxValue, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitSetupPlotAxisLimitsConstraints* Constraints = NewObject<UImGuiToolkitSetupPlotAxisLimitsConstraints>(OuterObject);
	Constraints->Axis = Axis;
	Constraints->MinValue = MinValue;
	Constraints->MaxValue = MaxValue;

	if (Container)
		Container->AddWidget(Constraints);

	return Constraints;
}

UImGuiToolkitSetupPlotAxisZoomConstraints* UImGuiToolkitFunctionLibrary::CreateImPlotSetupAxisZoomConstraints(
	EImPlotAxis Axis, double MinZoom, double MaxZoom, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitSetupPlotAxisZoomConstraints* Constraints = NewObject<UImGuiToolkitSetupPlotAxisZoomConstraints>(OuterObject);
	Constraints->Axis = Axis;
	Constraints->MinZoom = MinZoom;
	Constraints->MaxZoom = MaxZoom;

	if (Container)
		Container->AddWidget(Constraints);

	return Constraints;
}

UImGuiToolkitSetupPlotAxisTicks* UImGuiToolkitFunctionLibrary::CreateImPlotSetupAxisTicks(EImPlotAxis Axis,
	TArray<float> Values, TArray<FText> Labels, bool bKeepDefault, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitSetupPlotAxisTicks* SetupTicks = NewObject<UImGuiToolkitSetupPlotAxisTicks>(OuterObject);
	SetupTicks->Axis = Axis;
	SetupTicks->Values = Values;
	SetupTicks->Labels = Labels;
	SetupTicks->bKeepDefault = bKeepDefault;

	if (Container)
		Container->AddWidget(SetupTicks);

	return SetupTicks;
}

UImGuiToolkitSetupPlotAxisTicksRange* UImGuiToolkitFunctionLibrary::CreateImPlotSetupAxisTicksRange(
	EImPlotAxis Axis, double MinValue, double MaxValue, int32 TickCount, TArray<FText> Labels, bool bKeepDefault,
	UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitSetupPlotAxisTicksRange* SetupTicks = NewObject<UImGuiToolkitSetupPlotAxisTicksRange>(OuterObject);
	SetupTicks->Axis = Axis;
	SetupTicks->MinValue = MinValue;
	SetupTicks->MaxValue = MaxValue;
	SetupTicks->TickCount = TickCount;
	SetupTicks->Labels = Labels;
	SetupTicks->bKeepDefault = bKeepDefault;

	if (Container)
		Container->AddWidget(SetupTicks);

	return SetupTicks;
}

UImGuiToolkitSetupPlotFinish* UImGuiToolkitFunctionLibrary::CreateImPlotSetupFinish(UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitSetupPlotFinish* SetupFinish = NewObject<UImGuiToolkitSetupPlotFinish>(OuterObject);

	if (Container)
		Container->AddWidget(SetupFinish);

	return SetupFinish;
}

UImGuiToolkitSetNextPlotAxisLimits* UImGuiToolkitFunctionLibrary::CreateImPlotSetNextAxisLimits(EImPlotAxis Axis,
	double MinValue, double MaxValue, EImPlotCondition Condition, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitSetNextPlotAxisLimits* SetNextAxisLimits = NewObject<UImGuiToolkitSetNextPlotAxisLimits>(OuterObject);
	SetNextAxisLimits->Axis = Axis;
	SetNextAxisLimits->MinValue = MinValue;
	SetNextAxisLimits->MaxValue = MaxValue;
	SetNextAxisLimits->Condition = Condition;

	if (Container)
		Container->AddWidget(SetNextAxisLimits);

	return SetNextAxisLimits;
}

UImGuiToolkitSetNextPlotAxesLimits* UImGuiToolkitFunctionLibrary::CreateImPlotSetNextAxesLimits(FVector2D XLimits,
	FVector2D YLimits, EImPlotCondition Condition, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitSetNextPlotAxesLimits* SetNextAxesLimits = NewObject<UImGuiToolkitSetNextPlotAxesLimits>(OuterObject);
	SetNextAxesLimits->XLimits = XLimits;
	SetNextAxesLimits->YLimits = YLimits;
	SetNextAxesLimits->Condition = Condition;

	if (Container)
		Container->AddWidget(SetNextAxesLimits);

	return SetNextAxesLimits;
}

UImGuiToolkitSetNextPlotAxisToFit* UImGuiToolkitFunctionLibrary::CreateImPlotSetNextAxisToFit(EImPlotAxis Axis,
	UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitSetNextPlotAxisToFit* SetNextAxisToFit = NewObject<UImGuiToolkitSetNextPlotAxisToFit>(OuterObject);
	SetNextAxisToFit->Axis = Axis;

	if (Container)
		Container->AddWidget(SetNextAxisToFit);

	return SetNextAxisToFit;
}

UImGuiToolkitSetNextPlotAxesToFit* UImGuiToolkitFunctionLibrary::CreateImPlotSetNextAxesToFit(
	UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitSetNextPlotAxesToFit* SetNextAxesToFit = NewObject<UImGuiToolkitSetNextPlotAxesToFit>(OuterObject);

	if (Container)
		Container->AddWidget(SetNextAxesToFit);

	return SetNextAxesToFit;
}

UImGuiToolkitSetPlotAxis* UImGuiToolkitFunctionLibrary::CreateImPlotSetAxis(EImPlotAxis Axis,
	UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitSetPlotAxis* SetAxis = NewObject<UImGuiToolkitSetPlotAxis>(OuterObject);
	SetAxis->Axis = Axis;

	if (Container)
		Container->AddWidget(SetAxis);

	return SetAxis;
}

UImGuiToolkitSetPlotAxes* UImGuiToolkitFunctionLibrary::CreateImPlotSetAxes(EImPlotAxis XAxis, EImPlotAxis YAxis,
	UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitSetPlotAxes* SetAxes = NewObject<UImGuiToolkitSetPlotAxes>(OuterObject);
	SetAxes->XAxis = XAxis;
	SetAxes->YAxis = YAxis;

	if (Container)
		Container->AddWidget(SetAxes);

	return SetAxes;
}

UImGuiToolkitHideNextPlotItem* UImGuiToolkitFunctionLibrary::CreateImPlotHideNextItem(bool bHidden,
	EImPlotCondition Condition, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitHideNextPlotItem* HideNextItem = NewObject<UImGuiToolkitHideNextPlotItem>(OuterObject);
	HideNextItem->bHidden = bHidden;
	HideNextItem->Condition = Condition;

	if (Container)
		Container->AddWidget(HideNextItem);

	return HideNextItem;
}

UImGuiToolkitPlotQuery* UImGuiToolkitFunctionLibrary::CreateImPlotQuery(EImPlotAxis XAxis, EImPlotAxis YAxis,
	UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitPlotQuery* Query = NewObject<UImGuiToolkitPlotQuery>(OuterObject);
	Query->XAxis = XAxis;
	Query->YAxis = YAxis;

	if (Container)
		Container->AddWidget(Query);

	return Query;
}

UImGuiToolkitPlotAxisQuery* UImGuiToolkitFunctionLibrary::CreateImPlotAxisQuery(EImPlotAxis Axis,
	UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitPlotAxisQuery* Query = NewObject<UImGuiToolkitPlotAxisQuery>(OuterObject);
	Query->Axis = Axis;

	if (Container)
		Container->AddWidget(Query);

	return Query;
}

UImGuiToolkitCancelPlotSelection* UImGuiToolkitFunctionLibrary::CreateImPlotCancelSelection(
	UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitCancelPlotSelection* CancelSelection = NewObject<UImGuiToolkitCancelPlotSelection>(OuterObject);

	if (Container)
		Container->AddWidget(CancelSelection);

	return CancelSelection;
}

UImGuiToolkitPlotStairs* UImGuiToolkitFunctionLibrary::CreateImPlotStairs(FText Label, TArray<float> Values,
	TArray<EImPlotStairsFlag> StairsFlags, TArray<EImPlotItemFlag> ItemFlags, double XScale, double XStart,
	UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitPlotStairs* PlotStairs = NewObject<UImGuiToolkitPlotStairs>(OuterObject);
	PlotStairs->CreateUniqueWidgetLabel(Label);
	PlotStairs->Values = Values;
	PlotStairs->StairsFlags = StairsFlags;
	PlotStairs->ItemFlags = ItemFlags;
	PlotStairs->XScale = XScale;
	PlotStairs->XStart = XStart;

	if (Container)
		Container->AddWidget(PlotStairs);

	return PlotStairs;
}

UImGuiToolkitPlotStairsXY* UImGuiToolkitFunctionLibrary::CreateImPlotStairsXY(FText Label,
	TArray<float> XValues, TArray<float> YValues, TArray<EImPlotStairsFlag> StairsFlags,
	TArray<EImPlotItemFlag> ItemFlags, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitPlotStairsXY* PlotStairs = NewObject<UImGuiToolkitPlotStairsXY>(OuterObject);
	PlotStairs->CreateUniqueWidgetLabel(Label);
	PlotStairs->XValues = XValues;
	PlotStairs->YValues = YValues;
	PlotStairs->StairsFlags = StairsFlags;
	PlotStairs->ItemFlags = ItemFlags;

	if (Container)
		Container->AddWidget(PlotStairs);

	return PlotStairs;
}

UImGuiToolkitPlotShaded* UImGuiToolkitFunctionLibrary::CreateImPlotShaded(FText Label, TArray<float> Values,
	TArray<EImPlotItemFlag> ItemFlags, double YReference, double XScale, double XStart,
	UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitPlotShaded* PlotShaded = NewObject<UImGuiToolkitPlotShaded>(OuterObject);
	PlotShaded->CreateUniqueWidgetLabel(Label);
	PlotShaded->Values = Values;
	PlotShaded->ItemFlags = ItemFlags;
	PlotShaded->YReference = YReference;
	PlotShaded->XScale = XScale;
	PlotShaded->XStart = XStart;

	if (Container)
		Container->AddWidget(PlotShaded);

	return PlotShaded;
}

UImGuiToolkitPlotShadedXY* UImGuiToolkitFunctionLibrary::CreateImPlotShadedXY(FText Label,
	TArray<float> XValues, TArray<float> YValues, TArray<EImPlotItemFlag> ItemFlags, double YReference,
	UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitPlotShadedXY* PlotShaded = NewObject<UImGuiToolkitPlotShadedXY>(OuterObject);
	PlotShaded->CreateUniqueWidgetLabel(Label);
	PlotShaded->XValues = XValues;
	PlotShaded->YValues = YValues;
	PlotShaded->ItemFlags = ItemFlags;
	PlotShaded->YReference = YReference;

	if (Container)
		Container->AddWidget(PlotShaded);

	return PlotShaded;
}

UImGuiToolkitPlotShadedBetweenXY* UImGuiToolkitFunctionLibrary::CreateImPlotShadedBetweenXY(FText Label,
	TArray<float> XValues, TArray<float> Y1Values, TArray<float> Y2Values, TArray<EImPlotItemFlag> ItemFlags,
	UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitPlotShadedBetweenXY* PlotShaded = NewObject<UImGuiToolkitPlotShadedBetweenXY>(OuterObject);
	PlotShaded->CreateUniqueWidgetLabel(Label);
	PlotShaded->XValues = XValues;
	PlotShaded->Y1Values = Y1Values;
	PlotShaded->Y2Values = Y2Values;
	PlotShaded->ItemFlags = ItemFlags;

	if (Container)
		Container->AddWidget(PlotShaded);

	return PlotShaded;
}

UImGuiToolkitPlotErrorBars* UImGuiToolkitFunctionLibrary::CreateImPlotErrorBars(FText Label,
	TArray<float> XValues, TArray<float> YValues, TArray<float> ErrorValues,
	TArray<EImPlotErrorBarsFlag> ErrorBarsFlags, TArray<EImPlotItemFlag> ItemFlags, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitPlotErrorBars* PlotErrorBars = NewObject<UImGuiToolkitPlotErrorBars>(OuterObject);
	PlotErrorBars->CreateUniqueWidgetLabel(Label);
	PlotErrorBars->XValues = XValues;
	PlotErrorBars->YValues = YValues;
	PlotErrorBars->ErrorValues = ErrorValues;
	PlotErrorBars->ErrorBarsFlags = ErrorBarsFlags;
	PlotErrorBars->ItemFlags = ItemFlags;

	if (Container)
		Container->AddWidget(PlotErrorBars);

	return PlotErrorBars;
}

UImGuiToolkitPlotErrorBarsNegPos* UImGuiToolkitFunctionLibrary::CreateImPlotErrorBarsNegPos(FText Label,
	TArray<float> XValues, TArray<float> YValues, TArray<float> NegativeErrorValues,
	TArray<float> PositiveErrorValues, TArray<EImPlotErrorBarsFlag> ErrorBarsFlags, TArray<EImPlotItemFlag> ItemFlags,
	UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitPlotErrorBarsNegPos* PlotErrorBars = NewObject<UImGuiToolkitPlotErrorBarsNegPos>(OuterObject);
	PlotErrorBars->CreateUniqueWidgetLabel(Label);
	PlotErrorBars->XValues = XValues;
	PlotErrorBars->YValues = YValues;
	PlotErrorBars->NegativeErrorValues = NegativeErrorValues;
	PlotErrorBars->PositiveErrorValues = PositiveErrorValues;
	PlotErrorBars->ErrorBarsFlags = ErrorBarsFlags;
	PlotErrorBars->ItemFlags = ItemFlags;

	if (Container)
		Container->AddWidget(PlotErrorBars);

	return PlotErrorBars;
}

UImGuiToolkitPlotStems* UImGuiToolkitFunctionLibrary::CreateImPlotStems(FText Label, TArray<float> Values,
	TArray<EImPlotStemsFlag> StemsFlags, TArray<EImPlotItemFlag> ItemFlags, double Reference, double XScale, double XStart,
	UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitPlotStems* PlotStems = NewObject<UImGuiToolkitPlotStems>(OuterObject);
	PlotStems->CreateUniqueWidgetLabel(Label);
	PlotStems->Values = Values;
	PlotStems->StemsFlags = StemsFlags;
	PlotStems->ItemFlags = ItemFlags;
	PlotStems->Reference = Reference;
	PlotStems->XScale = XScale;
	PlotStems->XStart = XStart;

	if (Container)
		Container->AddWidget(PlotStems);

	return PlotStems;
}

UImGuiToolkitPlotStemsXY* UImGuiToolkitFunctionLibrary::CreateImPlotStemsXY(FText Label,
	TArray<float> XValues, TArray<float> YValues, TArray<EImPlotStemsFlag> StemsFlags,
	TArray<EImPlotItemFlag> ItemFlags, double Reference, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitPlotStemsXY* PlotStems = NewObject<UImGuiToolkitPlotStemsXY>(OuterObject);
	PlotStems->CreateUniqueWidgetLabel(Label);
	PlotStems->XValues = XValues;
	PlotStems->YValues = YValues;
	PlotStems->StemsFlags = StemsFlags;
	PlotStems->ItemFlags = ItemFlags;
	PlotStems->Reference = Reference;

	if (Container)
		Container->AddWidget(PlotStems);

	return PlotStems;
}

UImGuiToolkitPlotInfLines* UImGuiToolkitFunctionLibrary::CreateImPlotInfLines(FText Label,
	TArray<float> Values, TArray<EImPlotInfLinesFlag> InfLinesFlags, TArray<EImPlotItemFlag> ItemFlags,
	UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitPlotInfLines* PlotInfLines = NewObject<UImGuiToolkitPlotInfLines>(OuterObject);
	PlotInfLines->CreateUniqueWidgetLabel(Label);
	PlotInfLines->Values = Values;
	PlotInfLines->InfLinesFlags = InfLinesFlags;
	PlotInfLines->ItemFlags = ItemFlags;

	if (Container)
		Container->AddWidget(PlotInfLines);

	return PlotInfLines;
}

UImGuiToolkitPlotPieChart* UImGuiToolkitFunctionLibrary::CreateImPlotPieChart(TArray<FText> Labels,
	TArray<float> Values, TArray<EImPlotPieChartFlag> PieChartFlags, TArray<EImPlotItemFlag> ItemFlags,
	FVector2D Center, double Radius, FString LabelFormat, double Angle0, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitPlotPieChart* PlotPieChart = NewObject<UImGuiToolkitPlotPieChart>(OuterObject);
	PlotPieChart->Labels = Labels;
	PlotPieChart->Values = Values;
	PlotPieChart->PieChartFlags = PieChartFlags;
	PlotPieChart->ItemFlags = ItemFlags;
	PlotPieChart->Center = Center;
	PlotPieChart->Radius = Radius;
	PlotPieChart->LabelFormat = LabelFormat;
	PlotPieChart->Angle0 = Angle0;

	if (Container)
		Container->AddWidget(PlotPieChart);

	return PlotPieChart;
}

UImGuiToolkitPlotHeatmap* UImGuiToolkitFunctionLibrary::CreateImPlotHeatmap(FText Label, TArray<float> Values,
	int32 Rows, int32 Columns, TArray<EImPlotHeatmapFlag> HeatmapFlags, TArray<EImPlotItemFlag> ItemFlags,
	double ScaleMin, double ScaleMax, FString LabelFormat, FVector2D BoundsMin, FVector2D BoundsMax,
	UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitPlotHeatmap* PlotHeatmap = NewObject<UImGuiToolkitPlotHeatmap>(OuterObject);
	PlotHeatmap->CreateUniqueWidgetLabel(Label);
	PlotHeatmap->Values = Values;
	PlotHeatmap->Rows = Rows;
	PlotHeatmap->Columns = Columns;
	PlotHeatmap->HeatmapFlags = HeatmapFlags;
	PlotHeatmap->ItemFlags = ItemFlags;
	PlotHeatmap->ScaleMin = ScaleMin;
	PlotHeatmap->ScaleMax = ScaleMax;
	PlotHeatmap->LabelFormat = LabelFormat;
	PlotHeatmap->BoundsMin = BoundsMin;
	PlotHeatmap->BoundsMax = BoundsMax;

	if (Container)
		Container->AddWidget(PlotHeatmap);

	return PlotHeatmap;
}

UImGuiToolkitPlotHistogram* UImGuiToolkitFunctionLibrary::CreateImPlotHistogram(FText Label,
	TArray<float> Values, TArray<EImPlotHistogramFlag> HistogramFlags, TArray<EImPlotItemFlag> ItemFlags,
	int32 Bins, double BarScale, bool bUseRange, FVector2D Range, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitPlotHistogram* PlotHistogram = NewObject<UImGuiToolkitPlotHistogram>(OuterObject);
	PlotHistogram->CreateUniqueWidgetLabel(Label);
	PlotHistogram->Values = Values;
	PlotHistogram->HistogramFlags = HistogramFlags;
	PlotHistogram->ItemFlags = ItemFlags;
	PlotHistogram->Bins = Bins;
	PlotHistogram->BarScale = BarScale;
	PlotHistogram->bUseRange = bUseRange;
	PlotHistogram->Range = Range;

	if (Container)
		Container->AddWidget(PlotHistogram);

	return PlotHistogram;
}

UImGuiToolkitPlotHistogram2D* UImGuiToolkitFunctionLibrary::CreateImPlotHistogram2D(FText Label,
	TArray<float> XValues, TArray<float> YValues, TArray<EImPlotHistogramFlag> HistogramFlags,
	TArray<EImPlotItemFlag> ItemFlags, int32 XBins, int32 YBins, bool bUseRange, FVector2D XRange,
	FVector2D YRange, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitPlotHistogram2D* PlotHistogram = NewObject<UImGuiToolkitPlotHistogram2D>(OuterObject);
	PlotHistogram->CreateUniqueWidgetLabel(Label);
	PlotHistogram->XValues = XValues;
	PlotHistogram->YValues = YValues;
	PlotHistogram->HistogramFlags = HistogramFlags;
	PlotHistogram->ItemFlags = ItemFlags;
	PlotHistogram->XBins = XBins;
	PlotHistogram->YBins = YBins;
	PlotHistogram->bUseRange = bUseRange;
	PlotHistogram->XRange = XRange;
	PlotHistogram->YRange = YRange;

	if (Container)
		Container->AddWidget(PlotHistogram);

	return PlotHistogram;
}

UImGuiToolkitPlotDigital* UImGuiToolkitFunctionLibrary::CreateImPlotDigital(FText Label, TArray<float> XValues,
	TArray<float> YValues, TArray<EImPlotItemFlag> ItemFlags, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitPlotDigital* PlotDigital = NewObject<UImGuiToolkitPlotDigital>(OuterObject);
	PlotDigital->CreateUniqueWidgetLabel(Label);
	PlotDigital->XValues = XValues;
	PlotDigital->YValues = YValues;
	PlotDigital->ItemFlags = ItemFlags;

	if (Container)
		Container->AddWidget(PlotDigital);

	return PlotDigital;
}

UImGuiToolkitPlotImage* UImGuiToolkitFunctionLibrary::CreateImPlotImage(FText Label, UTexture2D* Texture,
	FVector2D BoundsMin, FVector2D BoundsMax, TArray<EImPlotItemFlag> ItemFlags, FVector2D UV0, FVector2D UV1,
	FLinearColor TintColor, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitPlotImage* PlotImage = NewObject<UImGuiToolkitPlotImage>(OuterObject);
	PlotImage->CreateUniqueWidgetLabel(Label);
	PlotImage->ResourceObject = Texture;
	PlotImage->BoundsMin = BoundsMin;
	PlotImage->BoundsMax = BoundsMax;
	PlotImage->ItemFlags = ItemFlags;
	PlotImage->UV0 = UV0;
	PlotImage->UV1 = UV1;
	PlotImage->TintColor = TintColor;

	if (Container)
		Container->AddWidget(PlotImage);

	return PlotImage;
}

UImGuiToolkitPlotImage* UImGuiToolkitFunctionLibrary::CreateImPlotMaterialImage(FText Label,
	UMaterialInterface* Material, FVector2D BoundsMin, FVector2D BoundsMax, TArray<EImPlotItemFlag> ItemFlags,
	FVector2D UV0, FVector2D UV1, FLinearColor TintColor, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitPlotImage* PlotImage = NewObject<UImGuiToolkitPlotImage>(OuterObject);
	PlotImage->CreateUniqueWidgetLabel(Label);
	PlotImage->ResourceObject = Material;
	PlotImage->BoundsMin = BoundsMin;
	PlotImage->BoundsMax = BoundsMax;
	PlotImage->ItemFlags = ItemFlags;
	PlotImage->UV0 = UV0;
	PlotImage->UV1 = UV1;
	PlotImage->TintColor = TintColor;

	if (Container)
		Container->AddWidget(PlotImage);

	return PlotImage;
}

UImGuiToolkitPlotText* UImGuiToolkitFunctionLibrary::CreateImPlotText(FText Text, FVector2D Position,
	TArray<EImPlotTextFlag> TextFlags, TArray<EImPlotItemFlag> ItemFlags, FVector2D PixelOffset,
	UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitPlotText* PlotText = NewObject<UImGuiToolkitPlotText>(OuterObject);
	PlotText->Text = Text;
	PlotText->Position = Position;
	PlotText->TextFlags = TextFlags;
	PlotText->ItemFlags = ItemFlags;
	PlotText->PixelOffset = PixelOffset;

	if (Container)
		Container->AddWidget(PlotText);

	return PlotText;
}

UImGuiToolkitPlotDummy* UImGuiToolkitFunctionLibrary::CreateImPlotDummy(FText Label, TArray<EImPlotItemFlag> ItemFlags,
	UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitPlotDummy* PlotDummy = NewObject<UImGuiToolkitPlotDummy>(OuterObject);
	PlotDummy->CreateUniqueWidgetLabel(Label);
	PlotDummy->ItemFlags = ItemFlags;

	if (Container)
		Container->AddWidget(PlotDummy);

	return PlotDummy;
}

UImGuiToolkitPlotDragPoint* UImGuiToolkitFunctionLibrary::CreateImPlotDragPoint(int32 ID, double X, double Y,
	FLinearColor Color, TArray<EImPlotDragToolFlag> DragToolFlags, float Size, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitPlotDragPoint* DragPoint = NewObject<UImGuiToolkitPlotDragPoint>(OuterObject);
	DragPoint->ID = ID;
	DragPoint->X = X;
	DragPoint->Y = Y;
	DragPoint->Color = Color;
	DragPoint->DragToolFlags = DragToolFlags;
	DragPoint->Size = Size;

	if (Container)
		Container->AddWidget(DragPoint);

	return DragPoint;
}

UImGuiToolkitPlotDragLineX* UImGuiToolkitFunctionLibrary::CreateImPlotDragLineX(int32 ID, double X,
	FLinearColor Color, TArray<EImPlotDragToolFlag> DragToolFlags, float Thickness,
	UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitPlotDragLineX* DragLine = NewObject<UImGuiToolkitPlotDragLineX>(OuterObject);
	DragLine->ID = ID;
	DragLine->X = X;
	DragLine->Color = Color;
	DragLine->DragToolFlags = DragToolFlags;
	DragLine->Thickness = Thickness;

	if (Container)
		Container->AddWidget(DragLine);

	return DragLine;
}

UImGuiToolkitPlotDragLineY* UImGuiToolkitFunctionLibrary::CreateImPlotDragLineY(int32 ID, double Y,
	FLinearColor Color, TArray<EImPlotDragToolFlag> DragToolFlags, float Thickness,
	UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitPlotDragLineY* DragLine = NewObject<UImGuiToolkitPlotDragLineY>(OuterObject);
	DragLine->ID = ID;
	DragLine->Y = Y;
	DragLine->Color = Color;
	DragLine->DragToolFlags = DragToolFlags;
	DragLine->Thickness = Thickness;

	if (Container)
		Container->AddWidget(DragLine);

	return DragLine;
}

UImGuiToolkitPlotDragRect* UImGuiToolkitFunctionLibrary::CreateImPlotDragRect(int32 ID, double X1, double Y1,
	double X2, double Y2, FLinearColor Color, TArray<EImPlotDragToolFlag> DragToolFlags,
	UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitPlotDragRect* DragRect = NewObject<UImGuiToolkitPlotDragRect>(OuterObject);
	DragRect->ID = ID;
	DragRect->X1 = X1;
	DragRect->Y1 = Y1;
	DragRect->X2 = X2;
	DragRect->Y2 = Y2;
	DragRect->Color = Color;
	DragRect->DragToolFlags = DragToolFlags;

	if (Container)
		Container->AddWidget(DragRect);

	return DragRect;
}

UImGuiToolkitPlotAnnotation* UImGuiToolkitFunctionLibrary::CreateImPlotAnnotation(FText Text, FVector2D Position,
	FLinearColor Color, FVector2D PixelOffset, bool bClamp, bool bRound, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitPlotAnnotation* Annotation = NewObject<UImGuiToolkitPlotAnnotation>(OuterObject);
	Annotation->Text = Text;
	Annotation->Position = Position;
	Annotation->Color = Color;
	Annotation->PixelOffset = PixelOffset;
	Annotation->bClamp = bClamp;
	Annotation->bRound = bRound;

	if (Container)
		Container->AddWidget(Annotation);

	return Annotation;
}

UImGuiToolkitPlotTagX* UImGuiToolkitFunctionLibrary::CreateImPlotTagX(double X, FLinearColor Color, FText Text,
	bool bRound, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitPlotTagX* Tag = NewObject<UImGuiToolkitPlotTagX>(OuterObject);
	Tag->X = X;
	Tag->Color = Color;
	Tag->Text = Text;
	Tag->bRound = bRound;

	if (Container)
		Container->AddWidget(Tag);

	return Tag;
}

UImGuiToolkitPlotTagY* UImGuiToolkitFunctionLibrary::CreateImPlotTagY(double Y, FLinearColor Color, FText Text,
	bool bRound, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitPlotTagY* Tag = NewObject<UImGuiToolkitPlotTagY>(OuterObject);
	Tag->Y = Y;
	Tag->Color = Color;
	Tag->Text = Text;
	Tag->bRound = bRound;

	if (Container)
		Container->AddWidget(Tag);

	return Tag;
}

UImGuiToolkitPushPlotStyleColor* UImGuiToolkitFunctionLibrary::CreateImPlotPushStyleColor(
	EImPlotStyleColor StyleColor, FLinearColor Color, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitPushPlotStyleColor* PushStyleColor = NewObject<UImGuiToolkitPushPlotStyleColor>(OuterObject);
	PushStyleColor->StyleColor = StyleColor;
	PushStyleColor->Color = Color;

	if (Container)
		Container->AddWidget(PushStyleColor);

	return PushStyleColor;
}

UImGuiToolkitPopPlotStyleColor* UImGuiToolkitFunctionLibrary::CreateImPlotPopStyleColor(int32 Count,
	UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitPopPlotStyleColor* PopStyleColor = NewObject<UImGuiToolkitPopPlotStyleColor>(OuterObject);
	PopStyleColor->Count = Count;

	if (Container)
		Container->AddWidget(PopStyleColor);

	return PopStyleColor;
}

UImGuiToolkitPushPlotStyleVar* UImGuiToolkitFunctionLibrary::CreateImPlotPushStyleVar(EImPlotStyleVar StyleVar,
	float FloatValue, int32 IntValue, FVector2D Vector2DValue, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitPushPlotStyleVar* PushStyleVar = NewObject<UImGuiToolkitPushPlotStyleVar>(OuterObject);
	PushStyleVar->StyleVar = StyleVar;
	PushStyleVar->FloatValue = FloatValue;
	PushStyleVar->IntValue = IntValue;
	PushStyleVar->Vector2DValue = Vector2DValue;

	if (Container)
		Container->AddWidget(PushStyleVar);

	return PushStyleVar;
}

UImGuiToolkitPopPlotStyleVar* UImGuiToolkitFunctionLibrary::CreateImPlotPopStyleVar(int32 Count,
	UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitPopPlotStyleVar* PopStyleVar = NewObject<UImGuiToolkitPopPlotStyleVar>(OuterObject);
	PopStyleVar->Count = Count;

	if (Container)
		Container->AddWidget(PopStyleVar);

	return PopStyleVar;
}

UImGuiToolkitSetNextPlotLineStyle* UImGuiToolkitFunctionLibrary::CreateImPlotSetNextLineStyle(
	FLinearColor Color, float Weight, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitSetNextPlotLineStyle* LineStyle = NewObject<UImGuiToolkitSetNextPlotLineStyle>(OuterObject);
	LineStyle->Color = Color;
	LineStyle->Weight = Weight;

	if (Container)
		Container->AddWidget(LineStyle);

	return LineStyle;
}

UImGuiToolkitSetNextPlotFillStyle* UImGuiToolkitFunctionLibrary::CreateImPlotSetNextFillStyle(
	FLinearColor Color, float AlphaMod, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitSetNextPlotFillStyle* FillStyle = NewObject<UImGuiToolkitSetNextPlotFillStyle>(OuterObject);
	FillStyle->Color = Color;
	FillStyle->AlphaMod = AlphaMod;

	if (Container)
		Container->AddWidget(FillStyle);

	return FillStyle;
}

UImGuiToolkitSetNextPlotMarkerStyle* UImGuiToolkitFunctionLibrary::CreateImPlotSetNextMarkerStyle(
	EImPlotMarker Marker, FLinearColor FillColor, FLinearColor OutlineColor, float Size, float Weight,
	UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitSetNextPlotMarkerStyle* MarkerStyle = NewObject<UImGuiToolkitSetNextPlotMarkerStyle>(OuterObject);
	MarkerStyle->Marker = Marker;
	MarkerStyle->FillColor = FillColor;
	MarkerStyle->OutlineColor = OutlineColor;
	MarkerStyle->Size = Size;
	MarkerStyle->Weight = Weight;

	if (Container)
		Container->AddWidget(MarkerStyle);

	return MarkerStyle;
}

UImGuiToolkitSetNextPlotErrorBarStyle* UImGuiToolkitFunctionLibrary::CreateImPlotSetNextErrorBarStyle(
	FLinearColor Color, float Size, float Weight, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitSetNextPlotErrorBarStyle* ErrorBarStyle = NewObject<UImGuiToolkitSetNextPlotErrorBarStyle>(OuterObject);
	ErrorBarStyle->Color = Color;
	ErrorBarStyle->Size = Size;
	ErrorBarStyle->Weight = Weight;

	if (Container)
		Container->AddWidget(ErrorBarStyle);

	return ErrorBarStyle;
}

UImGuiToolkitStylePlotColors* UImGuiToolkitFunctionLibrary::CreateImPlotStyleColors(EImPlotStylePreset Preset,
	UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitStylePlotColors* StyleColors = NewObject<UImGuiToolkitStylePlotColors>(OuterObject);
	StyleColors->Preset = Preset;

	if (Container)
		Container->AddWidget(StyleColors);

	return StyleColors;
}

UImGuiToolkitPushPlotColormap* UImGuiToolkitFunctionLibrary::CreateImPlotPushColormap(EImPlotColormap Colormap,
	UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitPushPlotColormap* PushColormap = NewObject<UImGuiToolkitPushPlotColormap>(OuterObject);
	PushColormap->Colormap = Colormap;

	if (Container)
		Container->AddWidget(PushColormap);

	return PushColormap;
}

UImGuiToolkitPopPlotColormap* UImGuiToolkitFunctionLibrary::CreateImPlotPopColormap(int32 Count,
	UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitPopPlotColormap* PopColormap = NewObject<UImGuiToolkitPopPlotColormap>(OuterObject);
	PopColormap->Count = Count;

	if (Container)
		Container->AddWidget(PopColormap);

	return PopColormap;
}

UImGuiToolkitPlotColormapScale* UImGuiToolkitFunctionLibrary::CreateImPlotColormapScale(FText Label,
	double ScaleMin, double ScaleMax, TArray<EImPlotColormapScaleFlag> ColormapScaleFlags, FVector2D Size,
	FString Format, EImPlotColormap Colormap, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitPlotColormapScale* ColormapScale = NewObject<UImGuiToolkitPlotColormapScale>(OuterObject);
	ColormapScale->CreateUniqueWidgetLabel(Label);
	ColormapScale->ScaleMin = ScaleMin;
	ColormapScale->ScaleMax = ScaleMax;
	ColormapScale->Size = Size;
	ColormapScale->Format = Format;
	ColormapScale->Colormap = Colormap;
	ColormapScale->ColormapScaleFlags = ColormapScaleFlags;

	if (Container)
		Container->AddWidget(ColormapScale);

	return ColormapScale;
}

UImGuiToolkitPlotColormapSlider* UImGuiToolkitFunctionLibrary::CreateImPlotColormapSlider(FText Label,
	float Value, FString Format, EImPlotColormap Colormap, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitPlotColormapSlider* ColormapSlider = NewObject<UImGuiToolkitPlotColormapSlider>(OuterObject);
	ColormapSlider->CreateUniqueWidgetLabel(Label);
	ColormapSlider->Value = Value;
	ColormapSlider->Format = Format;
	ColormapSlider->Colormap = Colormap;

	if (Container)
		Container->AddWidget(ColormapSlider);

	return ColormapSlider;
}

UImGuiToolkitPlotColormapButton* UImGuiToolkitFunctionLibrary::CreateImPlotColormapButton(FText Label,
	FVector2D Size, EImPlotColormap Colormap, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitPlotColormapButton* ColormapButton = NewObject<UImGuiToolkitPlotColormapButton>(OuterObject);
	ColormapButton->CreateUniqueWidgetLabel(Label);
	ColormapButton->Size = Size;
	ColormapButton->Colormap = Colormap;

	if (Container)
		Container->AddWidget(ColormapButton);

	return ColormapButton;
}

UImGuiToolkitBeginTabBar* UImGuiToolkitFunctionLibrary::CreateImGuiBeginTabBar(FText Label,
	UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitBeginTabBar* BeginTabBar = NewObject<UImGuiToolkitBeginTabBar>(OuterObject);
	BeginTabBar->CreateUniqueWidgetLabel(Label);

	if (Container)
		Container->AddWidget(BeginTabBar);

	return BeginTabBar;
}

UImGuiToolkitEndTabBar* UImGuiToolkitFunctionLibrary::EndImGuiTabBar(UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitEndTabBar* EndTabBar = NewObject<UImGuiToolkitEndTabBar>(OuterObject);

	if (Container)
		Container->AddWidget(EndTabBar);

	return EndTabBar;
}

UImGuiToolkiBeginTabItem* UImGuiToolkitFunctionLibrary::CreateImGuiBeginTabItem(FText Label, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkiBeginTabItem* BeginTabItem = NewObject<UImGuiToolkiBeginTabItem>(OuterObject);
	BeginTabItem->CreateUniqueWidgetLabel(Label);

	if (Container)
		Container->AddWidget(BeginTabItem);

	return BeginTabItem;
}

UImGuiToolkitEndTabItem* UImGuiToolkitFunctionLibrary::EndImGuiTabItem(UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitEndTabItem* EndTabItem = NewObject<UImGuiToolkitEndTabItem>(OuterObject);

	if (Container)
		Container->AddWidget(EndTabItem);

	return EndTabItem;
}

UImGuiToolkitCombo* UImGuiToolkitFunctionLibrary::CreateImGuiCombo(FText Label, TArray<FText> ComboItems, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitCombo* Combo = NewObject<UImGuiToolkitCombo>(OuterObject);
	Combo->CreateUniqueWidgetLabel(Label);
	Combo->ComboItems = ComboItems;

	if (Container)
		Container->AddWidget(Combo);

	return Combo;
}

UImGuiToolkitBeginCombo* UImGuiToolkitFunctionLibrary::CreateImGuiBeginCombo(FText Label, FText PreviewValue,
	TArray<EImGuiComboFlag> ComboFlags, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitBeginCombo* BeginCombo = NewObject<UImGuiToolkitBeginCombo>(OuterObject);
	BeginCombo->CreateUniqueWidgetLabel(Label);
	BeginCombo->PreviewValue = PreviewValue;
	BeginCombo->ComboFlags = ComboFlags;

	if (Container)
		Container->AddWidget(BeginCombo);

	return BeginCombo;
}

UImGuiToolkitDragInt* UImGuiToolkitFunctionLibrary::CreateImGuiDragInt(FText Label, int32 InitialValue, int32 MinValue, int32 MaxValue, float Speed, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitDragInt* DragInt = NewObject<UImGuiToolkitDragInt>(OuterObject);
	DragInt->CreateUniqueWidgetLabel(Label);
	DragInt->Value = InitialValue;
	DragInt->MinValue = MinValue;
	DragInt->MaxValue = MaxValue;
	DragInt->Speed = Speed;

	if (Container)
		Container->AddWidget(DragInt);

	return DragInt;
}

UImGuiToolkitDragIntPoint* UImGuiToolkitFunctionLibrary::CreateImGuiDragIntPoint(FText Label,
	FIntPoint InitialValue, int32 MinValue, int32 MaxValue, float Speed, FString Format, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitDragIntPoint* DragIntPoint = NewObject<UImGuiToolkitDragIntPoint>(OuterObject);
	DragIntPoint->CreateUniqueWidgetLabel(Label);
	DragIntPoint->Value = InitialValue;
	DragIntPoint->MinValue = MinValue;
	DragIntPoint->MaxValue = MaxValue;
	DragIntPoint->Speed = Speed;
	DragIntPoint->Format = Format;

	if (Container)
		Container->AddWidget(DragIntPoint);

	return DragIntPoint;
}

UImGuiToolkitDragIntVector* UImGuiToolkitFunctionLibrary::CreateImGuiDragIntVector(FText Label,
	FIntVector InitialValue, int32 MinValue, int32 MaxValue, float Speed, FString Format, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitDragIntVector* DragIntVector = NewObject<UImGuiToolkitDragIntVector>(OuterObject);
	DragIntVector->CreateUniqueWidgetLabel(Label);
	DragIntVector->Value = InitialValue;
	DragIntVector->MinValue = MinValue;
	DragIntVector->MaxValue = MaxValue;
	DragIntVector->Speed = Speed;
	DragIntVector->Format = Format;

	if (Container)
		Container->AddWidget(DragIntVector);

	return DragIntVector;
}

UImGuiToolkitDragIntVector4* UImGuiToolkitFunctionLibrary::CreateImGuiDragIntVector4(FText Label,
	FIntVector4 InitialValue, int32 MinValue, int32 MaxValue, float Speed, FString Format, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitDragIntVector4* DragIntVector4 = NewObject<UImGuiToolkitDragIntVector4>(OuterObject);
	DragIntVector4->CreateUniqueWidgetLabel(Label);
	DragIntVector4->Value = InitialValue;
	DragIntVector4->MinValue = MinValue;
	DragIntVector4->MaxValue = MaxValue;
	DragIntVector4->Speed = Speed;
	DragIntVector4->Format = Format;

	if (Container)
		Container->AddWidget(DragIntVector4);

	return DragIntVector4;
}

UImGuiToolkitSeparator* UImGuiToolkitFunctionLibrary::CreateImGuiSeparator(UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitSeparator* Separator = NewObject<UImGuiToolkitSeparator>(OuterObject);

	if (Container)
		Container->AddWidget(Separator);

	return Separator;
}

UImGuiToolkitNewLine* UImGuiToolkitFunctionLibrary::CreateImGuiNewLine(UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitNewLine* NewLine = NewObject<UImGuiToolkitNewLine>(OuterObject);
	
	if (Container)
		Container->AddWidget(NewLine);

	return NewLine;
}

UImGuiToolkitDummy* UImGuiToolkitFunctionLibrary::CreateImGuiDummy(FVector2D Size,
	UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitDummy* Dummy = NewObject<UImGuiToolkitDummy>(OuterObject);
	Dummy->Size = Size;

	if (Container)
		Container->AddWidget(Dummy);

	return Dummy;
}

UImGuiToolkitTextColored* UImGuiToolkitFunctionLibrary::CreateImGuiTextColored(FLinearColor Color, FText Text, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitTextColored* TextColored = NewObject<UImGuiToolkitTextColored>(OuterObject);
	TextColored->Color = Color;
	TextColored->Text = Text;

	if (Container)
		Container->AddWidget(TextColored);

	return TextColored;
}

UImGuiToolkitTextWrapped* UImGuiToolkitFunctionLibrary::CreateImGuiTextWrapped(FText Text,
	UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitTextWrapped* TextWrapped = NewObject<UImGuiToolkitTextWrapped>(OuterObject);
	TextWrapped->Text = Text;

	if (Container)
		Container->AddWidget(TextWrapped);

	return TextWrapped;
}

UImGuiToolkitSmallButton* UImGuiToolkitFunctionLibrary::CreateImGuiSmallButton(FText Label,
	FText Tooltip, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitSmallButton* SmallButton = NewObject<UImGuiToolkitSmallButton>(OuterObject);
	SmallButton->CreateUniqueWidgetLabel(Label);
	SmallButton->Tooltip = Tooltip;

	if (Container)
		Container->AddWidget(SmallButton);

	return SmallButton;
}

UImGuiToolkitArrowButton* UImGuiToolkitFunctionLibrary::CreateImGuiArrowButton(EImGuiToolkitDir CardinalDirection, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitArrowButton* ArrowButton = NewObject<UImGuiToolkitArrowButton>(OuterObject);
	ArrowButton->CardinalDirection = CardinalDirection;
	
	if (Container)
		Container->AddWidget(ArrowButton);

	return ArrowButton;
}

UImGuiToolkitRadioButtonGroup* UImGuiToolkitFunctionLibrary::CreateImGuiRadioButtonGroup(TArray<FText> RadioButtonLabels, int32 InitialIndex, EImGuiToolkitRadioButtonDirection Direction, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitRadioButtonGroup* RadioButtonGroup = NewObject<UImGuiToolkitRadioButtonGroup>(OuterObject);
	RadioButtonGroup->RadioItems = RadioButtonLabels;
	RadioButtonGroup->SelectedIndex = InitialIndex;
	RadioButtonGroup->PreviouslySelectedIndex = InitialIndex;
	RadioButtonGroup->Direction = Direction;

	if (Container)
		Container->AddWidget(RadioButtonGroup);

	return RadioButtonGroup;
}

UImGuiToolkitProgressBar* UImGuiToolkitFunctionLibrary::CreateImGuiProgressBar(float Percent, FVector2D Size, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitProgressBar* ProgressBar = NewObject<UImGuiToolkitProgressBar>(OuterObject);
	ProgressBar->Percent = Percent;
	ProgressBar->Size = Size;

	if (Container)
		Container->AddWidget(ProgressBar);

	return ProgressBar;
}

UImGuiToolkitBullet* UImGuiToolkitFunctionLibrary::CreateImGuiBullet(UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitBullet* Bullet = NewObject<UImGuiToolkitBullet>(OuterObject);

	if (Container)
		Container->AddWidget(Bullet);

	return Bullet;
}

UImGuiToolkitBeginDisabled* UImGuiToolkitFunctionLibrary::CreateImGuiBeginDisabled(bool bDisabled, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitBeginDisabled* BeginDisabled = NewObject<UImGuiToolkitBeginDisabled>(OuterObject);
	BeginDisabled->bDisabled = bDisabled;

	if (Container)
		Container->AddWidget(BeginDisabled);

	return BeginDisabled;
}

UImGuiToolkitEndDisabled* UImGuiToolkitFunctionLibrary::CreateImGuiEndDisabled(UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitEndDisabled* EndDisabled = NewObject<UImGuiToolkitEndDisabled>(OuterObject);

	if (Container)
		Container->AddWidget(EndDisabled);

	return EndDisabled;
}

UImGuiToolkitPushStyleColor* UImGuiToolkitFunctionLibrary::CreateImGuiPushStyleColor(EImGuiStyleColor StyleColor,
	FLinearColor Color, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitPushStyleColor* PushStyleColor = NewObject<UImGuiToolkitPushStyleColor>(OuterObject);
	PushStyleColor->StyleColor = StyleColor;
	PushStyleColor->Color = Color;

	if (Container)
		Container->AddWidget(PushStyleColor);

	return PushStyleColor;
}

UImGuiToolkitPopStyleColor* UImGuiToolkitFunctionLibrary::CreateImGuiPopStyleColor(int32 Count, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitPopStyleColor* PopStyleColor = NewObject<UImGuiToolkitPopStyleColor>(OuterObject);
	PopStyleColor->Count = Count;

	if (Container)
		Container->AddWidget(PopStyleColor);

	return PopStyleColor;
}

UImGuiToolkitPushStyleVar* UImGuiToolkitFunctionLibrary::CreateImGuiPushStyleVar(EImGuiStyleVar StyleVar,
	float FloatValue, FVector2D Vector2DValue, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitPushStyleVar* PushStyleVar = NewObject<UImGuiToolkitPushStyleVar>(OuterObject);
	PushStyleVar->StyleVar = StyleVar;
	PushStyleVar->FloatValue = FloatValue;
	PushStyleVar->Vector2DValue = Vector2DValue;

	if (Container)
		Container->AddWidget(PushStyleVar);

	return PushStyleVar;
}

UImGuiToolkitPopStyleVar* UImGuiToolkitFunctionLibrary::CreateImGuiPopStyleVar(int32 Count, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitPopStyleVar* PopStyleVar = NewObject<UImGuiToolkitPopStyleVar>(OuterObject);
	PopStyleVar->Count = Count;

	if (Container)
		Container->AddWidget(PopStyleVar);

	return PopStyleVar;
}

UImGuiToolkitTextLinkOpenURL* UImGuiToolkitFunctionLibrary::CreateTextLinkOpenURL(FText Text, FString URL, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitTextLinkOpenURL* TextLinkOpenURL = NewObject<UImGuiToolkitTextLinkOpenURL>(OuterObject);
	TextLinkOpenURL->Text = Text;
	TextLinkOpenURL->URL = URL;

	if (Container)
		Container->AddWidget(TextLinkOpenURL);

	return TextLinkOpenURL;
}

UImGuiToolkitDragFloat* UImGuiToolkitFunctionLibrary::CreateImGuiDragFloat(FText Label,
	float InitialValue, float MinValue, float MaxValue, float Speed, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitDragFloat* DragFloat = NewObject<UImGuiToolkitDragFloat>(OuterObject);
	DragFloat->CreateUniqueWidgetLabel(Label);
	DragFloat->Value = InitialValue;
	DragFloat->MinValue = MinValue;
	DragFloat->MaxValue = MaxValue;
	DragFloat->Speed = Speed;

	if (Container)
		Container->AddWidget(DragFloat);

	return DragFloat;
}

UImGuiToolkitDragVector2D* UImGuiToolkitFunctionLibrary::CreateImGuiDragVector2D(FText Label,
	FVector2D InitialValue, float MinValue, float MaxValue, float Speed, FString Format, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitDragVector2D* DragVector2D = NewObject<UImGuiToolkitDragVector2D>(OuterObject);
	DragVector2D->CreateUniqueWidgetLabel(Label);
	DragVector2D->Value = InitialValue;
	DragVector2D->MinValue = MinValue;
	DragVector2D->MaxValue = MaxValue;
	DragVector2D->Speed = Speed;
	DragVector2D->Format = Format;

	if (Container)
		Container->AddWidget(DragVector2D);

	return DragVector2D;
}

UImGuiToolkitDragVector* UImGuiToolkitFunctionLibrary::CreateImGuiDragVector(FText Label,
	FVector InitialValue, float MinValue, float MaxValue, float Speed, FString Format, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitDragVector* DragVector = NewObject<UImGuiToolkitDragVector>(OuterObject);
	DragVector->CreateUniqueWidgetLabel(Label);
	DragVector->Value = InitialValue;
	DragVector->MinValue = MinValue;
	DragVector->MaxValue = MaxValue;
	DragVector->Speed = Speed;
	DragVector->Format = Format;

	if (Container)
		Container->AddWidget(DragVector);

	return DragVector;
}

UImGuiToolkitDragVector4* UImGuiToolkitFunctionLibrary::CreateImGuiDragVector4(FText Label,
	FVector4 InitialValue, float MinValue, float MaxValue, float Speed, FString Format, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitDragVector4* DragVector4 = NewObject<UImGuiToolkitDragVector4>(OuterObject);
	DragVector4->CreateUniqueWidgetLabel(Label);
	DragVector4->Value = InitialValue;
	DragVector4->MinValue = MinValue;
	DragVector4->MaxValue = MaxValue;
	DragVector4->Speed = Speed;
	DragVector4->Format = Format;

	if (Container)
		Container->AddWidget(DragVector4);

	return DragVector4;
}

UImGuiToolkitSliderFloat* UImGuiToolkitFunctionLibrary::CreateImGuiSliderFloat(FText Label,
	float Value, float MinValue, float MaxValue, FString Format, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitSliderFloat* SliderFloat = NewObject<UImGuiToolkitSliderFloat>(OuterObject);
	SliderFloat->CreateUniqueWidgetLabel(Label);
	SliderFloat->Value = Value;
	SliderFloat->MinValue = MinValue;
	SliderFloat->MaxValue = MaxValue;
	SliderFloat->Format = Format;

	if (Container)
		Container->AddWidget(SliderFloat);

	return SliderFloat;
}

UImGuiToolkitSliderVector2D* UImGuiToolkitFunctionLibrary::CreateImGuiSliderVector2D(FText Label,
	FVector2D Value, float MinValue, float MaxValue, FString Format, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitSliderVector2D* SliderVector2D = NewObject<UImGuiToolkitSliderVector2D>(OuterObject);
	SliderVector2D->CreateUniqueWidgetLabel(Label);
	SliderVector2D->Value = Value;
	SliderVector2D->MinValue = MinValue;
	SliderVector2D->MaxValue = MaxValue;
	SliderVector2D->Format = Format;

	if (Container)
		Container->AddWidget(SliderVector2D);

	return SliderVector2D;
}

UImGuiToolkitSliderVector* UImGuiToolkitFunctionLibrary::CreateImGuiSliderVector(FText Label,
	FVector Value, float MinValue, float MaxValue, FString Format, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitSliderVector* SliderVector = NewObject<UImGuiToolkitSliderVector>(OuterObject);
	SliderVector->CreateUniqueWidgetLabel(Label);
	SliderVector->Value = Value;
	SliderVector->MinValue = MinValue;
	SliderVector->MaxValue = MaxValue;
	SliderVector->Format = Format;

	if (Container)
		Container->AddWidget(SliderVector);

	return SliderVector;
}

UImGuiToolkitSliderVector4* UImGuiToolkitFunctionLibrary::CreateImGuiSliderVector4(FText Label,
	FVector4 Value, float MinValue, float MaxValue, FString Format, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitSliderVector4* SliderVector4 = NewObject<UImGuiToolkitSliderVector4>(OuterObject);
	SliderVector4->CreateUniqueWidgetLabel(Label);
	SliderVector4->Value = Value;
	SliderVector4->MinValue = MinValue;
	SliderVector4->MaxValue = MaxValue;
	SliderVector4->Format = Format;

	if (Container)
		Container->AddWidget(SliderVector4);

	return SliderVector4;
}

UImGuiToolkitSliderAngle* UImGuiToolkitFunctionLibrary::CreateImGuiSliderAngle(FText Label,
	float AngleDegrees, float MinDegrees, float MaxDegrees, FString Format, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitSliderAngle* SliderAngle = NewObject<UImGuiToolkitSliderAngle>(OuterObject);
	SliderAngle->CreateUniqueWidgetLabel(Label);
	SliderAngle->AngleDegrees = AngleDegrees;
	SliderAngle->MinDegrees = MinDegrees;
	SliderAngle->MaxDegrees = MaxDegrees;
	SliderAngle->Format = Format;

	if (Container)
		Container->AddWidget(SliderAngle);

	return SliderAngle;
}

UImGuiToolkitSliderInt* UImGuiToolkitFunctionLibrary::CreateImGuiSliderInt(FText Label,
	int32 Value, int32 MinValue, int32 MaxValue, FString Format, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitSliderInt* SliderInt = NewObject<UImGuiToolkitSliderInt>(OuterObject);
	SliderInt->CreateUniqueWidgetLabel(Label);
	SliderInt->Value = Value;
	SliderInt->MinValue = MinValue;
	SliderInt->MaxValue = MaxValue;
	SliderInt->Format = Format;

	if (Container)
		Container->AddWidget(SliderInt);

	return SliderInt;
}

UImGuiToolkitVerticalSliderFloat* UImGuiToolkitFunctionLibrary::CreateImGuiVerticalSliderFloat(FText Label,
	float Value, float MinValue, float MaxValue, FVector2D Size, FString Format, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitVerticalSliderFloat* VerticalSliderFloat = NewObject<UImGuiToolkitVerticalSliderFloat>(OuterObject);
	VerticalSliderFloat->CreateUniqueWidgetLabel(Label);
	VerticalSliderFloat->Value = Value;
	VerticalSliderFloat->MinValue = MinValue;
	VerticalSliderFloat->MaxValue = MaxValue;
	VerticalSliderFloat->Size = Size;
	VerticalSliderFloat->Format = Format;

	if (Container)
		Container->AddWidget(VerticalSliderFloat);

	return VerticalSliderFloat;
}

UImGuiToolkitVerticalSliderInt* UImGuiToolkitFunctionLibrary::CreateImGuiVerticalSliderInt(FText Label,
	int32 Value, int32 MinValue, int32 MaxValue, FVector2D Size, FString Format, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitVerticalSliderInt* VerticalSliderInt = NewObject<UImGuiToolkitVerticalSliderInt>(OuterObject);
	VerticalSliderInt->CreateUniqueWidgetLabel(Label);
	VerticalSliderInt->Value = Value;
	VerticalSliderInt->MinValue = MinValue;
	VerticalSliderInt->MaxValue = MaxValue;
	VerticalSliderInt->Size = Size;
	VerticalSliderInt->Format = Format;

	if (Container)
		Container->AddWidget(VerticalSliderInt);

	return VerticalSliderInt;
}

UImGuiToolkitBeginMenuBar* UImGuiToolkitFunctionLibrary::CreateImGuiBeginMenuBar(FText Label, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitBeginMenuBar* BeginMenuBar = NewObject<UImGuiToolkitBeginMenuBar>(OuterObject);
	BeginMenuBar->CreateUniqueWidgetLabel(Label);

	if (Container)
		Container->AddWidget(BeginMenuBar);

	return BeginMenuBar;
}

UImGuiToolkitBeginMenu* UImGuiToolkitFunctionLibrary::CreateImGuiBeginMenu(FText Label,
	UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitBeginMenu* BeginMenu = NewObject<UImGuiToolkitBeginMenu>(OuterObject);
	BeginMenu->CreateUniqueWidgetLabel(Label);

	if (Container)
		Container->AddWidget(BeginMenu);

	return BeginMenu;
}

UImGuiToolkitMenuItem* UImGuiToolkitFunctionLibrary::CreateImGuiMenuItem(FText Label, FText Shortcut, bool bIsSelected,
	UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitMenuItem* MenuItem = NewObject<UImGuiToolkitMenuItem>(OuterObject);
	MenuItem->CreateUniqueWidgetLabel(Label);
	MenuItem->Shortcut = Shortcut;
	MenuItem->bIsSelected = bIsSelected;

	if (Container)
		Container->AddWidget(MenuItem);

	return MenuItem;
}

UImGuiToolkitEndMenuBar* UImGuiToolkitFunctionLibrary::EndImGuiMenuBar(UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitEndMenuBar* EndMenuBar = NewObject<UImGuiToolkitEndMenuBar>(OuterObject);

	if (Container)
		Container->AddWidget(EndMenuBar);

	return EndMenuBar;
}

UImGuiToolkitEndMenu* UImGuiToolkitFunctionLibrary::EndImGuiMenu(UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitEndMenu* EndMenu = NewObject<UImGuiToolkitEndMenu>(OuterObject);

	if (Container)
		Container->AddWidget(EndMenu);

	return EndMenu;
}

UImGuiToolkitInputText* UImGuiToolkitFunctionLibrary::CreateImGuiInputText(FText Label, FText PreviewText,
	UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitInputText* InputText = NewObject<UImGuiToolkitInputText>(OuterObject);
	InputText->CreateUniqueWidgetLabel(Label);
	InputText->SetPreviewText(PreviewText);

	if (Container)
		Container->AddWidget(InputText);

	return InputText;
}

UImGuiToolkitInputTextWithHint* UImGuiToolkitFunctionLibrary::CreateImGuiInputTextWithHint(
	FText Label, FText Hint, FText PreviewText, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitInputTextWithHint* InputTextWithHint = NewObject<UImGuiToolkitInputTextWithHint>(OuterObject);
	InputTextWithHint->CreateUniqueWidgetLabel(Label);
	InputTextWithHint->SetHint(Hint);
	InputTextWithHint->SetPreviewText(PreviewText);

	if (Container)
		Container->AddWidget(InputTextWithHint);

	return InputTextWithHint;
}

UImGuiToolkitInputTextMultiline* UImGuiToolkitFunctionLibrary::CreateImGuiInputTextMultiline(
	FText Label, FText PreviewText, FVector2D TextBoxSize, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitInputTextMultiline* InputTextMultiline = NewObject<UImGuiToolkitInputTextMultiline>(OuterObject);
	InputTextMultiline->CreateUniqueWidgetLabel(Label);
	InputTextMultiline->SetPreviewText(PreviewText);
	InputTextMultiline->Size = TextBoxSize;

	if (Container)
		Container->AddWidget(InputTextMultiline);

	return InputTextMultiline;
}

UImGuiToolkitInputFloat* UImGuiToolkitFunctionLibrary::CreateImGuiInputFloat(FText Label, float PreviewFloat, FString Format, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitInputFloat* InputFloat = NewObject<UImGuiToolkitInputFloat>(OuterObject);
	InputFloat->CreateUniqueWidgetLabel(Label);
	InputFloat->SetPreviewFloat(PreviewFloat);
	InputFloat->SetFormat(Format);

	if (Container)
		Container->AddWidget(InputFloat);

	return InputFloat;
}

UImGuiToolkitInputDouble* UImGuiToolkitFunctionLibrary::CreateImGuiInputDouble(FText Label, double PreviewDouble, FString Format, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitInputDouble* InputDouble = NewObject<UImGuiToolkitInputDouble>(OuterObject);
	InputDouble->CreateUniqueWidgetLabel(Label);
	InputDouble->SetPreviewDouble(PreviewDouble);
	InputDouble->SetFormat(Format);

	if (Container)
		Container->AddWidget(InputDouble);

	return InputDouble;
}

UImGuiToolkitInputVector2D* UImGuiToolkitFunctionLibrary::CreateImGuiInputVector2D(FText Label, FVector2D PreviewVector2D, FString Format, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitInputVector2D* InputVector2D = NewObject<UImGuiToolkitInputVector2D>(OuterObject);
	InputVector2D->CreateUniqueWidgetLabel(Label);
	InputVector2D->SetPreviewVector2D(PreviewVector2D);
	InputVector2D->SetFormat(Format);

	if (Container)
		Container->AddWidget(InputVector2D);

	return InputVector2D;
}

UImGuiToolkitInputVector* UImGuiToolkitFunctionLibrary::CreateImGuiInputVector(FText Label, FVector PreviewVector, FString Format, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitInputVector* InputVector = NewObject<UImGuiToolkitInputVector>(OuterObject);
	InputVector->CreateUniqueWidgetLabel(Label);
	InputVector->SetPreviewVector(PreviewVector);
	InputVector->SetFormat(Format);

	if (Container)
		Container->AddWidget(InputVector);

	return InputVector;
}

UImGuiToolkitInputVector4* UImGuiToolkitFunctionLibrary::CreateImGuiInputVector4(FText Label, FVector4 PreviewVector4, FString Format, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitInputVector4* InputVector4 = NewObject<UImGuiToolkitInputVector4>(OuterObject);
	InputVector4->CreateUniqueWidgetLabel(Label);
	InputVector4->SetPreviewVector4(PreviewVector4);
	InputVector4->SetFormat(Format);

	if (Container)
		Container->AddWidget(InputVector4);

	return InputVector4;
}

UImGuiToolkitInputInt* UImGuiToolkitFunctionLibrary::CreateImGuiInputInt(FText Label,
	int32 PreviewInt, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitInputInt* InputInt = NewObject<UImGuiToolkitInputInt>(OuterObject);
	InputInt->CreateUniqueWidgetLabel(Label);
	InputInt->SetPreviewInt(PreviewInt);

	if (Container)
		Container->AddWidget(InputInt);

	return InputInt;
}

UImGuiToolkitInputInt2* UImGuiToolkitFunctionLibrary::CreateImGuiInputInt2(FText Label,
	FIntPoint PreviewInt2, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitInputInt2* InputInt2 = NewObject<UImGuiToolkitInputInt2>(OuterObject);
	InputInt2->CreateUniqueWidgetLabel(Label);
	InputInt2->SetPreviewInt2(PreviewInt2);

	if (Container)
		Container->AddWidget(InputInt2);

	return InputInt2;
}

UImGuiToolkitInputInt3* UImGuiToolkitFunctionLibrary::CreateImGuiInputInt3(FText Label,
	FIntVector PreviewInt3, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitInputInt3* InputInt3 = NewObject<UImGuiToolkitInputInt3>(OuterObject);
	InputInt3->CreateUniqueWidgetLabel(Label);
	InputInt3->SetPreviewInt3(PreviewInt3);

	if (Container)
		Container->AddWidget(InputInt3);

	return InputInt3;
}

UImGuiToolkitInputInt4* UImGuiToolkitFunctionLibrary::CreateImGuiInputInt4(FText Label,
	FIntVector4 PreviewInt4, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(Container);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitInputInt4* InputInt4 = NewObject<UImGuiToolkitInputInt4>(OuterObject);
	InputInt4->CreateUniqueWidgetLabel(Label);
	InputInt4->SetPreviewInt4(PreviewInt4);

	if (Container)
		Container->AddWidget(InputInt4);

	return InputInt4;
}

UObject* UImGuiToolkitFunctionLibrary::GetValidOuterObject(UObject* OuterCandidate)
{
	if (OuterCandidate)
		return OuterCandidate;

	// Fall back to the ImGuiToolkitSubsystem, renders while the editor is running
	if (GEngine)
	{
		if (UImGuiToolkitSubsystem* Subsystem = GEngine->GetEngineSubsystem<UImGuiToolkitSubsystem>())
		{
			return Subsystem;
		}
	}

	return nullptr;
}
