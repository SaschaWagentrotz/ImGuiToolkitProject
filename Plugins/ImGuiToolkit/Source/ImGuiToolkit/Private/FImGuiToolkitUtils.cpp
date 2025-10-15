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
		case ImGuiDir_Left:  return EImGuiToolkitDir::Left;
		case ImGuiDir_Right: return EImGuiToolkitDir::Right;
		case ImGuiDir_Up:    return EImGuiToolkitDir::Up;
		case ImGuiDir_Down:  return EImGuiToolkitDir::Down;
		case ImGuiDir_None:
		default:             return EImGuiToolkitDir::None;
	}
}

ImGuiDir FImGuiToolkitUtils::UnrealDirToImGuiDir(EImGuiToolkitDir Dir)
{
	switch (Dir)
	{
		case EImGuiToolkitDir::Left:  return ImGuiDir_Left;
		case EImGuiToolkitDir::Right: return ImGuiDir_Right;
		case EImGuiToolkitDir::Up:    return ImGuiDir_Up;
		case EImGuiToolkitDir::Down:  return ImGuiDir_Down;
		case EImGuiToolkitDir::None:
		default:                               return ImGuiDir_None;
	}
}
