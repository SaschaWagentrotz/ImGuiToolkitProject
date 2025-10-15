// Fill out your copyright notice in the Description page of Project Settings.

#include "ImGuiToolkitFunctionLibrary.h"
#include "Containers/ImGuiToolkitWindow.h"
#include "Widgets/Main/ImGuiToolkitButton.h"
#include "Widgets/Layout/ImGuiToolkitSameLine.h"
#include "ImGuiToolkitSubsystem.h"
#include "Components/Widget.h"
#include "Containers/ImGuiToolkitCollapsingHeader.h"
#include "Widgets/Text/ImGuiToolkitText.h"

// TODO: Tidy all these functions up by grouping them together in a logical way

void UImGuiToolkitFunctionLibrary::ToggleImGuiDemoWindow()
{
	if (UImGuiToolkitSubsystem* Subsystem = GEngine->GetEngineSubsystem<UImGuiToolkitSubsystem>())
	{
		Subsystem->SetShowImGuiDemoWindow(!Subsystem->GetShowImGuiDemoWindow());
	}
}

UImGuiToolkitWindow* UImGuiToolkitFunctionLibrary::CreateImGuiWindow(UObject* WorldContextObject, FText WindowTitle)
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

	// Auto-register with subsystem
	if (UImGuiToolkitSubsystem* Subsystem = GEngine->GetEngineSubsystem<UImGuiToolkitSubsystem>())
	{
		Subsystem->RegisterWindow(Window);
	}

	return Window;
}

FVector2D UImGuiToolkitFunctionLibrary::GetWidgetPosition(UObject* WorldContextObject, UWidget* Widget)
{
	const FGeometry& Geo = Widget->GetCachedGeometry();
	const FVector2D AbsTopLeft = Geo.GetAbsolutePosition();

	const float Scale = FSlateApplication::Get().GetApplicationScale();
	const FVector2D ScreenPos = AbsTopLeft / Scale;
	
	return ScreenPos;
}

void UImGuiToolkitFunctionLibrary::DestroyImGuiWindow(UObject* WorldContextObject, UImGuiToolkitWindow* Window)
{
	UObject* OuterObject = GetValidOuterObject(WorldContextObject);
	if (!OuterObject)
		return;

	// Use GEngine directly instead of GetEngine()
	if (!GEngine)
		return;

	if (UImGuiToolkitSubsystem* Subsystem = GEngine->GetEngineSubsystem<UImGuiToolkitSubsystem>())
	{
		Subsystem->UnregisterWindow(Window);
	}
}

UImGuiToolkitSameLine* UImGuiToolkitFunctionLibrary::CreateImGuiSameLine(UObject* WorldContextObject, float OffsetFromStartX, float Spacing, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(WorldContextObject);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitSameLine* SameLine = NewObject<UImGuiToolkitSameLine>(OuterObject);
	SameLine->OffsetFromStartX = OffsetFromStartX;
	SameLine->Spacing = Spacing;

	if (Container)
		Container->AddWidget(SameLine);
	
	return SameLine;
}


UImGuiToolkitButton* UImGuiToolkitFunctionLibrary::CreateImGuiButton(UObject* WorldContextObject, FText Label, FText Tooltip, FVector2D Size, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(WorldContextObject);
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

UImGuiToolkitHelpMarker* UImGuiToolkitFunctionLibrary::CreateImGuiHelpMarker(UObject* WorldContextObject, FText Text, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(WorldContextObject);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitHelpMarker* HelpMarker = NewObject<UImGuiToolkitHelpMarker>(OuterObject);
	HelpMarker->Text = Text;

	if (Container)
		Container->AddWidget(HelpMarker);

	return HelpMarker;
}

UImGuiToolkitSetItemTooltip* UImGuiToolkitFunctionLibrary::CreateImGuiSetItemTooltip(UObject* WorldContextObject, FText Text, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(WorldContextObject);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitSetItemTooltip* Tooltip = NewObject<UImGuiToolkitSetItemTooltip>(OuterObject);
	Tooltip->Text = Text;

	if (Container)
		Container->AddWidget(Tooltip);

	return Tooltip;
}

UImGuiToolkitCollapsingHeader* UImGuiToolkitFunctionLibrary::CreateImGuiCollapsingHeader(UObject* WorldContextObject, FText Label, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(WorldContextObject);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitCollapsingHeader* CollapsingHeader = NewObject<UImGuiToolkitCollapsingHeader>(OuterObject);
	CollapsingHeader->CreateUniqueWidgetLabel(Label);

	if (Container)
		Container->AddWidget(CollapsingHeader);

	return CollapsingHeader;
}

UImGuiToolkitText* UImGuiToolkitFunctionLibrary::CreateImGuiText(UObject* WorldContextObject, FText Text, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(WorldContextObject);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitText* TextBlock = NewObject<UImGuiToolkitText>(OuterObject);
	TextBlock->Text = Text;

	if (Container)
		Container->AddWidget(TextBlock);

	return TextBlock;
}

UImGuiToolkitAlignTextToFramePadding* UImGuiToolkitFunctionLibrary::CreateImGuiAlignTextToFramePadding(
	UObject* WorldContextObject, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(WorldContextObject);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitAlignTextToFramePadding* AlignTextToFramePadding = NewObject<UImGuiToolkitAlignTextToFramePadding>(OuterObject);

	if (Container)
		Container->AddWidget(AlignTextToFramePadding);
	
	return AlignTextToFramePadding;
}

UImGuiToolkitTextDisabled* UImGuiToolkitFunctionLibrary::CreateImGuiTextDisabled(UObject* WorldContextObject, FText Text, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(WorldContextObject);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitTextDisabled* TextBlock = NewObject<UImGuiToolkitTextDisabled>(OuterObject);
	TextBlock->Text = Text;

	if (Container)
		Container->AddWidget(TextBlock);

	return TextBlock;
}

UImGuiToolkitSeparatorText* UImGuiToolkitFunctionLibrary::CreateImGuiSeparatorText(UObject* WorldContextObject, FText Text, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(WorldContextObject);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitSeparatorText* SeparatorText = NewObject<UImGuiToolkitSeparatorText>(OuterObject);
	SeparatorText->Text = Text;

	if (Container)
		Container->AddWidget(SeparatorText);

	return SeparatorText;
}

UImGuiToolkitBulletText* UImGuiToolkitFunctionLibrary::CreateImGuiBulletText(UObject* WorldContextObject, FText Text, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(WorldContextObject);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitBulletText* BulletText = NewObject<UImGuiToolkitBulletText>(OuterObject);
	BulletText->Text = Text;

	if (Container)
		Container->AddWidget(BulletText);

	return BulletText;
}

UImGuiToolkitLabelText* UImGuiToolkitFunctionLibrary::CreateImGuiLabelText(UObject* WorldContextObject, FText LeftText, FText RightText, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(WorldContextObject);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitLabelText* LabelText = NewObject<UImGuiToolkitLabelText>(OuterObject);
	LabelText->Label = RightText;
	LabelText->Value = LeftText;

	if (Container)
		Container->AddWidget(LabelText);

	return LabelText;
}

UImGuiToolkitSpacing* UImGuiToolkitFunctionLibrary::CreateImGuiSpacing(UObject* WorldContextObject, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(WorldContextObject);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitSpacing* Spacing = NewObject<UImGuiToolkitSpacing>(OuterObject);

	if (Container)
		Container->AddWidget(Spacing);
	
	return Spacing;
}

UImGuiToolkitIndent* UImGuiToolkitFunctionLibrary::CreateImGuiIndent(UObject* WorldContextObject, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(WorldContextObject);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitIndent* Indent = NewObject<UImGuiToolkitIndent>(OuterObject);

	if (Container)
		Container->AddWidget(Indent);
	
	return Indent;
}

UImGuiToolkitUnindent* UImGuiToolkitFunctionLibrary::CreateImGuiUnindent(UObject* WorldContextObject, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(WorldContextObject);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitUnindent* Unindent = NewObject<UImGuiToolkitUnindent>(OuterObject);

	if (Container)
		Container->AddWidget(Unindent);
	
	return Unindent;
}

UImGuiToolkitTreeNode* UImGuiToolkitFunctionLibrary::CreateImGuiTreeNode(UObject* WorldContextObject, FText Label, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(WorldContextObject);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitTreeNode* TreeNode = NewObject<UImGuiToolkitTreeNode>(OuterObject);
	TreeNode->CreateUniqueWidgetLabel(Label);

	if (Container)
		Container->AddWidget(TreeNode);

	return TreeNode;
}

UImGuiToolkitTreePush* UImGuiToolkitFunctionLibrary::CreateImGuiTreePush(UObject* WorldContextObject, FText Label,
	UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(WorldContextObject);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitTreePush* TreePush = NewObject<UImGuiToolkitTreePush>(OuterObject);
	TreePush->Text = Label;

	if (Container)
		Container->AddWidget(TreePush);

	return TreePush;
}

UImGuiToolkitTreePop* UImGuiToolkitFunctionLibrary::CreateImGuiTreePop(UObject* WorldContextObject,
	UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(WorldContextObject);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitTreePop* TreePop = NewObject<UImGuiToolkitTreePop>(OuterObject);

	if (Container)
		Container->AddWidget(TreePop);

	return TreePop;
}

UImGuiToolkitCheckbox* UImGuiToolkitFunctionLibrary::CreateImGuiCheckbox(UObject* WorldContextObject, FText Label,
	FText Tooltip, bool bIsChecked, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(WorldContextObject);
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

UImGuiToolkitBeginTabBar* UImGuiToolkitFunctionLibrary::CreateImGuiBeginTabBar(UObject* WorldContextObject, FText Label,
	UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(WorldContextObject);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitBeginTabBar* BeginTabBar = NewObject<UImGuiToolkitBeginTabBar>(OuterObject);
	BeginTabBar->CreateUniqueWidgetLabel(Label);

	if (Container)
		Container->AddWidget(BeginTabBar);

	return BeginTabBar;
}

UImGuiToolkitEndTabBar* UImGuiToolkitFunctionLibrary::EndImGuiTabBar(UObject* WorldContextObject,
	UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(WorldContextObject);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitEndTabBar* EndTabBar = NewObject<UImGuiToolkitEndTabBar>(OuterObject);

	if (Container)
		Container->AddWidget(EndTabBar);

	return EndTabBar;
}

UImGuiToolkiBeginTabItem* UImGuiToolkitFunctionLibrary::CreateImGuiBeginTabItem(UObject* WorldContextObject,
	FText Label, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(WorldContextObject);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkiBeginTabItem* BeginTabItem = NewObject<UImGuiToolkiBeginTabItem>(OuterObject);
	BeginTabItem->CreateUniqueWidgetLabel(Label);

	if (Container)
		Container->AddWidget(BeginTabItem);

	return BeginTabItem;
}

UImGuiToolkitEndTabItem* UImGuiToolkitFunctionLibrary::EndImGuiTabItem(UObject* WorldContextObject,
	UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(WorldContextObject);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitEndTabItem* EndTabItem = NewObject<UImGuiToolkitEndTabItem>(OuterObject);

	if (Container)
		Container->AddWidget(EndTabItem);

	return EndTabItem;
}

UImGuiToolkitCombo* UImGuiToolkitFunctionLibrary::CreateImGuiCombo(UObject* WorldContextObject, FText Label, TArray<FText> ComboItems, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(WorldContextObject);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitCombo* Combo = NewObject<UImGuiToolkitCombo>(OuterObject);
	Combo->CreateUniqueWidgetLabel(Label);
	Combo->ComboItems = ComboItems;

	if (Container)
		Container->AddWidget(Combo);

	return Combo;
}

UImGuiToolkitDragInt* UImGuiToolkitFunctionLibrary::CreateImGuiDragInt(UObject* WorldContextObject, FText Label, int32 InitialValue, int32 MinValue, int32 MaxValue, float Speed, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(WorldContextObject);
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

UImGuiToolkitSeparator* UImGuiToolkitFunctionLibrary::CreateImGuiSeparator(UObject* WorldContextObject,
	UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(WorldContextObject);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitSeparator* Separator = NewObject<UImGuiToolkitSeparator>(OuterObject);

	if (Container)
		Container->AddWidget(Separator);

	return Separator;
}

UImGuiToolkitNewLine* UImGuiToolkitFunctionLibrary::CreateImGuiNewLine(UObject* WorldContextObject,
	UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(WorldContextObject);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitNewLine* NewLine = NewObject<UImGuiToolkitNewLine>(OuterObject);
	
	if (Container)
		Container->AddWidget(NewLine);

	return NewLine;
}

UImGuiToolkitDummy* UImGuiToolkitFunctionLibrary::CreateImGuiDummy(UObject* WorldContextObject, FVector2D Size,
	UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(WorldContextObject);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitDummy* Dummy = NewObject<UImGuiToolkitDummy>(OuterObject);
	Dummy->Size = Size;

	if (Container)
		Container->AddWidget(Dummy);

	return Dummy;
}

UImGuiToolkitTextColored* UImGuiToolkitFunctionLibrary::CreateImGuiTextColored(UObject* WorldContextObject,
	FLinearColor Color, FText Text, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(WorldContextObject);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitTextColored* TextColored = NewObject<UImGuiToolkitTextColored>(OuterObject);
	TextColored->Color = Color;
	TextColored->Text = Text;

	if (Container)
		Container->AddWidget(TextColored);

	return TextColored;
}

UImGuiToolkitTextWrapped* UImGuiToolkitFunctionLibrary::CreateImGuiTextWrapped(UObject* WorldContextObject, FText Text,
	UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(WorldContextObject);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitTextWrapped* TextWrapped = NewObject<UImGuiToolkitTextWrapped>(OuterObject);
	TextWrapped->Text = Text;

	if (Container)
		Container->AddWidget(TextWrapped);

	return TextWrapped;
}

UImGuiToolkitSmallButton* UImGuiToolkitFunctionLibrary::CreateImGuiSmallButton(UObject* WorldContextObject, FText Label,
	FText Tooltip, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(WorldContextObject);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitSmallButton* SmallButton = NewObject<UImGuiToolkitSmallButton>(OuterObject);
	SmallButton->CreateUniqueWidgetLabel(Label);
	SmallButton->Tooltip = Tooltip;

	if (Container)
		Container->AddWidget(SmallButton);

	return SmallButton;
}

UImGuiToolkitArrowButton* UImGuiToolkitFunctionLibrary::CreateImGuiArrowButton(UObject* WorldContextObject,
	EImGuiToolkitDir CardinalDirection, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(WorldContextObject);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitArrowButton* ArrowButton = NewObject<UImGuiToolkitArrowButton>(OuterObject);
	ArrowButton->CardinalDirection = CardinalDirection;
	
	if (Container)
		Container->AddWidget(ArrowButton);

	return ArrowButton;
}

UImGuiToolkitRadioButtonGroup* UImGuiToolkitFunctionLibrary::CreateImGuiRadioButtonGroup(UObject* WorldContextObject,
	TArray<FText> RadioButtonLabels, int32 InitialIndex, EImGuiToolkitRadioButtonDirection Direction, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(WorldContextObject);
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

UImGuiToolkitProgressBar* UImGuiToolkitFunctionLibrary::CreateImGuiProgressBar(UObject* WorldContextObject,
	float Percent, FVector2D Size, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(WorldContextObject);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitProgressBar* ProgressBar = NewObject<UImGuiToolkitProgressBar>(OuterObject);
	ProgressBar->Percent = Percent;
	ProgressBar->Size = Size;

	if (Container)
		Container->AddWidget(ProgressBar);

	return ProgressBar;
}

UImGuiToolkitBullet* UImGuiToolkitFunctionLibrary::CreateImGuiBullet(UObject* WorldContextObject,
	UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(WorldContextObject);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitBullet* Bullet = NewObject<UImGuiToolkitBullet>(OuterObject);

	if (Container)
		Container->AddWidget(Bullet);

	return Bullet;
}

UImGuiToolkitTextLinkOpenURL* UImGuiToolkitFunctionLibrary::CreateTextLinkOpenURL(UObject* WorldContextObject,
	FText Text, FString URL, UImGuiToolkitContainer* Container)
{
	UObject* OuterObject = GetValidOuterObject(WorldContextObject);
	if (!OuterObject)
		return nullptr;

	UImGuiToolkitTextLinkOpenURL* TextLinkOpenURL = NewObject<UImGuiToolkitTextLinkOpenURL>(OuterObject);
	TextLinkOpenURL->Text = Text;
	TextLinkOpenURL->URL = URL;

	if (Container)
		Container->AddWidget(TextLinkOpenURL);

	return TextLinkOpenURL;
}

UObject* UImGuiToolkitFunctionLibrary::GetValidOuterObject(UObject* WorldContextObject)
{
	// If we have a valid WorldContextObject, use it
	if (WorldContextObject)
		return WorldContextObject;

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
