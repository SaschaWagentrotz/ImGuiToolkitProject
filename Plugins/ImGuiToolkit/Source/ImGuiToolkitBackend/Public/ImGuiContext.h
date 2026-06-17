#pragma once

#include "ImGuiToolkitSettings.h"

#include <Templates/SharedPointer.h>

#if WITH_ENGINE
#include <Engine/Texture2D.h>
#include <UObject/StrongObjectPtr.h>
#endif

class SWindow;
class SImGuiOverlay;
struct FDisplayMetrics;
struct FSlateBrush;
struct ImGuiContext;
struct ImGuiViewport;
struct ImPlotContext;

struct IMGUI_API FImGuiViewportData
{
	/// Returns the existing viewport data or creates one
	static FImGuiViewportData* GetOrCreate(ImGuiViewport* Viewport);

	TWeakPtr<SWindow> Window = nullptr;
	TWeakPtr<SImGuiOverlay> Overlay = nullptr;
};

class IMGUI_API FImGuiContext : public TSharedFromThis<FImGuiContext>
{
public:
	/// Creates a managed ImGui context
	static TSharedRef<FImGuiContext> Create(EImGuiToolkitStyleTarget StyleTarget = EImGuiToolkitStyleTarget::Runtime);

	/// Returns an existing managed ImGui context
	static TSharedPtr<FImGuiContext> Get(const ImGuiContext* Context);

	~FImGuiContext();

	/// Begins a new frame
	void BeginFrame();

	/// Ends the current frame
	void EndFrame();

	EImGuiToolkitStyleTarget GetStyleTarget() const { return StyleTarget; }

#if WITH_NETIMGUI
	/// Listens for remote connections
	bool Listen(uint16 Port);

	/// Connects to a remote host
	bool Connect(const FString& Host, int16 Port);

	/// Closes all remote connections
	void Disconnect();
#endif

	/// Access to the underlying ImGui context
	operator ImGuiContext*() const;

#if WITH_IMPLOT
	/// Access to the underlying ImPlot context
	operator ImPlotContext*() const;
#endif

private:
	void Initialize(EImGuiToolkitStyleTarget InStyleTarget);

	void OnDisplayMetricsChanged(const FDisplayMetrics& DisplayMetrics);
	void UpdateConfiguredFontAtlas();

	ImGuiContext* Context = nullptr;

#if WITH_IMPLOT
	ImPlotContext* PlotContext = nullptr;
#endif

	char IniFilenameUtf8[1024] = {};
	char LogFilenameUtf8[1024] = {};
	TArray<char> ClipboardBuffer;
	EImGuiToolkitStyleTarget StyleTarget = EImGuiToolkitStyleTarget::Runtime;
	float ConfiguredFontScale = -1.0f;
	float ConfiguredFontSize = -1.0f;
	FString ConfiguredFontPath;

#if WITH_NETIMGUI
	bool bIsRemote = false;
#endif

#if WITH_ENGINE
	TStrongObjectPtr<UTexture2D> FontAtlasTexturePtr = nullptr;
#else
	TSharedPtr<FSlateBrush> FontAtlasTexturePtr = nullptr;
#endif
};
