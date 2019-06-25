// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "Nexty_Plugin.h"
#include "Nexty_PluginStyle.h"
#include "Nexty_PluginCommands.h"
#include "LevelEditor.h"
#include "Widgets/Docking/SDockTab.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Text/STextBlock.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"

static const FName Nexty_PluginTabName("Nexty_Plugin");

#define LOCTEXT_NAMESPACE "FNexty_PluginModule"

void FNexty_PluginModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
	FNexty_PluginStyle::Initialize();
	FNexty_PluginStyle::ReloadTextures();

	FNexty_PluginCommands::Register();
	
	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FNexty_PluginCommands::Get().OpenPluginWindow,
		FExecuteAction::CreateRaw(this, &FNexty_PluginModule::PluginButtonClicked),
		FCanExecuteAction());
		
	FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
	
	{
		TSharedPtr<FExtender> MenuExtender = MakeShareable(new FExtender());
		MenuExtender->AddMenuExtension("WindowLayout", EExtensionHook::After, PluginCommands, FMenuExtensionDelegate::CreateRaw(this, &FNexty_PluginModule::AddMenuExtension));

		LevelEditorModule.GetMenuExtensibilityManager()->AddExtender(MenuExtender);
	}
	
	{
		TSharedPtr<FExtender> ToolbarExtender = MakeShareable(new FExtender);
		ToolbarExtender->AddToolBarExtension("Settings", EExtensionHook::After, PluginCommands, FToolBarExtensionDelegate::CreateRaw(this, &FNexty_PluginModule::AddToolbarExtension));
		
		LevelEditorModule.GetToolBarExtensibilityManager()->AddExtender(ToolbarExtender);
	}
	
	FGlobalTabmanager::Get()->RegisterNomadTabSpawner(Nexty_PluginTabName, FOnSpawnTab::CreateRaw(this, &FNexty_PluginModule::OnSpawnPluginTab))
		.SetDisplayName(LOCTEXT("FNexty_PluginTabTitle", "Nexty_Plugin"))
		.SetMenuType(ETabSpawnerMenuType::Hidden);
}

void FNexty_PluginModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	FNexty_PluginStyle::Shutdown();

	FNexty_PluginCommands::Unregister();

	FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(Nexty_PluginTabName);
}

TSharedRef<SDockTab> FNexty_PluginModule::OnSpawnPluginTab(const FSpawnTabArgs& SpawnTabArgs)
{
	FText WidgetText = FText::Format(
		LOCTEXT("NextyPlugin", "This Plugin is tested to see if the {0} can be applied to the {1}."),
		FText::FromString(TEXT("Open Street map")),
		FText::FromString(TEXT("Nexty_Project"))
		);

	return SNew(SDockTab)
		.TabRole(ETabRole::NomadTab)
		[
			// Put your tab content here!
			SNew(SBox)
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Center)
			[
				SNew(STextBlock)
				.Text(WidgetText)
			]
		];
}

void FNexty_PluginModule::PluginButtonClicked()
{
	FGlobalTabmanager::Get()->InvokeTab(Nexty_PluginTabName);
}

void FNexty_PluginModule::AddMenuExtension(FMenuBuilder& Builder)
{
	Builder.AddMenuEntry(FNexty_PluginCommands::Get().OpenPluginWindow);
}

void FNexty_PluginModule::AddToolbarExtension(FToolBarBuilder& Builder)
{
	Builder.AddToolBarButton(FNexty_PluginCommands::Get().OpenPluginWindow);
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FNexty_PluginModule, Nexty_Plugin)