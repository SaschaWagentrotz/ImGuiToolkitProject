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
enum class EImGuiComboFlag : uint8
{
	None						= 0				UMETA(DisplayName = "None"),
	PopupAlignLeft				= 1				UMETA(DisplayName = "Popup Align Left"),
	HeightSmall					= 2				UMETA(DisplayName = "Height Small"),
	HeightRegular				= 3				UMETA(DisplayName = "Height Regular"),
	HeightLarge					= 4				UMETA(DisplayName = "Height Large"),
	HeightLargest				= 5				UMETA(DisplayName = "Height Largest"),
	NoArrowButton				= 6				UMETA(DisplayName = "No Arrow Button"),
	NoPreview					= 7				UMETA(DisplayName = "No Preview"),
	WidthFitPreview				= 8				UMETA(DisplayName = "Width Fit Preview"),
};

UENUM(BlueprintType)
enum class EImGuiStyleColor : uint8
{
	Text						= 0				UMETA(DisplayName = "Text"),
	TextDisabled				= 1				UMETA(DisplayName = "Text Disabled"),
	WindowBg					= 2				UMETA(DisplayName = "Window Background"),
	ChildBg						= 3				UMETA(DisplayName = "Child Background"),
	PopupBg						= 4				UMETA(DisplayName = "Popup Background"),
	Border						= 5				UMETA(DisplayName = "Border"),
	BorderShadow				= 6				UMETA(DisplayName = "Border Shadow"),
	FrameBg						= 7				UMETA(DisplayName = "Frame Background"),
	FrameBgHovered				= 8				UMETA(DisplayName = "Frame Background Hovered"),
	FrameBgActive				= 9				UMETA(DisplayName = "Frame Background Active"),
	TitleBg						= 10			UMETA(DisplayName = "Title Background"),
	TitleBgActive				= 11			UMETA(DisplayName = "Title Background Active"),
	TitleBgCollapsed			= 12			UMETA(DisplayName = "Title Background Collapsed"),
	MenuBarBg					= 13			UMETA(DisplayName = "Menu Bar Background"),
	ScrollbarBg					= 14			UMETA(DisplayName = "Scrollbar Background"),
	ScrollbarGrab				= 15			UMETA(DisplayName = "Scrollbar Grab"),
	ScrollbarGrabHovered		= 16			UMETA(DisplayName = "Scrollbar Grab Hovered"),
	ScrollbarGrabActive			= 17			UMETA(DisplayName = "Scrollbar Grab Active"),
	CheckMark					= 18			UMETA(DisplayName = "Check Mark"),
	SliderGrab					= 19			UMETA(DisplayName = "Slider Grab"),
	SliderGrabActive			= 20			UMETA(DisplayName = "Slider Grab Active"),
	Button						= 21			UMETA(DisplayName = "Button"),
	ButtonHovered				= 22			UMETA(DisplayName = "Button Hovered"),
	ButtonActive					= 23			UMETA(DisplayName = "Button Active"),
	Header						= 24			UMETA(DisplayName = "Header"),
	HeaderHovered				= 25			UMETA(DisplayName = "Header Hovered"),
	HeaderActive				= 26			UMETA(DisplayName = "Header Active"),
	Separator					= 27			UMETA(DisplayName = "Separator"),
	SeparatorHovered			= 28			UMETA(DisplayName = "Separator Hovered"),
	SeparatorActive				= 29			UMETA(DisplayName = "Separator Active"),
	ResizeGrip					= 30			UMETA(DisplayName = "Resize Grip"),
	ResizeGripHovered			= 31			UMETA(DisplayName = "Resize Grip Hovered"),
	ResizeGripActive			= 32			UMETA(DisplayName = "Resize Grip Active"),
	TabHovered					= 33			UMETA(DisplayName = "Tab Hovered"),
	Tab							= 34			UMETA(DisplayName = "Tab"),
	TabSelected					= 35			UMETA(DisplayName = "Tab Selected"),
	TabSelectedOverline			= 36			UMETA(DisplayName = "Tab Selected Overline"),
	TabDimmed					= 37			UMETA(DisplayName = "Tab Dimmed"),
	TabDimmedSelected			= 38			UMETA(DisplayName = "Tab Dimmed Selected"),
	TabDimmedSelectedOverline	= 39			UMETA(DisplayName = "Tab Dimmed Selected Overline"),
	DockingPreview				= 40			UMETA(DisplayName = "Docking Preview"),
	DockingEmptyBg				= 41			UMETA(DisplayName = "Docking Empty Background"),
	PlotLines					= 42			UMETA(DisplayName = "Plot Lines"),
	PlotLinesHovered			= 43			UMETA(DisplayName = "Plot Lines Hovered"),
	PlotHistogram				= 44			UMETA(DisplayName = "Plot Histogram"),
	PlotHistogramHovered		= 45			UMETA(DisplayName = "Plot Histogram Hovered"),
	TableHeaderBg				= 46			UMETA(DisplayName = "Table Header Background"),
	TableBorderStrong			= 47			UMETA(DisplayName = "Table Border Strong"),
	TableBorderLight			= 48			UMETA(DisplayName = "Table Border Light"),
	TableRowBg					= 49			UMETA(DisplayName = "Table Row Background"),
	TableRowBgAlt				= 50			UMETA(DisplayName = "Table Row Background Alt"),
	TextLink					= 51			UMETA(DisplayName = "Text Link"),
	TextSelectedBg				= 52			UMETA(DisplayName = "Text Selected Background"),
	DragDropTarget				= 53			UMETA(DisplayName = "Drag Drop Target"),
	NavCursor					= 54			UMETA(DisplayName = "Navigation Cursor"),
	NavWindowingHighlight		= 55			UMETA(DisplayName = "Navigation Windowing Highlight"),
	NavWindowingDimBg			= 56			UMETA(DisplayName = "Navigation Windowing Dim Background"),
	ModalWindowDimBg			= 57			UMETA(DisplayName = "Modal Window Dim Background"),
};

UENUM(BlueprintType)
enum class EImGuiStyleVar : uint8
{
	Alpha						= 0				UMETA(DisplayName = "Alpha"),
	DisabledAlpha				= 1				UMETA(DisplayName = "Disabled Alpha"),
	WindowPadding				= 2				UMETA(DisplayName = "Window Padding"),
	WindowRounding				= 3				UMETA(DisplayName = "Window Rounding"),
	WindowBorderSize			= 4				UMETA(DisplayName = "Window Border Size"),
	WindowMinSize				= 5				UMETA(DisplayName = "Window Min Size"),
	WindowTitleAlign			= 6				UMETA(DisplayName = "Window Title Align"),
	ChildRounding				= 7				UMETA(DisplayName = "Child Rounding"),
	ChildBorderSize				= 8				UMETA(DisplayName = "Child Border Size"),
	PopupRounding				= 9				UMETA(DisplayName = "Popup Rounding"),
	PopupBorderSize				= 10			UMETA(DisplayName = "Popup Border Size"),
	FramePadding				= 11			UMETA(DisplayName = "Frame Padding"),
	FrameRounding				= 12			UMETA(DisplayName = "Frame Rounding"),
	FrameBorderSize				= 13			UMETA(DisplayName = "Frame Border Size"),
	ItemSpacing					= 14			UMETA(DisplayName = "Item Spacing"),
	ItemInnerSpacing			= 15			UMETA(DisplayName = "Item Inner Spacing"),
	IndentSpacing				= 16			UMETA(DisplayName = "Indent Spacing"),
	CellPadding					= 17			UMETA(DisplayName = "Cell Padding"),
	ScrollbarSize				= 18			UMETA(DisplayName = "Scrollbar Size"),
	ScrollbarRounding			= 19			UMETA(DisplayName = "Scrollbar Rounding"),
	GrabMinSize					= 20			UMETA(DisplayName = "Grab Min Size"),
	GrabRounding				= 21			UMETA(DisplayName = "Grab Rounding"),
	TabRounding					= 22			UMETA(DisplayName = "Tab Rounding"),
	TabBorderSize				= 23			UMETA(DisplayName = "Tab Border Size"),
	TabBarBorderSize			= 24			UMETA(DisplayName = "Tab Bar Border Size"),
	TabBarOverlineSize			= 25			UMETA(DisplayName = "Tab Bar Overline Size"),
	TableAngledHeadersAngle		= 26			UMETA(DisplayName = "Table Angled Headers Angle"),
	TableAngledHeadersTextAlign	= 27			UMETA(DisplayName = "Table Angled Headers Text Align"),
	ButtonTextAlign				= 28			UMETA(DisplayName = "Button Text Align"),
	SelectableTextAlign			= 29			UMETA(DisplayName = "Selectable Text Align"),
	SeparatorTextBorderSize		= 30			UMETA(DisplayName = "Separator Text Border Size"),
	SeparatorTextAlign			= 31			UMETA(DisplayName = "Separator Text Align"),
	SeparatorTextPadding		= 32			UMETA(DisplayName = "Separator Text Padding"),
	DockingSeparatorSize			= 33			UMETA(DisplayName = "Docking Separator Size"),
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
	static ImGuiComboFlags UnrealFlagToImGuiComboFlag(EImGuiComboFlag Flags);
	static int32 CombineImGuiComboFlags(TArray<EImGuiComboFlag> Flags);
	static ImGuiCol UnrealStyleColorToImGuiCol(EImGuiStyleColor StyleColor);
	static ImGuiStyleVar UnrealStyleVarToImGuiStyleVar(EImGuiStyleVar StyleVar);
	static bool IsImGuiStyleVarVector(EImGuiStyleVar StyleVar);
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
