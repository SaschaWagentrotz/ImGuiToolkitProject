// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ImGuiToolkit : ModuleRules
{
	public ImGuiToolkit(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"Engine",
				"ImGuiToolkitBackend",
				"ImPlotLibrary",
				"UMG"
			}
		);

		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Slate",
				"SlateCore"
			}
		);
	}
}
