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

UImGuiToolkitSliderFloat* UImGuiToolkitFunctionLibrary::CreateImGuiSliderFloat(FText Label,
	float Value, float MinValue, float MaxValue, FText Format, UImGuiToolkitContainer* Container)
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

UImGuiToolkitSliderInt* UImGuiToolkitFunctionLibrary::CreateImGuiSliderInt(FText Label,
	int32 Value, int32 MinValue, int32 MaxValue, FText Format, UImGuiToolkitContainer* Container)
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
