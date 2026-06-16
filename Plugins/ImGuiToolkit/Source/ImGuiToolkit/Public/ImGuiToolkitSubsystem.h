#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Containers/ImGuiToolkitWindow.h"
#include "ImGuiToolkitSubsystem.generated.h"

class UImGuiToolkitHostWidget;
struct ImGuiContext;

DECLARE_MULTICAST_DELEGATE(FOnImGuiRender);

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitSubsystem : public UEngineSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	void SetImGuiToolkitStyle();
	void ApplyStyleToCurrentContext();

	UPROPERTY()
	float CustomUIScale = 2.0f;

	void SetShowImGuiDemoWindow(bool bNewShow);
	bool GetShowImGuiDemoWindow() const { return bShowDemoWindow; }
	void ShowImGuiDemoWindow(bool bShow);
	
	UFUNCTION(BlueprintCallable, Category = "ImGui")
	void RegisterWindow(UImGuiToolkitWindow* Window);

	UFUNCTION(BlueprintCallable, Category = "ImGui")
	void UnregisterWindow(UImGuiToolkitWindow* Window);

	void RegisterHostWidget(UImGuiToolkitHostWidget* HostWidget);
	void UnregisterHostWidget(UImGuiToolkitHostWidget* HostWidget);
	
	const TArray<TObjectPtr<UImGuiToolkitWindow>>& GetRegisteredWindows() const { return RegisteredWindows; }
	
	FOnImGuiRender OnImGuiRender;

private:
	bool OnTick(float DeltaTime);
	void OnEndFrame();

	FTSTicker::FDelegateHandle TickHandle;
	FDelegateHandle EndFrameHandle;

	bool bShowDemoWindow = false;
	TSet<ImGuiContext*> StyledContexts;

	UPROPERTY()
	TArray<TObjectPtr<UImGuiToolkitWindow>> RegisteredWindows;

	TArray<TWeakObjectPtr<UImGuiToolkitHostWidget>> RegisteredHostWidgets;
};
