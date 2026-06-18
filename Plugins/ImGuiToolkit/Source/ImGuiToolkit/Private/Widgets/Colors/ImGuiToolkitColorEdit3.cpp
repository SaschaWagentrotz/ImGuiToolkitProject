#include "Widgets/Colors/ImGuiToolkitColorEdit3.h"

#include "Widgets/Colors/ImGuiToolkitColorHelpers.h"

void UImGuiToolkitColorEdit3::Render()
{
	if (!bEnabled)
		return;

	const ImGuiColorEditFlags CombinedFlags = ImGuiToolkitColorHelpers::GetColorEditFlags(ColorEditFlags);
	float Values[4];
	ImGuiToolkitColorHelpers::LinearColorToColorEditValues(Color, CombinedFlags, Values);

	if (ImGui::ColorEdit3(TCHAR_TO_UTF8(*UniqueWidgetLabel), Values, CombinedFlags))
	{
		Color = ImGuiToolkitColorHelpers::ColorEditValuesToLinearColor(Values, FImGuiToolkitUtils::LinearColorToImVec4(Color).w, CombinedFlags);
		OnChanged.Broadcast(this, Color);
	}
}
