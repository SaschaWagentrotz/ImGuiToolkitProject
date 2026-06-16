#include "ImGuiToolkitSubsystem.h"

#include "ImGuiToolkitHostWidget.h"
#include "Engine/Engine.h"
#include "Engine/World.h"
#include "ImGuiConfig.h"
#include "ImGuiToolkitSettings.h"

#include <imgui.h>

namespace
{
	UWorld* GetObjectWorld(const UObject* Object)
	{
		for (const UObject* Current = Object; Current; Current = Current->GetOuter())
		{
			if (UWorld* World = Current->GetWorld())
			{
				return World;
			}

			if (const UWorld* World = Cast<UWorld>(Current))
			{
				return const_cast<UWorld*>(World);
			}
		}

		return nullptr;
	}

	int32 GetImGuiPieSessionId(const UObject* Object)
	{
		UWorld* World = GetObjectWorld(Object);
		if (!World || World->WorldType != EWorldType::PIE || !GEngine)
		{
			return INDEX_NONE;
		}

		if (const FWorldContext* WorldContext = GEngine->GetWorldContextFromWorld(World))
		{
			return WorldContext->PIEInstance;
		}

		return INDEX_NONE;
	}
}

void UImGuiToolkitSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	TickHandle = FTSTicker::GetCoreTicker().AddTicker(FTickerDelegate::CreateUObject(this, &UImGuiToolkitSubsystem::OnTick), 0.0f);

	EndFrameHandle = FCoreDelegates::OnEndFrame.AddUObject(this, &UImGuiToolkitSubsystem::OnEndFrame);
}

void UImGuiToolkitSubsystem::Deinitialize()
{
	if (EndFrameHandle.IsValid())
		FCoreDelegates::OnEndFrame.Remove(EndFrameHandle);

	if (TickHandle.IsValid())
		FTSTicker::GetCoreTicker().RemoveTicker(TickHandle);

	Super::Deinitialize();
}

static inline ImVec4 ToImGuiColor(const FLinearColor& Color)
{
	const FColor SRGBColor = Color.ToFColorSRGB();
	return ImVec4(
		SRGBColor.R / 255.0f,
		SRGBColor.G / 255.0f,
		SRGBColor.B / 255.0f,
		SRGBColor.A / 255.0f
	);
}

void UImGuiToolkitSubsystem::SetImGuiToolkitStyle()
{
	const UImGuiToolkitSettings* Settings = GetDefault<UImGuiToolkitSettings>();
	if (!Settings)
	{
		return;
	}

	ImGuiStyle* dst_style = NULL;
	ImGuiStyle& style = dst_style ? *dst_style : ImGui::GetStyle();
	style = ImGuiStyle();
    ImVec4* colors = style.Colors;

    // ---- Assignments ----
    colors[ImGuiCol_Text]                   = ToImGuiColor(Settings->Text);
    colors[ImGuiCol_TextDisabled]           = ToImGuiColor(Settings->TextDisabled);

    colors[ImGuiCol_WindowBg]               = ToImGuiColor(Settings->WindowBg);
    colors[ImGuiCol_ChildBg]                = ToImGuiColor(Settings->ChildBg);
    colors[ImGuiCol_PopupBg]                = ToImGuiColor(Settings->PopupBg);

    colors[ImGuiCol_Border]                 = ToImGuiColor(Settings->Border);
    colors[ImGuiCol_BorderShadow]           = ToImGuiColor(Settings->BorderShadow);

    colors[ImGuiCol_FrameBg]                = ToImGuiColor(Settings->FrameBg);
    colors[ImGuiCol_FrameBgHovered]         = ToImGuiColor(Settings->FrameBgHovered);
    colors[ImGuiCol_FrameBgActive]          = ToImGuiColor(Settings->FrameBgActive);

    // Buttons (UE behavior)
    colors[ImGuiCol_Button]                 = ToImGuiColor(Settings->Button);
    colors[ImGuiCol_ButtonHovered]          = ToImGuiColor(Settings->ButtonHovered);
    colors[ImGuiCol_ButtonActive]           = ToImGuiColor(Settings->ButtonActive);

    // Sliders / checks use accent to signal interaction
    colors[ImGuiCol_CheckMark]              = ToImGuiColor(Settings->CheckMark);
    colors[ImGuiCol_SliderGrab]             = ToImGuiColor(Settings->SliderGrab);
    colors[ImGuiCol_SliderGrabActive]       = ToImGuiColor(Settings->SliderGrabActive);

    // Headers stay neutral (not blue)
    colors[ImGuiCol_Header]                 = ToImGuiColor(Settings->Header);
    colors[ImGuiCol_HeaderHovered]          = ToImGuiColor(Settings->HeaderHovered);
    colors[ImGuiCol_HeaderActive]           = ToImGuiColor(Settings->HeaderActive);

    // Separators / grips
    colors[ImGuiCol_Separator]              = ToImGuiColor(Settings->Separator);
    colors[ImGuiCol_SeparatorHovered]       = ToImGuiColor(Settings->SeparatorHovered);
    colors[ImGuiCol_SeparatorActive]        = ToImGuiColor(Settings->SeparatorActive);

    colors[ImGuiCol_ResizeGrip]             = ToImGuiColor(Settings->ResizeGrip);
    colors[ImGuiCol_ResizeGripHovered]      = ToImGuiColor(Settings->ResizeGripHovered);
    colors[ImGuiCol_ResizeGripActive]       = ToImGuiColor(Settings->ResizeGripActive);

    // Tabs
    colors[ImGuiCol_Tab]                    = ToImGuiColor(Settings->Tab);
    colors[ImGuiCol_TabHovered]             = ToImGuiColor(Settings->TabHovered);
    colors[ImGuiCol_TabSelected]            = ToImGuiColor(Settings->TabSelected);
    colors[ImGuiCol_TabSelectedOverline]    = ToImGuiColor(Settings->TabSelectedOverline);
    colors[ImGuiCol_TabDimmed]              = ToImGuiColor(Settings->TabDimmed);
    colors[ImGuiCol_TabDimmedSelected]      = ToImGuiColor(Settings->TabDimmedSelected);
    colors[ImGuiCol_TabDimmedSelectedOverline] = ToImGuiColor(Settings->TabDimmedSelectedOverline);

    // Docking
    colors[ImGuiCol_DockingPreview]         = ToImGuiColor(Settings->DockingPreview);
    colors[ImGuiCol_DockingEmptyBg]         = ToImGuiColor(Settings->DockingEmptyBg);

    // Scrollbars
    colors[ImGuiCol_ScrollbarBg]            = ToImGuiColor(Settings->ScrollbarBg);
    colors[ImGuiCol_ScrollbarGrab]          = ToImGuiColor(Settings->ScrollbarGrab);
    colors[ImGuiCol_ScrollbarGrabHovered]   = ToImGuiColor(Settings->ScrollbarGrabHovered);
    colors[ImGuiCol_ScrollbarGrabActive]    = ToImGuiColor(Settings->ScrollbarGrabActive);

    // Tables / plots
    colors[ImGuiCol_TableHeaderBg]          = ToImGuiColor(Settings->TableHeaderBg);
    colors[ImGuiCol_TableBorderStrong]      = ToImGuiColor(Settings->TableBorderStrong);
    colors[ImGuiCol_TableBorderLight]       = ToImGuiColor(Settings->TableBorderLight);
    colors[ImGuiCol_TableRowBg]             = ToImGuiColor(Settings->TableRowBg);
    colors[ImGuiCol_TableRowBgAlt]          = ToImGuiColor(Settings->TableRowBgAlt);

    colors[ImGuiCol_PlotLines]              = ToImGuiColor(Settings->PlotLines);
    colors[ImGuiCol_PlotLinesHovered]       = ToImGuiColor(Settings->PlotLinesHovered);
    colors[ImGuiCol_PlotHistogram]          = ToImGuiColor(Settings->PlotHistogram);
    colors[ImGuiCol_PlotHistogramHovered]   = ToImGuiColor(Settings->PlotHistogramHovered);

    // Links / selection / nav / modals
    colors[ImGuiCol_TextLink]               = ToImGuiColor(Settings->TextLink);
    colors[ImGuiCol_TextSelectedBg]         = ToImGuiColor(Settings->TextSelectedBg);
    colors[ImGuiCol_DragDropTarget]         = ToImGuiColor(Settings->DragDropTarget);
    colors[ImGuiCol_NavCursor]              = ToImGuiColor(Settings->NavCursor);
    colors[ImGuiCol_NavWindowingHighlight]  = ToImGuiColor(Settings->NavWindowingHighlight);
    colors[ImGuiCol_NavWindowingDimBg]      = ToImGuiColor(Settings->NavWindowingDimBg);
    colors[ImGuiCol_ModalWindowDimBg]       = ToImGuiColor(Settings->ModalWindowDimBg);

    colors[ImGuiCol_TitleBg]                = ToImGuiColor(Settings->TitleBg);
    colors[ImGuiCol_TitleBgActive]          = ToImGuiColor(Settings->TitleBgActive);
    colors[ImGuiCol_TitleBgCollapsed]       = ToImGuiColor(Settings->TitleBgCollapsed);
    colors[ImGuiCol_MenuBarBg]              = ToImGuiColor(Settings->MenuBarBg);

    // ---- Layout / metrics ----
    style.FramePadding            = ImVec2(8.0f, 5.0f);
    style.ItemSpacing             = ImVec2(8.0f, 6.0f);
    style.ItemInnerSpacing        = ImVec2(6.0f, 5.0f);
    style.CellPadding             = ImVec2(6.0f, 4.0f);

    style.ScrollbarSize           = 14.0f;
    style.GrabMinSize             = 10.0f;

    style.WindowRounding          = 3.0f;
    style.ChildRounding           = 3.0f;
    style.FrameRounding           = 3.0f;
    style.PopupRounding           = 3.0f;
    style.ScrollbarRounding       = 3.0f;
    style.GrabRounding            = 3.0f;
    style.TabRounding             = 3.0f;

    style.WindowBorderSize        = 1.0f;
    style.ChildBorderSize         = 1.0f;
    style.PopupBorderSize         = 1.0f;
    style.FrameBorderSize         = 1.0f;
    style.TabBorderSize           = 1.0f;

    style.WindowTitleAlign        = ImVec2(0.0f, 0.5f);
    style.ColorButtonPosition     = ImGuiDir_Right;
    style.ButtonTextAlign         = ImVec2(0.5f, 0.5f);
    style.SelectableTextAlign     = ImVec2(0.0f, 0.5f);

    style.TabBarBorderSize        = 1.0f;
    style.TabBarOverlineSize      = 2.0f;
    style.SeparatorTextPadding    = ImVec2(18.0f, 3.0f);
}

void UImGuiToolkitSubsystem::SetShowImGuiDemoWindow(bool bNewShow)
{
	bShowDemoWindow = bNewShow;
}

void UImGuiToolkitSubsystem::ShowImGuiDemoWindow(bool bShow)
{
	if (bShow)
	{
		ImGui::ShowDemoWindow();
	}
}

void UImGuiToolkitSubsystem::RegisterWindow(UImGuiToolkitWindow* Window)
{
	if (Window && !RegisteredWindows.Contains(Window))
	{
		RegisteredWindows.Add(Window);
	}
}

void UImGuiToolkitSubsystem::UnregisterWindow(UImGuiToolkitWindow* Window)
{
	RegisteredWindows.Remove(Window);
}

void UImGuiToolkitSubsystem::RegisterHostWidget(UImGuiToolkitHostWidget* HostWidget)
{
	if (HostWidget)
	{
		RegisteredHostWidgets.AddUnique(TWeakObjectPtr<UImGuiToolkitHostWidget>(HostWidget));
	}
}

void UImGuiToolkitSubsystem::UnregisterHostWidget(UImGuiToolkitHostWidget* HostWidget)
{
	RegisteredHostWidgets.RemoveAllSwap([HostWidget](const TWeakObjectPtr<UImGuiToolkitHostWidget>& RegisteredHostWidget)
	{
		return !RegisteredHostWidget.IsValid() || RegisteredHostWidget.Get() == HostWidget;
	});
}

bool UImGuiToolkitSubsystem::OnTick(float DeltaTime)
{
	for (int32 HostIndex = RegisteredHostWidgets.Num() - 1; HostIndex >= 0; --HostIndex)
	{
		UImGuiToolkitHostWidget* HostWidget = RegisteredHostWidgets[HostIndex].Get();
		if (!HostWidget)
		{
			RegisteredHostWidgets.RemoveAtSwap(HostIndex);
			continue;
		}

		HostWidget->RenderHost();
	}

	// This runs every frame in both editor and game.
	for (UImGuiToolkitWindow* Window : RegisteredWindows)
	{
		const bool bIsAssignedToHost = RegisteredHostWidgets.ContainsByPredicate([Window](const TWeakObjectPtr<UImGuiToolkitHostWidget>& RegisteredHostWidget)
		{
			UImGuiToolkitHostWidget* HostWidget = RegisteredHostWidget.Get();
			return HostWidget && HostWidget->GetHostedWindow() == Window;
		});

		if (!Window || Window->bIsHosted || bIsAssignedToHost)
		{
			continue;
		}

		const ImGui::FScopedContext ScopedContext(GetImGuiPieSessionId(Window));
		if (ScopedContext)
		{
			ApplyStyleToCurrentContext();
			Window->Render();
		}
	}

	const ImGui::FScopedContext ScopedContext;
	if (ScopedContext)
	{
		ApplyStyleToCurrentContext();
		ShowImGuiDemoWindow(bShowDemoWindow);

		// Broadcast delegate
		OnImGuiRender.Broadcast();
	} 
	
	return true; // Keep ticking
}

void UImGuiToolkitSubsystem::OnEndFrame()
{
	ApplyStyleToCurrentContext();
}

void UImGuiToolkitSubsystem::ApplyStyleToCurrentContext()
{
	ImGuiContext* Context = ImGui::GetCurrentContext();
	if (!Context)
	{
		return;
	}

	const UImGuiToolkitSettings* Settings = GetDefault<UImGuiToolkitSettings>();
	const float Scale = FMath::Clamp(Settings ? Settings->Scale : 1.0f, 0.25f, 4.0f);

	ImGuiIO& IO = ImGui::GetIO();
	IO.FontGlobalScale = 1.0f;

	SetImGuiToolkitStyle();
	ImGui::GetStyle().ScaleAllSizes(Scale);
}
