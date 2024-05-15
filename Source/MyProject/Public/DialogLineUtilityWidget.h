// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EditorUtilityWidget.h"
#include "DialogLineUtilityWidget.generated.h"

class UEditorUtilityMultiLineEditableTextBox;
/**
 * 
 */


UCLASS(Abstract, meta = (ShowWorldContextPin), Config = Editor)
class MYPROJECT_API UDialogLineUtilityWidget : public UEditorUtilityWidget
{
	GENERATED_BODY()

public:
	virtual bool IsEditorUtility() const override { return true; }
	

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UEditorUtilityMultiLineEditableTextBox* AnswerInputField;
};
