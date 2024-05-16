// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InGameDialogWidget.generated.h"

class UDialogData;
class UVerticalBox;
class UTextBlock;
/**
 * 
 */
UCLASS()
class MYPROJECT_API UInGameDialogWidget : public UUserWidget
{
	GENERATED_BODY()


protected:
	UPROPERTY(EditDefaultsOnly, Category = "Dialog")
		UDialogData* DialogToPlay;
private:
	UPROPERTY(meta = (BindWidget))
		UTextBlock* DialogTextBox;

	UPROPERTY(meta = (BindWidget))
		UVerticalBox* AnswersVerticlaBox;

};
