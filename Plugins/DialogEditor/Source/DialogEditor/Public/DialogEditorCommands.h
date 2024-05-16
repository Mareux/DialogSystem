// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "DialogEditorStyle.h"

class FDialogEditorCommands : public TCommands<FDialogEditorCommands>
{
public:

	FDialogEditorCommands()
		: TCommands<FDialogEditorCommands>(TEXT("DialogEditor"), NSLOCTEXT("Contexts", "DialogEditor", "DialogEditor Plugin"), NAME_None, FDialogEditorStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > PluginAction;
};
