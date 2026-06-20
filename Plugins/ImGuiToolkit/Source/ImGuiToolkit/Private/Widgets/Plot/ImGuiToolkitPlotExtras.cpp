#include "Widgets/Plot/ImGuiToolkitPlotExtras.h"

namespace ImGuiToolkitPlotExtras
{
	int32 MinPositiveCount(std::initializer_list<int32> Counts)
	{
		int32 MinCount = MAX_int32;
		for (const int32 Count : Counts)
		{
			MinCount = FMath::Min(MinCount, Count);
		}
		return MinCount == MAX_int32 ? 0 : MinCount;
	}

	void BuildLabelPointers(const TArray<FText>& Labels, TArray<TArray<ANSICHAR>>& LabelBuffers, TArray<const char*>& LabelPointers)
	{
		LabelBuffers.Reset(Labels.Num());
		LabelPointers.Reset(Labels.Num());

		for (const FText& Label : Labels)
		{
			const FString LabelString = Label.ToString();
			FTCHARToUTF8 ConvertedLabel(*LabelString);
			TArray<ANSICHAR>& Buffer = LabelBuffers.AddDefaulted_GetRef();
			Buffer.Append(ConvertedLabel.Get(), ConvertedLabel.Length());
			Buffer.Add('\0');
			LabelPointers.Add(Buffer.GetData());
		}
	}
}

void UImGuiToolkitSetupPlotLegend::Render()
{
	if (!bEnabled)
		return;

	ImPlot::SetupLegend(
		FImGuiToolkitUtils::UnrealPlotLocationToImPlotLocation(Location),
		FImGuiToolkitUtils::CombineImPlotLegendFlags(LegendFlags)
	);
}

void UImGuiToolkitSetupPlotMouseText::Render()
{
	if (!bEnabled)
		return;

	ImPlot::SetupMouseText(
		FImGuiToolkitUtils::UnrealPlotLocationToImPlotLocation(Location),
		FImGuiToolkitUtils::CombineImPlotMouseTextFlags(MouseTextFlags)
	);
}

void UImGuiToolkitSetupPlotAxisFormat::Render()
{
	if (!bEnabled)
		return;

	ImPlot::SetupAxisFormat(FImGuiToolkitUtils::UnrealPlotAxisToImPlotAxis(Axis), TCHAR_TO_UTF8(*Format));
}

void UImGuiToolkitSetupPlotAxisScale::Render()
{
	if (!bEnabled)
		return;

	ImPlot::SetupAxisScale(
		FImGuiToolkitUtils::UnrealPlotAxisToImPlotAxis(Axis),
		FImGuiToolkitUtils::UnrealPlotScaleToImPlotScale(Scale)
	);
}

void UImGuiToolkitSetupPlotAxes::Render()
{
	if (!bEnabled)
		return;

	const FString XLabelString = XLabel.ToString();
	const FString YLabelString = YLabel.ToString();
	ImPlot::SetupAxes(
		XLabelString.IsEmpty() ? nullptr : TCHAR_TO_UTF8(*XLabelString),
		YLabelString.IsEmpty() ? nullptr : TCHAR_TO_UTF8(*YLabelString),
		FImGuiToolkitUtils::CombineImPlotAxisFlags(XAxisFlags),
		FImGuiToolkitUtils::CombineImPlotAxisFlags(YAxisFlags)
	);
}

void UImGuiToolkitSetupPlotAxesLimits::Render()
{
	if (!bEnabled)
		return;

	ImPlot::SetupAxesLimits(
		XLimits.X,
		XLimits.Y,
		YLimits.X,
		YLimits.Y,
		FImGuiToolkitUtils::UnrealPlotConditionToImPlotCond(Condition)
	);
}

void UImGuiToolkitSetupPlotAxisLimitsConstraints::Render()
{
	if (!bEnabled)
		return;

	ImPlot::SetupAxisLimitsConstraints(FImGuiToolkitUtils::UnrealPlotAxisToImPlotAxis(Axis), MinValue, MaxValue);
}

void UImGuiToolkitSetupPlotAxisZoomConstraints::Render()
{
	if (!bEnabled)
		return;

	ImPlot::SetupAxisZoomConstraints(FImGuiToolkitUtils::UnrealPlotAxisToImPlotAxis(Axis), MinZoom, MaxZoom);
}

void UImGuiToolkitSetupPlotAxisTicks::Render()
{
	if (!bEnabled || Values.IsEmpty())
		return;

	TArray<TArray<ANSICHAR>> LabelBuffers;
	TArray<const char*> LabelPointers;
	const char* const* LabelPointerData = nullptr;
	if (Labels.Num() >= Values.Num())
	{
		ImGuiToolkitPlotExtras::BuildLabelPointers(Labels, LabelBuffers, LabelPointers);
		LabelPointerData = LabelPointers.GetData();
	}

	TArray<double> DoubleValues;
	DoubleValues.Reserve(Values.Num());
	for (float Value : Values)
	{
		DoubleValues.Add(Value);
	}

	ImPlot::SetupAxisTicks(
		FImGuiToolkitUtils::UnrealPlotAxisToImPlotAxis(Axis),
		DoubleValues.GetData(),
		DoubleValues.Num(),
		LabelPointerData,
		bKeepDefault
	);
}

void UImGuiToolkitSetupPlotAxisTicksRange::Render()
{
	if (!bEnabled)
		return;

	const int32 ClampedTickCount = FMath::Max(1, TickCount);
	TArray<TArray<ANSICHAR>> LabelBuffers;
	TArray<const char*> LabelPointers;
	const char* const* LabelPointerData = nullptr;
	if (Labels.Num() >= ClampedTickCount)
	{
		ImGuiToolkitPlotExtras::BuildLabelPointers(Labels, LabelBuffers, LabelPointers);
		LabelPointerData = LabelPointers.GetData();
	}

	ImPlot::SetupAxisTicks(
		FImGuiToolkitUtils::UnrealPlotAxisToImPlotAxis(Axis),
		MinValue,
		MaxValue,
		ClampedTickCount,
		LabelPointerData,
		bKeepDefault
	);
}

void UImGuiToolkitSetupPlotFinish::Render()
{
	if (!bEnabled)
		return;

	ImPlot::SetupFinish();
}

void UImGuiToolkitSetNextPlotAxisLimits::Render()
{
	if (!bEnabled)
		return;

	ImPlot::SetNextAxisLimits(
		FImGuiToolkitUtils::UnrealPlotAxisToImPlotAxis(Axis),
		MinValue,
		MaxValue,
		FImGuiToolkitUtils::UnrealPlotConditionToImPlotCond(Condition)
	);
}

void UImGuiToolkitSetNextPlotAxesLimits::Render()
{
	if (!bEnabled)
		return;

	ImPlot::SetNextAxesLimits(
		XLimits.X,
		XLimits.Y,
		YLimits.X,
		YLimits.Y,
		FImGuiToolkitUtils::UnrealPlotConditionToImPlotCond(Condition)
	);
}

void UImGuiToolkitSetNextPlotAxisToFit::Render()
{
	if (!bEnabled)
		return;

	ImPlot::SetNextAxisToFit(FImGuiToolkitUtils::UnrealPlotAxisToImPlotAxis(Axis));
}

void UImGuiToolkitSetNextPlotAxesToFit::Render()
{
	if (!bEnabled)
		return;

	ImPlot::SetNextAxesToFit();
}

void UImGuiToolkitSetPlotAxis::Render()
{
	if (!bEnabled)
		return;

	ImPlot::SetAxis(FImGuiToolkitUtils::UnrealPlotAxisToImPlotAxis(Axis));
}

void UImGuiToolkitSetPlotAxes::Render()
{
	if (!bEnabled)
		return;

	ImPlot::SetAxes(
		FImGuiToolkitUtils::UnrealPlotAxisToImPlotAxis(XAxis),
		FImGuiToolkitUtils::UnrealPlotAxisToImPlotAxis(YAxis)
	);
}

void UImGuiToolkitHideNextPlotItem::Render()
{
	if (!bEnabled)
		return;

	ImPlot::HideNextItem(bHidden, FImGuiToolkitUtils::UnrealPlotConditionToImPlotCond(Condition));
}

void UImGuiToolkitPlotQuery::Render()
{
	if (!bEnabled)
		return;

	const ImAxis ImXAxis = FImGuiToolkitUtils::UnrealPlotAxisToImPlotAxis(XAxis);
	const ImAxis ImYAxis = FImGuiToolkitUtils::UnrealPlotAxisToImPlotAxis(YAxis);
	const ImPlotPoint MousePos = ImPlot::GetPlotMousePos(ImXAxis, ImYAxis);
	const ImPlotRect Limits = ImPlot::GetPlotLimits(ImXAxis, ImYAxis);
	const ImPlotRect Selection = ImPlot::GetPlotSelection(ImXAxis, ImYAxis);

	MousePosition = FVector2D(MousePos.x, MousePos.y);
	PlotLimitsMin = FVector2D(Limits.X.Min, Limits.Y.Min);
	PlotLimitsMax = FVector2D(Limits.X.Max, Limits.Y.Max);
	bPlotHovered = ImPlot::IsPlotHovered();
	bSubplotsHovered = ImPlot::IsSubplotsHovered();
	bPlotSelected = ImPlot::IsPlotSelected();
	SelectionMin = FVector2D(Selection.X.Min, Selection.Y.Min);
	SelectionMax = FVector2D(Selection.X.Max, Selection.Y.Max);
}

void UImGuiToolkitPlotAxisQuery::Render()
{
	if (!bEnabled)
		return;

	bAxisHovered = ImPlot::IsAxisHovered(FImGuiToolkitUtils::UnrealPlotAxisToImPlotAxis(Axis));
}

void UImGuiToolkitCancelPlotSelection::Render()
{
	if (!bEnabled)
		return;

	ImPlot::CancelPlotSelection();
}

void UImGuiToolkitPlotStairs::Render()
{
	if (!bEnabled || Values.IsEmpty())
		return;

	ImPlot::PlotStairs(
		TCHAR_TO_UTF8(*UniqueWidgetLabel),
		Values.GetData(),
		Values.Num(),
		XScale,
		XStart,
		FImGuiToolkitUtils::CombineImPlotStairsFlags(StairsFlags) | FImGuiToolkitUtils::CombineImPlotItemFlags(ItemFlags)
	);
}

void UImGuiToolkitPlotBarGroups::Render()
{
	const int32 ClampedItemCount = FMath::Max(1, ItemCount);
	const int32 ClampedGroupCount = FMath::Max(1, GroupCount);
	if (!bEnabled || Labels.Num() < ClampedItemCount || Values.Num() < ClampedItemCount * ClampedGroupCount)
		return;

	TArray<TArray<ANSICHAR>> LabelBuffers;
	TArray<const char*> LabelPointers;
	ImGuiToolkitPlotExtras::BuildLabelPointers(Labels, LabelBuffers, LabelPointers);

	ImPlot::PlotBarGroups(
		LabelPointers.GetData(),
		Values.GetData(),
		ClampedItemCount,
		ClampedGroupCount,
		GroupSize,
		Shift,
		FImGuiToolkitUtils::CombineImPlotBarGroupsFlags(BarGroupsFlags) | FImGuiToolkitUtils::CombineImPlotItemFlags(ItemFlags)
	);
}

void UImGuiToolkitStylePlotColors::Render()
{
	if (!bEnabled)
		return;

	switch (Preset)
	{
		case EImPlotStylePreset::Classic:
			ImPlot::StyleColorsClassic();
			break;
		case EImPlotStylePreset::Dark:
			ImPlot::StyleColorsDark();
			break;
		case EImPlotStylePreset::Light:
			ImPlot::StyleColorsLight();
			break;
		case EImPlotStylePreset::Auto:
		default:
			ImPlot::StyleColorsAuto();
			break;
	}
}

void UImGuiToolkitPlotStairsXY::Render()
{
	const int32 Count = ImGuiToolkitPlotExtras::MinPositiveCount({ XValues.Num(), YValues.Num() });
	if (!bEnabled || Count <= 0)
		return;

	ImPlot::PlotStairs(
		TCHAR_TO_UTF8(*UniqueWidgetLabel),
		XValues.GetData(),
		YValues.GetData(),
		Count,
		FImGuiToolkitUtils::CombineImPlotStairsFlags(StairsFlags) | FImGuiToolkitUtils::CombineImPlotItemFlags(ItemFlags)
	);
}

void UImGuiToolkitPlotShaded::Render()
{
	if (!bEnabled || Values.IsEmpty())
		return;

	ImPlot::PlotShaded(
		TCHAR_TO_UTF8(*UniqueWidgetLabel),
		Values.GetData(),
		Values.Num(),
		YReference,
		XScale,
		XStart,
		FImGuiToolkitUtils::CombineImPlotItemFlags(ItemFlags)
	);
}

void UImGuiToolkitPlotShadedXY::Render()
{
	const int32 Count = ImGuiToolkitPlotExtras::MinPositiveCount({ XValues.Num(), YValues.Num() });
	if (!bEnabled || Count <= 0)
		return;

	ImPlot::PlotShaded(
		TCHAR_TO_UTF8(*UniqueWidgetLabel),
		XValues.GetData(),
		YValues.GetData(),
		Count,
		YReference,
		FImGuiToolkitUtils::CombineImPlotItemFlags(ItemFlags)
	);
}

void UImGuiToolkitPlotShadedBetweenXY::Render()
{
	const int32 Count = ImGuiToolkitPlotExtras::MinPositiveCount({ XValues.Num(), Y1Values.Num(), Y2Values.Num() });
	if (!bEnabled || Count <= 0)
		return;

	ImPlot::PlotShaded(
		TCHAR_TO_UTF8(*UniqueWidgetLabel),
		XValues.GetData(),
		Y1Values.GetData(),
		Y2Values.GetData(),
		Count,
		FImGuiToolkitUtils::CombineImPlotItemFlags(ItemFlags)
	);
}

void UImGuiToolkitPlotErrorBars::Render()
{
	const int32 Count = ImGuiToolkitPlotExtras::MinPositiveCount({ XValues.Num(), YValues.Num(), ErrorValues.Num() });
	if (!bEnabled || Count <= 0)
		return;

	ImPlot::PlotErrorBars(
		TCHAR_TO_UTF8(*UniqueWidgetLabel),
		XValues.GetData(),
		YValues.GetData(),
		ErrorValues.GetData(),
		Count,
		FImGuiToolkitUtils::CombineImPlotErrorBarsFlags(ErrorBarsFlags) | FImGuiToolkitUtils::CombineImPlotItemFlags(ItemFlags)
	);
}

void UImGuiToolkitPlotErrorBarsNegPos::Render()
{
	const int32 Count = ImGuiToolkitPlotExtras::MinPositiveCount({ XValues.Num(), YValues.Num(), NegativeErrorValues.Num(), PositiveErrorValues.Num() });
	if (!bEnabled || Count <= 0)
		return;

	ImPlot::PlotErrorBars(
		TCHAR_TO_UTF8(*UniqueWidgetLabel),
		XValues.GetData(),
		YValues.GetData(),
		NegativeErrorValues.GetData(),
		PositiveErrorValues.GetData(),
		Count,
		FImGuiToolkitUtils::CombineImPlotErrorBarsFlags(ErrorBarsFlags) | FImGuiToolkitUtils::CombineImPlotItemFlags(ItemFlags)
	);
}

void UImGuiToolkitPlotStems::Render()
{
	if (!bEnabled || Values.IsEmpty())
		return;

	ImPlot::PlotStems(
		TCHAR_TO_UTF8(*UniqueWidgetLabel),
		Values.GetData(),
		Values.Num(),
		Reference,
		XScale,
		XStart,
		FImGuiToolkitUtils::CombineImPlotStemsFlags(StemsFlags) | FImGuiToolkitUtils::CombineImPlotItemFlags(ItemFlags)
	);
}

void UImGuiToolkitPlotStemsXY::Render()
{
	const int32 Count = ImGuiToolkitPlotExtras::MinPositiveCount({ XValues.Num(), YValues.Num() });
	if (!bEnabled || Count <= 0)
		return;

	ImPlot::PlotStems(
		TCHAR_TO_UTF8(*UniqueWidgetLabel),
		XValues.GetData(),
		YValues.GetData(),
		Count,
		Reference,
		FImGuiToolkitUtils::CombineImPlotStemsFlags(StemsFlags) | FImGuiToolkitUtils::CombineImPlotItemFlags(ItemFlags)
	);
}

void UImGuiToolkitPlotInfLines::Render()
{
	if (!bEnabled || Values.IsEmpty())
		return;

	ImPlot::PlotInfLines(
		TCHAR_TO_UTF8(*UniqueWidgetLabel),
		Values.GetData(),
		Values.Num(),
		FImGuiToolkitUtils::CombineImPlotInfLinesFlags(InfLinesFlags) | FImGuiToolkitUtils::CombineImPlotItemFlags(ItemFlags)
	);
}

void UImGuiToolkitPlotPieChart::Render()
{
	const int32 Count = ImGuiToolkitPlotExtras::MinPositiveCount({ Labels.Num(), Values.Num() });
	if (!bEnabled || Count <= 0)
		return;

	TArray<TArray<ANSICHAR>> LabelBuffers;
	TArray<const char*> LabelPointers;
	ImGuiToolkitPlotExtras::BuildLabelPointers(Labels, LabelBuffers, LabelPointers);

	ImPlot::PlotPieChart(
		LabelPointers.GetData(),
		Values.GetData(),
		Count,
		Center.X,
		Center.Y,
		Radius,
		LabelFormat.IsEmpty() ? nullptr : TCHAR_TO_UTF8(*LabelFormat),
		Angle0,
		FImGuiToolkitUtils::CombineImPlotPieChartFlags(PieChartFlags) | FImGuiToolkitUtils::CombineImPlotItemFlags(ItemFlags)
	);
}

void UImGuiToolkitPlotHeatmap::Render()
{
	const int32 ClampedRows = FMath::Max(1, Rows);
	const int32 ClampedColumns = FMath::Max(1, Columns);
	if (!bEnabled || Values.Num() < ClampedRows * ClampedColumns)
		return;

	ImPlot::PlotHeatmap(
		TCHAR_TO_UTF8(*UniqueWidgetLabel),
		Values.GetData(),
		ClampedRows,
		ClampedColumns,
		ScaleMin,
		ScaleMax,
		LabelFormat.IsEmpty() ? nullptr : TCHAR_TO_UTF8(*LabelFormat),
		ImPlotPoint(BoundsMin.X, BoundsMin.Y),
		ImPlotPoint(BoundsMax.X, BoundsMax.Y),
		FImGuiToolkitUtils::CombineImPlotHeatmapFlags(HeatmapFlags) | FImGuiToolkitUtils::CombineImPlotItemFlags(ItemFlags)
	);
}

void UImGuiToolkitPlotHistogram::Render()
{
	if (!bEnabled || Values.IsEmpty())
		return;

	const ImPlotRange PlotRange = bUseRange ? ImPlotRange(Range.X, Range.Y) : ImPlotRange();
	LargestBinCount = ImPlot::PlotHistogram(
		TCHAR_TO_UTF8(*UniqueWidgetLabel),
		Values.GetData(),
		Values.Num(),
		Bins,
		BarScale,
		PlotRange,
		FImGuiToolkitUtils::CombineImPlotHistogramFlags(HistogramFlags) | FImGuiToolkitUtils::CombineImPlotItemFlags(ItemFlags)
	);
}

void UImGuiToolkitPlotHistogram2D::Render()
{
	const int32 Count = ImGuiToolkitPlotExtras::MinPositiveCount({ XValues.Num(), YValues.Num() });
	if (!bEnabled || Count <= 0)
		return;

	const ImPlotRect PlotRange = bUseRange ? ImPlotRect(XRange.X, XRange.Y, YRange.X, YRange.Y) : ImPlotRect();
	LargestBinCount = ImPlot::PlotHistogram2D(
		TCHAR_TO_UTF8(*UniqueWidgetLabel),
		XValues.GetData(),
		YValues.GetData(),
		Count,
		XBins,
		YBins,
		PlotRange,
		FImGuiToolkitUtils::CombineImPlotHistogramFlags(HistogramFlags) | FImGuiToolkitUtils::CombineImPlotItemFlags(ItemFlags)
	);
}

void UImGuiToolkitPlotDigital::Render()
{
	const int32 Count = ImGuiToolkitPlotExtras::MinPositiveCount({ XValues.Num(), YValues.Num() });
	if (!bEnabled || Count <= 0)
		return;

	ImPlot::PlotDigital(TCHAR_TO_UTF8(*UniqueWidgetLabel), XValues.GetData(), YValues.GetData(), Count, FImGuiToolkitUtils::CombineImPlotItemFlags(ItemFlags));
}

void UImGuiToolkitPlotImage::Render()
{
	if (!bEnabled || !ResourceObject)
		return;

	ImPlot::PlotImage(
		TCHAR_TO_UTF8(*UniqueWidgetLabel),
		ResourceObject,
		ImPlotPoint(BoundsMin.X, BoundsMin.Y),
		ImPlotPoint(BoundsMax.X, BoundsMax.Y),
		ImVec2(UV0.X, UV0.Y),
		ImVec2(UV1.X, UV1.Y),
		FImGuiToolkitUtils::LinearColorToImVec4(TintColor),
		FImGuiToolkitUtils::CombineImPlotItemFlags(ItemFlags)
	);
}

void UImGuiToolkitPlotText::Render()
{
	if (!bEnabled)
		return;

	const FString TextString = Text.ToString();
	ImPlot::PlotText(
		TCHAR_TO_UTF8(*TextString),
		Position.X,
		Position.Y,
		ImVec2(PixelOffset.X, PixelOffset.Y),
		FImGuiToolkitUtils::CombineImPlotTextFlags(TextFlags) | FImGuiToolkitUtils::CombineImPlotItemFlags(ItemFlags)
	);
}

void UImGuiToolkitPlotDummy::Render()
{
	if (!bEnabled)
		return;

	ImPlot::PlotDummy(TCHAR_TO_UTF8(*UniqueWidgetLabel), FImGuiToolkitUtils::CombineImPlotItemFlags(ItemFlags));
}

void UImGuiToolkitPlotDragPoint::Render()
{
	if (!bEnabled)
		return;

	if (ImPlot::DragPoint(
		ID,
		&X,
		&Y,
		FImGuiToolkitUtils::LinearColorToImVec4(Color),
		Size,
		FImGuiToolkitUtils::CombineImPlotDragToolFlags(DragToolFlags),
		&bClicked,
		&bHovered,
		&bHeld))
	{
		OnChanged.Broadcast(this, X, Y);
	}
}

void UImGuiToolkitPlotDragLineX::Render()
{
	if (!bEnabled)
		return;

	if (ImPlot::DragLineX(
		ID,
		&X,
		FImGuiToolkitUtils::LinearColorToImVec4(Color),
		Thickness,
		FImGuiToolkitUtils::CombineImPlotDragToolFlags(DragToolFlags),
		&bClicked,
		&bHovered,
		&bHeld))
	{
		OnChanged.Broadcast(this, X);
	}
}

void UImGuiToolkitPlotDragLineY::Render()
{
	if (!bEnabled)
		return;

	if (ImPlot::DragLineY(
		ID,
		&Y,
		FImGuiToolkitUtils::LinearColorToImVec4(Color),
		Thickness,
		FImGuiToolkitUtils::CombineImPlotDragToolFlags(DragToolFlags),
		&bClicked,
		&bHovered,
		&bHeld))
	{
		OnChanged.Broadcast(this, Y);
	}
}

void UImGuiToolkitPlotDragRect::Render()
{
	if (!bEnabled)
		return;

	if (ImPlot::DragRect(
		ID,
		&X1,
		&Y1,
		&X2,
		&Y2,
		FImGuiToolkitUtils::LinearColorToImVec4(Color),
		FImGuiToolkitUtils::CombineImPlotDragToolFlags(DragToolFlags),
		&bClicked,
		&bHovered,
		&bHeld))
	{
		OnChanged.Broadcast(this, X1, Y1, X2, Y2);
	}
}

void UImGuiToolkitPlotAnnotation::Render()
{
	if (!bEnabled)
		return;

	const ImVec4 ImColor = FImGuiToolkitUtils::LinearColorToImVec4(Color);
	const ImVec2 ImPixelOffset(PixelOffset.X, PixelOffset.Y);
	const FString TextString = Text.ToString();
	if (TextString.IsEmpty())
	{
		ImPlot::Annotation(Position.X, Position.Y, ImColor, ImPixelOffset, bClamp, bRound);
	}
	else
	{
		ImPlot::Annotation(Position.X, Position.Y, ImColor, ImPixelOffset, bClamp, "%s", TCHAR_TO_UTF8(*TextString));
	}
}

void UImGuiToolkitPlotTagX::Render()
{
	if (!bEnabled)
		return;

	const FString TextString = Text.ToString();
	if (TextString.IsEmpty())
	{
		ImPlot::TagX(X, FImGuiToolkitUtils::LinearColorToImVec4(Color), bRound);
	}
	else
	{
		ImPlot::TagX(X, FImGuiToolkitUtils::LinearColorToImVec4(Color), "%s", TCHAR_TO_UTF8(*TextString));
	}
}

void UImGuiToolkitPlotTagY::Render()
{
	if (!bEnabled)
		return;

	const FString TextString = Text.ToString();
	if (TextString.IsEmpty())
	{
		ImPlot::TagY(Y, FImGuiToolkitUtils::LinearColorToImVec4(Color), bRound);
	}
	else
	{
		ImPlot::TagY(Y, FImGuiToolkitUtils::LinearColorToImVec4(Color), "%s", TCHAR_TO_UTF8(*TextString));
	}
}

void UImGuiToolkitPushPlotStyleColor::Render()
{
	if (!bEnabled)
		return;

	ImPlot::PushStyleColor(
		FImGuiToolkitUtils::UnrealPlotStyleColorToImPlotCol(StyleColor),
		FImGuiToolkitUtils::LinearColorToImVec4(Color)
	);
}

void UImGuiToolkitPopPlotStyleColor::Render()
{
	if (!bEnabled)
		return;

	ImPlot::PopStyleColor(FMath::Max(1, Count));
}

void UImGuiToolkitPushPlotStyleVar::Render()
{
	if (!bEnabled)
		return;

	const ImPlotStyleVar ImStyleVar = FImGuiToolkitUtils::UnrealPlotStyleVarToImPlotStyleVar(StyleVar);
	if (FImGuiToolkitUtils::IsImPlotStyleVarVector(StyleVar))
	{
		ImPlot::PushStyleVar(ImStyleVar, ImVec2(Vector2DValue.X, Vector2DValue.Y));
	}
	else if (StyleVar == EImPlotStyleVar::Marker)
	{
		ImPlot::PushStyleVar(ImStyleVar, IntValue);
	}
	else
	{
		ImPlot::PushStyleVar(ImStyleVar, FloatValue);
	}
}

void UImGuiToolkitPopPlotStyleVar::Render()
{
	if (!bEnabled)
		return;

	ImPlot::PopStyleVar(FMath::Max(1, Count));
}

void UImGuiToolkitSetNextPlotLineStyle::Render()
{
	if (!bEnabled)
		return;

	ImPlot::SetNextLineStyle(FImGuiToolkitUtils::LinearColorToImVec4(Color), Weight);
}

void UImGuiToolkitSetNextPlotFillStyle::Render()
{
	if (!bEnabled)
		return;

	ImPlot::SetNextFillStyle(FImGuiToolkitUtils::LinearColorToImVec4(Color), AlphaMod);
}

void UImGuiToolkitSetNextPlotMarkerStyle::Render()
{
	if (!bEnabled)
		return;

	ImPlot::SetNextMarkerStyle(
		FImGuiToolkitUtils::UnrealPlotMarkerToImPlotMarker(Marker),
		Size,
		FImGuiToolkitUtils::LinearColorToImVec4(FillColor),
		Weight,
		FImGuiToolkitUtils::LinearColorToImVec4(OutlineColor)
	);
}

void UImGuiToolkitSetNextPlotErrorBarStyle::Render()
{
	if (!bEnabled)
		return;

	ImPlot::SetNextErrorBarStyle(FImGuiToolkitUtils::LinearColorToImVec4(Color), Size, Weight);
}

void UImGuiToolkitPushPlotColormap::Render()
{
	if (!bEnabled)
		return;

	ImPlot::PushColormap(FImGuiToolkitUtils::UnrealPlotColormapToImPlotColormap(Colormap));
}

void UImGuiToolkitPopPlotColormap::Render()
{
	if (!bEnabled)
		return;

	ImPlot::PopColormap(FMath::Max(1, Count));
}

void UImGuiToolkitPlotColormapScale::Render()
{
	if (!bEnabled)
		return;

	ImPlot::ColormapScale(
		TCHAR_TO_UTF8(*UniqueWidgetLabel),
		ScaleMin,
		ScaleMax,
		ImVec2(Size.X, Size.Y),
		TCHAR_TO_UTF8(*Format),
		FImGuiToolkitUtils::CombineImPlotColormapScaleFlags(ColormapScaleFlags),
		FImGuiToolkitUtils::UnrealPlotColormapToImPlotColormap(Colormap)
	);
}

void UImGuiToolkitPlotColormapSlider::Render()
{
	if (!bEnabled)
		return;

	ImVec4 OutColor;
	if (ImPlot::ColormapSlider(
		TCHAR_TO_UTF8(*UniqueWidgetLabel),
		&Value,
		&OutColor,
		TCHAR_TO_UTF8(*Format),
		FImGuiToolkitUtils::UnrealPlotColormapToImPlotColormap(Colormap)))
	{
		SampledColor = FImGuiToolkitUtils::ImVec4ToLinearColor(OutColor);
		OnChanged.Broadcast(this, Value);
	}
	else
	{
		SampledColor = FImGuiToolkitUtils::ImVec4ToLinearColor(OutColor);
	}
}

void UImGuiToolkitPlotColormapButton::Render()
{
	if (!bEnabled)
	{
		bClicked = false;
		return;
	}

	bClicked = ImPlot::ColormapButton(
		TCHAR_TO_UTF8(*UniqueWidgetLabel),
		ImVec2(Size.X, Size.Y),
		FImGuiToolkitUtils::UnrealPlotColormapToImPlotColormap(Colormap)
	);

	if (bClicked)
	{
		OnClicked.Broadcast(this);
	}
}
