#include "Widgets/Main/ImGuiToolkitListBox.h"

namespace
{
	const char* GetListBoxItemText(void* UserData, int32 Index)
	{
		const TArray<FText>* ListItems = static_cast<const TArray<FText>*>(UserData);
		if (!ListItems || !ListItems->IsValidIndex(Index))
		{
			return "";
		}

		static TArray<char> Buffer;
		Buffer.Reset();

		const FString StringValue = (*ListItems)[Index].ToString();
		const FTCHARToUTF8 Converter(*StringValue);
		Buffer.Append(Converter.Get(), Converter.Length());
		Buffer.Add('\0');

		return Buffer.GetData();
	}
}

void UImGuiToolkitListBox::Render()
{
	if (!bEnabled)
		return;

	if (ListItems.Num() > 0)
	{
		SelectedIndex = FMath::Clamp(SelectedIndex, 0, ListItems.Num() - 1);
	}
	else
	{
		SelectedIndex = 0;
	}

	const int32 PreviousItem = SelectedIndex;

	ImGui::ListBox(TCHAR_TO_UTF8(*UniqueWidgetLabel), &SelectedIndex, GetListBoxItemText, &ListItems, ListItems.Num(), HeightInItems);

	if (PreviousItem != SelectedIndex)
	{
		OnSelectionChanged.Broadcast(this, SelectedIndex);
	}
}
