// Fill out your copyright notice in the Description page of Project Settings.


#include "SDialogEditWindow.h"

#include "DialogEditorSubsystem.h"

#define LOCTEXT_NAMESPACE "FDialogEditorModule"


void SDialogEditWindow::Construct(const FArguments& InArgs) {
	const FText AnswerHelperTest = LOCTEXT("FAnswerHelperTest", "Add answers to selected question:");
	const FText AddAnswerButtonText = LOCTEXT("FAddAnswerButtonText", "Add new answer");
	const FText AddQuestionButtonText = LOCTEXT("FAddQuestionButtonText", "Add new question");
	const FText EditQuestionButtonText = LOCTEXT("FEditQuestionButtonText", "Edit question");
	const FText RemoveQuestionButtonText = LOCTEXT("FRemoveQuestionButtonText", "Remove question");
	const FText InputNewDialogHelperText = LOCTEXT("FInputNewDialogHelperText", "Input new dialog question here:");
	const FText SelectNewQuestionHelperText = LOCTEXT("FSelectNewQuestionHelperText", "Select question to add answer for");
	const FText InputHint = LOCTEXT("InputHint", "Input question here:");

	// first panel
	ChildSlot[

		SNew(SGridPanel)
			+ SGridPanel::Slot(1, 1)
			[
				SNew(SGridPanel)
				+ SGridPanel::Slot(2, 1)
			[
				SNew(SScrollBox)
			]
		+ SGridPanel::Slot(1, 1)
			[
				SNew(SGridPanel)
				+ SGridPanel::Slot(1, 1)
			[
				SNew(STextBlock)
				.Text(AnswerHelperTest)
			]
		+ SGridPanel::Slot(1, 2)
			[
				SNew(SButton)
				[
					SNew(STextBlock).
					Text(AddAnswerButtonText)
				]
			]
			]
			]

		//second panel
		+ SGridPanel::Slot(1, 2)
			[
				SNew(SGridPanel)
				+ SGridPanel::Slot(1, 1)
			[
				SNew(SGridPanel)
				+ SGridPanel::Slot(1, 1)
			[
				SNew(STextBlock)
				.Text(InputNewDialogHelperText)
			]
		+ SGridPanel::Slot(1, 2)
			[
				SAssignNew(QuestionInput, SEditableTextBox)
				.HintText(InputHint)
			]
		+ SGridPanel::Slot(2, 2)
			[
				SNew(SButton)
				.OnClicked(this, &SDialogEditWindow::OnAddQuestionButtonClicked)
			[
				SNew(STextBlock)
				.Text(AddQuestionButtonText)
			]
			]
		+ SGridPanel::Slot(1, 3)
			[
				SNew(STextBlock)
				.Text(SelectNewQuestionHelperText)
			]
		+ SGridPanel::Slot(1, 4)
			//combo box
			+ SGridPanel::Slot(1, 5)
			[
				SAssignNew(QuestionEdit, SEditableTextBox)
			]
		+ SGridPanel::Slot(2, 6)
			[
				SNew(SButton)
				[
					SNew(STextBlock)
					.Text(EditQuestionButtonText)
				]
			]
		+ SGridPanel::Slot(3, 6)
			[
				SNew(SButton)
				[
					SNew(STextBlock)
					.Text(RemoveQuestionButtonText)
				]
			]

			]
		// THIRD panel
		+ SGridPanel::Slot(2, 1)[
			SNew(SGridPanel)
				//TODO:LATER
				//+ SGridPanel::Slot(1, 1)
				//[
				//	//SDetailsView
				//]
				// save & load button
		]
			]
	];

}

FReply SDialogEditWindow::OnAddQuestionButtonClicked() const {
	const FText QuestionText = QuestionInput.Get()->GetText();
	if (QuestionText.IsEmpty()) {
		QuestionInput.Get()->SetColorAndOpacity(FColor::Red);
	} else {
		QuestionInput.Get()->SetColorAndOpacity(FColor::White);
		QuestionEdit.Get()->SetText(QuestionText);
		QuestionInput.Get()->ClearContent();
		UDialogEditorSubsystem::GeInstance()->AddQuestionLine(QuestionText);
	}

	return FReply::Handled();
}


#undef LOCTEXT_NAMESPACE
