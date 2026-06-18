#include "Widgets/Popups/ImGuiToolkitBeginPopup.h"

void UImGuiToolkitBeginPopup::Render()
{
	if (!bEnabled)
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

	bIsOpen = ImGui::BeginPopup(TCHAR_TO_UTF8(*PopupIDString), FImGuiToolkitUtils::CombineImGuiWindowFlags(WindowFlags));
	if (bIsOpen)
	{
		RenderChildren();
		ImGui::EndPopup();
	}
}
