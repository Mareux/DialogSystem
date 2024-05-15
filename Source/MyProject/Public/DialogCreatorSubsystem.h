// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "DialogCreatorSubsystem.generated.h"

/**
 * 
 */

class UDataTable;


USTRUCT(BlueprintType)
struct FQuestionDialogData : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	FText Text;

	UPROPERTY(EditDefaultsOnly)
	int IdQuestion;
};

USTRUCT(BlueprintType)
struct FAnswerDialogData : public FTableRowBase {
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	FText Text;

	UPROPERTY(EditDefaultsOnly)
	int QuestionCurrent;

	UPROPERTY(EditDefaultsOnly)
	int QuestionNext;
};

UCLASS()
class MYPROJECT_API UDialogCreatorSubsystem : public UEditorSubsystem
{
	GENERATED_BODY()
	
private:

	//UObject* CreateNewDialog(FText Name);
};
