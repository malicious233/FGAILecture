// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class AiLEcture : ModuleRules
{
	public AiLEcture(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "GameplayAbilities", "CoreUObject", "GameplayTasks", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
