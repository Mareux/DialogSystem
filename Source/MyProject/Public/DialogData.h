// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DialogData.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FAnswerData 
{
	GENERATED_BODY()

	FText Text;

	int IdQuestionNext;
};

UCLASS()
class MYPROJECT_API UDialogData : public UDataAsset
{
	GENERATED_BODY()

	UPROPERTY()
		TMap<int, FText> Questions;

	UPROPERTY()
		TMap<int, FAnswerData> Answers;
};
