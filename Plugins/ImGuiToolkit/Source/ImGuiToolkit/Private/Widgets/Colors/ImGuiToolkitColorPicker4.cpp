#include "Widgets/Colors/ImGuiToolkitColorPicker4.h"

#include "Widgets/Colors/ImGuiToolkitColorHelpers.h"

void UImGuiToolkitColorPicker4::Render()
{
	if (!bEnabled)
		return;

	const ImGuiColorEditFlags CombinedFlags = ImGuiToolkitColorHelpers::GetColorPickerFlags(ColorEditFlags);
	float Values[4];
	ImGuiToolkitColorHelpers::LinearColorToColorEditValues(Color, CombinedFlags, Values);

	if (ImGui::ColorPicker4(TCHAR_TO_UTF8(*UniqueWidgetLabel), Values, CombinedFlags))
	{
		Color = ImGuiToolkitColorHelpers::ColorEditValuesToLinearColor(Values, Values[3], CombinedFlags);
		OnChanged.Broadcast(this, Color);
	}
}
