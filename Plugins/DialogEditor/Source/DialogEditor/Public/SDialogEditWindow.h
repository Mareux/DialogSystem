// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UDialogEditorCustomSettings.h"

class SQuestionLineSelectComboBox;
class UUDialogEditorCustomSettings;
/**
 * 
 */
class DIALOGEDITOR_API SDialogEditWindow : public SCompoundWidget
{
public:

	SLATE_BEGIN_ARGS(SDialogEditWindow) { }
	SLATE_ARGUMENT(UUDialogEditorCustomSettings*, DialogCustomSetting)
	SLATE_ARGUMENT(TWeakPtr<IDetailsView>, SettingsWidget)

	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

	virtual bool SupportsKeyboardFocus() const override { return true; }

	FReply OnAddQuestionButtonClicked() const;

	FReply OnAddAnswerButtonClicked() const;
	FReply OnSaveButtonClicked() const;
	FReply OnLoadButtonClicked() const;

	void OnComboBoxSelectionChanged(TSharedPtr<FDialogEditorQuestionData> NewItem);

private:
	UUDialogEditorCustomSettings* DialogCustomSetting = nullptr;
	TWeakPtr<IDetailsView> SettingsWidget;

	TSharedPtr<SEditableTextBox> QuestionInput;
	TSharedPtr<SEditableTextBox> QuestionEdit;

	//TSharedPtr<SComboBox<TSharedPtr<FString>>> QuestionsComboBox;
	TSharedPtr<SQuestionLineSelectComboBox> ComboBox;

	TSharedPtr<SScrollBox> AnswersScrollBox;

	TSharedPtr<FString> CurrentItem;
	TSharedPtr<TArray<TSharedPtr<FDialogEditorQuestionData>>> QuestionOptions;
	mutable TMap<int, TSharedPtr<TArray<FDialogEditorAnswerData>>> Answers;

	FString FDefaultComboBoxText = "None";



};
