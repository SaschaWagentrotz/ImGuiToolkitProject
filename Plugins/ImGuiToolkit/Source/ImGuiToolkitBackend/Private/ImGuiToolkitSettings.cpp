#include "ImGuiToolkitSettings.h"

namespace
{
	FLinearColor FromSRGB(const uint8 R, const uint8 G, const uint8 B, const uint8 A = 255)
	{
		return FLinearColor::FromSRGBColor(FColor(R, G, B, A));
	}
}

UImGuiToolkitSettings::UImGuiToolkitSettings()
{
	Text = FromSRGB(230, 230, 230);
	TextDisabled = FromSRGB(132, 137, 145);
	TextLink = FromSRGB(45, 120, 225);
	TextSelectedBg = FromSRGB(60, 120, 200, 100);

	WindowBg = FromSRGB(16, 17, 19, 240);
	ChildBg = FromSRGB(20, 21, 24, 240);
	PopupBg = FromSRGB(22, 23, 26, 240);
	TitleBg = FromSRGB(26, 27, 31);
	TitleBgActive = FromSRGB(34, 36, 41);
	TitleBgCollapsed = FromSRGB(0, 0, 0, 130);
	MenuBarBg = FromSRGB(24, 26, 29);

	Border = FromSRGB(56, 60, 66);
	BorderShadow = FromSRGB(0, 0, 0, 0);

	FrameBg = FromSRGB(34, 37, 42, 220);
	FrameBgHovered = FromSRGB(42, 46, 52, 230);
	FrameBgActive = FromSRGB(48, 53, 60);

	Button = FromSRGB(52, 54, 58, 220);
	ButtonHovered = FromSRGB(70, 73, 78);
	ButtonActive = FromSRGB(35, 100, 210);

	CheckMark = FromSRGB(45, 120, 225);
	SliderGrab = FromSRGB(70, 145, 245);
	SliderGrabActive = FromSRGB(35, 100, 210);

	Header = FromSRGB(45, 49, 56, 200);
	HeaderHovered = FromSRGB(55, 60, 68, 230);
	HeaderActive = FromSRGB(60, 66, 75);

	Separator = FromSRGB(56, 60, 66);
	SeparatorHovered = FromSRGB(70, 145, 245);
	SeparatorActive = FromSRGB(35, 100, 210);

	ResizeGrip = FromSRGB(45, 120, 225, 56);
	ResizeGripHovered = FromSRGB(45, 120, 225, 184);
	ResizeGripActive = FromSRGB(45, 120, 225, 242);

	Tab = FromSRGB(40, 44, 50);
	TabHovered = FromSRGB(55, 60, 68);
	TabSelected = FromSRGB(45, 120, 225);
	TabSelectedOverline = FromSRGB(45, 120, 225);
	TabDimmed = FromSRGB(38, 40, 44);
	TabDimmedSelected = FromSRGB(45, 48, 53);
	TabDimmedSelectedOverline = FromSRGB(0, 0, 0, 0);

	DockingPreview = FromSRGB(45, 120, 225, 179);
	DockingEmptyBg = FromSRGB(34, 36, 41);

	ScrollbarBg = FromSRGB(16, 17, 19, 135);
	ScrollbarGrab = FromSRGB(67, 72, 79);
	ScrollbarGrabHovered = FromSRGB(86, 92, 100);
	ScrollbarGrabActive = FromSRGB(104, 112, 122);

	TableHeaderBg = FromSRGB(40, 43, 49);
	TableBorderStrong = FromSRGB(70, 74, 82);
	TableBorderLight = FromSRGB(52, 56, 63);
	TableRowBg = FromSRGB(0, 0, 0, 0);
	TableRowBgAlt = FromSRGB(255, 255, 255, 16);

	PlotLines = FromSRGB(156, 156, 156);
	PlotLinesHovered = FromSRGB(255, 110, 96);
	PlotHistogram = FromSRGB(229, 178, 59);
	PlotHistogramHovered = FromSRGB(255, 171, 51);

	DragDropTarget = FromSRGB(255, 220, 0, 230);
	NavCursor = FromSRGB(45, 120, 225);
	NavWindowingHighlight = FromSRGB(255, 255, 255, 180);
	NavWindowingDimBg = FromSRGB(0, 0, 0, 120);
	ModalWindowDimBg = FromSRGB(0, 0, 0, 150);
}

FName UImGuiToolkitSettings::GetCategoryName() const
{
	return TEXT("Plugins");
}

FName UImGuiToolkitSettings::GetSectionName() const
{
	return TEXT("ImGuiToolkit");
}
