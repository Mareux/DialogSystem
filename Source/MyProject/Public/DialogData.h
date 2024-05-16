// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DialogCreatorSubsystem.h"
#include "DialogData.generated.h"

/**
 * 
 */


UCLASS()
class MYPROJECT_API UDialogData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
	TMap<int, FText> Questions;

	UPROPERTY(EditDefaultsOnly)
	TArray<FAnswerData> Answers;
};
