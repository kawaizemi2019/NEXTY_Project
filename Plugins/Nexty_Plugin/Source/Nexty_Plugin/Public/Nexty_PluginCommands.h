// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "Nexty_PluginStyle.h"

class FNexty_PluginCommands : public TCommands<FNexty_PluginCommands>
{
public:

	FNexty_PluginCommands()
		: TCommands<FNexty_PluginCommands>(TEXT("Nexty_Plugin"), NSLOCTEXT("Contexts", "Nexty_Plugin", "Nexty_Plugin Plugin"), NAME_None, FNexty_PluginStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > OpenPluginWindow;
};