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

struct FImGuiToolkitUtils
{
	static ImVec4 LinearColorToImVec4(const FLinearColor& Color);
	static FLinearColor ImVec4ToLinearColor(const ImVec4& Color);

	static EImGuiToolkitDir ImGuiDirToUnrealDir(ImGuiDir Dir);
	static ImGuiDir UnrealDirToImGuiDir(EImGuiToolkitDir Dir);
};
