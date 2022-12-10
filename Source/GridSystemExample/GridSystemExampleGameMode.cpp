// Copyright Epic Games, Inc. All Rights Reserved.

#include "GridSystemExampleGameMode.h"
#include "GridSystemExampleCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGridSystemExampleGameMode::AGridSystemExampleGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Character/Blueprints/BP_Character"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
