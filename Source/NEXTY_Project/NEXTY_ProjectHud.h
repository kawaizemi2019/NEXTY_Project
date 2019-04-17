// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "NEXTY_ProjectHud.generated.h"

UCLASS(config = Game)
class ANEXTY_ProjectHud : public AHUD
{
	GENERATED_BODY()

public:
	ANEXTY_ProjectHud();

	/** Font used to render the vehicle info */
	UPROPERTY()
	UFont* HUDFont;

	// Begin AHUD interface
	virtual void DrawHUD() override;
	// End AHUD interface

};
