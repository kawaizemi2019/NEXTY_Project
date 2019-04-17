// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "NEXTY_ProjectGameMode.h"
#include "NEXTY_ProjectPawn.h"
#include "NEXTY_ProjectHud.h"

ANEXTY_ProjectGameMode::ANEXTY_ProjectGameMode()
{
	DefaultPawnClass = ANEXTY_ProjectPawn::StaticClass();
	HUDClass = ANEXTY_ProjectHud::StaticClass();
}
