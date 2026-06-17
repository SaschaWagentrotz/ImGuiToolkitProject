#include "Widgets/Tables/ImGuiToolkitTableHeader.h"

void UImGuiToolkitTableHeader::Render()
{
	if (!bEnabled)
	{
		return;
	}

	const FString LabelString = Label.ToString();
	ImGui::TableHeader(TCHAR_TO_UTF8(*LabelString));
}
