// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class DIALOGEDITOR_API SDialogEditWindow : public SCompoundWidget
{
public:

	SLATE_BEGIN_ARGS(SDialogEditWindow) { }

	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

	virtual bool SupportsKeyboardFocus() const override { return true; }

	FReply OnAddQuestionButtonClicked() const;



private:
	TSharedPtr<SEditableTextBox> QuestionInput;
	TSharedPtr<SEditableTextBox> QuestionEdit;
};
