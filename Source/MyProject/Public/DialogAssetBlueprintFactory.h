// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/BlueprintFactory.h"
#include "DialogAssetBlueprintFactory.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API UDialogAssetBlueprintFactory : public UBlueprintFactory
{
	GENERATED_BODY()

	virtual UObject* FactoryCreateFile(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, const FString& Filename, const TCHAR* Parms, FFeedbackContext* Warn, bool& bOutOperationCanceled) override;
};
