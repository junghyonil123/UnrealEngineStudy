// Copyright Epic Games, Inc. All Rights Reserved.

#include "UnrealMemoryGameMode.h"
#include "UnrealMemoryCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUnrealMemoryGameMode::AUnrealMemoryGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
