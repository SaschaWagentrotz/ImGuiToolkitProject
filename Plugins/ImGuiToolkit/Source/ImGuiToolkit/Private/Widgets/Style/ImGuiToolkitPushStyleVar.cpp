#include "Widgets/Style/ImGuiToolkitPushStyleVar.h"

void UImGuiToolkitPushStyleVar::Render()
{
	if (!bEnabled)
		return;

	const ImGuiStyleVar ImGuiStyleVarValue = FImGuiToolkitUtils::UnrealStyleVarToImGuiStyleVar(StyleVar);
	if (FImGuiToolkitUtils::IsImGuiStyleVarVector(StyleVar))
	{
		ImGui::PushStyleVar(ImGuiStyleVarValue, ImVec2(Vector2DValue.X, Vector2DValue.Y));
		return;
	}

	ImGui::PushStyleVar(ImGuiStyleVarValue, FloatValue);
}
