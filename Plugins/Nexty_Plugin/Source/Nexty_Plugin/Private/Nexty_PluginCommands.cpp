// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "Nexty_PluginCommands.h"

#define LOCTEXT_NAMESPACE "FNexty_PluginModule"

void FNexty_PluginCommands::RegisterCommands()
{
	UI_COMMAND(OpenPluginWindow, "Nexty_Plugin", "Bring up Nexty_Plugin window", EUserInterfaceActionType::Button, FInputGesture());
}

#undef LOCTEXT_NAMESPACE
