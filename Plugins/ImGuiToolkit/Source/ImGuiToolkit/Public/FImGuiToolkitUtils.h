#pragma once
#include "CoreMinimal.h"
#include <imgui.h>

// A cardinal direction
UENUM(BlueprintType)
enum class EImGuiToolkitDir : uint8
{
	None    = -1,
	Left    = 0,
	Right   = 1,
	Up      = 2,
	Down    = 3,
	COUNT
};

UENUM(BlueprintType)
enum class EImGuiWindowFlag : uint8
{
	None						= -1			UMETA(DisplayName = "None"),
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

struct FImGuiToolkitUtils
{
	static ImVec4 LinearColorToImVec4(const FLinearColor& Color);
	static FLinearColor ImVec4ToLinearColor(const ImVec4& Color);

	static EImGuiToolkitDir ImGuiDirToUnrealDir(ImGuiDir Dir);
	static ImGuiDir UnrealDirToImGuiDir(EImGuiToolkitDir Dir);

	static EImGuiWindowFlag ImGuiWindowFlagToUnrealFlag(ImGuiWindowFlags Flags);
	static ImGuiWindowFlags UnrealFlagToImGuiWindowFlag(EImGuiWindowFlag Flags);
	static int32 CombineImGuiWindowFlags(TArray<EImGuiWindowFlag> Flags);

	static int32 ImGuiResizeCallback(ImGuiInputTextCallbackData* Data);
};
