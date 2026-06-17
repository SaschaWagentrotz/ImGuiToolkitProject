#include "ImGuiToolkitSettings.h"

namespace
{
	FLinearColor FromSRGB(const uint8 R, const uint8 G, const uint8 B, const uint8 A = 255)
	{
		return FLinearColor::FromSRGBColor(FColor(R, G, B, A));
	}
}

FImGuiToolkitStyleSettings::FImGuiToolkitStyleSettings()
{
	Text = FromSRGB(230, 230, 230);
	TextDisabled = FromSRGB(132, 137, 145);
	TextLink = FromSRGB(40, 103, 203);
	TextSelectedBg = FromSRGB(40, 103, 203);

	WindowBg = FromSRGB(26, 26, 25);
	ChildBg = FromSRGB(26, 26, 26);
	PopupBg = FromSRGB(56, 55, 56);
	TitleBg = FromSRGB(26, 27, 31);
	TitleBgActive = FromSRGB(21, 21, 21);
	TitleBgCollapsed = FromSRGB(0, 0, 0, 130);
	MenuBarBg = FromSRGB(36, 35, 35);

	Border = FromSRGB(56, 60, 66, 0);
	BorderShadow = FromSRGB(0, 0, 0, 0);

	FrameBg = FromSRGB(36, 36, 36);
	FrameBgHovered = FromSRGB(42, 46, 52, 230);
	FrameBgActive = FromSRGB(48, 53, 60);

	Button = FromSRGB(56, 55, 56);
	ButtonHovered = FromSRGB(82, 82, 82);
	ButtonActive = FromSRGB(57, 101, 196);

	CheckMark = FromSRGB(40, 103, 203);
	SliderGrab = FromSRGB(70, 145, 245);
	SliderGrabActive = FromSRGB(57, 101, 196);

	Header = FromSRGB(40, 103, 203);
	HeaderHovered = FromSRGB(82, 82, 82);
	HeaderActive = FromSRGB(60, 66, 75);

	Separator = FromSRGB(56, 60, 66);
	SeparatorHovered = FromSRGB(40, 103, 203);
	SeparatorActive = FromSRGB(57, 101, 196);

	ResizeGrip = FromSRGB(45, 120, 225, 56);
	ResizeGripHovered = FromSRGB(40, 103, 203, 184);
	ResizeGripActive = FromSRGB(40, 103, 203, 242);

	Tab = FromSRGB(21, 21, 20);
	TabHovered = FromSRGB(33, 33, 33);
	TabSelected = FromSRGB(36, 35, 35);
	TabSelectedOverline = FromSRGB(36, 35, 35);
	TabDimmed = FromSRGB(38, 40, 44);
	TabDimmedSelected = FromSRGB(45, 48, 53);
	TabDimmedSelectedOverline = FromSRGB(0, 0, 0, 0);

	DockingPreview = FromSRGB(40, 103, 203, 179);
	DockingEmptyBg = FromSRGB(34, 36, 41);

	ScrollbarBg = FromSRGB(26, 26, 25, 135);
	ScrollbarGrab = FromSRGB(56, 55, 56);
	ScrollbarGrabHovered = FromSRGB(82, 82, 82);
	ScrollbarGrabActive = FromSRGB(104, 104, 104);

	TableHeaderBg = FromSRGB(36, 35, 35);
	TableBorderStrong = FromSRGB(82, 82, 82);
	TableBorderLight = FromSRGB(56, 55, 56);
	TableRowBg = FromSRGB(0, 0, 0, 0);
	TableRowBgAlt = FromSRGB(255, 255, 255, 16);

	PlotLines = FromSRGB(156, 156, 156);
	PlotLinesHovered = FromSRGB(255, 110, 96);
	PlotHistogram = FromSRGB(229, 178, 59);
	PlotHistogramHovered = FromSRGB(255, 171, 51);

	DragDropTarget = FromSRGB(255, 220, 0, 230);
	NavCursor = FromSRGB(40, 103, 203);
	NavWindowingHighlight = FromSRGB(255, 255, 255, 180);
	NavWindowingDimBg = FromSRGB(0, 0, 0, 120);
	ModalWindowDimBg = FromSRGB(0, 0, 0, 150);
}

UImGuiToolkitSettings::UImGuiToolkitSettings()
{
	RuntimeStyle = FImGuiToolkitStyleSettings();
	EditorHostedStyle = RuntimeStyle;
}

const FImGuiToolkitStyleSettings& UImGuiToolkitSettings::GetStyleSettingsForTarget(EImGuiToolkitStyleTarget StyleTarget) const
{
	return StyleTarget == EImGuiToolkitStyleTarget::EditorHosted ? EditorHostedStyle : RuntimeStyle;
}

float UImGuiToolkitSettings::GetScaleForTarget(EImGuiToolkitStyleTarget StyleTarget) const
{
	const FImGuiToolkitStyleSettings& StyleSettings = GetStyleSettingsForTarget(StyleTarget);
	return FMath::Clamp(StyleSettings.Scale, 0.25f, 4.0f);
}

FName UImGuiToolkitSettings::GetCategoryName() const
{
	return TEXT("Plugins");
}

FName UImGuiToolkitSettings::GetSectionName() const
{
	return TEXT("ImGuiToolkit");
}
