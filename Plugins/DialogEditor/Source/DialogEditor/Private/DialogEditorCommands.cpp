// Copyright Epic Games, Inc. All Rights Reserved.

#include "DialogEditorCommands.h"

#define LOCTEXT_NAMESPACE "FDialogEditorModule"

void FDialogEditorCommands::RegisterCommands()
{
	UI_COMMAND(PluginAction, "DialogEditor", "Execute DialogEditor action", EUserInterfaceActionType::Button, FInputChord());
}

#undef LOCTEXT_NAMESPACE
