#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Containers/ImGuiToolkitWindow.h"
#include "ImGuiToolkitSubsystem.generated.h"

class UImGuiToolkitHostWidget;
struct FImGuiToolkitStyleSettings;
struct ImGuiContext;

DECLARE_MULTICAST_DELEGATE(FOnImGuiRender);

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitSubsystem : public UEngineSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	void SetImGuiToolkitStyle(const FImGuiToolkitStyleSettings& StyleSettings);
	void ApplyStyleToCurrentContext();

	void SetShowImGuiDemoWindow(bool bNewShow);
	bool GetShowImGuiDemoWindow() const { return bShowDemoWindow; }
	void ShowImGuiDemoWindow(bool bShow);
	
	UFUNCTION(BlueprintCallable, Category = "ImGui")
	void RegisterWindow(UImGuiToolkitWindow* Window);

	UFUNCTION(BlueprintCallable, Category = "ImGui")
	void UnregisterWindow(UImGuiToolkitWindow* Window);

	void RegisterHostWidget(UImGuiToolkitHostWidget* HostWidget);
	void UnregisterHostWidget(UImGuiToolkitHostWidget* HostWidget);
	void QueueDockWindow(UImGuiToolkitWindow* WindowToDock, UImGuiToolkitWindow* TargetWindow, EImGuiToolkitDockSplitDirection Direction, float SplitRatio);
	void ApplyPendingDockRequests(UImGuiToolkitWindow* HostWindow = nullptr);
	void ApplyHostedDockRequests(UImGuiToolkitWindow* HostWindow);
	void RenderWindowsDockedToHost(UImGuiToolkitWindow* HostWindow);
	bool HasWindowsDockedToHost(UImGuiToolkitWindow* HostWindow) const;
	bool UpdateHostedDockNodeBounds(UImGuiToolkitWindow* HostWindow, const FVector2D& HostPosition, const FVector2D& HostSize);
	
	const TArray<TObjectPtr<UImGuiToolkitWindow>>& GetRegisteredWindows() const { return RegisteredWindows; }
	
	FOnImGuiRender OnImGuiRender;

private:
	struct FPendingDockRequest
	{
		TWeakObjectPtr<UImGuiToolkitWindow> WindowToDock;
		TWeakObjectPtr<UImGuiToolkitWindow> TargetWindow;
		EImGuiToolkitDockSplitDirection Direction = EImGuiToolkitDockSplitDirection::Center;
		float SplitRatio = 0.5f;
	};

	bool OnTick(float DeltaTime);
	bool ApplyDockRequest(const FPendingDockRequest& Request, bool bHostedDocking = false);
	bool IsWindowHostedByRegisteredHost(UImGuiToolkitWindow* Window) const;
	bool IsRenderedByHostDocking(UImGuiToolkitWindow* Window) const;
	void RegisterHostedDockRequest(const FPendingDockRequest& Request);
	void RegisterPendingDockRequestsForHost(UImGuiToolkitWindow* HostWindow);
	void RemovePendingDockRequestsForHost(UImGuiToolkitWindow* HostWindow);
	void RemoveWindowReferences(UImGuiToolkitWindow* Window);

	FTSTicker::FDelegateHandle TickHandle;

	bool bShowDemoWindow = false;

	UPROPERTY()
	TArray<TObjectPtr<UImGuiToolkitWindow>> RegisteredWindows;

	TArray<TWeakObjectPtr<UImGuiToolkitHostWidget>> RegisteredHostWidgets;
	TArray<FPendingDockRequest> PendingDockRequests;
	TMap<TWeakObjectPtr<UImGuiToolkitWindow>, TArray<FPendingDockRequest>> HostedDockRequests;
	TMap<TWeakObjectPtr<UImGuiToolkitWindow>, TArray<TWeakObjectPtr<UImGuiToolkitWindow>>> HostedDockedWindows;
};
