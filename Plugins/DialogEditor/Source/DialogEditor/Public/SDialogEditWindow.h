// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UDialogEditorCustomSettings.h"

class UUDialogEditorCustomSettings;
/**
 * 
 */
class DIALOGEDITOR_API SDialogEditWindow : public SCompoundWidget
{
public:

	SLATE_BEGIN_ARGS(SDialogEditWindow) { }
	SLATE_ARGUMENT(TWeakPtr<UUDialogEditorCustomSettings>, DialogCustomSetting)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

	virtual bool SupportsKeyboardFocus() const override { return true; }

	FReply OnAddQuestionButtonClicked() const;

	FReply OnAddAnswerButtonClicked() const;

	void OnAnswerSelectionChanged(const TSharedPtr<FString> NewValue, ESelectInfo::Type);
	TSharedRef<SWidget> MakeWidgetForOption(TSharedPtr<FString> InOption);

	FText GetCurrentItemLabel() const;

private:
	TWeakPtr<UUDialogEditorCustomSettings> DialogCustomSetting;

	TSharedPtr<SEditableTextBox> QuestionInput;
	TSharedPtr<SEditableTextBox> QuestionEdit;

	TSharedPtr<SComboBox<TSharedPtr<FString>>> QuestionsComboBox;

	TSharedPtr<SScrollBox> AnswersScrollBox;

	TSharedPtr<FString> CurrentItem;

	mutable TSharedPtr <TArray<TSharedPtr<FString>>> Options;

	FString FDefaultComboBoxText = "None";



};
