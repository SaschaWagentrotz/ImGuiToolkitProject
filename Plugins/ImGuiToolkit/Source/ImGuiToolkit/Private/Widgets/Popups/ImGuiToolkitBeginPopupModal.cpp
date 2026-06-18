#include "Widgets/Popups/ImGuiToolkitBeginPopupModal.h"

void UImGuiToolkitBeginPopupModal::Render()
{
	if (!bEnabled || !bModalOpen)
	{
		bIsOpen = false;
		return;
	}

	const FString PopupIDString = PopupID.ToString();
	if (PopupIDString.IsEmpty())
	{
		bIsOpen = false;
		return;
	}

	bool OpenState = bModalOpen;
	bool* OpenStatePtr = bShowCloseButton ? &OpenState : nullptr;
	bIsOpen = ImGui::BeginPopupModal(TCHAR_TO_UTF8(*PopupIDString), OpenStatePtr, FImGuiToolkitUtils::CombineImGuiWindowFlags(WindowFlags));
	if (bIsOpen)
	{
		RenderChildren();
		ImGui::EndPopup();
	}

	if (bShowCloseButton)
	{
		bModalOpen = OpenState;
	}
}
