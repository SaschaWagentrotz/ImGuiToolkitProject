#include "Widgets/Popups/ImGuiToolkitBeginPopupContextVoid.h"

#include "Widgets/Popups/ImGuiToolkitPopupHelpers.h"

void UImGuiToolkitBeginPopupContextVoid::Render()
{
	if (!bEnabled)
	{
		bIsOpen = false;
		return;
	}

	if (ImGuiToolkitPopupHelpers::ShouldSuppressPopupAutoOpen())
	{
		bIsOpen = false;
		return;
	}

	const FString PopupIDString = PopupID.ToString();
	const FTCHARToUTF8 PopupIDUtf8(*PopupIDString);
	const char* PopupIDArg = PopupIDString.IsEmpty() ? nullptr : PopupIDUtf8.Get();
	const ImGuiPopupFlags CombinedFlags = FImGuiToolkitUtils::CombineImGuiPopupFlags(PopupFlags) |
		FImGuiToolkitUtils::UnrealPopupMouseButtonToImGuiPopupFlag(MouseButton);

	bIsOpen = ImGui::BeginPopupContextVoid(PopupIDArg, CombinedFlags);
	if (bIsOpen)
	{
		RenderChildren();
		ImGui::EndPopup();
	}
}
