#include "Containers/ImGuiToolkitBeginChild.h"

void UImGuiToolkitBeginChild::Render()
{
	if (!bEnabled)
	{
		return;
	}

	const ImVec2 ChildSize(Size.X, Size.Y);
	const ImGuiChildFlags CombinedChildFlags = FImGuiToolkitUtils::CombineImGuiChildFlags(ChildFlags);
	const ImGuiWindowFlags CombinedWindowFlags = FImGuiToolkitUtils::CombineImGuiWindowFlags(WindowFlags);

	if (ImGui::BeginChild(TCHAR_TO_UTF8(*UniqueWidgetLabel), ChildSize, CombinedChildFlags, CombinedWindowFlags))
	{
		RenderChildren();
	}

	ImGui::EndChild();
}
