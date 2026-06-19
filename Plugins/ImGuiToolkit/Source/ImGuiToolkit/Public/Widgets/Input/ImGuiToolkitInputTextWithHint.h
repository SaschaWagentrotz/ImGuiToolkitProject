#pragma once

#include "CoreMinimal.h"
#include "ImGuiToolkitWidget.h"
#include "ImGuiToolkitInputTextWithHint.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnImGuiInputTextWithHintChanged, FString, InputText);

UCLASS()
class IMGUITOOLKIT_API UImGuiToolkitInputTextWithHint : public UImGuiToolkitWidget
{
	GENERATED_BODY()

public:
	virtual void Render() override;

	UPROPERTY(BlueprintReadOnly, Category = "ImGui Toolkit Widget")
	FString InputText;

	UPROPERTY(BlueprintReadOnly, Category = "ImGui Toolkit Widget")
	FText Hint;

	UPROPERTY(BlueprintAssignable, Category = "ImGui Toolkit Widget")
	FOnImGuiInputTextWithHintChanged OnTextChanged;

	UFUNCTION()
	void SetPreviewText(FText PreviewText);

	UFUNCTION()
	void SetHint(FText InHint);

private:
	TArray<char> InputBuffer;
	FString LastSyncedInputText;
};
