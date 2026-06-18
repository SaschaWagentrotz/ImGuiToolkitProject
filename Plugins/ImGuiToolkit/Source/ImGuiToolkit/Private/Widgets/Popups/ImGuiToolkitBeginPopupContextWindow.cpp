#include "Widgets/Popups/ImGuiToolkitBeginPopupContextWindow.h"

#include "Widgets/Popups/ImGuiToolkitPopupHelpers.h"

void UImGuiToolkitBeginPopupContextWindow::Render()
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

	bIsOpen = ImGui::BeginPopupContextWindow(PopupIDArg, CombinedFlags);
	if (bIsOpen)
	{
		RenderChildren();
		ImGui::EndPopup();
	}
}
