// Copyright Epic Games, Inc. All Rights Reserved.

#include "SpawnDestroyGameMode.h"
#include "SpawnDestroyCharacter.h"
#include "UObject/ConstructorHelpers.h"

ASpawnDestroyGameMode::ASpawnDestroyGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
