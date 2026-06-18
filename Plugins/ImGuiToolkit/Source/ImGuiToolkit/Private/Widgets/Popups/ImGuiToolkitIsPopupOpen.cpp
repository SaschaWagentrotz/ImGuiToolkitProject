#include "Widgets/Popups/ImGuiToolkitIsPopupOpen.h"

void UImGuiToolkitIsPopupOpen::Render()
{
	if (!bEnabled)
	{
		if (bIsOpen)
		{
			bIsOpen = false;
			OnOpenStateChanged.Broadcast(this, bIsOpen);
		}
		return;
	}

	const FString PopupIDString = PopupID.ToString();
	ImGuiPopupFlags CombinedFlags = FImGuiToolkitUtils::CombineImGuiPopupFlags(PopupFlags);
	if ((CombinedFlags & ImGuiPopupFlags_AnyPopupLevel) != 0)
	{
		CombinedFlags |= ImGuiPopupFlags_AnyPopupId;
	}

	const bool bNewIsOpen = ImGui::IsPopupOpen(PopupIDString.IsEmpty() ? "" : TCHAR_TO_UTF8(*PopupIDString), CombinedFlags);
	if (bIsOpen != bNewIsOpen)
	{
		bIsOpen = bNewIsOpen;
		OnOpenStateChanged.Broadcast(this, bIsOpen);
	}
}
