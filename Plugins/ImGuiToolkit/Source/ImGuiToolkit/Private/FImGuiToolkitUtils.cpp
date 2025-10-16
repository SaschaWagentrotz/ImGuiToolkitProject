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
		const uint32 Bit = static_cast<uint32>(Flag);
		Mask |= static_cast<ImGuiWindowFlags>(1u << Bit);
	}
	return Mask;
}
