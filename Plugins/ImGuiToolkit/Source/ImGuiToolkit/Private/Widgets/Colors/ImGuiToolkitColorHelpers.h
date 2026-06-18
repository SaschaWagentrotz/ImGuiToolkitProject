#pragma once

#include "FImGuiToolkitUtils.h"
#include "Math/UnrealMathUtility.h"

namespace ImGuiToolkitColorHelpers
{
	inline ImGuiColorEditFlags ChooseSingleColorEditFlag(ImGuiColorEditFlags Flags, ImGuiColorEditFlags Mask, ImGuiColorEditFlags PreferredFlag)
	{
		const ImGuiColorEditFlags MatchingFlags = Flags & Mask;
		if (MatchingFlags == 0 || FMath::IsPowerOfTwo(MatchingFlags))
		{
			return Flags;
		}

		if ((MatchingFlags & PreferredFlag) != 0)
		{
			return (Flags & ~Mask) | PreferredFlag;
		}

		return Flags & ~Mask;
	}

	inline ImGuiColorEditFlags SanitizeColorEditFlags(ImGuiColorEditFlags Flags, bool bAllowMultipleDisplayModes)
	{
		if (!bAllowMultipleDisplayModes)
		{
			Flags = ChooseSingleColorEditFlag(Flags, ImGuiColorEditFlags_DisplayMask_, ImGuiColorEditFlags_DisplayRGB);
		}
		Flags = ChooseSingleColorEditFlag(Flags, ImGuiColorEditFlags_DataTypeMask_, ImGuiColorEditFlags_Float);
		Flags = ChooseSingleColorEditFlag(Flags, ImGuiColorEditFlags_PickerMask_, ImGuiColorEditFlags_PickerHueWheel);
		Flags = ChooseSingleColorEditFlag(Flags, ImGuiColorEditFlags_InputMask_, ImGuiColorEditFlags_InputRGB);

		if ((Flags & ImGuiColorEditFlags_InputMask_) == 0)
		{
			Flags |= ImGuiColorEditFlags_InputRGB;
		}

		return Flags;
	}

	inline ImGuiColorEditFlags GetColorEditFlags(const TArray<EImGuiColorEditFlag>& Flags)
	{
		return SanitizeColorEditFlags(FImGuiToolkitUtils::CombineImGuiColorEditFlags(Flags), false);
	}

	inline ImGuiColorEditFlags GetColorPickerFlags(const TArray<EImGuiColorEditFlag>& Flags)
	{
		return SanitizeColorEditFlags(FImGuiToolkitUtils::CombineImGuiColorEditFlags(Flags), true);
	}

	inline void LinearColorToColorEditValues(const FLinearColor& Color, ImGuiColorEditFlags Flags, float Values[4])
	{
		const ImVec4 ImGuiColor = FImGuiToolkitUtils::LinearColorToImVec4(Color);
		if ((Flags & ImGuiColorEditFlags_InputHSV) != 0)
		{
			ImGui::ColorConvertRGBtoHSV(ImGuiColor.x, ImGuiColor.y, ImGuiColor.z, Values[0], Values[1], Values[2]);
		}
		else
		{
			Values[0] = ImGuiColor.x;
			Values[1] = ImGuiColor.y;
			Values[2] = ImGuiColor.z;
		}
		Values[3] = ImGuiColor.w;
	}

	inline FLinearColor ColorEditValuesToLinearColor(const float Values[4], float Alpha, ImGuiColorEditFlags Flags)
	{
		float Red = Values[0];
		float Green = Values[1];
		float Blue = Values[2];
		if ((Flags & ImGuiColorEditFlags_InputHSV) != 0)
		{
			ImGui::ColorConvertHSVtoRGB(Values[0], Values[1], Values[2], Red, Green, Blue);
		}

		return FImGuiToolkitUtils::ImVec4ToLinearColor(ImVec4(Red, Green, Blue, Alpha));
	}
}
