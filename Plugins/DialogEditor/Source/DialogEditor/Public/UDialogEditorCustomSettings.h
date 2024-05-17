// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DialogEditorDataAsset.h"
#include "UObject/NoExportTypes.h"
#include "UDialogEditorCustomSettings.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, config = EditorPerProjectUserSettings)
class DIALOGEDITOR_API UUDialogEditorCustomSettings : public UObject
{
	GENERATED_BODY()

public:
	void Save();

	UDialogEditorDataAsset* GetDialogEditorDataAsset() const { return DialogEditorDataAsset; }

private:
	UPROPERTY(EditAnywhere, Category = "Dialog Assets")
	UDialogEditorDataAsset* DialogEditorDataAsset;

	UPROPERTY(EditAnywhere, Category = "Dialog Assets")
	UTexture2D* InGameBackground;
};
