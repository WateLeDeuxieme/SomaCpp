// Copyright Epic Games, Inc. All Rights Reserved.

#include "SomaCppGameMode.h"
#include "SomaCppCharacter.h"
#include "UObject/ConstructorHelpers.h"

ASomaCppGameMode::ASomaCppGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
