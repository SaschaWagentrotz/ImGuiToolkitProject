#include "Containers/ImGuiToolkitTreeNode.h"

void UImGuiToolkitTreeNode::Render()
{
	if (!bEnabled)
		return;

	if (ImGui::TreeNode(TCHAR_TO_UTF8(*UniqueWidgetLabel)))
	{
		RenderChildren();
		ImGui::TreePop();
	}
}
