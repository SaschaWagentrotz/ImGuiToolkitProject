// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Containers/ImGuiToolkitWindow.h"
#include "ImGuiToolkitSubsystem.generated.h"

/**
 * 
 */
DECLARE_MULTICAST_DELEGATE(FOnImGuiRender);

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitSubsystem : public UEngineSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	void SetImGuiToolkitStyle();

	UPROPERTY()
	float CustomUIScale = 2.0f;

	void SetShowImGuiDemoWindow(bool bNewShow);
	bool GetShowImGuiDemoWindow() const { return bShowDemoWindow; }
	void ShowImGuiDemoWindow(bool bShow);
	
	UFUNCTION(BlueprintCallable, Category = "ImGui")
	void RegisterWindow(UImGuiToolkitWindow* Window);

	UFUNCTION(BlueprintCallable, Category = "ImGui")
	void UnregisterWindow(UImGuiToolkitWindow* Window);
	
	const TArray<TObjectPtr<UImGuiToolkitWindow>>& GetRegisteredWindows() const { return RegisteredWindows; }
	
	FOnImGuiRender OnImGuiRender;

private:
	bool OnTick(float DeltaTime);
	void OnEndFrame();

	FTSTicker::FDelegateHandle TickHandle;
	FDelegateHandle EndFrameHandle;

	bool bRebuildFontsPending = true;
	bool bShowDemoWindow = false;

	UPROPERTY()
	TArray<TObjectPtr<UImGuiToolkitWindow>> RegisteredWindows;
};