#include "Widgets/Popups/ImGuiToolkitBeginPopupContextItem.h"

#include "Widgets/Popups/ImGuiToolkitPopupHelpers.h"

void UImGuiToolkitBeginPopupContextItem::Render()
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
	const char* PopupIDArg = (bUsePreviousItemID || PopupIDString.IsEmpty()) ? nullptr : PopupIDUtf8.Get();
	const ImGuiPopupFlags CombinedFlags = FImGuiToolkitUtils::CombineImGuiPopupFlags(PopupFlags) |
		FImGuiToolkitUtils::UnrealPopupMouseButtonToImGuiPopupFlag(MouseButton);

	bIsOpen = ImGui::BeginPopupContextItem(PopupIDArg, CombinedFlags);
	if (bIsOpen)
	{
		RenderChildren();
		ImGui::EndPopup();
	}
}
