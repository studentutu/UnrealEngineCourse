// Copyright Epic Games, Inc. All Rights Reserved.

#include "UE4ThirdPersonGameMode.h"
#include "UE4ThirdPersonCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUE4ThirdPersonGameMode::AUE4ThirdPersonGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
