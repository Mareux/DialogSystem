// Fill out your copyright notice in the Description page of Project Settings.


#include "UDialogEditorCustomSettings.h"

#include "AssetViewUtils.h"
#include "UObject/SavePackage.h"

void UUDialogEditorCustomSettings::Save()
{
	DialogEditorDataAsset->MarkPackageDirty();
	AssetViewUtils::SaveDirtyPackages();
}
