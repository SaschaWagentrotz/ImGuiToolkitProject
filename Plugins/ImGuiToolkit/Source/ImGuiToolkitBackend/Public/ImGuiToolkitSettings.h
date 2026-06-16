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
	FLinearColor Text = FLinearColor(230.0f / 255.0f, 230.0f / 255.0f, 230.0f / 255.0f, 1.0f);

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Text")
	FLinearColor TextDisabled = FLinearColor(132.0f / 255.0f, 137.0f / 255.0f, 145.0f / 255.0f, 1.0f);

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Text")
	FLinearColor TextLink = FLinearColor(45.0f / 255.0f, 120.0f / 255.0f, 225.0f / 255.0f, 1.0f);

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Text")
	FLinearColor TextSelectedBg = FLinearColor(60.0f / 255.0f, 120.0f / 255.0f, 200.0f / 255.0f, 100.0f / 255.0f);

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Windows")
	FLinearColor WindowBg = FLinearColor(16.0f / 255.0f, 17.0f / 255.0f, 19.0f / 255.0f, 240.0f / 255.0f);

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Windows")
	FLinearColor ChildBg = FLinearColor(20.0f / 255.0f, 21.0f / 255.0f, 24.0f / 255.0f, 240.0f / 255.0f);

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Windows")
	FLinearColor PopupBg = FLinearColor(22.0f / 255.0f, 23.0f / 255.0f, 26.0f / 255.0f, 240.0f / 255.0f);

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Windows")
	FLinearColor TitleBg = FLinearColor(26.0f / 255.0f, 27.0f / 255.0f, 31.0f / 255.0f, 1.0f);

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Windows")
	FLinearColor TitleBgActive = FLinearColor(34.0f / 255.0f, 36.0f / 255.0f, 41.0f / 255.0f, 1.0f);

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Windows")
	FLinearColor TitleBgCollapsed = FLinearColor(0.0f, 0.0f, 0.0f, 130.0f / 255.0f);

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Borders")
	FLinearColor Border = FLinearColor(56.0f / 255.0f, 60.0f / 255.0f, 66.0f / 255.0f, 1.0f);

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Borders")
	FLinearColor BorderShadow = FLinearColor(0.0f, 0.0f, 0.0f, 0.0f);

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Frames")
	FLinearColor FrameBg = FLinearColor(34.0f / 255.0f, 37.0f / 255.0f, 42.0f / 255.0f, 220.0f / 255.0f);

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Frames")
	FLinearColor FrameBgHovered = FLinearColor(42.0f / 255.0f, 46.0f / 255.0f, 52.0f / 255.0f, 230.0f / 255.0f);

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Frames")
	FLinearColor FrameBgActive = FLinearColor(48.0f / 255.0f, 53.0f / 255.0f, 60.0f / 255.0f, 1.0f);

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Buttons")
	FLinearColor Button = FLinearColor(52.0f / 255.0f, 54.0f / 255.0f, 58.0f / 255.0f, 220.0f / 255.0f);

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Buttons")
	FLinearColor ButtonHovered = FLinearColor(70.0f / 255.0f, 73.0f / 255.0f, 78.0f / 255.0f, 1.0f);

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Buttons")
	FLinearColor ButtonActive = FLinearColor(35.0f / 255.0f, 100.0f / 255.0f, 210.0f / 255.0f, 1.0f);

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Accent")
	FLinearColor CheckMark = FLinearColor(45.0f / 255.0f, 120.0f / 255.0f, 225.0f / 255.0f, 1.0f);

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Accent")
	FLinearColor SliderGrab = FLinearColor(70.0f / 255.0f, 145.0f / 255.0f, 245.0f / 255.0f, 1.0f);

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Accent")
	FLinearColor SliderGrabActive = FLinearColor(35.0f / 255.0f, 100.0f / 255.0f, 210.0f / 255.0f, 1.0f);

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Headers")
	FLinearColor Header = FLinearColor(45.0f / 255.0f, 49.0f / 255.0f, 56.0f / 255.0f, 200.0f / 255.0f);

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Headers")
	FLinearColor HeaderHovered = FLinearColor(55.0f / 255.0f, 60.0f / 255.0f, 68.0f / 255.0f, 230.0f / 255.0f);

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Headers")
	FLinearColor HeaderActive = FLinearColor(60.0f / 255.0f, 66.0f / 255.0f, 75.0f / 255.0f, 1.0f);

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Separators")
	FLinearColor Separator = FLinearColor(56.0f / 255.0f, 60.0f / 255.0f, 66.0f / 255.0f, 1.0f);

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Separators")
	FLinearColor SeparatorHovered = FLinearColor(70.0f / 255.0f, 145.0f / 255.0f, 245.0f / 255.0f, 1.0f);

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Separators")
	FLinearColor SeparatorActive = FLinearColor(35.0f / 255.0f, 100.0f / 255.0f, 210.0f / 255.0f, 1.0f);

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Resize Grip")
	FLinearColor ResizeGrip = FLinearColor(45.0f / 255.0f, 120.0f / 255.0f, 225.0f / 255.0f, 0.22f);

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Resize Grip")
	FLinearColor ResizeGripHovered = FLinearColor(45.0f / 255.0f, 120.0f / 255.0f, 225.0f / 255.0f, 0.72f);

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Resize Grip")
	FLinearColor ResizeGripActive = FLinearColor(45.0f / 255.0f, 120.0f / 255.0f, 225.0f / 255.0f, 0.95f);

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Tabs")
	FLinearColor Tab = FLinearColor(40.0f / 255.0f, 44.0f / 255.0f, 50.0f / 255.0f, 1.0f);

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Tabs")
	FLinearColor TabHovered = FLinearColor(55.0f / 255.0f, 60.0f / 255.0f, 68.0f / 255.0f, 1.0f);

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Tabs")
	FLinearColor TabSelected = FLinearColor(45.0f / 255.0f, 120.0f / 255.0f, 225.0f / 255.0f, 1.0f);

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Tabs")
	FLinearColor TabSelectedOverline = FLinearColor(45.0f / 255.0f, 120.0f / 255.0f, 225.0f / 255.0f, 1.0f);

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Tabs")
	FLinearColor TabDimmed = FLinearColor(38.0f / 255.0f, 40.0f / 255.0f, 44.0f / 255.0f, 1.0f);

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Tabs")
	FLinearColor TabDimmedSelected = FLinearColor(45.0f / 255.0f, 48.0f / 255.0f, 53.0f / 255.0f, 1.0f);

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Tabs")
	FLinearColor TabDimmedSelectedOverline = FLinearColor(0.0f, 0.0f, 0.0f, 0.0f);

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Docking")
	FLinearColor DockingPreview = FLinearColor(45.0f / 255.0f, 120.0f / 255.0f, 225.0f / 255.0f, 0.70f);

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Docking")
	FLinearColor DockingEmptyBg = FLinearColor(34.0f / 255.0f, 36.0f / 255.0f, 41.0f / 255.0f, 1.0f);

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Scrollbars")
	FLinearColor ScrollbarBg = FLinearColor(16.0f / 255.0f, 17.0f / 255.0f, 19.0f / 255.0f, 135.0f / 255.0f);

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Scrollbars")
	FLinearColor ScrollbarGrab = FLinearColor(67.0f / 255.0f, 72.0f / 255.0f, 79.0f / 255.0f, 1.0f);

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Scrollbars")
	FLinearColor ScrollbarGrabHovered = FLinearColor(86.0f / 255.0f, 92.0f / 255.0f, 100.0f / 255.0f, 1.0f);

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Scrollbars")
	FLinearColor ScrollbarGrabActive = FLinearColor(104.0f / 255.0f, 112.0f / 255.0f, 122.0f / 255.0f, 1.0f);

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Tables")
	FLinearColor TableHeaderBg = FLinearColor(40.0f / 255.0f, 43.0f / 255.0f, 49.0f / 255.0f, 1.0f);

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Tables")
	FLinearColor TableBorderStrong = FLinearColor(70.0f / 255.0f, 74.0f / 255.0f, 82.0f / 255.0f, 1.0f);

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Tables")
	FLinearColor TableBorderLight = FLinearColor(52.0f / 255.0f, 56.0f / 255.0f, 63.0f / 255.0f, 1.0f);

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Tables")
	FLinearColor TableRowBg = FLinearColor(0.0f, 0.0f, 0.0f, 0.0f);

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Tables")
	FLinearColor TableRowBgAlt = FLinearColor(1.0f, 1.0f, 1.0f, 16.0f / 255.0f);

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Plots")
	FLinearColor PlotLines = FLinearColor(156.0f / 255.0f, 156.0f / 255.0f, 156.0f / 255.0f, 1.0f);

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Plots")
	FLinearColor PlotLinesHovered = FLinearColor(1.0f, 110.0f / 255.0f, 96.0f / 255.0f, 1.0f);

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Plots")
	FLinearColor PlotHistogram = FLinearColor(229.0f / 255.0f, 178.0f / 255.0f, 59.0f / 255.0f, 1.0f);

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Plots")
	FLinearColor PlotHistogramHovered = FLinearColor(1.0f, 171.0f / 255.0f, 51.0f / 255.0f, 1.0f);

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Feedback")
	FLinearColor DragDropTarget = FLinearColor(1.0f, 220.0f / 255.0f, 0.0f, 230.0f / 255.0f);

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Navigation")
	FLinearColor NavCursor = FLinearColor(45.0f / 255.0f, 120.0f / 255.0f, 225.0f / 255.0f, 1.0f);

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Navigation")
	FLinearColor NavWindowingHighlight = FLinearColor(1.0f, 1.0f, 1.0f, 180.0f / 255.0f);

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Navigation")
	FLinearColor NavWindowingDimBg = FLinearColor(0.0f, 0.0f, 0.0f, 120.0f / 255.0f);

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Modals")
	FLinearColor ModalWindowDimBg = FLinearColor(0.0f, 0.0f, 0.0f, 150.0f / 255.0f);

	UPROPERTY(Config, EditAnywhere, Category = "Colors|Menus")
	FLinearColor MenuBarBg = FLinearColor(24.0f / 255.0f, 26.0f / 255.0f, 29.0f / 255.0f, 1.0f);

	virtual FName GetCategoryName() const override;
	virtual FName GetSectionName() const override;
};
