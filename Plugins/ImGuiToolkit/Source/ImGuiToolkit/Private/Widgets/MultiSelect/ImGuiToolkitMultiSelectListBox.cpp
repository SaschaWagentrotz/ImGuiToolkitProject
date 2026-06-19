#include "Widgets/MultiSelect/ImGuiToolkitMultiSelectListBox.h"

void UImGuiToolkitMultiSelectListBox::ClearSelection()
{
	SetSelectedIndices({});
}

void UImGuiToolkitMultiSelectListBox::SelectAll()
{
	TArray<int32> NewSelectedIndices;
	NewSelectedIndices.Reserve(Items.Num());
	for (int32 ItemIndex = 0; ItemIndex < Items.Num(); ++ItemIndex)
	{
		NewSelectedIndices.Add(ItemIndex);
	}
	SetSelectedIndices(NewSelectedIndices);
}

void UImGuiToolkitMultiSelectListBox::SetSelectedIndices(const TArray<int32>& InSelectedIndices)
{
	const TArray<int32> NewSelectedIndices = NormalizeSelectedIndices(InSelectedIndices);
	if (SelectedIndices != NewSelectedIndices)
	{
		SelectedIndices = NewSelectedIndices;
		OnSelectionChanged.Broadcast(this, SelectedIndices);
	}
}

void UImGuiToolkitMultiSelectListBox::Render()
{
	if (!bEnabled)
		return;

	SelectedIndices = NormalizeSelectedIndices(SelectedIndices);

	TSet<int32> SelectionSet;
	for (const int32 SelectedIndex : SelectedIndices)
	{
		SelectionSet.Add(SelectedIndex);
	}

	const ImVec2 ListBoxSize(Size.X, Size.Y);
	if (!ImGui::BeginChild(TCHAR_TO_UTF8(*UniqueWidgetLabel), ListBoxSize, ImGuiChildFlags_Borders))
	{
		ImGui::EndChild();
		return;
	}

	ImGuiMultiSelectFlags CombinedMultiSelectFlags = FImGuiToolkitUtils::CombineImGuiMultiSelectFlags(MultiSelectFlags);
	if (CombinedMultiSelectFlags == ImGuiMultiSelectFlags_None)
	{
		CombinedMultiSelectFlags = ImGuiMultiSelectFlags_ClearOnEscape | ImGuiMultiSelectFlags_BoxSelect1d;
	}
	if ((CombinedMultiSelectFlags & ImGuiMultiSelectFlags_ScopeRect) == 0 &&
		(CombinedMultiSelectFlags & ImGuiMultiSelectFlags_ScopeWindow) == 0)
	{
		CombinedMultiSelectFlags |= ImGuiMultiSelectFlags_ScopeRect;
	}

	ImGuiMultiSelectIO* MultiSelectIO = ImGui::BeginMultiSelect(CombinedMultiSelectFlags, SelectionSet.Num(), Items.Num());
	ApplySelectionRequests(MultiSelectIO, SelectionSet);

	const ImGuiSelectableFlags CombinedSelectableFlags = FImGuiToolkitUtils::CombineImGuiSelectableFlags(SelectableFlags);
	LastHoveredIndex = INDEX_NONE;
	for (int32 ItemIndex = 0; ItemIndex < Items.Num(); ++ItemIndex)
	{
		const bool bItemIsSelected = SelectionSet.Contains(ItemIndex);
		const FString ItemLabel = FString::Printf(TEXT("%s###%s_Item_%d"), *Items[ItemIndex].ToString(), *UniqueID.ToString(), ItemIndex);

		ImGui::SetNextItemSelectionUserData(ItemIndex);
		if (ImGui::Selectable(TCHAR_TO_UTF8(*ItemLabel), bItemIsSelected, CombinedSelectableFlags))
		{
			LastClickedIndex = ItemIndex;
			OnItemClicked.Broadcast(this, ItemIndex, SelectionSet.Contains(ItemIndex));
		}

		if (ImGui::IsItemHovered())
		{
			LastHoveredIndex = ItemIndex;
			OnItemHovered.Broadcast(this, ItemIndex, SelectionSet.Contains(ItemIndex));
		}
	}

	MultiSelectIO = ImGui::EndMultiSelect();
	ApplySelectionRequests(MultiSelectIO, SelectionSet);
	UpdateSelectedIndicesFromSet(SelectionSet);

	ImGui::EndChild();
}

TArray<int32> UImGuiToolkitMultiSelectListBox::NormalizeSelectedIndices(const TArray<int32>& InSelectedIndices) const
{
	TSet<int32> UniqueIndices;
	for (const int32 SelectedIndex : InSelectedIndices)
	{
		if (SelectedIndex >= 0 && SelectedIndex < Items.Num())
		{
			UniqueIndices.Add(SelectedIndex);
		}
	}

	TArray<int32> NormalizedIndices = UniqueIndices.Array();
	NormalizedIndices.Sort();
	return NormalizedIndices;
}

void UImGuiToolkitMultiSelectListBox::ApplySelectionRequests(ImGuiMultiSelectIO* MultiSelectIO, TSet<int32>& SelectionSet) const
{
	if (!MultiSelectIO || Items.IsEmpty())
	{
		SelectionSet.Empty();
		return;
	}

	for (const ImGuiSelectionRequest& Request : MultiSelectIO->Requests)
	{
		if (Request.Type == ImGuiSelectionRequestType_SetAll)
		{
			SelectionSet.Empty();
			if (Request.Selected)
			{
				for (int32 ItemIndex = 0; ItemIndex < Items.Num(); ++ItemIndex)
				{
					SelectionSet.Add(ItemIndex);
				}
			}
		}
		else if (Request.Type == ImGuiSelectionRequestType_SetRange)
		{
			const int32 FirstItem = FMath::Clamp(static_cast<int32>(Request.RangeFirstItem), 0, Items.Num() - 1);
			const int32 LastItem = FMath::Clamp(static_cast<int32>(Request.RangeLastItem), 0, Items.Num() - 1);
			const int32 RangeMin = FMath::Min(FirstItem, LastItem);
			const int32 RangeMax = FMath::Max(FirstItem, LastItem);
			for (int32 ItemIndex = RangeMin; ItemIndex <= RangeMax; ++ItemIndex)
			{
				if (Request.Selected)
				{
					SelectionSet.Add(ItemIndex);
				}
				else
				{
					SelectionSet.Remove(ItemIndex);
				}
			}
		}
	}
}

void UImGuiToolkitMultiSelectListBox::UpdateSelectedIndicesFromSet(const TSet<int32>& SelectionSet)
{
	TArray<int32> NewSelectedIndices = SelectionSet.Array();
	NewSelectedIndices.Sort();

	if (SelectedIndices != NewSelectedIndices)
	{
		SelectedIndices = NewSelectedIndices;
		OnSelectionChanged.Broadcast(this, SelectedIndices);
	}
}
