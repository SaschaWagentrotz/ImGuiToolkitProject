#pragma once

#include "CoreMinimal.h"
#include "ImGuiToolkitContainer.h"
#include "ImGuiToolkitBeginListBox.generated.h"

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitBeginListBox : public UImGuiToolkitContainer
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadWrite, Category = "ImGuiTK Containers")
	FVector2D Size = FVector2D::ZeroVector;
};
