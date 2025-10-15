// Fill out your copyright notice in the Description page of Project Settings.


#include "ImGuiToolkitSubsystem.h"
#include <imgui.h>
#include "ImGuiModule.h"
#include "ImGuiToolkit.h"


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

static inline ImVec4 SRGB(float r, float g, float b, float a = 1.0f)
{
	return ImVec4(r/255.0f, g/255.0f, b/255.0f, a);
}

void UImGuiToolkitSubsystem::SetImGuiToolkitStyle()
{
	ImGuiStyle* dst_style = NULL;
	ImGuiStyle& style = dst_style ? *dst_style : ImGui::GetStyle();
    ImVec4* colors = style.Colors;

	const ImVec4 col_text                 = SRGB(230,230,230);
    const ImVec4 col_text_disabled        = SRGB(132,137,145);

    const ImVec4 col_bg_window            = SRGB(16,17,19, 240/255.0f);
    const ImVec4 col_bg_child             = SRGB(20,21,24, 240/255.0f);
    const ImVec4 col_bg_popup             = SRGB(22,23,26, 240/255.0f);

    const ImVec4 col_border               = SRGB(56,60,66);
    const ImVec4 col_border_shadow        = SRGB(0,0,0, 0.0f);

    const ImVec4 col_frame_bg             = SRGB(34,37,42, 220/255.0f);
    const ImVec4 col_frame_bg_hovered     = SRGB(42,46,52, 230/255.0f);
    const ImVec4 col_frame_bg_active      = SRGB(48,53,60);

    const ImVec4 col_menu_bar_bg          = SRGB(24,26,29);

    const ImVec4 col_scrollbar_bg         = SRGB(16,17,19, 135/255.0f);
    const ImVec4 col_scrollbar_grab       = SRGB(67,72,79);
    const ImVec4 col_scrollbar_hover      = SRGB(86,92,100);
    const ImVec4 col_scrollbar_active     = SRGB(104,112,122);

    const ImVec4 col_header               = SRGB(45,49,56, 200/255.0f);
    const ImVec4 col_header_hovered       = SRGB(55,60,68, 230/255.0f);
    const ImVec4 col_header_active        = SRGB(60,66,75);

    const ImVec4 col_table_header_bg      = SRGB(40,43,49);
    const ImVec4 col_table_border_strong  = SRGB(70,74,82);
    const ImVec4 col_table_border_light   = SRGB(52,56,63);

    const ImVec4 col_plot_lines           = SRGB(156,156,156);
    const ImVec4 col_plot_lines_hover     = SRGB(255,110,96);
    const ImVec4 col_plot_hist            = SRGB(229,178,59);
    const ImVec4 col_plot_hist_hover      = SRGB(255,171,51);

    const ImVec4 col_dragdrop_target      = SRGB(255,220,0, 230/255.0f);
    const ImVec4 col_text_selected_bg     = SRGB(60,120,200, 100/255.0f);

    const ImVec4 col_title_bg             = SRGB(26,27,31);
    const ImVec4 col_title_bg_active      = SRGB(34,36,41);
    const ImVec4 col_title_bg_collapsed   = SRGB(0,0,0, 130/255.0f);

    // ---- Accent (used for selected/active states) ----
    const ImVec4 col_accent               = SRGB(45,120,225);   // UE-like selection blue
    const ImVec4 col_accent_hover         = SRGB(70,145,245);
    const ImVec4 col_accent_active        = SRGB(35,100,210);

    // ---- Buttons: grey by default; blue only when active ----
    const ImVec4 col_button_idle          = SRGB(52,54,58, 220/255.0f);
    const ImVec4 col_button_hover         = SRGB(70,73,78);
    const ImVec4 col_button_active        = col_accent_active;

    // ---- Tabs (neutral; selected = blue) ----
    const ImVec4 col_tab_base             = SRGB(40,44,50);
    const ImVec4 col_tab_hovered          = SRGB(55,60,68);
    const ImVec4 col_tab_selected         = col_accent;
    const ImVec4 col_tab_dimmed           = SRGB(38,40,44);
    const ImVec4 col_tab_dimmed_selected  = SRGB(45,48,53);

    // ---- Assignments ----
    colors[ImGuiCol_Text]                   = col_text;
    colors[ImGuiCol_TextDisabled]           = col_text_disabled;

    colors[ImGuiCol_WindowBg]               = col_bg_window;
    colors[ImGuiCol_ChildBg]                = col_bg_child;
    colors[ImGuiCol_PopupBg]                = col_bg_popup;

    colors[ImGuiCol_Border]                 = col_border;
    colors[ImGuiCol_BorderShadow]           = col_border_shadow;

    colors[ImGuiCol_FrameBg]                = col_frame_bg;
    colors[ImGuiCol_FrameBgHovered]         = col_frame_bg_hovered;
    colors[ImGuiCol_FrameBgActive]          = col_frame_bg_active;

    // Buttons (UE behavior)
    colors[ImGuiCol_Button]                 = col_button_idle;
    colors[ImGuiCol_ButtonHovered]          = col_button_hover;
    colors[ImGuiCol_ButtonActive]           = col_button_active;

    // Sliders / checks use accent to signal interaction
    colors[ImGuiCol_CheckMark]              = col_accent;
    colors[ImGuiCol_SliderGrab]             = col_accent_hover;
    colors[ImGuiCol_SliderGrabActive]       = col_accent_active;

    // Headers stay neutral (not blue)
    colors[ImGuiCol_Header]                 = col_header;
    colors[ImGuiCol_HeaderHovered]          = col_header_hovered;
    colors[ImGuiCol_HeaderActive]           = col_header_active;

    // Separators / grips
    colors[ImGuiCol_Separator]              = col_border;
    colors[ImGuiCol_SeparatorHovered]       = col_accent_hover;
    colors[ImGuiCol_SeparatorActive]        = col_accent_active;

    colors[ImGuiCol_ResizeGrip]             = ImVec4(col_accent.x, col_accent.y, col_accent.z, 0.22f);
    colors[ImGuiCol_ResizeGripHovered]      = ImVec4(col_accent.x, col_accent.y, col_accent.z, 0.72f);
    colors[ImGuiCol_ResizeGripActive]       = ImVec4(col_accent.x, col_accent.y, col_accent.z, 0.95f);

    // Tabs
    colors[ImGuiCol_Tab]                    = col_tab_base;
    colors[ImGuiCol_TabHovered]             = col_tab_hovered;
    colors[ImGuiCol_TabSelected]            = col_tab_selected;
    colors[ImGuiCol_TabSelectedOverline]    = col_accent;
    colors[ImGuiCol_TabDimmed]              = col_tab_dimmed;
    colors[ImGuiCol_TabDimmedSelected]      = col_tab_dimmed_selected;
    colors[ImGuiCol_TabDimmedSelectedOverline] = ImVec4(0,0,0,0);

    // Docking
    colors[ImGuiCol_DockingPreview]         = ImVec4(col_accent.x, col_accent.y, col_accent.z, 0.70f);
    colors[ImGuiCol_DockingEmptyBg]         = SRGB(34,36,41);

    // Scrollbars
    colors[ImGuiCol_ScrollbarBg]            = col_scrollbar_bg;
    colors[ImGuiCol_ScrollbarGrab]          = col_scrollbar_grab;
    colors[ImGuiCol_ScrollbarGrabHovered]   = col_scrollbar_hover;
    colors[ImGuiCol_ScrollbarGrabActive]    = col_scrollbar_active;

    // Tables / plots
    colors[ImGuiCol_TableHeaderBg]          = col_table_header_bg;
    colors[ImGuiCol_TableBorderStrong]      = col_table_border_strong;
    colors[ImGuiCol_TableBorderLight]       = col_table_border_light;
    colors[ImGuiCol_TableRowBg]             = ImVec4(0,0,0,0);
    colors[ImGuiCol_TableRowBgAlt]          = SRGB(255,255,255, 16/255.0f);

    colors[ImGuiCol_PlotLines]              = col_plot_lines;
    colors[ImGuiCol_PlotLinesHovered]       = col_plot_lines_hover;
    colors[ImGuiCol_PlotHistogram]          = col_plot_hist;
    colors[ImGuiCol_PlotHistogramHovered]   = col_plot_hist_hover;

    // Links / selection / nav / modals
    colors[ImGuiCol_TextLink]               = col_accent;
    colors[ImGuiCol_TextSelectedBg]         = col_text_selected_bg;
    colors[ImGuiCol_DragDropTarget]         = col_dragdrop_target;
    colors[ImGuiCol_NavCursor]              = col_accent;
    colors[ImGuiCol_NavWindowingHighlight]  = SRGB(255,255,255, 180/255.0f);
    colors[ImGuiCol_NavWindowingDimBg]      = SRGB(0,0,0, 120/255.0f);
    colors[ImGuiCol_ModalWindowDimBg]       = SRGB(0,0,0, 150/255.0f);

    colors[ImGuiCol_TitleBg]                = col_title_bg;
    colors[ImGuiCol_TitleBgActive]          = col_title_bg_active;
    colors[ImGuiCol_TitleBgCollapsed]       = col_title_bg_collapsed;

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

bool UImGuiToolkitSubsystem::OnTick(float DeltaTime)
{
	// This runs every frame in both editor and game!
	const ImGui::FScopedContext ScopedContext;
	if (ScopedContext)
	{
		// Render all registered windows
		for (UImGuiToolkitWindow* Window : RegisteredWindows)
		{
			if (Window)
			{
				Window->Render();
			}
		} 

		ShowImGuiDemoWindow(bShowDemoWindow);

		// Broadcast delegate
		OnImGuiRender.Broadcast();
	} 
	
	return true; // Keep ticking
}

void UImGuiToolkitSubsystem::OnEndFrame()
{
	ImGuiContext* Ctx = ImGui::GetCurrentContext();
	if (!Ctx)
	{
		return;
	}
	
	if (bRebuildFontsPending)
	{
		const FString FontPath = FPaths::EngineContentDir() / TEXT("Slate/Fonts/Roboto-Regular.ttf");
		ImGuiIO& io = ImGui::GetIO();
		io.Fonts->ClearFonts();
		io.Fonts->AddFontFromFileTTF(TCHAR_TO_UTF8(*FontPath), 16.0f * CustomUIScale);
	
		SetImGuiToolkitStyle();
	
		ImGui::GetStyle().ScaleAllSizes(CustomUIScale);
	
		bRebuildFontsPending = false;
	}



}


