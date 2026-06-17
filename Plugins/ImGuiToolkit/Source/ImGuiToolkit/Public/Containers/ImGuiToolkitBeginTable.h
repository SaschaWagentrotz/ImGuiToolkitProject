#pragma once

#include "CoreMinimal.h"
#include "FImGuiToolkitUtils.h"
#include "ImGuiToolkitContainer.h"
#include "ImGuiToolkitBeginTable.generated.h"

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitBeginTable : public UImGuiToolkitContainer
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGuiTK Containers", meta = (ClampMin = "1", UIMin = "1"))
	int32 ColumnCount = 1;

	UPROPERTY(BlueprintReadWrite, Category = "ImGuiTK Containers")
	TArray<EImGuiTableFlag> TableFlags;

	UPROPERTY(BlueprintReadWrite, Category = "ImGuiTK Containers")
	FVector2D OuterSize = FVector2D::ZeroVector;

	UPROPERTY(BlueprintReadWrite, Category = "ImGuiTK Containers")
	float InnerWidth = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "ImGuiTK Containers")
	bool bIsOpen = false;
};
