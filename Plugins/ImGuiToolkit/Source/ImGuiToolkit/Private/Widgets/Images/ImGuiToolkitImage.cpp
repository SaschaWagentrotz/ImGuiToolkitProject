#include "Widgets/Images/ImGuiToolkitImage.h"

#include "Widgets/Images/ImGuiToolkitImageHelpers.h"

void UImGuiToolkitImage::Render()
{
	if (!bEnabled)
		return;

	ImGui::Image(
		ResourceObject,
		ImGuiToolkitImageHelpers::GetImageSize(ResourceObject, Size),
		ImGuiToolkitImageHelpers::ToImVec2(UV0),
		ImGuiToolkitImageHelpers::ToImVec2(UV1),
		FImGuiToolkitUtils::LinearColorToImVec4(TintColor),
		FImGuiToolkitUtils::LinearColorToImVec4(BorderColor)
	);
}
