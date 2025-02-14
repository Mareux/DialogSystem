// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UDialogEditorCustomSettings.h"
#include "Modules/ModuleManager.h"

class UUDialogEditorCustomSettings;
class FToolBarBuilder;
class FMenuBuilder;

class FDialogEditorModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	
	/** This function will be bound to Command. */
	void PluginButtonClicked();

	FReply OnSaveButtonClicked() const;

private:

	void RegisterMenus();

	TSharedRef<class SDockTab> OnSpawnPluginTab(const class FSpawnTabArgs& SpawnTabArgs);

private:
	TSharedPtr<class FUICommandList> PluginCommands;
	TSharedPtr<class IDetailsView> PropertyWidget;
	UUDialogEditorCustomSettings* CustomSettings = nullptr;

};
