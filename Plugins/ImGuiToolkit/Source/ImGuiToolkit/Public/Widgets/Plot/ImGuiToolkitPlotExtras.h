#pragma once

#include "CoreMinimal.h"
#include "FImGuiToolkitUtils.h"
#include "ImGuiToolkitWidget.h"
#include "ImGuiToolkitPlotExtras.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FImPlotDragPointChangedSignature, UImGuiToolkitWidget*, Element, double, X, double, Y);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FImPlotDragLineChangedSignature, UImGuiToolkitWidget*, Element, double, Value);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FiveParams(FImPlotDragRectChangedSignature, UImGuiToolkitWidget*, Element, double, X1, double, Y1, double, X2, double, Y2);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FImPlotFloatChangedSignature, UImGuiToolkitWidget*, Element, float, Value);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FImPlotClickedSignature, UImGuiToolkitWidget*, Element);

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitSetupPlotLegend : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	EImPlotLocation Location = EImPlotLocation::NorthEast;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<EImPlotLegendFlag> LegendFlags;
};

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitSetupPlotMouseText : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	EImPlotLocation Location = EImPlotLocation::SouthEast;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<EImPlotMouseTextFlag> MouseTextFlags;
};

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitSetupPlotAxisFormat : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	EImPlotAxis Axis = EImPlotAxis::X1;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	FString Format = TEXT("%g");
};

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitSetupPlotAxisScale : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	EImPlotAxis Axis = EImPlotAxis::X1;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	EImPlotScale Scale = EImPlotScale::Linear;
};

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitSetupPlotAxes : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	FText XLabel;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	FText YLabel;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<EImPlotAxisFlag> XAxisFlags;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<EImPlotAxisFlag> YAxisFlags;
};

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitSetupPlotAxesLimits : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	FVector2D XLimits = FVector2D(0.0f, 1.0f);

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	FVector2D YLimits = FVector2D(0.0f, 1.0f);

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	EImPlotCondition Condition = EImPlotCondition::Once;
};

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitSetupPlotAxisLimitsConstraints : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	EImPlotAxis Axis = EImPlotAxis::X1;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	double MinValue = 0.0;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	double MaxValue = 1.0;
};

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitSetupPlotAxisZoomConstraints : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	EImPlotAxis Axis = EImPlotAxis::X1;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	double MinZoom = 0.0;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	double MaxZoom = 1.0;
};

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitSetupPlotAxisTicks : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	EImPlotAxis Axis = EImPlotAxis::X1;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<float> Values;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<FText> Labels;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	bool bKeepDefault = false;
};

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitSetupPlotAxisTicksRange : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	EImPlotAxis Axis = EImPlotAxis::X1;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	double MinValue = 0.0;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	double MaxValue = 1.0;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot", meta = (ClampMin = "1", UIMin = "1"))
	int32 TickCount = 5;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<FText> Labels;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	bool bKeepDefault = false;
};

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitSetupPlotFinish : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;
};

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitSetNextPlotAxisLimits : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	EImPlotAxis Axis = EImPlotAxis::X1;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	double MinValue = 0.0;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	double MaxValue = 1.0;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	EImPlotCondition Condition = EImPlotCondition::Once;
};

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitSetNextPlotAxesLimits : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	FVector2D XLimits = FVector2D(0.0f, 1.0f);

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	FVector2D YLimits = FVector2D(0.0f, 1.0f);

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	EImPlotCondition Condition = EImPlotCondition::Once;
};

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitSetNextPlotAxisToFit : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	EImPlotAxis Axis = EImPlotAxis::X1;
};

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitSetNextPlotAxesToFit : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;
};

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitSetPlotAxis : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	EImPlotAxis Axis = EImPlotAxis::X1;
};

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitSetPlotAxes : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	EImPlotAxis XAxis = EImPlotAxis::X1;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	EImPlotAxis YAxis = EImPlotAxis::Y1;
};

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitHideNextPlotItem : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	bool bHidden = true;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	EImPlotCondition Condition = EImPlotCondition::Once;
};

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitPlotQuery : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	EImPlotAxis XAxis = EImPlotAxis::X1;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	EImPlotAxis YAxis = EImPlotAxis::Y1;

	UPROPERTY(BlueprintReadOnly, Category = "ImGui Toolkit Plot")
	FVector2D MousePosition = FVector2D::ZeroVector;

	UPROPERTY(BlueprintReadOnly, Category = "ImGui Toolkit Plot")
	FVector2D PlotLimitsMin = FVector2D::ZeroVector;

	UPROPERTY(BlueprintReadOnly, Category = "ImGui Toolkit Plot")
	FVector2D PlotLimitsMax = FVector2D::ZeroVector;

	UPROPERTY(BlueprintReadOnly, Category = "ImGui Toolkit Plot")
	bool bPlotHovered = false;

	UPROPERTY(BlueprintReadOnly, Category = "ImGui Toolkit Plot")
	bool bSubplotsHovered = false;

	UPROPERTY(BlueprintReadOnly, Category = "ImGui Toolkit Plot")
	bool bPlotSelected = false;

	UPROPERTY(BlueprintReadOnly, Category = "ImGui Toolkit Plot")
	FVector2D SelectionMin = FVector2D::ZeroVector;

	UPROPERTY(BlueprintReadOnly, Category = "ImGui Toolkit Plot")
	FVector2D SelectionMax = FVector2D::ZeroVector;
};

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitPlotAxisQuery : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	EImPlotAxis Axis = EImPlotAxis::X1;

	UPROPERTY(BlueprintReadOnly, Category = "ImGui Toolkit Plot")
	bool bAxisHovered = false;
};

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitCancelPlotSelection : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;
};

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitPlotStairs : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<float> Values;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	double XScale = 1.0;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	double XStart = 0.0;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<EImPlotStairsFlag> StairsFlags;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<EImPlotItemFlag> ItemFlags;
};

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitPlotBarGroups : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<FText> Labels;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<float> Values;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot", meta = (ClampMin = "1", UIMin = "1"))
	int32 ItemCount = 1;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot", meta = (ClampMin = "1", UIMin = "1"))
	int32 GroupCount = 1;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	double GroupSize = 0.67;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	double Shift = 0.0;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<EImPlotBarGroupsFlag> BarGroupsFlags;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<EImPlotItemFlag> ItemFlags;
};

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitStylePlotColors : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	EImPlotStylePreset Preset = EImPlotStylePreset::Auto;
};

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitPlotStairsXY : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<float> XValues;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<float> YValues;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<EImPlotStairsFlag> StairsFlags;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<EImPlotItemFlag> ItemFlags;
};

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitPlotShaded : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<float> Values;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	double YReference = 0.0;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	double XScale = 1.0;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	double XStart = 0.0;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<EImPlotItemFlag> ItemFlags;
};

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitPlotShadedXY : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<float> XValues;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<float> YValues;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	double YReference = 0.0;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<EImPlotItemFlag> ItemFlags;
};

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitPlotShadedBetweenXY : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<float> XValues;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<float> Y1Values;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<float> Y2Values;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<EImPlotItemFlag> ItemFlags;
};

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitPlotErrorBars : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<float> XValues;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<float> YValues;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<float> ErrorValues;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<EImPlotErrorBarsFlag> ErrorBarsFlags;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<EImPlotItemFlag> ItemFlags;
};

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitPlotErrorBarsNegPos : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<float> XValues;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<float> YValues;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<float> NegativeErrorValues;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<float> PositiveErrorValues;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<EImPlotErrorBarsFlag> ErrorBarsFlags;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<EImPlotItemFlag> ItemFlags;
};

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitPlotStems : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<float> Values;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	double Reference = 0.0;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	double XScale = 1.0;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	double XStart = 0.0;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<EImPlotStemsFlag> StemsFlags;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<EImPlotItemFlag> ItemFlags;
};

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitPlotStemsXY : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<float> XValues;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<float> YValues;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	double Reference = 0.0;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<EImPlotStemsFlag> StemsFlags;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<EImPlotItemFlag> ItemFlags;
};

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitPlotInfLines : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<float> Values;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<EImPlotInfLinesFlag> InfLinesFlags;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<EImPlotItemFlag> ItemFlags;
};

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitPlotPieChart : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<FText> Labels;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<float> Values;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	FVector2D Center = FVector2D::ZeroVector;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	double Radius = 1.0;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	FString LabelFormat = TEXT("%.1f");

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	double Angle0 = 90.0;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<EImPlotPieChartFlag> PieChartFlags;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<EImPlotItemFlag> ItemFlags;
};

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitPlotHeatmap : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<float> Values;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot", meta = (ClampMin = "1", UIMin = "1"))
	int32 Rows = 1;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot", meta = (ClampMin = "1", UIMin = "1"))
	int32 Columns = 1;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	double ScaleMin = 0.0;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	double ScaleMax = 0.0;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	FString LabelFormat = TEXT("%.1f");

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	FVector2D BoundsMin = FVector2D(0.0f, 0.0f);

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	FVector2D BoundsMax = FVector2D(1.0f, 1.0f);

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<EImPlotHeatmapFlag> HeatmapFlags;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<EImPlotItemFlag> ItemFlags;
};

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitPlotHistogram : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<float> Values;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	int32 Bins = -2;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	double BarScale = 1.0;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	bool bUseRange = false;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot", meta = (EditCondition = "bUseRange"))
	FVector2D Range = FVector2D::ZeroVector;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<EImPlotHistogramFlag> HistogramFlags;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<EImPlotItemFlag> ItemFlags;

	UPROPERTY(BlueprintReadOnly, Category = "ImGui Toolkit Plot")
	double LargestBinCount = 0.0;
};

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitPlotHistogram2D : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<float> XValues;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<float> YValues;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	int32 XBins = -2;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	int32 YBins = -2;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	bool bUseRange = false;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot", meta = (EditCondition = "bUseRange"))
	FVector2D XRange = FVector2D::ZeroVector;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot", meta = (EditCondition = "bUseRange"))
	FVector2D YRange = FVector2D::ZeroVector;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<EImPlotHistogramFlag> HistogramFlags;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<EImPlotItemFlag> ItemFlags;

	UPROPERTY(BlueprintReadOnly, Category = "ImGui Toolkit Plot")
	double LargestBinCount = 0.0;
};

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitPlotDigital : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<float> XValues;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<float> YValues;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<EImPlotItemFlag> ItemFlags;
};

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitPlotImage : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	UObject* ResourceObject = nullptr;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	FVector2D BoundsMin = FVector2D::ZeroVector;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	FVector2D BoundsMax = FVector2D(1.0f, 1.0f);

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	FVector2D UV0 = FVector2D(0.0f, 0.0f);

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	FVector2D UV1 = FVector2D(1.0f, 1.0f);

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	FLinearColor TintColor = FLinearColor::White;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<EImPlotItemFlag> ItemFlags;
};

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitPlotText : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	FText Text;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	FVector2D Position = FVector2D::ZeroVector;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	FVector2D PixelOffset = FVector2D::ZeroVector;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<EImPlotTextFlag> TextFlags;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<EImPlotItemFlag> ItemFlags;
};

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitPlotDummy : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<EImPlotItemFlag> ItemFlags;
};

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitPlotDragPoint : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	int32 ID = 0;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	double X = 0.0;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	double Y = 0.0;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	FLinearColor Color = FLinearColor::White;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	float Size = 4.0f;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<EImPlotDragToolFlag> DragToolFlags;

	UPROPERTY(BlueprintReadOnly, Category = "ImGui Toolkit Plot")
	bool bClicked = false;

	UPROPERTY(BlueprintReadOnly, Category = "ImGui Toolkit Plot")
	bool bHovered = false;

	UPROPERTY(BlueprintReadOnly, Category = "ImGui Toolkit Plot")
	bool bHeld = false;

	UPROPERTY(BlueprintAssignable, Category = "ImGui Toolkit Plot")
	FImPlotDragPointChangedSignature OnChanged;
};

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitPlotDragLineX : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	int32 ID = 0;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	double X = 0.0;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	FLinearColor Color = FLinearColor::White;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	float Thickness = 1.0f;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<EImPlotDragToolFlag> DragToolFlags;

	UPROPERTY(BlueprintReadOnly, Category = "ImGui Toolkit Plot")
	bool bClicked = false;

	UPROPERTY(BlueprintReadOnly, Category = "ImGui Toolkit Plot")
	bool bHovered = false;

	UPROPERTY(BlueprintReadOnly, Category = "ImGui Toolkit Plot")
	bool bHeld = false;

	UPROPERTY(BlueprintAssignable, Category = "ImGui Toolkit Plot")
	FImPlotDragLineChangedSignature OnChanged;
};

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitPlotDragLineY : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	int32 ID = 0;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	double Y = 0.0;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	FLinearColor Color = FLinearColor::White;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	float Thickness = 1.0f;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<EImPlotDragToolFlag> DragToolFlags;

	UPROPERTY(BlueprintReadOnly, Category = "ImGui Toolkit Plot")
	bool bClicked = false;

	UPROPERTY(BlueprintReadOnly, Category = "ImGui Toolkit Plot")
	bool bHovered = false;

	UPROPERTY(BlueprintReadOnly, Category = "ImGui Toolkit Plot")
	bool bHeld = false;

	UPROPERTY(BlueprintAssignable, Category = "ImGui Toolkit Plot")
	FImPlotDragLineChangedSignature OnChanged;
};

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitPlotDragRect : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	int32 ID = 0;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	double X1 = 0.0;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	double Y1 = 0.0;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	double X2 = 1.0;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	double Y2 = 1.0;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	FLinearColor Color = FLinearColor::White;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<EImPlotDragToolFlag> DragToolFlags;

	UPROPERTY(BlueprintReadOnly, Category = "ImGui Toolkit Plot")
	bool bClicked = false;

	UPROPERTY(BlueprintReadOnly, Category = "ImGui Toolkit Plot")
	bool bHovered = false;

	UPROPERTY(BlueprintReadOnly, Category = "ImGui Toolkit Plot")
	bool bHeld = false;

	UPROPERTY(BlueprintAssignable, Category = "ImGui Toolkit Plot")
	FImPlotDragRectChangedSignature OnChanged;
};

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitPlotAnnotation : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	FText Text;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	FVector2D Position = FVector2D::ZeroVector;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	FLinearColor Color = FLinearColor::White;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	FVector2D PixelOffset = FVector2D::ZeroVector;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	bool bClamp = false;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	bool bRound = false;
};

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitPlotTagX : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	double X = 0.0;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	FLinearColor Color = FLinearColor::White;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	FText Text;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	bool bRound = false;
};

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitPlotTagY : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	double Y = 0.0;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	FLinearColor Color = FLinearColor::White;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	FText Text;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	bool bRound = false;
};

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitPushPlotStyleColor : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	EImPlotStyleColor StyleColor = EImPlotStyleColor::Line;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	FLinearColor Color = FLinearColor::White;
};

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitPopPlotStyleColor : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot", meta = (ClampMin = "1", UIMin = "1"))
	int32 Count = 1;
};

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitPushPlotStyleVar : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	EImPlotStyleVar StyleVar = EImPlotStyleVar::LineWeight;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	float FloatValue = 1.0f;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	int32 IntValue = 0;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	FVector2D Vector2DValue = FVector2D(1.0f, 1.0f);
};

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitPopPlotStyleVar : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot", meta = (ClampMin = "1", UIMin = "1"))
	int32 Count = 1;
};

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitSetNextPlotLineStyle : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	FLinearColor Color = FLinearColor::White;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	float Weight = 1.0f;
};

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitSetNextPlotFillStyle : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	FLinearColor Color = FLinearColor::White;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	float AlphaMod = 1.0f;
};

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitSetNextPlotMarkerStyle : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	EImPlotMarker Marker = EImPlotMarker::Circle;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	float Size = 4.0f;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	FLinearColor FillColor = FLinearColor::White;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	float Weight = 1.0f;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	FLinearColor OutlineColor = FLinearColor::Black;
};

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitSetNextPlotErrorBarStyle : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	FLinearColor Color = FLinearColor::White;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	float Size = 5.0f;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	float Weight = 1.0f;
};

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitPushPlotColormap : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	EImPlotColormap Colormap = EImPlotColormap::Deep;
};

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitPopPlotColormap : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot", meta = (ClampMin = "1", UIMin = "1"))
	int32 Count = 1;
};

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitPlotColormapScale : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	double ScaleMin = 0.0;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	double ScaleMax = 1.0;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	FVector2D Size = FVector2D(0.0f, 0.0f);

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	FString Format = TEXT("%g");

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	EImPlotColormap Colormap = EImPlotColormap::Deep;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	TArray<EImPlotColormapScaleFlag> ColormapScaleFlags;
};

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitPlotColormapSlider : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	float Value = 0.0f;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	FString Format;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	EImPlotColormap Colormap = EImPlotColormap::Deep;

	UPROPERTY(BlueprintReadOnly, Category = "ImGui Toolkit Plot")
	FLinearColor SampledColor = FLinearColor::White;

	UPROPERTY(BlueprintAssignable, Category = "ImGui Toolkit Plot")
	FImPlotFloatChangedSignature OnChanged;
};

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitPlotColormapButton : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	FVector2D Size = FVector2D(0.0f, 0.0f);

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Plot")
	EImPlotColormap Colormap = EImPlotColormap::Deep;

	UPROPERTY(BlueprintReadOnly, Category = "ImGui Toolkit Plot")
	bool bClicked = false;

	UPROPERTY(BlueprintAssignable, Category = "ImGui Toolkit Plot")
	FImPlotClickedSignature OnClicked;
};
