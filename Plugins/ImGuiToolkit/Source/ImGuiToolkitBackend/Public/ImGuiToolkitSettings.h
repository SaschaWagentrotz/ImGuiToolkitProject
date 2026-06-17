#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "ImGuiToolkitSettings.generated.h"

UCLASS(Config = Game, DefaultConfig, DisplayName = "ImGuiToolkit")
class IMGUI_API UImGuiToolkitSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UImGuiToolkitSettings();

	UPROPERTY(Config, EditAnywhere, Category = "General", meta = (ClampMin = "0.25", ClampMax = "4.0", UIMin = "0.25", UIMax = "4.0"))
	float Scale = 2.0f;

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Text")
	FLinearColor Text = FLinearColor::FromSRGBColor(FColor(230, 230, 230));

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Text")
	FLinearColor TextDisabled = FLinearColor::FromSRGBColor(FColor(132, 137, 145));

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Text")
	FLinearColor TextLink = FLinearColor::FromSRGBColor(FColor(40, 103, 203));

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Text")
	FLinearColor TextSelectedBg = FLinearColor::FromSRGBColor(FColor(40, 103, 203));

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Windows")
	FLinearColor WindowBg = FLinearColor::FromSRGBColor(FColor(26, 26, 25));

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Windows")
	FLinearColor ChildBg = FLinearColor::FromSRGBColor(FColor(26, 26, 26));

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Windows")
	FLinearColor PopupBg = FLinearColor::FromSRGBColor(FColor(56, 55, 56));

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Windows")
	FLinearColor TitleBg = FLinearColor::FromSRGBColor(FColor(26, 27, 31));

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Windows")
	FLinearColor TitleBgActive = FLinearColor::FromSRGBColor(FColor(21, 21, 21));

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Windows")
	FLinearColor TitleBgCollapsed = FLinearColor::FromSRGBColor(FColor(0, 0, 0, 130));

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Borders")
	FLinearColor Border = FLinearColor::FromSRGBColor(FColor(56, 60, 66, 0));

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Borders")
	FLinearColor BorderShadow = FLinearColor::FromSRGBColor(FColor(0, 0, 0, 0));

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Frames")
	FLinearColor FrameBg = FLinearColor::FromSRGBColor(FColor(36, 36, 36));

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Frames")
	FLinearColor FrameBgHovered = FLinearColor::FromSRGBColor(FColor(42, 46, 52, 230));

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Frames")
	FLinearColor FrameBgActive = FLinearColor::FromSRGBColor(FColor(48, 53, 60));

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Buttons")
	FLinearColor Button = FLinearColor::FromSRGBColor(FColor(56, 55, 56));

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Buttons")
	FLinearColor ButtonHovered = FLinearColor::FromSRGBColor(FColor(82, 82, 82));

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Buttons")
	FLinearColor ButtonActive = FLinearColor::FromSRGBColor(FColor(57, 101, 196));

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Accent")
	FLinearColor CheckMark = FLinearColor::FromSRGBColor(FColor(40, 103, 203));

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Accent")
	FLinearColor SliderGrab = FLinearColor::FromSRGBColor(FColor(70, 145, 245));

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Accent")
	FLinearColor SliderGrabActive = FLinearColor::FromSRGBColor(FColor(57, 101, 196));

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Headers")
	FLinearColor Header = FLinearColor::FromSRGBColor(FColor(40, 103, 203));

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Headers")
	FLinearColor HeaderHovered = FLinearColor::FromSRGBColor(FColor(82, 82, 82));

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Headers")
	FLinearColor HeaderActive = FLinearColor::FromSRGBColor(FColor(60, 66, 75));

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Separators")
	FLinearColor Separator = FLinearColor::FromSRGBColor(FColor(56, 60, 66));

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Separators")
	FLinearColor SeparatorHovered = FLinearColor::FromSRGBColor(FColor(40, 103, 203));

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Separators")
	FLinearColor SeparatorActive = FLinearColor::FromSRGBColor(FColor(57, 101, 196));

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Resize Grip")
	FLinearColor ResizeGrip = FLinearColor::FromSRGBColor(FColor(45, 120, 225, 56));

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Resize Grip")
	FLinearColor ResizeGripHovered = FLinearColor::FromSRGBColor(FColor(40, 103, 203, 184));

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Resize Grip")
	FLinearColor ResizeGripActive = FLinearColor::FromSRGBColor(FColor(40, 103, 203, 242));

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Tabs")
	FLinearColor Tab = FLinearColor::FromSRGBColor(FColor(21, 21, 20));

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Tabs")
	FLinearColor TabHovered = FLinearColor::FromSRGBColor(FColor(33, 33, 33));

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Tabs")
	FLinearColor TabSelected = FLinearColor::FromSRGBColor(FColor(36, 35, 35));

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Tabs")
	FLinearColor TabSelectedOverline = FLinearColor::FromSRGBColor(FColor(36, 35, 35));

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Tabs")
	FLinearColor TabDimmed = FLinearColor::FromSRGBColor(FColor(38, 40, 44));

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Tabs")
	FLinearColor TabDimmedSelected = FLinearColor::FromSRGBColor(FColor(45, 48, 53));

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Tabs")
	FLinearColor TabDimmedSelectedOverline = FLinearColor::FromSRGBColor(FColor(0, 0, 0, 0));

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Docking")
	FLinearColor DockingPreview = FLinearColor::FromSRGBColor(FColor(40, 103, 203, 179));

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Docking")
	FLinearColor DockingEmptyBg = FLinearColor::FromSRGBColor(FColor(34, 36, 41));

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Scrollbars")
	FLinearColor ScrollbarBg = FLinearColor::FromSRGBColor(FColor(26, 26, 25, 135));

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Scrollbars")
	FLinearColor ScrollbarGrab = FLinearColor::FromSRGBColor(FColor(56, 55, 56));

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Scrollbars")
	FLinearColor ScrollbarGrabHovered = FLinearColor::FromSRGBColor(FColor(82, 82, 82));

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Scrollbars")
	FLinearColor ScrollbarGrabActive = FLinearColor::FromSRGBColor(FColor(104, 104, 104));

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Tables")
	FLinearColor TableHeaderBg = FLinearColor::FromSRGBColor(FColor(36, 35, 35));

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Tables")
	FLinearColor TableBorderStrong = FLinearColor::FromSRGBColor(FColor(82, 82, 82));

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Tables")
	FLinearColor TableBorderLight = FLinearColor::FromSRGBColor(FColor(56, 55, 56));

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Tables")
	FLinearColor TableRowBg = FLinearColor::FromSRGBColor(FColor(0, 0, 0, 0));

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Tables")
	FLinearColor TableRowBgAlt = FLinearColor::FromSRGBColor(FColor(255, 255, 255, 16));

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Plots")
	FLinearColor PlotLines = FLinearColor::FromSRGBColor(FColor(156, 156, 156));

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Plots")
	FLinearColor PlotLinesHovered = FLinearColor::FromSRGBColor(FColor(255, 110, 96));

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Plots")
	FLinearColor PlotHistogram = FLinearColor::FromSRGBColor(FColor(229, 178, 59));

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Plots")
	FLinearColor PlotHistogramHovered = FLinearColor::FromSRGBColor(FColor(255, 171, 51));

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Feedback")
	FLinearColor DragDropTarget = FLinearColor::FromSRGBColor(FColor(255, 220, 0, 230));

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Navigation")
	FLinearColor NavCursor = FLinearColor::FromSRGBColor(FColor(40, 103, 203));

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Navigation")
	FLinearColor NavWindowingHighlight = FLinearColor::FromSRGBColor(FColor(255, 255, 255, 180));

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Navigation")
	FLinearColor NavWindowingDimBg = FLinearColor::FromSRGBColor(FColor(0, 0, 0, 120));

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Modals")
	FLinearColor ModalWindowDimBg = FLinearColor::FromSRGBColor(FColor(0, 0, 0, 150));

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Menus")
	FLinearColor MenuBarBg = FLinearColor::FromSRGBColor(FColor(36, 35, 35));

	virtual FName GetCategoryName() const override;
	virtual FName GetSectionName() const override;
};
