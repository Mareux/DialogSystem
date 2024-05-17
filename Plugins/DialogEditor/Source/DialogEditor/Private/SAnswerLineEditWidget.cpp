// Fill out your copyright notice in the Description page of Project Settings.


#include "SAnswerLineEditWidget.h"


#define LOCTEXT_NAMESPACE "FDialogEditorModule"

void SAnswerLineEditWidget::Construct(const FArguments& InArgs)
{
	QuestionID = InArgs._QuestionID;
	AnswerID = InArgs._AnswerID;
	Options = InArgs._Options;

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
			SAssignNew(QuestionsComboBox, SComboBox<TSharedPtr<FString>>)
			.OptionsSource(&*Options.Pin())
			.OnSelectionChanged(this, &SAnswerLineEditWidget::OnAnswerSelectionChanged)
			.OnGenerateWidget(this, &SAnswerLineEditWidget::MakeWidgetForOption)
			.InitiallySelectedItem(CurrentItem)
			[
				SNew(STextBlock)
				.Text(this, &SAnswerLineEditWidget::GetCurrentItemLabel)
			]
		]
		+SHorizontalBox::Slot()
		[
			SNew(SButton)
			[
				SNew(STextBlock)
				.Text(AnswerSaveOrEditButtonText)
			]
		]
			
	];
}


void SAnswerLineEditWidget::OnAnswerSelectionChanged(const TSharedPtr<FString> NewValue, ESelectInfo::Type) {
	CurrentItem = NewValue;
}

TSharedRef<SWidget> SAnswerLineEditWidget::MakeWidgetForOption(TSharedPtr<FString> InOption) {
	return SNew(STextBlock).Text(FText::FromString(*InOption));
}

FText SAnswerLineEditWidget::GetCurrentItemLabel() const {
	if (CurrentItem.IsValid()) {
		return FText::FromString(*CurrentItem);
	}

	return LOCTEXT("InvalidComboEntryText", "<<Invalid option>>");
}

#undef LOCTEXT_NAMESPACE
