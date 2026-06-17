#include "FImGuiToolkitUtils.h"

ImVec4 FImGuiToolkitUtils::LinearColorToImVec4(const FLinearColor& Color)
{
	const FColor ColorSRGB = Color.ToFColorSRGB(); 
	const ImVec4 ImGuiColor(
		ColorSRGB.R / 255.0f,
		ColorSRGB.G / 255.0f,
		ColorSRGB.B / 255.0f,
		ColorSRGB.A / 255.0f
	);

	return ImGuiColor;
}

FLinearColor FImGuiToolkitUtils::ImVec4ToLinearColor(const ImVec4& Color)
{
	const FColor SRGBColor(
		FMath::Clamp(FMath::RoundToInt(Color.x * 255.0f), 0, 255),
		FMath::Clamp(FMath::RoundToInt(Color.y * 255.0f), 0, 255),
		FMath::Clamp(FMath::RoundToInt(Color.z * 255.0f), 0, 255),
		FMath::Clamp(FMath::RoundToInt(Color.w * 255.0f), 0, 255)
	);

	return FLinearColor::FromSRGBColor(SRGBColor);
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
