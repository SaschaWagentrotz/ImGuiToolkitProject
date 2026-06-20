#include "Widgets/Images/ImGuiToolkitImageButton.h"

#include "Widgets/Images/ImGuiToolkitImageHelpers.h"

void UImGuiToolkitImageButton::Render()
{
	if (!bEnabled)
		return;

	if (ImGui::ImageButton(
		TCHAR_TO_UTF8(*UniqueWidgetLabel),
		ResourceObject,
		ImGuiToolkitImageHelpers::GetImageSize(ResourceObject, Size),
		ImGuiToolkitImageHelpers::ToImVec2(UV0),
		ImGuiToolkitImageHelpers::ToImVec2(UV1),
		FImGuiToolkitUtils::LinearColorToImVec4(BackgroundColor),
		FImGuiToolkitUtils::LinearColorToImVec4(TintColor)
	))
	{
		OnClicked.Broadcast(this);
	}

	if (ImGui::IsItemHovered())
	{
		OnHovered.Broadcast(this);
		if (!Tooltip.IsEmpty())
		{
			ImGui::SetTooltip("%s", TCHAR_TO_UTF8(*Tooltip.ToString()));
		}
	}
}
