#pragma once

#include "FImGuiToolkitUtils.h"

#include "Engine/Texture.h"

namespace ImGuiToolkitImageHelpers
{
	inline ImVec2 ToImVec2(const FVector2D& Vector)
	{
		return ImVec2(static_cast<float>(Vector.X), static_cast<float>(Vector.Y));
	}

	inline ImVec2 GetImageSize(UObject* ResourceObject, const FVector2D& RequestedSize)
	{
		if (!FMath::IsNearlyZero(RequestedSize.X) || !FMath::IsNearlyZero(RequestedSize.Y))
		{
			return ToImVec2(RequestedSize);
		}

		if (const UTexture* Texture = Cast<UTexture>(ResourceObject))
		{
			return ImVec2(Texture->GetSurfaceWidth(), Texture->GetSurfaceHeight());
		}

		return ImVec2(64.0f, 64.0f);
	}
}
