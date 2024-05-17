// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class DIALOGEDITOR_API SAnswerLineEditWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SAnswerLineEditWidget) { }
	SLATE_ARGUMENT(int32, QuestionID)
	SLATE_ARGUMENT(int8, AnswerID)
	SLATE_ARGUMENT(TWeakPtr<TArray<TSharedPtr<FString>>>, Options)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

	void OnAnswerSelectionChanged(const TSharedPtr<FString> NewValue, ESelectInfo::Type);
	TSharedRef<SWidget> MakeWidgetForOption(TSharedPtr<FString> InOption);

	FText GetCurrentItemLabel() const;

	virtual bool SupportsKeyboardFocus() const override { return true; }

private:

	TSharedPtr<SEditableTextBox> AnswerInput;
	TWeakPtr<TArray<TSharedPtr<FString>>> Options;

	TSharedPtr<FString> CurrentItem;

	TSharedPtr<SComboBox<TSharedPtr<FString>>> QuestionsComboBox;

	int32 QuestionID;
	int8 AnswerID;
};
