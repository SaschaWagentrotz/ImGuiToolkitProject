#pragma once

#include "CoreMinimal.h"
#include "FImGuiToolkitUtils.h"
#include "ImGuiToolkitContainer.h"
#include "ImGuiToolkitBeginChild.generated.h"

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitBeginChild : public UImGuiToolkitContainer
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGuiTK Containers")
	FVector2D Size = FVector2D::ZeroVector;

	UPROPERTY(BlueprintReadWrite, Category = "ImGuiTK Containers")
	TArray<EImGuiChildFlag> ChildFlags;

	UPROPERTY(BlueprintReadWrite, Category = "ImGuiTK Containers")
	TArray<EImGuiWindowFlag> WindowFlags;
};
