#pragma once

#include <Misc/EngineVersionComparison.h>
#include <Modules/ModuleManager.h>

enum class EImGuiToolkitStyleTarget : uint8;
class FImGuiContext;
class SWindow;
class UGameViewportClient;

class IMGUI_API FImGuiModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	/// Returns this module's instance, loading it on demand if needed
	/// @note Beware of calling this during the shutdown phase as the module might have been unloaded already
	static FImGuiModule& Get();

	/// Finds or creates an ImGui context for an editor or game session
	/// @param PieSessionId Optional target Play-in-Editor instance, defaults to the current instance
#if UE_VERSION_OLDER_THAN(5, 5, 0)
	TSharedPtr<FImGuiContext> FindOrCreateSessionContext(const int32 PieSessionId = GPlayInEditorID);
#else
	TSharedPtr<FImGuiContext> FindOrCreateSessionContext(const int32 PieSessionId = UE::GetPlayInEditorID());
#endif

	/// Creates an ImGui context for a Slate window
	static TSharedPtr<FImGuiContext> CreateWindowContext(const TSharedRef<SWindow>& Window, EImGuiToolkitStyleTarget StyleTarget);

	/// Creates an ImGui context for a game viewport
	static TSharedPtr<FImGuiContext> CreateViewportContext(UGameViewportClient* GameViewport, EImGuiToolkitStyleTarget StyleTarget);

private:
	void OnEndPIE(bool bIsSimulating);
	void OnViewportCreated() const;

	TMap<int32, TSharedPtr<FImGuiContext>> SessionContexts;
};
