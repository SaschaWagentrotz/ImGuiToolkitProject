#pragma once
#include "CoreMinimal.h"
#include <imgui.h>

// A cardinal direction
UENUM(BlueprintType)
enum class EImGuiToolkitDir : uint8
{
	None    = 255,
	Left    = 0,
	Right   = 1,
	Up      = 2,
	Down    = 3,
	COUNT
};

UENUM(BlueprintType)
enum class EImGuiToolkitDockSplitDirection : uint8
{
	Center  = 255	UMETA(DisplayName = "Center"),
	Left    = 0		UMETA(DisplayName = "Left"),
	Right   = 1		UMETA(DisplayName = "Right"),
	Up      = 2		UMETA(DisplayName = "Up"),
	Down    = 3		UMETA(DisplayName = "Down")
};

UENUM(BlueprintType)
enum class EImGuiWindowFlag : uint8
{
	None						= 255			UMETA(DisplayName = "None"),
    NoTitleBar                  = 0				UMETA(DisplayName = "No Title Bar"),
    NoResize                    = 1				UMETA(DisplayName = "No Resize"),
    NoMove                      = 2				UMETA(DisplayName = "No Move"),
    NoScrollbar                 = 3				UMETA(DisplayName = "No Scrollbar"),
    NoScrollWithMouse           = 4				UMETA(DisplayName = "No Scroll With Mouse"),
    NoCollapse                  = 5				UMETA(DisplayName = "No Collapse"),
    AlwaysAutoResize            = 6				UMETA(DisplayName = "Always Auto Resize"),
    NoBackground                = 7				UMETA(DisplayName = "No Background"),
    NoSavedSettings             = 8				UMETA(DisplayName = "No Saved Settings"),
    NoMouseInputs               = 9				UMETA(DisplayName = "No Mouse Inputs"),
    MenuBar                     = 10			UMETA(DisplayName = "Menu Bar"),
    HorizontalScrollbar         = 11			UMETA(DisplayName = "Horizontal Scrollbar"),
    NoFocusOnAppearing          = 12			UMETA(DisplayName = "No Focus On Appearing"),
    NoBringToFrontOnFocus       = 13			UMETA(DisplayName = "No Bring To Front On Focus"),
    AlwaysVerticalScrollbar     = 14			UMETA(DisplayName = "Always Vertical Scrollbar"),
    AlwaysHorizontalScrollbar   = 15			UMETA(DisplayName = "Always Horizontal Scrollbar"),
    NoNavInputs                 = 16			UMETA(DisplayName = "No Nav Inputs"),
    NoNavFocus                  = 17			UMETA(DisplayName = "No Nav Focus"),
    UnsavedDocument             = 18			UMETA(DisplayName = "Unsaved Document"),
    NoDocking                   = 19			UMETA(DisplayName = "No Docking"),
};

UENUM(BlueprintType)
enum class EImGuiChildFlag : uint8
{
	None						= 255			UMETA(DisplayName = "None"),
	Borders						= 0				UMETA(DisplayName = "Borders"),
	AlwaysUseWindowPadding		= 1				UMETA(DisplayName = "Always Use Window Padding"),
	ResizeX						= 2				UMETA(DisplayName = "Resize X"),
	ResizeY						= 3				UMETA(DisplayName = "Resize Y"),
	AutoResizeX					= 4				UMETA(DisplayName = "Auto Resize X"),
	AutoResizeY					= 5				UMETA(DisplayName = "Auto Resize Y"),
	AlwaysAutoResize			= 6				UMETA(DisplayName = "Always Auto Resize"),
	FrameStyle					= 7				UMETA(DisplayName = "Frame Style"),
	NavFlattened				= 8				UMETA(DisplayName = "Nav Flattened"),
};

UENUM(BlueprintType)
enum class EImGuiSelectableFlag : uint8
{
	None						= 255			UMETA(DisplayName = "None"),
	NoAutoClosePopups			= 0				UMETA(DisplayName = "No Auto Close Popups"),
	SpanAllColumns				= 1				UMETA(DisplayName = "Span All Columns"),
	AllowDoubleClick			= 2				UMETA(DisplayName = "Allow Double Click"),
	Disabled					= 3				UMETA(DisplayName = "Disabled"),
	AllowOverlap				= 4				UMETA(DisplayName = "Allow Overlap"),
	Highlight					= 5				UMETA(DisplayName = "Highlight"),
};

UENUM(BlueprintType)
enum class EImGuiTableFlag : uint8
{
	None						= 255			UMETA(DisplayName = "None"),
	Resizable					= 0				UMETA(DisplayName = "Resizable"),
	Reorderable					= 1				UMETA(DisplayName = "Reorderable"),
	Hideable					= 2				UMETA(DisplayName = "Hideable"),
	Sortable					= 3				UMETA(DisplayName = "Sortable"),
	NoSavedSettings				= 4				UMETA(DisplayName = "No Saved Settings"),
	ContextMenuInBody			= 5				UMETA(DisplayName = "Context Menu In Body"),
	RowBg						= 6				UMETA(DisplayName = "Row Background"),
	BordersInnerH				= 7				UMETA(DisplayName = "Borders Inner Horizontal"),
	BordersOuterH				= 8				UMETA(DisplayName = "Borders Outer Horizontal"),
	BordersInnerV				= 9				UMETA(DisplayName = "Borders Inner Vertical"),
	BordersOuterV				= 10			UMETA(DisplayName = "Borders Outer Vertical"),
	BordersH					= 11			UMETA(DisplayName = "Borders Horizontal"),
	BordersV					= 12			UMETA(DisplayName = "Borders Vertical"),
	BordersInner				= 13			UMETA(DisplayName = "Borders Inner"),
	BordersOuter				= 14			UMETA(DisplayName = "Borders Outer"),
	Borders						= 15			UMETA(DisplayName = "Borders"),
	NoBordersInBody				= 16			UMETA(DisplayName = "No Borders In Body"),
	NoBordersInBodyUntilResize	= 17			UMETA(DisplayName = "No Borders In Body Until Resize"),
	SizingFixedFit				= 18			UMETA(DisplayName = "Sizing Fixed Fit"),
	SizingFixedSame				= 19			UMETA(DisplayName = "Sizing Fixed Same"),
	SizingStretchProp			= 20			UMETA(DisplayName = "Sizing Stretch Proportional"),
	SizingStretchSame			= 21			UMETA(DisplayName = "Sizing Stretch Same"),
	NoHostExtendX				= 22			UMETA(DisplayName = "No Host Extend X"),
	NoHostExtendY				= 23			UMETA(DisplayName = "No Host Extend Y"),
	NoKeepColumnsVisible		= 24			UMETA(DisplayName = "No Keep Columns Visible"),
	PreciseWidths				= 25			UMETA(DisplayName = "Precise Widths"),
	NoClip						= 26			UMETA(DisplayName = "No Clip"),
	PadOuterX					= 27			UMETA(DisplayName = "Pad Outer X"),
	NoPadOuterX					= 28			UMETA(DisplayName = "No Pad Outer X"),
	NoPadInnerX					= 29			UMETA(DisplayName = "No Pad Inner X"),
	ScrollX						= 30			UMETA(DisplayName = "Scroll X"),
	ScrollY						= 31			UMETA(DisplayName = "Scroll Y"),
	SortMulti					= 32			UMETA(DisplayName = "Sort Multi"),
	SortTristate				= 33			UMETA(DisplayName = "Sort Tristate"),
	HighlightHoveredColumn		= 34			UMETA(DisplayName = "Highlight Hovered Column"),
};

UENUM(BlueprintType)
enum class EImGuiTableColumnFlag : uint8
{
	None						= 255			UMETA(DisplayName = "None"),
	Disabled					= 0				UMETA(DisplayName = "Disabled"),
	DefaultHide					= 1				UMETA(DisplayName = "Default Hide"),
	DefaultSort					= 2				UMETA(DisplayName = "Default Sort"),
	WidthStretch				= 3				UMETA(DisplayName = "Width Stretch"),
	WidthFixed					= 4				UMETA(DisplayName = "Width Fixed"),
	NoResize					= 5				UMETA(DisplayName = "No Resize"),
	NoReorder					= 6				UMETA(DisplayName = "No Reorder"),
	NoHide						= 7				UMETA(DisplayName = "No Hide"),
	NoClip						= 8				UMETA(DisplayName = "No Clip"),
	NoSort						= 9				UMETA(DisplayName = "No Sort"),
	NoSortAscending				= 10			UMETA(DisplayName = "No Sort Ascending"),
	NoSortDescending			= 11			UMETA(DisplayName = "No Sort Descending"),
	NoHeaderLabel				= 12			UMETA(DisplayName = "No Header Label"),
	NoHeaderWidth				= 13			UMETA(DisplayName = "No Header Width"),
	PreferSortAscending			= 14			UMETA(DisplayName = "Prefer Sort Ascending"),
	PreferSortDescending		= 15			UMETA(DisplayName = "Prefer Sort Descending"),
	IndentEnable				= 16			UMETA(DisplayName = "Indent Enable"),
	IndentDisable				= 17			UMETA(DisplayName = "Indent Disable"),
	AngledHeader				= 18			UMETA(DisplayName = "Angled Header"),
};

UENUM(BlueprintType)
enum class EImGuiTableRowFlag : uint8
{
	None						= 255			UMETA(DisplayName = "None"),
	Headers						= 0				UMETA(DisplayName = "Headers"),
};

UENUM(BlueprintType)
enum class EImGuiColorEditFlag : uint8
{
	None						= 0				UMETA(DisplayName = "None"),
	NoAlpha						= 1				UMETA(DisplayName = "No Alpha"),
	NoPicker					= 2				UMETA(DisplayName = "No Picker"),
	NoOptions					= 3				UMETA(DisplayName = "No Options"),
	NoSmallPreview				= 4				UMETA(DisplayName = "No Small Preview"),
	NoInputs					= 5				UMETA(DisplayName = "No Inputs"),
	NoTooltip					= 6				UMETA(DisplayName = "No Tooltip"),
	NoLabel						= 7				UMETA(DisplayName = "No Label"),
	NoSidePreview				= 8				UMETA(DisplayName = "No Side Preview"),
	NoDragDrop					= 9				UMETA(DisplayName = "No Drag Drop"),
	NoBorder					= 10			UMETA(DisplayName = "No Border"),
	AlphaOpaque					= 11			UMETA(DisplayName = "Alpha Opaque"),
	AlphaNoBg					= 12			UMETA(DisplayName = "Alpha No Background"),
	AlphaPreviewHalf			= 13			UMETA(DisplayName = "Alpha Preview Half"),
	AlphaBar					= 16			UMETA(DisplayName = "Alpha Bar"),
	HDR							= 19			UMETA(DisplayName = "HDR"),
	DisplayRGB					= 20			UMETA(DisplayName = "Display RGB"),
	DisplayHSV					= 21			UMETA(DisplayName = "Display HSV"),
	DisplayHex					= 22			UMETA(DisplayName = "Display Hex"),
	Uint8						= 23			UMETA(DisplayName = "Uint8"),
	Float						= 24			UMETA(DisplayName = "Float"),
	PickerHueBar				= 25			UMETA(DisplayName = "Picker Hue Bar"),
	PickerHueWheel				= 26			UMETA(DisplayName = "Picker Hue Wheel"),
	InputRGB					= 27			UMETA(DisplayName = "Input RGB"),
	InputHSV					= 28			UMETA(DisplayName = "Input HSV"),
};

UENUM(BlueprintType)
enum class EImGuiPopupFlag : uint8
{
	None						= 0				UMETA(DisplayName = "None"),
	NoReopen					= 1				UMETA(DisplayName = "No Reopen"),
	NoOpenOverExistingPopup		= 2				UMETA(DisplayName = "No Open Over Existing Popup"),
	NoOpenOverItems				= 3				UMETA(DisplayName = "No Open Over Items"),
	AnyPopupID					= 4				UMETA(DisplayName = "Any Popup ID"),
	AnyPopupLevel				= 5				UMETA(DisplayName = "Any Popup Level"),
};

UENUM(BlueprintType)
enum class EImGuiPopupMouseButton : uint8
{
	Left						= 0				UMETA(DisplayName = "Left"),
	Right						= 1				UMETA(DisplayName = "Right"),
	Middle						= 2				UMETA(DisplayName = "Middle"),
};

UENUM(BlueprintType)
enum class EImGuiMultiSelectFlag : uint8
{
	None						= 0				UMETA(DisplayName = "None"),
	SingleSelect				= 1				UMETA(DisplayName = "Single Select"),
	NoSelectAll					= 2				UMETA(DisplayName = "No Select All"),
	NoRangeSelect				= 3				UMETA(DisplayName = "No Range Select"),
	NoAutoSelect				= 4				UMETA(DisplayName = "No Auto Select"),
	NoAutoClear					= 5				UMETA(DisplayName = "No Auto Clear"),
	NoAutoClearOnReselect		= 6				UMETA(DisplayName = "No Auto Clear On Reselect"),
	BoxSelect1D					= 7				UMETA(DisplayName = "Box Select 1D"),
	BoxSelect2D					= 8				UMETA(DisplayName = "Box Select 2D"),
	BoxSelectNoScroll			= 9				UMETA(DisplayName = "Box Select No Scroll"),
	ClearOnEscape				= 10			UMETA(DisplayName = "Clear On Escape"),
	ClearOnClickVoid			= 11			UMETA(DisplayName = "Clear On Click Void"),
	ScopeWindow					= 12			UMETA(DisplayName = "Scope Window"),
	ScopeRect					= 13			UMETA(DisplayName = "Scope Rect"),
	SelectOnClick				= 14			UMETA(DisplayName = "Select On Click"),
	SelectOnClickRelease		= 15			UMETA(DisplayName = "Select On Click Release"),
	NavWrapX					= 16			UMETA(DisplayName = "Navigation Wrap X"),
};

struct FImGuiToolkitUtils
{
	static ImVec4 LinearColorToImVec4(const FLinearColor& Color);
	static FLinearColor ImVec4ToLinearColor(const ImVec4& Color);

	static EImGuiToolkitDir ImGuiDirToUnrealDir(ImGuiDir Dir);
	static ImGuiDir UnrealDirToImGuiDir(EImGuiToolkitDir Dir);
	static ImGuiDir UnrealDockSplitDirectionToImGuiDir(EImGuiToolkitDockSplitDirection Direction);

	static EImGuiWindowFlag ImGuiWindowFlagToUnrealFlag(ImGuiWindowFlags Flags);
	static ImGuiWindowFlags UnrealFlagToImGuiWindowFlag(EImGuiWindowFlag Flags);
	static int32 CombineImGuiWindowFlags(TArray<EImGuiWindowFlag> Flags);
	static ImGuiChildFlags UnrealFlagToImGuiChildFlag(EImGuiChildFlag Flags);
	static int32 CombineImGuiChildFlags(TArray<EImGuiChildFlag> Flags);
	static ImGuiSelectableFlags UnrealFlagToImGuiSelectableFlag(EImGuiSelectableFlag Flags);
	static int32 CombineImGuiSelectableFlags(TArray<EImGuiSelectableFlag> Flags);
	static ImGuiTableFlags UnrealFlagToImGuiTableFlag(EImGuiTableFlag Flags);
	static int32 CombineImGuiTableFlags(TArray<EImGuiTableFlag> Flags);
	static ImGuiTableColumnFlags UnrealFlagToImGuiTableColumnFlag(EImGuiTableColumnFlag Flags);
	static int32 CombineImGuiTableColumnFlags(TArray<EImGuiTableColumnFlag> Flags);
	static ImGuiTableRowFlags UnrealFlagToImGuiTableRowFlag(EImGuiTableRowFlag Flags);
	static int32 CombineImGuiTableRowFlags(TArray<EImGuiTableRowFlag> Flags);
	static ImGuiColorEditFlags UnrealFlagToImGuiColorEditFlag(EImGuiColorEditFlag Flags);
	static int32 CombineImGuiColorEditFlags(TArray<EImGuiColorEditFlag> Flags);
	static ImGuiPopupFlags UnrealFlagToImGuiPopupFlag(EImGuiPopupFlag Flags);
	static int32 CombineImGuiPopupFlags(TArray<EImGuiPopupFlag> Flags);
	static ImGuiPopupFlags UnrealPopupMouseButtonToImGuiPopupFlag(EImGuiPopupMouseButton MouseButton);
	static ImGuiMultiSelectFlags UnrealFlagToImGuiMultiSelectFlag(EImGuiMultiSelectFlag Flags);
	static int32 CombineImGuiMultiSelectFlags(TArray<EImGuiMultiSelectFlag> Flags);

	static int32 ImGuiResizeCallback(ImGuiInputTextCallbackData* Data);
};
