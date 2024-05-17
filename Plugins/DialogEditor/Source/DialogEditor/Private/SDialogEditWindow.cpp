// Fill out your copyright notice in the Description page of Project Settings.


#include "SDialogEditWindow.h"

#include "SAnswerLineEditWidget.h"
#include "SQuestionLineSelectComboBox.h"

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
	const FText SaveButtonText = LOCTEXT("FSaveButtonText", "Save");
	const FText LoadButtonText = LOCTEXT("FLoadButtonText", "Load");

	DialogCustomSetting = InArgs._DialogCustomSetting;
	SettingsWidget = InArgs._SettingsWidget;
	QuestionOptions = MakeShareable(new TArray < TSharedPtr<FDialogEditorQuestionData>>());

	// first panel
	ChildSlot[

		SNew(SGridPanel)
			+ SGridPanel::Slot(2, 1)
			[
				SNew(SGridPanel)
				+ SGridPanel::Slot(2, 1)
				[
					SAssignNew(AnswersScrollBox, SScrollBox)
				]
				+ SGridPanel::Slot(1, 1)
				[
					SNew(SGridPanel)
					+ SGridPanel::Slot(1, 1)
					[
					SNew(STextBlock)
					.Text(AnswerHelperTest)
					]
					+ SGridPanel::Slot(2, 1)
					[
						SNew(SButton)
						.OnClicked(this, &SDialogEditWindow::OnAddAnswerButtonClicked)
						[
							SNew(STextBlock).
							Text(AddAnswerButtonText)
						]
					]
				]
			]

		//second panel
		+ SGridPanel::Slot(1, 1)
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
			[
				SAssignNew(ComboBox, SQuestionLineSelectComboBox)
				.Options(QuestionOptions)
				.OnSelectionChanged(this, &SDialogEditWindow::OnComboBoxSelectionChanged)
			]
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
		+ SGridPanel::Slot(1, 2)[
			SNew(SGridPanel)
				+ SGridPanel::Slot(1, 1)
				[
					SettingsWidget.Pin().ToSharedRef()
				]
				+ SGridPanel::Slot(2, 2)
				[
					SNew(SButton)
					.OnClicked(this, &SDialogEditWindow::OnSaveButtonClicked)
					[
						SNew(STextBlock)
						.Text(SaveButtonText)
					]
				]
				+ SGridPanel::Slot(3, 2)
				[
					SNew(SButton)
					.OnClicked(this, &SDialogEditWindow::OnLoadButtonClicked)
					[
						SNew(STextBlock)
						.Text(LoadButtonText)
					]
				]
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
		QuestionInput.Get()->SetText(FText::GetEmpty());


		FDialogEditorQuestionData NewData;
		NewData.Id = 0;
		if (QuestionOptions)
		{
			NewData.Id = QuestionOptions->Num();
		}
		NewData.QuestionText = QuestionText;
		QuestionOptions->Add(MakeShareable(new FDialogEditorQuestionData(NewData)));


		ComboBox->SetSelectedItem((*QuestionOptions)[QuestionOptions->Num() - 1]);
		ComboBox->RefreshOptions();

	}

	return FReply::Handled();
}

FReply SDialogEditWindow::OnAddAnswerButtonClicked() const
{
	Answers.Add(ComboBox->GetCurrentItem()->Id, MakeShareable(new TArray<FDialogEditorAnswerData>()));

	AnswersScrollBox.Get()->AddSlot()[
		SNew(SAnswerLineEditWidget).Options(QuestionOptions).AnswerID(ComboBox->GetCurrentItem()->Id).QuestionID(ComboBox->GetCurrentItem()->Id)
			.AnswerArray(*Answers.Find(ComboBox->GetCurrentItem()->Id))
	];

	return FReply::Handled();

}

FReply SDialogEditWindow::OnSaveButtonClicked() const
{
	UDialogEditorDataAsset* DataAsset = nullptr;

	if (DialogCustomSetting)
	{
		DataAsset = DialogCustomSetting->GetDialogEditorDataAsset();
	}

	if (DataAsset)
	{
		DataAsset->UpdateQuestionData(QuestionOptions);
		DataAsset->UpdateAnswerData(Answers);
		DialogCustomSetting->Save();
	}

	return FReply::Handled();
}

FReply SDialogEditWindow::OnLoadButtonClicked() const
{
	UDialogEditorDataAsset* DataAsset = nullptr;

	if (DialogCustomSetting) {
		DataAsset = DialogCustomSetting->GetDialogEditorDataAsset();
	}

	if (DataAsset)
	{
		auto QuestionData = DataAsset->LoadQuestionData();
		for (auto Data : QuestionData)
		{
			QuestionOptions.Get()->Add(MakeShareable(new FDialogEditorQuestionData(Data)));
		}

		//auto& AnswerData = DataAsset->LoadQuestionData();

		ComboBox->RefreshOptions();
	}

	return FReply::Handled();
}

void SDialogEditWindow::OnComboBoxSelectionChanged(TSharedPtr<FDialogEditorQuestionData> NewItem)
{
	AnswersScrollBox->ClearChildren();
}

#undef LOCTEXT_NAMESPACE
