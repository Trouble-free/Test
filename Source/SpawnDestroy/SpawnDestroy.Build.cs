// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class SpawnDestroy : ModuleRules
{
	public SpawnDestroy(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
