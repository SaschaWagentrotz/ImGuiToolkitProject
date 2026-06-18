#include "Widgets/Popups/ImGuiToolkitOpenPopupOnItemClick.h"

#include "Widgets/Popups/ImGuiToolkitPopupHelpers.h"

void UImGuiToolkitOpenPopupOnItemClick::Render()
{
	if (!bEnabled || ImGuiToolkitPopupHelpers::ShouldSuppressPopupAutoOpen())
		return;

	const FString PopupIDString = PopupID.ToString();
	const FTCHARToUTF8 PopupIDUtf8(*PopupIDString);
	const char* PopupIDArg = PopupIDString.IsEmpty() ? nullptr : PopupIDUtf8.Get();
	const ImGuiPopupFlags CombinedFlags = FImGuiToolkitUtils::CombineImGuiPopupFlags(PopupFlags) |
		FImGuiToolkitUtils::UnrealPopupMouseButtonToImGuiPopupFlag(MouseButton);

	ImGui::OpenPopupOnItemClick(PopupIDArg, CombinedFlags);
}
