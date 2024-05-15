// Fill out your copyright notice in the Description page of Project Settings.


#include "DialogAssetBlueprintFactory.h"

#include "DialogCreatorSubsystem.h"

UObject* UDialogAssetBlueprintFactory::FactoryCreateFile(UClass* InClass, UObject* InParent, FName InName,
                                                         EObjectFlags Flags, const FString& Filename, const TCHAR* Parms, FFeedbackContext* Warn,
                                                         bool& bOutOperationCanceled)
{

	UDataTable* NewAsset = NewObject<UDataTable>(InParent, InClass, InName, Flags);
	NewAsset->RowStruct = FQuestionDialogData::StaticStruct();

	bOutOperationCanceled = false;

	return NewAsset;
}
