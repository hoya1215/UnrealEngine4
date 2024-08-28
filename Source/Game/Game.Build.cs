// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Game : ModuleRules
{
	public Game(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "UMG", "Slate", "SlateCore", "NavigationSystem", "AIModule", "GameplayTasks" });


        PublicIncludePaths.AddRange(new string[] {
            "Game", 
            "Game/AI",
            "Game/Animation",
            "Game/Event",
            "Game/Mode",
            "Game/Object",
            "Game/Sound",
            "Game/UI"
        });
    }


}


