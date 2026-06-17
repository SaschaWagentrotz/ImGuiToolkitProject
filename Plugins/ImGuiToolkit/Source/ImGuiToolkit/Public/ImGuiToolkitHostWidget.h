#pragma once

#include "CoreMinimal.h"
#include "Components/Widget.h"
#include "Containers/ImGuiToolkitWindow.h"
#include "ImGuiToolkitHostWidget.generated.h"

class FImGuiContext;
class SImGuiOverlay;
class UPanelSlot;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FImGuiToolkitHostRenderEvent);

UCLASS(meta = (DisplayName = "ImGui Toolkit Host"))
class IMGUITOOLKIT_API UImGuiToolkitHostWidget : public UWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ImGuiToolkit")
	TObjectPtr<UImGuiToolkitWindow> HostedWindow = nullptr;

	UPROPERTY(BlueprintAssignable, Category = "ImGuiToolkit")
	FImGuiToolkitHostRenderEvent OnImGuiRender;

	UFUNCTION(BlueprintCallable, Category = "ImGuiToolkit")
	UImGuiToolkitWindow* GetHostedWindow();

	void RenderHost();

	virtual void ReleaseSlateResources(bool bReleaseChildren) override;
	virtual void BeginDestroy() override;

#if WITH_EDITOR
	virtual const FText GetPaletteCategory() override;
#endif

protected:
	virtual TSharedRef<SWidget> RebuildWidget() override;

private:
	void ApplyFillToParentSlot(bool bForce = false);
	bool IsHostVisible() const;
	void RegisterHost();
	void UnregisterHost();

	TSharedPtr<FImGuiContext> Context = nullptr;
	TSharedPtr<SImGuiOverlay> Overlay = nullptr;
	TWeakObjectPtr<UPanelSlot> FilledParentSlot = nullptr;
	bool bIsRegistered = false;
};
