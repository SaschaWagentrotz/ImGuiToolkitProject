#include "FImGuiToolkitUtils.h"

namespace
{
	float LinearToSRGBFloat(float Value)
	{
		if (Value <= 0.0f)
			return Value;

		if (Value <= 0.0031308f)
			return 12.92f * Value;

		return 1.055f * FMath::Pow(Value, 1.0f / 2.4f) - 0.055f;
	}

	float SRGBToLinearFloat(float Value)
	{
		if (Value <= 0.0f)
			return Value;

		if (Value <= 0.04045f)
			return Value / 12.92f;

		return FMath::Pow((Value + 0.055f) / 1.055f, 2.4f);
	}
}

ImVec4 FImGuiToolkitUtils::LinearColorToImVec4(const FLinearColor& Color)
{
	return ImVec4(
		LinearToSRGBFloat(Color.R),
		LinearToSRGBFloat(Color.G),
		LinearToSRGBFloat(Color.B),
		Color.A
	);
}

FLinearColor FImGuiToolkitUtils::ImVec4ToLinearColor(const ImVec4& Color)
{
	return FLinearColor(
		SRGBToLinearFloat(Color.x),
		SRGBToLinearFloat(Color.y),
		SRGBToLinearFloat(Color.z),
		Color.w
	);
}

EImGuiToolkitDir FImGuiToolkitUtils::ImGuiDirToUnrealDir(ImGuiDir Dir)
{
	switch (Dir)
	{
		case ImGuiDir_Left:				return EImGuiToolkitDir::Left;
		case ImGuiDir_Right:			return EImGuiToolkitDir::Right;
		case ImGuiDir_Up:				return EImGuiToolkitDir::Up;
		case ImGuiDir_Down:				return EImGuiToolkitDir::Down;
		case ImGuiDir_None:				return EImGuiToolkitDir::None;
		default:						return EImGuiToolkitDir::None;
	}
}

ImGuiDir FImGuiToolkitUtils::UnrealDirToImGuiDir(EImGuiToolkitDir Dir)
{
	switch (Dir)
	{
		case EImGuiToolkitDir::Left:	return ImGuiDir_Left;
		case EImGuiToolkitDir::Right:	return ImGuiDir_Right;
		case EImGuiToolkitDir::Up:		return ImGuiDir_Up;
		case EImGuiToolkitDir::Down:	return ImGuiDir_Down;
		case EImGuiToolkitDir::None:	return ImGuiDir_None;
		default:						return ImGuiDir_None;
	}
}

ImGuiDir FImGuiToolkitUtils::UnrealDockSplitDirectionToImGuiDir(EImGuiToolkitDockSplitDirection Direction)
{
	switch (Direction)
	{
		case EImGuiToolkitDockSplitDirection::Left:	return ImGuiDir_Left;
		case EImGuiToolkitDockSplitDirection::Right:	return ImGuiDir_Right;
		case EImGuiToolkitDockSplitDirection::Up:	return ImGuiDir_Up;
		case EImGuiToolkitDockSplitDirection::Down:	return ImGuiDir_Down;
		case EImGuiToolkitDockSplitDirection::Center:	return ImGuiDir_None;
		default:									return ImGuiDir_None;
	}
}

EImGuiWindowFlag FImGuiToolkitUtils::ImGuiWindowFlagToUnrealFlag(ImGuiWindowFlags Flags)
{
	switch (Flags)
	{
		case ImGuiWindowFlags_None:							return EImGuiWindowFlag::None;
		case ImGuiWindowFlags_NoTitleBar:					return EImGuiWindowFlag::NoTitleBar;
		case ImGuiWindowFlags_NoResize:						return EImGuiWindowFlag::NoResize;
		case ImGuiWindowFlags_NoMove:						return EImGuiWindowFlag::NoMove;
		case ImGuiWindowFlags_NoScrollbar:					return EImGuiWindowFlag::NoScrollbar;
		case ImGuiWindowFlags_NoScrollWithMouse:			return EImGuiWindowFlag::NoScrollWithMouse;
		case ImGuiWindowFlags_NoCollapse:					return EImGuiWindowFlag::NoCollapse;
		case ImGuiWindowFlags_AlwaysAutoResize:				return EImGuiWindowFlag::AlwaysAutoResize;
		case ImGuiWindowFlags_NoBackground:					return EImGuiWindowFlag::NoBackground;
		case ImGuiWindowFlags_NoSavedSettings:				return EImGuiWindowFlag::NoSavedSettings;
		case ImGuiWindowFlags_NoMouseInputs:				return EImGuiWindowFlag::NoMouseInputs;
		case ImGuiWindowFlags_MenuBar:						return EImGuiWindowFlag::MenuBar;
		case ImGuiWindowFlags_HorizontalScrollbar:			return EImGuiWindowFlag::HorizontalScrollbar;
		case ImGuiWindowFlags_NoFocusOnAppearing:			return EImGuiWindowFlag::NoFocusOnAppearing;
		case ImGuiWindowFlags_NoBringToFrontOnFocus:		return EImGuiWindowFlag::NoBringToFrontOnFocus;
		case ImGuiWindowFlags_AlwaysVerticalScrollbar:		return EImGuiWindowFlag::AlwaysVerticalScrollbar;
		case ImGuiWindowFlags_AlwaysHorizontalScrollbar:	return EImGuiWindowFlag::AlwaysHorizontalScrollbar;
		case ImGuiWindowFlags_NoNavInputs:					return EImGuiWindowFlag::NoNavInputs;
		case ImGuiWindowFlags_NoNavFocus:					return EImGuiWindowFlag::NoNavFocus;
		case ImGuiWindowFlags_UnsavedDocument:				return EImGuiWindowFlag::UnsavedDocument;
		case ImGuiWindowFlags_NoDocking:					return EImGuiWindowFlag::NoDocking;
		default:											return EImGuiWindowFlag::None;
	}
}

ImGuiWindowFlags FImGuiToolkitUtils::UnrealFlagToImGuiWindowFlag(EImGuiWindowFlag Flags)
{
	switch (Flags)
	{
		case EImGuiWindowFlag::None:						return ImGuiWindowFlags_None;
		case EImGuiWindowFlag::NoTitleBar:					return ImGuiWindowFlags_NoTitleBar;
		case EImGuiWindowFlag::NoResize:					return ImGuiWindowFlags_NoResize;
		case EImGuiWindowFlag::NoMove:						return ImGuiWindowFlags_NoMove;
		case EImGuiWindowFlag::NoScrollbar:					return ImGuiWindowFlags_NoScrollbar;
		case EImGuiWindowFlag::NoScrollWithMouse:			return ImGuiWindowFlags_NoScrollWithMouse;
		case EImGuiWindowFlag::NoCollapse:					return ImGuiWindowFlags_NoCollapse;
		case EImGuiWindowFlag::AlwaysAutoResize:			return ImGuiWindowFlags_AlwaysAutoResize;
		case EImGuiWindowFlag::NoBackground:				return ImGuiWindowFlags_NoBackground;
		case EImGuiWindowFlag::NoSavedSettings:				return ImGuiWindowFlags_NoSavedSettings;
		case EImGuiWindowFlag::NoMouseInputs:				return ImGuiWindowFlags_NoMouseInputs;
		case EImGuiWindowFlag::MenuBar:						return ImGuiWindowFlags_MenuBar;
		case EImGuiWindowFlag::HorizontalScrollbar:			return ImGuiWindowFlags_HorizontalScrollbar;
		case EImGuiWindowFlag::NoFocusOnAppearing:			return ImGuiWindowFlags_NoFocusOnAppearing;
		case EImGuiWindowFlag::NoBringToFrontOnFocus:		return ImGuiWindowFlags_NoBringToFrontOnFocus;
		case EImGuiWindowFlag::AlwaysVerticalScrollbar:		return ImGuiWindowFlags_AlwaysVerticalScrollbar;
		case EImGuiWindowFlag::AlwaysHorizontalScrollbar:	return ImGuiWindowFlags_AlwaysHorizontalScrollbar;
		case EImGuiWindowFlag::NoNavInputs:					return ImGuiWindowFlags_NoNavInputs;
		case EImGuiWindowFlag::NoNavFocus:					return ImGuiWindowFlags_NoNavFocus;
		case EImGuiWindowFlag::UnsavedDocument:				return ImGuiWindowFlags_UnsavedDocument;
		case EImGuiWindowFlag::NoDocking:					return ImGuiWindowFlags_NoDocking;
		default:											return ImGuiWindowFlags_None;
	}
}

int32 FImGuiToolkitUtils::CombineImGuiWindowFlags(TArray<EImGuiWindowFlag> Flags)
{
	ImGuiWindowFlags Mask = ImGuiWindowFlags_None;
	for (EImGuiWindowFlag Flag : Flags)
	{
		if (Flag == EImGuiWindowFlag::None)
		{
			continue;
		}

		const uint32 Bit = static_cast<uint32>(Flag);
		Mask |= static_cast<ImGuiWindowFlags>(1u << Bit);
	}
	return Mask;
}

ImGuiChildFlags FImGuiToolkitUtils::UnrealFlagToImGuiChildFlag(EImGuiChildFlag Flags)
{
	switch (Flags)
	{
		case EImGuiChildFlag::Borders:					return ImGuiChildFlags_Borders;
		case EImGuiChildFlag::AlwaysUseWindowPadding:	return ImGuiChildFlags_AlwaysUseWindowPadding;
		case EImGuiChildFlag::ResizeX:					return ImGuiChildFlags_ResizeX;
		case EImGuiChildFlag::ResizeY:					return ImGuiChildFlags_ResizeY;
		case EImGuiChildFlag::AutoResizeX:				return ImGuiChildFlags_AutoResizeX;
		case EImGuiChildFlag::AutoResizeY:				return ImGuiChildFlags_AutoResizeY;
		case EImGuiChildFlag::AlwaysAutoResize:			return ImGuiChildFlags_AlwaysAutoResize;
		case EImGuiChildFlag::FrameStyle:				return ImGuiChildFlags_FrameStyle;
		case EImGuiChildFlag::NavFlattened:				return ImGuiChildFlags_NavFlattened;
		case EImGuiChildFlag::None:						return ImGuiChildFlags_None;
		default:										return ImGuiChildFlags_None;
	}
}

int32 FImGuiToolkitUtils::CombineImGuiChildFlags(TArray<EImGuiChildFlag> Flags)
{
	ImGuiChildFlags Mask = ImGuiChildFlags_None;
	for (EImGuiChildFlag Flag : Flags)
	{
		Mask |= UnrealFlagToImGuiChildFlag(Flag);
	}
	return Mask;
}

ImGuiSelectableFlags FImGuiToolkitUtils::UnrealFlagToImGuiSelectableFlag(EImGuiSelectableFlag Flags)
{
	switch (Flags)
	{
		case EImGuiSelectableFlag::NoAutoClosePopups:	return ImGuiSelectableFlags_NoAutoClosePopups;
		case EImGuiSelectableFlag::SpanAllColumns:		return ImGuiSelectableFlags_SpanAllColumns;
		case EImGuiSelectableFlag::AllowDoubleClick:	return ImGuiSelectableFlags_AllowDoubleClick;
		case EImGuiSelectableFlag::Disabled:			return ImGuiSelectableFlags_Disabled;
		case EImGuiSelectableFlag::AllowOverlap:		return ImGuiSelectableFlags_AllowOverlap;
		case EImGuiSelectableFlag::Highlight:			return ImGuiSelectableFlags_Highlight;
		case EImGuiSelectableFlag::None:				return ImGuiSelectableFlags_None;
		default:										return ImGuiSelectableFlags_None;
	}
}

int32 FImGuiToolkitUtils::CombineImGuiSelectableFlags(TArray<EImGuiSelectableFlag> Flags)
{
	ImGuiSelectableFlags Mask = ImGuiSelectableFlags_None;
	for (EImGuiSelectableFlag Flag : Flags)
	{
		Mask |= UnrealFlagToImGuiSelectableFlag(Flag);
	}
	return Mask;
}

ImGuiComboFlags FImGuiToolkitUtils::UnrealFlagToImGuiComboFlag(EImGuiComboFlag Flags)
{
	switch (Flags)
	{
		case EImGuiComboFlag::PopupAlignLeft:	return ImGuiComboFlags_PopupAlignLeft;
		case EImGuiComboFlag::HeightSmall:		return ImGuiComboFlags_HeightSmall;
		case EImGuiComboFlag::HeightRegular:		return ImGuiComboFlags_HeightRegular;
		case EImGuiComboFlag::HeightLarge:		return ImGuiComboFlags_HeightLarge;
		case EImGuiComboFlag::HeightLargest:		return ImGuiComboFlags_HeightLargest;
		case EImGuiComboFlag::NoArrowButton:		return ImGuiComboFlags_NoArrowButton;
		case EImGuiComboFlag::NoPreview:			return ImGuiComboFlags_NoPreview;
		case EImGuiComboFlag::WidthFitPreview:	return ImGuiComboFlags_WidthFitPreview;
		case EImGuiComboFlag::None:				return ImGuiComboFlags_None;
		default:								return ImGuiComboFlags_None;
	}
}

int32 FImGuiToolkitUtils::CombineImGuiComboFlags(TArray<EImGuiComboFlag> Flags)
{
	ImGuiComboFlags Mask = ImGuiComboFlags_None;
	for (EImGuiComboFlag Flag : Flags)
	{
		Mask |= UnrealFlagToImGuiComboFlag(Flag);
	}
	return Mask;
}

ImGuiCol FImGuiToolkitUtils::UnrealStyleColorToImGuiCol(EImGuiStyleColor StyleColor)
{
	return static_cast<ImGuiCol>(StyleColor);
}

ImGuiStyleVar FImGuiToolkitUtils::UnrealStyleVarToImGuiStyleVar(EImGuiStyleVar StyleVar)
{
	return static_cast<ImGuiStyleVar>(StyleVar);
}

bool FImGuiToolkitUtils::IsImGuiStyleVarVector(EImGuiStyleVar StyleVar)
{
	switch (StyleVar)
	{
		case EImGuiStyleVar::WindowPadding:
		case EImGuiStyleVar::WindowMinSize:
		case EImGuiStyleVar::WindowTitleAlign:
		case EImGuiStyleVar::FramePadding:
		case EImGuiStyleVar::ItemSpacing:
		case EImGuiStyleVar::ItemInnerSpacing:
		case EImGuiStyleVar::CellPadding:
		case EImGuiStyleVar::TableAngledHeadersTextAlign:
		case EImGuiStyleVar::ButtonTextAlign:
		case EImGuiStyleVar::SelectableTextAlign:
		case EImGuiStyleVar::SeparatorTextAlign:
		case EImGuiStyleVar::SeparatorTextPadding:
			return true;
		default:
			return false;
	}
}

ImGuiTableFlags FImGuiToolkitUtils::UnrealFlagToImGuiTableFlag(EImGuiTableFlag Flags)
{
	switch (Flags)
	{
		case EImGuiTableFlag::Resizable:					return ImGuiTableFlags_Resizable;
		case EImGuiTableFlag::Reorderable:					return ImGuiTableFlags_Reorderable;
		case EImGuiTableFlag::Hideable:						return ImGuiTableFlags_Hideable;
		case EImGuiTableFlag::Sortable:						return ImGuiTableFlags_Sortable;
		case EImGuiTableFlag::NoSavedSettings:				return ImGuiTableFlags_NoSavedSettings;
		case EImGuiTableFlag::ContextMenuInBody:				return ImGuiTableFlags_ContextMenuInBody;
		case EImGuiTableFlag::RowBg:						return ImGuiTableFlags_RowBg;
		case EImGuiTableFlag::BordersInnerH:					return ImGuiTableFlags_BordersInnerH;
		case EImGuiTableFlag::BordersOuterH:					return ImGuiTableFlags_BordersOuterH;
		case EImGuiTableFlag::BordersInnerV:					return ImGuiTableFlags_BordersInnerV;
		case EImGuiTableFlag::BordersOuterV:					return ImGuiTableFlags_BordersOuterV;
		case EImGuiTableFlag::BordersH:						return ImGuiTableFlags_BordersH;
		case EImGuiTableFlag::BordersV:						return ImGuiTableFlags_BordersV;
		case EImGuiTableFlag::BordersInner:					return ImGuiTableFlags_BordersInner;
		case EImGuiTableFlag::BordersOuter:					return ImGuiTableFlags_BordersOuter;
		case EImGuiTableFlag::Borders:						return ImGuiTableFlags_Borders;
		case EImGuiTableFlag::NoBordersInBody:				return ImGuiTableFlags_NoBordersInBody;
		case EImGuiTableFlag::NoBordersInBodyUntilResize:	return ImGuiTableFlags_NoBordersInBodyUntilResize;
		case EImGuiTableFlag::SizingFixedFit:				return ImGuiTableFlags_SizingFixedFit;
		case EImGuiTableFlag::SizingFixedSame:				return ImGuiTableFlags_SizingFixedSame;
		case EImGuiTableFlag::SizingStretchProp:				return ImGuiTableFlags_SizingStretchProp;
		case EImGuiTableFlag::SizingStretchSame:				return ImGuiTableFlags_SizingStretchSame;
		case EImGuiTableFlag::NoHostExtendX:					return ImGuiTableFlags_NoHostExtendX;
		case EImGuiTableFlag::NoHostExtendY:					return ImGuiTableFlags_NoHostExtendY;
		case EImGuiTableFlag::NoKeepColumnsVisible:			return ImGuiTableFlags_NoKeepColumnsVisible;
		case EImGuiTableFlag::PreciseWidths:					return ImGuiTableFlags_PreciseWidths;
		case EImGuiTableFlag::NoClip:						return ImGuiTableFlags_NoClip;
		case EImGuiTableFlag::PadOuterX:						return ImGuiTableFlags_PadOuterX;
		case EImGuiTableFlag::NoPadOuterX:					return ImGuiTableFlags_NoPadOuterX;
		case EImGuiTableFlag::NoPadInnerX:					return ImGuiTableFlags_NoPadInnerX;
		case EImGuiTableFlag::ScrollX:						return ImGuiTableFlags_ScrollX;
		case EImGuiTableFlag::ScrollY:						return ImGuiTableFlags_ScrollY;
		case EImGuiTableFlag::SortMulti:						return ImGuiTableFlags_SortMulti;
		case EImGuiTableFlag::SortTristate:					return ImGuiTableFlags_SortTristate;
		case EImGuiTableFlag::HighlightHoveredColumn:		return ImGuiTableFlags_HighlightHoveredColumn;
		case EImGuiTableFlag::None:							return ImGuiTableFlags_None;
		default:											return ImGuiTableFlags_None;
	}
}

int32 FImGuiToolkitUtils::CombineImGuiTableFlags(TArray<EImGuiTableFlag> Flags)
{
	ImGuiTableFlags Mask = ImGuiTableFlags_None;
	for (EImGuiTableFlag Flag : Flags)
	{
		Mask |= UnrealFlagToImGuiTableFlag(Flag);
	}
	return Mask;
}

ImGuiTableColumnFlags FImGuiToolkitUtils::UnrealFlagToImGuiTableColumnFlag(EImGuiTableColumnFlag Flags)
{
	switch (Flags)
	{
		case EImGuiTableColumnFlag::Disabled:				return ImGuiTableColumnFlags_Disabled;
		case EImGuiTableColumnFlag::DefaultHide:				return ImGuiTableColumnFlags_DefaultHide;
		case EImGuiTableColumnFlag::DefaultSort:				return ImGuiTableColumnFlags_DefaultSort;
		case EImGuiTableColumnFlag::WidthStretch:			return ImGuiTableColumnFlags_WidthStretch;
		case EImGuiTableColumnFlag::WidthFixed:				return ImGuiTableColumnFlags_WidthFixed;
		case EImGuiTableColumnFlag::NoResize:				return ImGuiTableColumnFlags_NoResize;
		case EImGuiTableColumnFlag::NoReorder:				return ImGuiTableColumnFlags_NoReorder;
		case EImGuiTableColumnFlag::NoHide:					return ImGuiTableColumnFlags_NoHide;
		case EImGuiTableColumnFlag::NoClip:					return ImGuiTableColumnFlags_NoClip;
		case EImGuiTableColumnFlag::NoSort:					return ImGuiTableColumnFlags_NoSort;
		case EImGuiTableColumnFlag::NoSortAscending:			return ImGuiTableColumnFlags_NoSortAscending;
		case EImGuiTableColumnFlag::NoSortDescending:		return ImGuiTableColumnFlags_NoSortDescending;
		case EImGuiTableColumnFlag::NoHeaderLabel:			return ImGuiTableColumnFlags_NoHeaderLabel;
		case EImGuiTableColumnFlag::NoHeaderWidth:			return ImGuiTableColumnFlags_NoHeaderWidth;
		case EImGuiTableColumnFlag::PreferSortAscending:		return ImGuiTableColumnFlags_PreferSortAscending;
		case EImGuiTableColumnFlag::PreferSortDescending:	return ImGuiTableColumnFlags_PreferSortDescending;
		case EImGuiTableColumnFlag::IndentEnable:			return ImGuiTableColumnFlags_IndentEnable;
		case EImGuiTableColumnFlag::IndentDisable:			return ImGuiTableColumnFlags_IndentDisable;
		case EImGuiTableColumnFlag::AngledHeader:			return ImGuiTableColumnFlags_AngledHeader;
		case EImGuiTableColumnFlag::None:					return ImGuiTableColumnFlags_None;
		default:											return ImGuiTableColumnFlags_None;
	}
}

int32 FImGuiToolkitUtils::CombineImGuiTableColumnFlags(TArray<EImGuiTableColumnFlag> Flags)
{
	ImGuiTableColumnFlags Mask = ImGuiTableColumnFlags_None;
	for (EImGuiTableColumnFlag Flag : Flags)
	{
		Mask |= UnrealFlagToImGuiTableColumnFlag(Flag);
	}
	return Mask;
}

ImGuiTableRowFlags FImGuiToolkitUtils::UnrealFlagToImGuiTableRowFlag(EImGuiTableRowFlag Flags)
{
	switch (Flags)
	{
		case EImGuiTableRowFlag::Headers:	return ImGuiTableRowFlags_Headers;
		case EImGuiTableRowFlag::None:		return ImGuiTableRowFlags_None;
		default:							return ImGuiTableRowFlags_None;
	}
}

int32 FImGuiToolkitUtils::CombineImGuiTableRowFlags(TArray<EImGuiTableRowFlag> Flags)
{
	ImGuiTableRowFlags Mask = ImGuiTableRowFlags_None;
	for (EImGuiTableRowFlag Flag : Flags)
	{
		Mask |= UnrealFlagToImGuiTableRowFlag(Flag);
	}
	return Mask;
}

ImGuiColorEditFlags FImGuiToolkitUtils::UnrealFlagToImGuiColorEditFlag(EImGuiColorEditFlag Flags)
{
	switch (Flags)
	{
		case EImGuiColorEditFlag::NoAlpha:			return ImGuiColorEditFlags_NoAlpha;
		case EImGuiColorEditFlag::NoPicker:			return ImGuiColorEditFlags_NoPicker;
		case EImGuiColorEditFlag::NoOptions:			return ImGuiColorEditFlags_NoOptions;
		case EImGuiColorEditFlag::NoSmallPreview:	return ImGuiColorEditFlags_NoSmallPreview;
		case EImGuiColorEditFlag::NoInputs:			return ImGuiColorEditFlags_NoInputs;
		case EImGuiColorEditFlag::NoTooltip:			return ImGuiColorEditFlags_NoTooltip;
		case EImGuiColorEditFlag::NoLabel:			return ImGuiColorEditFlags_NoLabel;
		case EImGuiColorEditFlag::NoSidePreview:		return ImGuiColorEditFlags_NoSidePreview;
		case EImGuiColorEditFlag::NoDragDrop:		return ImGuiColorEditFlags_NoDragDrop;
		case EImGuiColorEditFlag::NoBorder:			return ImGuiColorEditFlags_NoBorder;
		case EImGuiColorEditFlag::AlphaOpaque:		return ImGuiColorEditFlags_AlphaOpaque;
		case EImGuiColorEditFlag::AlphaNoBg:			return ImGuiColorEditFlags_AlphaNoBg;
		case EImGuiColorEditFlag::AlphaPreviewHalf:	return ImGuiColorEditFlags_AlphaPreviewHalf;
		case EImGuiColorEditFlag::AlphaBar:			return ImGuiColorEditFlags_AlphaBar;
		case EImGuiColorEditFlag::HDR:				return ImGuiColorEditFlags_HDR;
		case EImGuiColorEditFlag::DisplayRGB:		return ImGuiColorEditFlags_DisplayRGB;
		case EImGuiColorEditFlag::DisplayHSV:		return ImGuiColorEditFlags_DisplayHSV;
		case EImGuiColorEditFlag::DisplayHex:		return ImGuiColorEditFlags_DisplayHex;
		case EImGuiColorEditFlag::Uint8:				return ImGuiColorEditFlags_Uint8;
		case EImGuiColorEditFlag::Float:				return ImGuiColorEditFlags_Float;
		case EImGuiColorEditFlag::PickerHueBar:		return ImGuiColorEditFlags_PickerHueBar;
		case EImGuiColorEditFlag::PickerHueWheel:	return ImGuiColorEditFlags_PickerHueWheel;
		case EImGuiColorEditFlag::InputRGB:			return ImGuiColorEditFlags_InputRGB;
		case EImGuiColorEditFlag::InputHSV:			return ImGuiColorEditFlags_InputHSV;
		case EImGuiColorEditFlag::None:				return ImGuiColorEditFlags_None;
		default:									return ImGuiColorEditFlags_None;
	}
}

int32 FImGuiToolkitUtils::CombineImGuiColorEditFlags(TArray<EImGuiColorEditFlag> Flags)
{
	ImGuiColorEditFlags Mask = ImGuiColorEditFlags_None;
	for (EImGuiColorEditFlag Flag : Flags)
	{
		Mask |= UnrealFlagToImGuiColorEditFlag(Flag);
	}
	return Mask;
}

ImGuiPopupFlags FImGuiToolkitUtils::UnrealFlagToImGuiPopupFlag(EImGuiPopupFlag Flags)
{
	switch (Flags)
	{
		case EImGuiPopupFlag::NoReopen:					return ImGuiPopupFlags_NoReopen;
		case EImGuiPopupFlag::NoOpenOverExistingPopup:	return ImGuiPopupFlags_NoOpenOverExistingPopup;
		case EImGuiPopupFlag::NoOpenOverItems:			return ImGuiPopupFlags_NoOpenOverItems;
		case EImGuiPopupFlag::AnyPopupID:				return ImGuiPopupFlags_AnyPopupId;
		case EImGuiPopupFlag::AnyPopupLevel:				return ImGuiPopupFlags_AnyPopupLevel;
		case EImGuiPopupFlag::None:						return ImGuiPopupFlags_None;
		default:										return ImGuiPopupFlags_None;
	}
}

int32 FImGuiToolkitUtils::CombineImGuiPopupFlags(TArray<EImGuiPopupFlag> Flags)
{
	ImGuiPopupFlags Mask = ImGuiPopupFlags_None;
	for (EImGuiPopupFlag Flag : Flags)
	{
		Mask |= UnrealFlagToImGuiPopupFlag(Flag);
	}
	return Mask;
}

ImGuiPopupFlags FImGuiToolkitUtils::UnrealPopupMouseButtonToImGuiPopupFlag(EImGuiPopupMouseButton MouseButton)
{
	switch (MouseButton)
	{
		case EImGuiPopupMouseButton::Left:	return ImGuiPopupFlags_MouseButtonLeft;
		case EImGuiPopupMouseButton::Right:	return ImGuiPopupFlags_MouseButtonRight;
		case EImGuiPopupMouseButton::Middle:	return ImGuiPopupFlags_MouseButtonMiddle;
		default:							return ImGuiPopupFlags_MouseButtonRight;
	}
}

ImGuiMultiSelectFlags FImGuiToolkitUtils::UnrealFlagToImGuiMultiSelectFlag(EImGuiMultiSelectFlag Flags)
{
	switch (Flags)
	{
		case EImGuiMultiSelectFlag::SingleSelect:			return ImGuiMultiSelectFlags_SingleSelect;
		case EImGuiMultiSelectFlag::NoSelectAll:				return ImGuiMultiSelectFlags_NoSelectAll;
		case EImGuiMultiSelectFlag::NoRangeSelect:			return ImGuiMultiSelectFlags_NoRangeSelect;
		case EImGuiMultiSelectFlag::NoAutoSelect:			return ImGuiMultiSelectFlags_NoAutoSelect;
		case EImGuiMultiSelectFlag::NoAutoClear:				return ImGuiMultiSelectFlags_NoAutoClear;
		case EImGuiMultiSelectFlag::NoAutoClearOnReselect:	return ImGuiMultiSelectFlags_NoAutoClearOnReselect;
		case EImGuiMultiSelectFlag::BoxSelect1D:				return ImGuiMultiSelectFlags_BoxSelect1d;
		case EImGuiMultiSelectFlag::BoxSelect2D:				return ImGuiMultiSelectFlags_BoxSelect2d;
		case EImGuiMultiSelectFlag::BoxSelectNoScroll:		return ImGuiMultiSelectFlags_BoxSelectNoScroll;
		case EImGuiMultiSelectFlag::ClearOnEscape:			return ImGuiMultiSelectFlags_ClearOnEscape;
		case EImGuiMultiSelectFlag::ClearOnClickVoid:		return ImGuiMultiSelectFlags_ClearOnClickVoid;
		case EImGuiMultiSelectFlag::ScopeWindow:				return ImGuiMultiSelectFlags_ScopeWindow;
		case EImGuiMultiSelectFlag::ScopeRect:				return ImGuiMultiSelectFlags_ScopeRect;
		case EImGuiMultiSelectFlag::SelectOnClick:			return ImGuiMultiSelectFlags_SelectOnClick;
		case EImGuiMultiSelectFlag::SelectOnClickRelease:	return ImGuiMultiSelectFlags_SelectOnClickRelease;
		case EImGuiMultiSelectFlag::NavWrapX:				return ImGuiMultiSelectFlags_NavWrapX;
		case EImGuiMultiSelectFlag::None:					return ImGuiMultiSelectFlags_None;
		default:											return ImGuiMultiSelectFlags_None;
	}
}

int32 FImGuiToolkitUtils::CombineImGuiMultiSelectFlags(TArray<EImGuiMultiSelectFlag> Flags)
{
	ImGuiMultiSelectFlags Mask = ImGuiMultiSelectFlags_None;
	for (EImGuiMultiSelectFlag Flag : Flags)
	{
		Mask |= UnrealFlagToImGuiMultiSelectFlag(Flag);
	}
	return Mask;
}

ImAxis FImGuiToolkitUtils::UnrealPlotAxisToImPlotAxis(EImPlotAxis Axis)
{
	switch (Axis)
	{
		case EImPlotAxis::X1:	return ImAxis_X1;
		case EImPlotAxis::X2:	return ImAxis_X2;
		case EImPlotAxis::X3:	return ImAxis_X3;
		case EImPlotAxis::Y1:	return ImAxis_Y1;
		case EImPlotAxis::Y2:	return ImAxis_Y2;
		case EImPlotAxis::Y3:	return ImAxis_Y3;
		default:				return ImAxis_X1;
	}
}

ImPlotCond FImGuiToolkitUtils::UnrealPlotConditionToImPlotCond(EImPlotCondition Condition)
{
	switch (Condition)
	{
		case EImPlotCondition::Always:	return ImPlotCond_Always;
		case EImPlotCondition::Once:	return ImPlotCond_Once;
		case EImPlotCondition::None:	return ImPlotCond_None;
		default:						return ImPlotCond_Once;
	}
}

ImPlotFlags FImGuiToolkitUtils::UnrealFlagToImPlotFlag(EImPlotFlag Flags)
{
	switch (Flags)
	{
		case EImPlotFlag::NoTitle:		return ImPlotFlags_NoTitle;
		case EImPlotFlag::NoLegend:		return ImPlotFlags_NoLegend;
		case EImPlotFlag::NoMouseText:	return ImPlotFlags_NoMouseText;
		case EImPlotFlag::NoInputs:		return ImPlotFlags_NoInputs;
		case EImPlotFlag::NoMenus:		return ImPlotFlags_NoMenus;
		case EImPlotFlag::NoBoxSelect:	return ImPlotFlags_NoBoxSelect;
		case EImPlotFlag::NoFrame:		return ImPlotFlags_NoFrame;
		case EImPlotFlag::Equal:			return ImPlotFlags_Equal;
		case EImPlotFlag::Crosshairs:	return ImPlotFlags_Crosshairs;
		case EImPlotFlag::CanvasOnly:	return ImPlotFlags_CanvasOnly;
		case EImPlotFlag::None:			return ImPlotFlags_None;
		default:						return ImPlotFlags_None;
	}
}

int32 FImGuiToolkitUtils::CombineImPlotFlags(TArray<EImPlotFlag> Flags)
{
	ImPlotFlags Mask = ImPlotFlags_None;
	for (EImPlotFlag Flag : Flags)
	{
		Mask |= UnrealFlagToImPlotFlag(Flag);
	}
	return Mask;
}

ImPlotAxisFlags FImGuiToolkitUtils::UnrealFlagToImPlotAxisFlag(EImPlotAxisFlag Flags)
{
	switch (Flags)
	{
		case EImPlotAxisFlag::NoLabel:			return ImPlotAxisFlags_NoLabel;
		case EImPlotAxisFlag::NoGridLines:		return ImPlotAxisFlags_NoGridLines;
		case EImPlotAxisFlag::NoTickMarks:		return ImPlotAxisFlags_NoTickMarks;
		case EImPlotAxisFlag::NoTickLabels:		return ImPlotAxisFlags_NoTickLabels;
		case EImPlotAxisFlag::NoInitialFit:		return ImPlotAxisFlags_NoInitialFit;
		case EImPlotAxisFlag::NoMenus:			return ImPlotAxisFlags_NoMenus;
		case EImPlotAxisFlag::NoSideSwitch:		return ImPlotAxisFlags_NoSideSwitch;
		case EImPlotAxisFlag::NoHighlight:		return ImPlotAxisFlags_NoHighlight;
		case EImPlotAxisFlag::Opposite:			return ImPlotAxisFlags_Opposite;
		case EImPlotAxisFlag::Foreground:		return ImPlotAxisFlags_Foreground;
		case EImPlotAxisFlag::Invert:			return ImPlotAxisFlags_Invert;
		case EImPlotAxisFlag::AutoFit:			return ImPlotAxisFlags_AutoFit;
		case EImPlotAxisFlag::RangeFit:			return ImPlotAxisFlags_RangeFit;
		case EImPlotAxisFlag::PanStretch:		return ImPlotAxisFlags_PanStretch;
		case EImPlotAxisFlag::LockMin:			return ImPlotAxisFlags_LockMin;
		case EImPlotAxisFlag::LockMax:			return ImPlotAxisFlags_LockMax;
		case EImPlotAxisFlag::Lock:				return ImPlotAxisFlags_Lock;
		case EImPlotAxisFlag::NoDecorations:	return ImPlotAxisFlags_NoDecorations;
		case EImPlotAxisFlag::AuxDefault:		return ImPlotAxisFlags_AuxDefault;
		case EImPlotAxisFlag::None:				return ImPlotAxisFlags_None;
		default:								return ImPlotAxisFlags_None;
	}
}

int32 FImGuiToolkitUtils::CombineImPlotAxisFlags(TArray<EImPlotAxisFlag> Flags)
{
	ImPlotAxisFlags Mask = ImPlotAxisFlags_None;
	for (EImPlotAxisFlag Flag : Flags)
	{
		Mask |= UnrealFlagToImPlotAxisFlag(Flag);
	}
	return Mask;
}

ImPlotLineFlags FImGuiToolkitUtils::UnrealFlagToImPlotLineFlag(EImPlotLineFlag Flags)
{
	switch (Flags)
	{
		case EImPlotLineFlag::Segments:	return ImPlotLineFlags_Segments;
		case EImPlotLineFlag::Loop:		return ImPlotLineFlags_Loop;
		case EImPlotLineFlag::SkipNaN:	return ImPlotLineFlags_SkipNaN;
		case EImPlotLineFlag::NoClip:	return ImPlotLineFlags_NoClip;
		case EImPlotLineFlag::Shaded:	return ImPlotLineFlags_Shaded;
		case EImPlotLineFlag::None:		return ImPlotLineFlags_None;
		default:						return ImPlotLineFlags_None;
	}
}

int32 FImGuiToolkitUtils::CombineImPlotLineFlags(TArray<EImPlotLineFlag> Flags)
{
	ImPlotLineFlags Mask = ImPlotLineFlags_None;
	for (EImPlotLineFlag Flag : Flags)
	{
		Mask |= UnrealFlagToImPlotLineFlag(Flag);
	}
	return Mask;
}

ImPlotItemFlags FImGuiToolkitUtils::UnrealFlagToImPlotItemFlag(EImPlotItemFlag Flags)
{
	switch (Flags)
	{
		case EImPlotItemFlag::NoLegend:	return ImPlotItemFlags_NoLegend;
		case EImPlotItemFlag::NoFit:	return ImPlotItemFlags_NoFit;
		case EImPlotItemFlag::None:		return ImPlotItemFlags_None;
		default:						return ImPlotItemFlags_None;
	}
}

int32 FImGuiToolkitUtils::CombineImPlotItemFlags(TArray<EImPlotItemFlag> Flags)
{
	ImPlotItemFlags Mask = ImPlotItemFlags_None;
	for (EImPlotItemFlag Flag : Flags)
	{
		Mask |= UnrealFlagToImPlotItemFlag(Flag);
	}
	return Mask;
}

ImPlotScatterFlags FImGuiToolkitUtils::UnrealFlagToImPlotScatterFlag(EImPlotScatterFlag Flags)
{
	switch (Flags)
	{
		case EImPlotScatterFlag::NoClip:	return ImPlotScatterFlags_NoClip;
		case EImPlotScatterFlag::None:	return ImPlotScatterFlags_None;
		default:						return ImPlotScatterFlags_None;
	}
}

int32 FImGuiToolkitUtils::CombineImPlotScatterFlags(TArray<EImPlotScatterFlag> Flags)
{
	ImPlotScatterFlags Mask = ImPlotScatterFlags_None;
	for (EImPlotScatterFlag Flag : Flags)
	{
		Mask |= UnrealFlagToImPlotScatterFlag(Flag);
	}
	return Mask;
}

ImPlotBarsFlags FImGuiToolkitUtils::UnrealFlagToImPlotBarsFlag(EImPlotBarsFlag Flags)
{
	switch (Flags)
	{
		case EImPlotBarsFlag::Horizontal:	return ImPlotBarsFlags_Horizontal;
		case EImPlotBarsFlag::None:			return ImPlotBarsFlags_None;
		default:							return ImPlotBarsFlags_None;
	}
}

int32 FImGuiToolkitUtils::CombineImPlotBarsFlags(TArray<EImPlotBarsFlag> Flags)
{
	ImPlotBarsFlags Mask = ImPlotBarsFlags_None;
	for (EImPlotBarsFlag Flag : Flags)
	{
		Mask |= UnrealFlagToImPlotBarsFlag(Flag);
	}
	return Mask;
}

ImPlotBarGroupsFlags FImGuiToolkitUtils::UnrealFlagToImPlotBarGroupsFlag(EImPlotBarGroupsFlag Flags)
{
	switch (Flags)
	{
		case EImPlotBarGroupsFlag::Horizontal:	return ImPlotBarGroupsFlags_Horizontal;
		case EImPlotBarGroupsFlag::Stacked:		return ImPlotBarGroupsFlags_Stacked;
		case EImPlotBarGroupsFlag::None:			return ImPlotBarGroupsFlags_None;
		default:								return ImPlotBarGroupsFlags_None;
	}
}

int32 FImGuiToolkitUtils::CombineImPlotBarGroupsFlags(TArray<EImPlotBarGroupsFlag> Flags)
{
	ImPlotBarGroupsFlags Mask = ImPlotBarGroupsFlags_None;
	for (EImPlotBarGroupsFlag Flag : Flags)
	{
		Mask |= UnrealFlagToImPlotBarGroupsFlag(Flag);
	}
	return Mask;
}

ImPlotStairsFlags FImGuiToolkitUtils::UnrealFlagToImPlotStairsFlag(EImPlotStairsFlag Flags)
{
	switch (Flags)
	{
		case EImPlotStairsFlag::PreStep:	return ImPlotStairsFlags_PreStep;
		case EImPlotStairsFlag::Shaded:		return ImPlotStairsFlags_Shaded;
		case EImPlotStairsFlag::None:		return ImPlotStairsFlags_None;
		default:							return ImPlotStairsFlags_None;
	}
}

int32 FImGuiToolkitUtils::CombineImPlotStairsFlags(TArray<EImPlotStairsFlag> Flags)
{
	ImPlotStairsFlags Mask = ImPlotStairsFlags_None;
	for (EImPlotStairsFlag Flag : Flags)
	{
		Mask |= UnrealFlagToImPlotStairsFlag(Flag);
	}
	return Mask;
}

ImPlotErrorBarsFlags FImGuiToolkitUtils::UnrealFlagToImPlotErrorBarsFlag(EImPlotErrorBarsFlag Flags)
{
	switch (Flags)
	{
		case EImPlotErrorBarsFlag::Horizontal:	return ImPlotErrorBarsFlags_Horizontal;
		case EImPlotErrorBarsFlag::None:			return ImPlotErrorBarsFlags_None;
		default:								return ImPlotErrorBarsFlags_None;
	}
}

int32 FImGuiToolkitUtils::CombineImPlotErrorBarsFlags(TArray<EImPlotErrorBarsFlag> Flags)
{
	ImPlotErrorBarsFlags Mask = ImPlotErrorBarsFlags_None;
	for (EImPlotErrorBarsFlag Flag : Flags)
	{
		Mask |= UnrealFlagToImPlotErrorBarsFlag(Flag);
	}
	return Mask;
}

ImPlotStemsFlags FImGuiToolkitUtils::UnrealFlagToImPlotStemsFlag(EImPlotStemsFlag Flags)
{
	switch (Flags)
	{
		case EImPlotStemsFlag::Horizontal:	return ImPlotStemsFlags_Horizontal;
		case EImPlotStemsFlag::None:		return ImPlotStemsFlags_None;
		default:							return ImPlotStemsFlags_None;
	}
}

int32 FImGuiToolkitUtils::CombineImPlotStemsFlags(TArray<EImPlotStemsFlag> Flags)
{
	ImPlotStemsFlags Mask = ImPlotStemsFlags_None;
	for (EImPlotStemsFlag Flag : Flags)
	{
		Mask |= UnrealFlagToImPlotStemsFlag(Flag);
	}
	return Mask;
}

ImPlotInfLinesFlags FImGuiToolkitUtils::UnrealFlagToImPlotInfLinesFlag(EImPlotInfLinesFlag Flags)
{
	switch (Flags)
	{
		case EImPlotInfLinesFlag::Horizontal:	return ImPlotInfLinesFlags_Horizontal;
		case EImPlotInfLinesFlag::None:			return ImPlotInfLinesFlags_None;
		default:								return ImPlotInfLinesFlags_None;
	}
}

int32 FImGuiToolkitUtils::CombineImPlotInfLinesFlags(TArray<EImPlotInfLinesFlag> Flags)
{
	ImPlotInfLinesFlags Mask = ImPlotInfLinesFlags_None;
	for (EImPlotInfLinesFlag Flag : Flags)
	{
		Mask |= UnrealFlagToImPlotInfLinesFlag(Flag);
	}
	return Mask;
}

ImPlotPieChartFlags FImGuiToolkitUtils::UnrealFlagToImPlotPieChartFlag(EImPlotPieChartFlag Flags)
{
	switch (Flags)
	{
		case EImPlotPieChartFlag::Normalize:		return ImPlotPieChartFlags_Normalize;
		case EImPlotPieChartFlag::IgnoreHidden:	return ImPlotPieChartFlags_IgnoreHidden;
		case EImPlotPieChartFlag::Exploding:		return ImPlotPieChartFlags_Exploding;
		case EImPlotPieChartFlag::None:			return ImPlotPieChartFlags_None;
		default:								return ImPlotPieChartFlags_None;
	}
}

int32 FImGuiToolkitUtils::CombineImPlotPieChartFlags(TArray<EImPlotPieChartFlag> Flags)
{
	ImPlotPieChartFlags Mask = ImPlotPieChartFlags_None;
	for (EImPlotPieChartFlag Flag : Flags)
	{
		Mask |= UnrealFlagToImPlotPieChartFlag(Flag);
	}
	return Mask;
}

ImPlotHeatmapFlags FImGuiToolkitUtils::UnrealFlagToImPlotHeatmapFlag(EImPlotHeatmapFlag Flags)
{
	switch (Flags)
	{
		case EImPlotHeatmapFlag::ColumnMajor:	return ImPlotHeatmapFlags_ColMajor;
		case EImPlotHeatmapFlag::None:			return ImPlotHeatmapFlags_None;
		default:								return ImPlotHeatmapFlags_None;
	}
}

int32 FImGuiToolkitUtils::CombineImPlotHeatmapFlags(TArray<EImPlotHeatmapFlag> Flags)
{
	ImPlotHeatmapFlags Mask = ImPlotHeatmapFlags_None;
	for (EImPlotHeatmapFlag Flag : Flags)
	{
		Mask |= UnrealFlagToImPlotHeatmapFlag(Flag);
	}
	return Mask;
}

ImPlotHistogramFlags FImGuiToolkitUtils::UnrealFlagToImPlotHistogramFlag(EImPlotHistogramFlag Flags)
{
	switch (Flags)
	{
		case EImPlotHistogramFlag::Horizontal:	return ImPlotHistogramFlags_Horizontal;
		case EImPlotHistogramFlag::Cumulative:	return ImPlotHistogramFlags_Cumulative;
		case EImPlotHistogramFlag::Density:		return ImPlotHistogramFlags_Density;
		case EImPlotHistogramFlag::NoOutliers:	return ImPlotHistogramFlags_NoOutliers;
		case EImPlotHistogramFlag::ColumnMajor:	return ImPlotHistogramFlags_ColMajor;
		case EImPlotHistogramFlag::None:			return ImPlotHistogramFlags_None;
		default:								return ImPlotHistogramFlags_None;
	}
}

int32 FImGuiToolkitUtils::CombineImPlotHistogramFlags(TArray<EImPlotHistogramFlag> Flags)
{
	ImPlotHistogramFlags Mask = ImPlotHistogramFlags_None;
	for (EImPlotHistogramFlag Flag : Flags)
	{
		Mask |= UnrealFlagToImPlotHistogramFlag(Flag);
	}
	return Mask;
}

ImPlotTextFlags FImGuiToolkitUtils::UnrealFlagToImPlotTextFlag(EImPlotTextFlag Flags)
{
	switch (Flags)
	{
		case EImPlotTextFlag::Vertical:	return ImPlotTextFlags_Vertical;
		case EImPlotTextFlag::None:		return ImPlotTextFlags_None;
		default:						return ImPlotTextFlags_None;
	}
}

int32 FImGuiToolkitUtils::CombineImPlotTextFlags(TArray<EImPlotTextFlag> Flags)
{
	ImPlotTextFlags Mask = ImPlotTextFlags_None;
	for (EImPlotTextFlag Flag : Flags)
	{
		Mask |= UnrealFlagToImPlotTextFlag(Flag);
	}
	return Mask;
}

ImPlotDragToolFlags FImGuiToolkitUtils::UnrealFlagToImPlotDragToolFlag(EImPlotDragToolFlag Flags)
{
	switch (Flags)
	{
		case EImPlotDragToolFlag::NoCursors:	return ImPlotDragToolFlags_NoCursors;
		case EImPlotDragToolFlag::NoFit:		return ImPlotDragToolFlags_NoFit;
		case EImPlotDragToolFlag::NoInputs:	return ImPlotDragToolFlags_NoInputs;
		case EImPlotDragToolFlag::Delayed:	return ImPlotDragToolFlags_Delayed;
		case EImPlotDragToolFlag::None:		return ImPlotDragToolFlags_None;
		default:							return ImPlotDragToolFlags_None;
	}
}

int32 FImGuiToolkitUtils::CombineImPlotDragToolFlags(TArray<EImPlotDragToolFlag> Flags)
{
	ImPlotDragToolFlags Mask = ImPlotDragToolFlags_None;
	for (EImPlotDragToolFlag Flag : Flags)
	{
		Mask |= UnrealFlagToImPlotDragToolFlag(Flag);
	}
	return Mask;
}

ImPlotSubplotFlags FImGuiToolkitUtils::UnrealFlagToImPlotSubplotFlag(EImPlotSubplotFlag Flags)
{
	switch (Flags)
	{
		case EImPlotSubplotFlag::NoTitle:		return ImPlotSubplotFlags_NoTitle;
		case EImPlotSubplotFlag::NoLegend:		return ImPlotSubplotFlags_NoLegend;
		case EImPlotSubplotFlag::NoMenus:		return ImPlotSubplotFlags_NoMenus;
		case EImPlotSubplotFlag::NoResize:		return ImPlotSubplotFlags_NoResize;
		case EImPlotSubplotFlag::NoAlign:		return ImPlotSubplotFlags_NoAlign;
		case EImPlotSubplotFlag::ShareItems:	return ImPlotSubplotFlags_ShareItems;
		case EImPlotSubplotFlag::LinkRows:		return ImPlotSubplotFlags_LinkRows;
		case EImPlotSubplotFlag::LinkColumns:	return ImPlotSubplotFlags_LinkCols;
		case EImPlotSubplotFlag::LinkAllX:		return ImPlotSubplotFlags_LinkAllX;
		case EImPlotSubplotFlag::LinkAllY:		return ImPlotSubplotFlags_LinkAllY;
		case EImPlotSubplotFlag::ColumnMajor:	return ImPlotSubplotFlags_ColMajor;
		case EImPlotSubplotFlag::None:			return ImPlotSubplotFlags_None;
		default:								return ImPlotSubplotFlags_None;
	}
}

int32 FImGuiToolkitUtils::CombineImPlotSubplotFlags(TArray<EImPlotSubplotFlag> Flags)
{
	ImPlotSubplotFlags Mask = ImPlotSubplotFlags_None;
	for (EImPlotSubplotFlag Flag : Flags)
	{
		Mask |= UnrealFlagToImPlotSubplotFlag(Flag);
	}
	return Mask;
}

ImPlotLegendFlags FImGuiToolkitUtils::UnrealFlagToImPlotLegendFlag(EImPlotLegendFlag Flags)
{
	switch (Flags)
	{
		case EImPlotLegendFlag::NoButtons:			return ImPlotLegendFlags_NoButtons;
		case EImPlotLegendFlag::NoHighlightItem:	return ImPlotLegendFlags_NoHighlightItem;
		case EImPlotLegendFlag::NoHighlightAxis:	return ImPlotLegendFlags_NoHighlightAxis;
		case EImPlotLegendFlag::NoMenus:			return ImPlotLegendFlags_NoMenus;
		case EImPlotLegendFlag::Outside:			return ImPlotLegendFlags_Outside;
		case EImPlotLegendFlag::Horizontal:			return ImPlotLegendFlags_Horizontal;
		case EImPlotLegendFlag::Sort:				return ImPlotLegendFlags_Sort;
		case EImPlotLegendFlag::None:				return ImPlotLegendFlags_None;
		default:									return ImPlotLegendFlags_None;
	}
}

int32 FImGuiToolkitUtils::CombineImPlotLegendFlags(TArray<EImPlotLegendFlag> Flags)
{
	ImPlotLegendFlags Mask = ImPlotLegendFlags_None;
	for (EImPlotLegendFlag Flag : Flags)
	{
		Mask |= UnrealFlagToImPlotLegendFlag(Flag);
	}
	return Mask;
}

ImPlotMouseTextFlags FImGuiToolkitUtils::UnrealFlagToImPlotMouseTextFlag(EImPlotMouseTextFlag Flags)
{
	switch (Flags)
	{
		case EImPlotMouseTextFlag::NoAuxAxes:	return ImPlotMouseTextFlags_NoAuxAxes;
		case EImPlotMouseTextFlag::NoFormat:	return ImPlotMouseTextFlags_NoFormat;
		case EImPlotMouseTextFlag::ShowAlways:	return ImPlotMouseTextFlags_ShowAlways;
		case EImPlotMouseTextFlag::None:		return ImPlotMouseTextFlags_None;
		default:								return ImPlotMouseTextFlags_None;
	}
}

int32 FImGuiToolkitUtils::CombineImPlotMouseTextFlags(TArray<EImPlotMouseTextFlag> Flags)
{
	ImPlotMouseTextFlags Mask = ImPlotMouseTextFlags_None;
	for (EImPlotMouseTextFlag Flag : Flags)
	{
		Mask |= UnrealFlagToImPlotMouseTextFlag(Flag);
	}
	return Mask;
}

ImPlotLocation FImGuiToolkitUtils::UnrealPlotLocationToImPlotLocation(EImPlotLocation Location)
{
	switch (Location)
	{
		case EImPlotLocation::Center:		return ImPlotLocation_Center;
		case EImPlotLocation::North:			return ImPlotLocation_North;
		case EImPlotLocation::South:			return ImPlotLocation_South;
		case EImPlotLocation::West:			return ImPlotLocation_West;
		case EImPlotLocation::East:			return ImPlotLocation_East;
		case EImPlotLocation::NorthWest:		return ImPlotLocation_NorthWest;
		case EImPlotLocation::NorthEast:		return ImPlotLocation_NorthEast;
		case EImPlotLocation::SouthWest:		return ImPlotLocation_SouthWest;
		case EImPlotLocation::SouthEast:		return ImPlotLocation_SouthEast;
		default:							return ImPlotLocation_NorthEast;
	}
}

ImPlotScale FImGuiToolkitUtils::UnrealPlotScaleToImPlotScale(EImPlotScale Scale)
{
	return static_cast<ImPlotScale>(Scale);
}

ImPlotColormap FImGuiToolkitUtils::UnrealPlotColormapToImPlotColormap(EImPlotColormap Colormap)
{
	return static_cast<ImPlotColormap>(Colormap);
}

ImPlotColormapScaleFlags FImGuiToolkitUtils::UnrealFlagToImPlotColormapScaleFlag(EImPlotColormapScaleFlag Flags)
{
	switch (Flags)
	{
		case EImPlotColormapScaleFlag::NoLabel:		return ImPlotColormapScaleFlags_NoLabel;
		case EImPlotColormapScaleFlag::Opposite:		return ImPlotColormapScaleFlags_Opposite;
		case EImPlotColormapScaleFlag::Invert:		return ImPlotColormapScaleFlags_Invert;
		case EImPlotColormapScaleFlag::None:			return ImPlotColormapScaleFlags_None;
		default:									return ImPlotColormapScaleFlags_None;
	}
}

int32 FImGuiToolkitUtils::CombineImPlotColormapScaleFlags(TArray<EImPlotColormapScaleFlag> Flags)
{
	ImPlotColormapScaleFlags Mask = ImPlotColormapScaleFlags_None;
	for (EImPlotColormapScaleFlag Flag : Flags)
	{
		Mask |= UnrealFlagToImPlotColormapScaleFlag(Flag);
	}
	return Mask;
}

ImPlotCol FImGuiToolkitUtils::UnrealPlotStyleColorToImPlotCol(EImPlotStyleColor StyleColor)
{
	return static_cast<ImPlotCol>(StyleColor);
}

ImPlotStyleVar FImGuiToolkitUtils::UnrealPlotStyleVarToImPlotStyleVar(EImPlotStyleVar StyleVar)
{
	return static_cast<ImPlotStyleVar>(StyleVar);
}

bool FImGuiToolkitUtils::IsImPlotStyleVarVector(EImPlotStyleVar StyleVar)
{
	switch (StyleVar)
	{
		case EImPlotStyleVar::MajorTickLen:
		case EImPlotStyleVar::MinorTickLen:
		case EImPlotStyleVar::MajorTickSize:
		case EImPlotStyleVar::MinorTickSize:
		case EImPlotStyleVar::MajorGridSize:
		case EImPlotStyleVar::MinorGridSize:
		case EImPlotStyleVar::PlotPadding:
		case EImPlotStyleVar::LabelPadding:
		case EImPlotStyleVar::LegendPadding:
		case EImPlotStyleVar::LegendInnerPadding:
		case EImPlotStyleVar::LegendSpacing:
		case EImPlotStyleVar::MousePosPadding:
		case EImPlotStyleVar::AnnotationPadding:
		case EImPlotStyleVar::FitPadding:
		case EImPlotStyleVar::PlotDefaultSize:
		case EImPlotStyleVar::PlotMinSize:
			return true;
		default:
			return false;
	}
}

ImPlotMarker FImGuiToolkitUtils::UnrealPlotMarkerToImPlotMarker(EImPlotMarker Marker)
{
	switch (Marker)
	{
		case EImPlotMarker::None:		return ImPlotMarker_None;
		case EImPlotMarker::Circle:		return ImPlotMarker_Circle;
		case EImPlotMarker::Square:		return ImPlotMarker_Square;
		case EImPlotMarker::Diamond:		return ImPlotMarker_Diamond;
		case EImPlotMarker::Up:			return ImPlotMarker_Up;
		case EImPlotMarker::Down:		return ImPlotMarker_Down;
		case EImPlotMarker::Left:		return ImPlotMarker_Left;
		case EImPlotMarker::Right:		return ImPlotMarker_Right;
		case EImPlotMarker::Cross:		return ImPlotMarker_Cross;
		case EImPlotMarker::Plus:		return ImPlotMarker_Plus;
		case EImPlotMarker::Asterisk:	return ImPlotMarker_Asterisk;
		default:						return ImPlotMarker_None;
	}
}

int32 FImGuiToolkitUtils::ImGuiResizeCallback(ImGuiInputTextCallbackData* Data)
{
	if (Data->EventFlag == ImGuiInputTextFlags_CallbackResize)
	{
		TArray<char>* Buffer = static_cast<TArray<char>*>(Data->UserData);
		Buffer->SetNumUninitialized(Data->BufTextLen + 1);
		Data->Buf = Buffer->GetData();
	}
	return 0;
}
