#pragma once

#include "CoreMinimal.h"
#include "FImGuiToolkitUtils.h"
#include "ImGuiToolkitWidget.h"
#include "ImGuiToolkitPushStyleVar.generated.h"

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitPushStyleVar : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Style")
	EImGuiStyleVar StyleVar = EImGuiStyleVar::Alpha;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Style")
	float FloatValue = 1.0f;

	UPROPERTY(BlueprintReadWrite, Category = "ImGui Toolkit Style")
	FVector2D Vector2DValue = FVector2D::ZeroVector;
};
