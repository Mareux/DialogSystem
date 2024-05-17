// Fill out your copyright notice in the Description page of Project Settings.


#include "SAnswerLineEditWidget.h"
#include "SQuestionLineSelectComboBox.h"

#define LOCTEXT_NAMESPACE "FDialogEditorModule"

void SAnswerLineEditWidget::Construct(const FArguments& InArgs)
{
	QuestionID = InArgs._QuestionID;
	AnswerID = InArgs._AnswerID;
	Options = InArgs._Options;
	AnswerArray = InArgs._AnswerArray;

	const FText AnswerInputHint = LOCTEXT("FAnswerInputHint", "Input answer here:");
	const FText AnswerSaveOrEditButtonText = LOCTEXT("FAnswerSaveOrEditButtonText", "Save answer");


	ChildSlot[
		SNew(SHorizontalBox)
		+ SHorizontalBox::Slot()
		[
			SAssignNew(AnswerInput, SEditableTextBox)
			.HintText(AnswerInputHint)
		]
		+SHorizontalBox::Slot()
		[
			SAssignNew(QuestionsComboBox, SQuestionLineSelectComboBox)
			.Options(Options)
		]
		+SHorizontalBox::Slot()
		[
			SNew(SButton)
			.OnClicked(this, &SAnswerLineEditWidget::OnButtonClicked)
			[
				SNew(STextBlock)
				.Text(AnswerSaveOrEditButtonText)
			]
		]
			
	];
}

FReply SAnswerLineEditWidget::OnButtonClicked() const
{
	const FDialogEditorQuestionData QuestionData = *QuestionsComboBox->GetCurrentItem();
	FDialogEditorAnswerData NewData;
	NewData.Id = AnswerID;
	NewData.NextQuestionId = QuestionData.Id;
	NewData.CurrentQuestionId = QuestionID;
	NewData.AnswerText = AnswerInput.Get()->GetText();
	AnswerArray.Pin().Get()->Add(NewData);

	return FReply::Handled();
}

#undef LOCTEXT_NAMESPACE
