// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "DialogEditorDataAsset.h"
#include "CoreMinimal.h"

/**
 * 
 */

class SQuestionLineSelectComboBox;

class DIALOGEDITOR_API SAnswerLineEditWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SAnswerLineEditWidget) { }
	SLATE_ARGUMENT(int32, QuestionID)
	SLATE_ARGUMENT(int8, AnswerID)
	SLATE_ARGUMENT(TWeakPtr<TArray<TSharedPtr<FDialogEditorQuestionData>>>, Options)
	SLATE_ARGUMENT(TWeakPtr<TArray<FDialogEditorAnswerData>>, AnswerArray)

	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

	FReply OnButtonClicked() const;

	virtual bool SupportsKeyboardFocus() const override { return true; }

private:

	TSharedPtr<SEditableTextBox> AnswerInput;
	TWeakPtr<TArray<TSharedPtr<FDialogEditorQuestionData>>> Options;
	TWeakPtr<TArray<FDialogEditorAnswerData>> AnswerArray;

	TSharedPtr<FString> CurrentItem;

	TSharedPtr<SQuestionLineSelectComboBox> QuestionsComboBox;

	int32 QuestionID = 0;
	int8 AnswerID = 0;
};
