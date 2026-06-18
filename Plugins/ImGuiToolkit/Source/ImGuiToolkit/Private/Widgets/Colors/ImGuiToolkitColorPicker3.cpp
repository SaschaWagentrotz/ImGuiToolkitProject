#include "Widgets/Colors/ImGuiToolkitColorPicker3.h"

#include "Widgets/Colors/ImGuiToolkitColorHelpers.h"

void UImGuiToolkitColorPicker3::Render()
{
	if (!bEnabled)
		return;

	const ImGuiColorEditFlags CombinedFlags = ImGuiToolkitColorHelpers::GetColorPickerFlags(ColorEditFlags);
	float Values[4];
	ImGuiToolkitColorHelpers::LinearColorToColorEditValues(Color, CombinedFlags, Values);

	if (ImGui::ColorPicker3(TCHAR_TO_UTF8(*UniqueWidgetLabel), Values, CombinedFlags))
	{
		Color = ImGuiToolkitColorHelpers::ColorEditValuesToLinearColor(Values, FImGuiToolkitUtils::LinearColorToImVec4(Color).w, CombinedFlags);
		OnChanged.Broadcast(this, Color);
	}
}
