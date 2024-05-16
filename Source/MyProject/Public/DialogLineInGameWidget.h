// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DialogLineInGameWidget.generated.h"

class UTextBlock;
class UButton;
/**
 * 
 */
UCLASS()
class MYPROJECT_API UDialogLineInGameWidget : public UUserWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(meta = (BindWidget))
		UButton* AnswerButton;

	UPROPERTY(meta = (BindWidget))
		UTextBlock* AnswerTextBlock;
};
