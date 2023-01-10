// Copyright Epic Games, Inc. All Rights Reserved.

#include "BucovinaGameMode.h"
#include "BucovinaCharacter.h"
#include "UObject/ConstructorHelpers.h"

ABucovinaGameMode::ABucovinaGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
