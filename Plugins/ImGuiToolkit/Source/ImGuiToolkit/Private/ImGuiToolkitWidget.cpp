// Fill out your copyright notice in the Description page of Project Settings.


#include "ImGuiToolkitWidget.h"

UImGuiToolkitWidget::UImGuiToolkitWidget()
{
	// Generate a unique ID when the widget is created
	UniqueID = FGuid::NewGuid();
}

void UImGuiToolkitWidget::Render()
{
}

void UImGuiToolkitWidget::CreateUniqueWidgetLabel(FText Label)
{
	WidgetLabel = Label;
	UniqueWidgetLabel = GetUniqueWidgetLabel(WidgetLabel);
}

FString UImGuiToolkitWidget::GetUniqueWidgetLabel(const FText& Label) const
{
	// Append unique ID to label to ensure ImGui sees it as unique
	// Format: "Label###UniqueID"
	// ImGui uses "###" to separate the displayed label from the ID
	return FString::Printf(TEXT("%s###%s"), *Label.ToString(), *UniqueID.ToString());
}

void UImGuiToolkitWidget::Destroy()
{
}

const char* UImGuiToolkitWidget::ConvertFTextArrayToCharBuffer(const TArray<FText>& TextArray)
{
	static TArray<char> Buffer;
	Buffer.Reset();

	for (const FText& Text : TextArray)
	{
		FString StringValue = Text.ToString();
		FTCHARToUTF8 Converter(*StringValue);
		const char* UTF8Data = Converter.Get();
		int32 UTF8Length = Converter.Length();
		
		Buffer.Append(UTF8Data, UTF8Length);
		Buffer.Add('\0');
	}
	Buffer.Add('\0');

	return Buffer.GetData();
}
