// Copyright Epic Games, Inc. All Rights Reserved.

#include "DialogEditor.h"
#include "DialogEditorStyle.h"
#include "DialogEditorCommands.h"
#include "SDialogEditWindow.h"
#include "Misc/MessageDialog.h"
#include "ToolMenus.h"
#include "UDialogEditorCustomSettings.h"


static const FName DialogEditorTabName("DialogEditor");

static const FName TestWindowTabName("TestWindow");

#define LOCTEXT_NAMESPACE "FDialogEditorModule"

void FDialogEditorModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
	FDialogEditorStyle::Initialize();
	FDialogEditorStyle::ReloadTextures();

	FDialogEditorCommands::Register();
	
	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FDialogEditorCommands::Get().PluginAction,
		FExecuteAction::CreateRaw(this, &FDialogEditorModule::PluginButtonClicked),
		FCanExecuteAction());

	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FDialogEditorModule::RegisterMenus));

	FGlobalTabmanager::Get()->RegisterNomadTabSpawner(TestWindowTabName, FOnSpawnTab::CreateRaw(this, &FDialogEditorModule::OnSpawnPluginTab))
		.SetDisplayName(LOCTEXT("FDialogEditorWindow", "Dialog Editor"))
		.SetMenuType(ETabSpawnerMenuType::Hidden);

}

void FDialogEditorModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	UToolMenus::UnRegisterStartupCallback(this);

	UToolMenus::UnregisterOwner(this);

	FDialogEditorStyle::Shutdown();

	FDialogEditorCommands::Unregister();
	FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(TestWindowTabName);
}

TSharedRef<SDockTab> FDialogEditorModule::OnSpawnPluginTab(const FSpawnTabArgs& SpawnTabArgs) {

	const FText SaveButtonText = LOCTEXT("FSaveButtonText", "Save");
	FPropertyEditorModule& PropertyModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");

	//FDetailsViewArgs is a struct of settings to customize our Details View Widget
	FDetailsViewArgs Args;
	Args.bHideSelectionTip = true;

	//Create the widget and store it in the PropertyWidget pointer
	PropertyWidget = PropertyModule.CreateDetailView(Args);


	if (!CustomSettings)
	{
		CustomSettings = MakeShareable(GetMutableDefault<UUDialogEditorCustomSettings>());
	}
	PropertyWidget->SetObject(CustomSettings.Get());

	//UDialogEditorSubsystem::GeInstance()->CustomSettings = 



	return SNew(SDockTab)
		.TabRole(ETabRole::NomadTab)
		[
			SNew(SGridPanel)
			+ SGridPanel::Slot(1, 1)[
				SNew(SDialogEditWindow).DialogCustomSetting(CustomSettings)
			]
			+ SGridPanel::Slot(2, 1)[
				SNew(SGridPanel)
				+ SGridPanel::Slot(1, 1)[
					PropertyWidget.ToSharedRef()
				]
				+ SGridPanel::Slot(1, 2)[
					SNew(SButton)
					[
						SNew(STextBlock)
						.Text(SaveButtonText)
					]
				]

			]
		];
}

void FDialogEditorModule::PluginButtonClicked()
{
	FGlobalTabmanager::Get()->TryInvokeTab(TestWindowTabName);
}

FReply FDialogEditorModule::OnSaveButtonClicked() const
{
	return FReply::Handled();
}


void FDialogEditorModule::RegisterMenus()
{
	// Owner will be used for cleanup in call to UToolMenus::UnregisterOwner
	FToolMenuOwnerScoped OwnerScoped(this);

	{
		UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Window");
		{
			FToolMenuSection& Section = Menu->FindOrAddSection("WindowLayout");
			Section.AddMenuEntryWithCommandList(FDialogEditorCommands::Get().PluginAction, PluginCommands);
		}
	}

	{
		UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar.PlayToolBar");
		{
			FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("PluginTools");
			{
				FToolMenuEntry& Entry = Section.AddEntry(FToolMenuEntry::InitToolBarButton(FDialogEditorCommands::Get().PluginAction));
				Entry.SetCommandList(PluginCommands);
			}
		}
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FDialogEditorModule, DialogEditor)