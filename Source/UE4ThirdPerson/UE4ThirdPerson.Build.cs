// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UE4ThirdPerson : ModuleRules
{
	public UE4ThirdPerson(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
