#include "ImGuiToolkitHostWidget.h"

#include "Components/BorderSlot.h"
#include "Components/CanvasPanelSlot.h"
#include "Components/HorizontalBoxSlot.h"
#include "Components/OverlaySlot.h"
#include "Components/VerticalBoxSlot.h"
#include "Engine/Engine.h"
#include "ImGuiContext.h"
#include "ImGuiConfig.h"
#include "ImGuiToolkitSubsystem.h"
#include "SImGuiOverlay.h"

#include <Widgets/SNullWidget.h>
#include <imgui.h>

TSharedRef<SWidget> UImGuiToolkitHostWidget::RebuildWidget()
{
	Context = FImGuiContext::Create();

	{
		const ImGui::FScopedContext ScopedContext(Context);
		ImGuiIO& IO = ImGui::GetIO();
		IO.ConfigFlags &= ~ImGuiConfigFlags_ViewportsEnable;
		IO.BackendFlags &= ~ImGuiBackendFlags_PlatformHasViewports;
		IO.BackendFlags &= ~ImGuiBackendFlags_RendererHasViewports;

		FImGuiViewportData* ViewportData = FImGuiViewportData::GetOrCreate(ImGui::GetMainViewport());
		if (ViewportData)
		{
			SAssignNew(Overlay, SImGuiOverlay)
				.Context(Context);

			ViewportData->Overlay = Overlay;
		}
	}

	RegisterHost();

	if (Overlay.IsValid())
	{
		return Overlay.ToSharedRef();
	}

	return SNullWidget::NullWidget;
}

void UImGuiToolkitHostWidget::ReleaseSlateResources(bool bReleaseChildren)
{
	UnregisterHost();

	Super::ReleaseSlateResources(bReleaseChildren);

	Overlay.Reset();
	Context.Reset();
}

void UImGuiToolkitHostWidget::BeginDestroy()
{
	UnregisterHost();

	Super::BeginDestroy();
}

UImGuiToolkitWindow* UImGuiToolkitHostWidget::GetHostedWindow()
{
	return HostedWindow;
}

void UImGuiToolkitHostWidget::RenderHost()
{
	ApplyFillToParentSlot();

	if (UImGuiToolkitWindow* Window = HostedWindow)
	{
		Window->bIsHosted = true;
		Window->bIsOpen = true;
		Window->HostPosition = FVector2D::ZeroVector;
	}

	if (!Context.IsValid() || !IsHostVisible())
	{
		return;
	}

	const ImGui::FScopedContext ScopedContext(Context);
	if (!ScopedContext)
	{
		return;
	}

	if (GEngine)
	{
		if (UImGuiToolkitSubsystem* Subsystem = GEngine->GetEngineSubsystem<UImGuiToolkitSubsystem>())
		{
			Subsystem->ApplyStyleToCurrentContext();
		}
	}

	const FVector2D HostSize = Overlay.IsValid()
		? FVector2D(Overlay->GetTickSpaceGeometry().GetAbsoluteSize())
		: FVector2D::ZeroVector;

	UImGuiToolkitSubsystem* ImGuiToolkitSubsystem = GEngine ? GEngine->GetEngineSubsystem<UImGuiToolkitSubsystem>() : nullptr;
	bool bHostedDockNodeExists = false;

	if (UImGuiToolkitWindow* Window = HostedWindow)
	{
		Window->HostSize = HostSize;

		const bool bHasDockedWindows = ImGuiToolkitSubsystem && ImGuiToolkitSubsystem->HasWindowsDockedToHost(Window);
		if (bHasDockedWindows)
		{
			bHostedDockNodeExists = ImGuiToolkitSubsystem->UpdateHostedDockNodeBounds(Window, Window->HostPosition, Window->HostSize);
		}

		const bool bWasSuppressingPlacement = Window->bSuppressNextWindowPlacement;
		Window->bSuppressNextWindowPlacement = bHostedDockNodeExists;
		Window->Render();
		Window->bSuppressNextWindowPlacement = bWasSuppressingPlacement;
	}

	if (ImGuiToolkitSubsystem)
	{
		ImGuiToolkitSubsystem->ApplyPendingDockRequests(HostedWindow);
		bHostedDockNodeExists = ImGuiToolkitSubsystem->UpdateHostedDockNodeBounds(HostedWindow, FVector2D::ZeroVector, HostSize);
		if (!bHostedDockNodeExists)
		{
			ImGuiToolkitSubsystem->ApplyHostedDockRequests(HostedWindow);
			ImGuiToolkitSubsystem->UpdateHostedDockNodeBounds(HostedWindow, FVector2D::ZeroVector, HostSize);
		}
		ImGuiToolkitSubsystem->RenderWindowsDockedToHost(HostedWindow);
	}

	OnImGuiRender.Broadcast();
}

void UImGuiToolkitHostWidget::ApplyFillToParentSlot(bool bForce)
{
	if (!Slot)
	{
		FilledParentSlot.Reset();
		return;
	}

	if (!bForce && FilledParentSlot.Get() == Slot)
	{
		return;
	}

	if (UCanvasPanelSlot* CanvasSlot = Cast<UCanvasPanelSlot>(Slot))
	{
		CanvasSlot->SetAutoSize(false);
		CanvasSlot->SetAnchors(FAnchors(0.0f, 0.0f, 1.0f, 1.0f));
		CanvasSlot->SetOffsets(FMargin(0.0f));
		CanvasSlot->SetAlignment(FVector2D::ZeroVector);
	}
	else if (UOverlaySlot* OverlaySlot = Cast<UOverlaySlot>(Slot))
	{
		OverlaySlot->SetPadding(FMargin(0.0f));
		OverlaySlot->SetHorizontalAlignment(HAlign_Fill);
		OverlaySlot->SetVerticalAlignment(VAlign_Fill);
	}
	else if (UBorderSlot* BorderSlot = Cast<UBorderSlot>(Slot))
	{
		BorderSlot->SetHorizontalAlignment(HAlign_Fill);
		BorderSlot->SetVerticalAlignment(VAlign_Fill);
	}
	else if (UHorizontalBoxSlot* HorizontalBoxSlot = Cast<UHorizontalBoxSlot>(Slot))
	{
		HorizontalBoxSlot->SetSize(FSlateChildSize(ESlateSizeRule::Fill));
		HorizontalBoxSlot->SetHorizontalAlignment(HAlign_Fill);
		HorizontalBoxSlot->SetVerticalAlignment(VAlign_Fill);
	}
	else if (UVerticalBoxSlot* VerticalBoxSlot = Cast<UVerticalBoxSlot>(Slot))
	{
		VerticalBoxSlot->SetSize(FSlateChildSize(ESlateSizeRule::Fill));
		VerticalBoxSlot->SetHorizontalAlignment(HAlign_Fill);
		VerticalBoxSlot->SetVerticalAlignment(VAlign_Fill);
	}

	FilledParentSlot = Slot;
}

bool UImGuiToolkitHostWidget::IsHostVisible() const
{
	if (GetVisibility() == ESlateVisibility::Collapsed || GetVisibility() == ESlateVisibility::Hidden)
	{
		return false;
	}

	if (!Overlay.IsValid() || !Overlay->GetVisibility().IsVisible() || !Overlay->WasRecentlyPainted())
	{
		return false;
	}

	const FVector2D HostSize = Overlay->GetTickSpaceGeometry().GetAbsoluteSize();
	return HostSize.X > 0.0 && HostSize.Y > 0.0;
}

void UImGuiToolkitHostWidget::RegisterHost()
{
	if (!bIsRegistered && GEngine)
	{
		if (UImGuiToolkitSubsystem* Subsystem = GEngine->GetEngineSubsystem<UImGuiToolkitSubsystem>())
		{
			Subsystem->RegisterHostWidget(this);
			bIsRegistered = true;
		}
	}
}

void UImGuiToolkitHostWidget::UnregisterHost()
{
	if (bIsRegistered && GEngine)
	{
		if (UImGuiToolkitSubsystem* Subsystem = GEngine->GetEngineSubsystem<UImGuiToolkitSubsystem>())
		{
			Subsystem->UnregisterHostWidget(this);
		}
	}

	bIsRegistered = false;
}

#if WITH_EDITOR
const FText UImGuiToolkitHostWidget::GetPaletteCategory()
{
	return NSLOCTEXT("ImGuiToolkit", "ImGuiToolkitPaletteCategory", "ImGuiToolkit");
}
#endif
