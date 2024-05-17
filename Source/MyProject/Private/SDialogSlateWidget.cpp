// Fill out your copyright notice in the Description page of Project Settings.


#include "SDialogSlateWidget.h"

#include "SDialogButton.h"

#define LOCTEXT_NAMESPACE "DialogMenu"

void SDialogSlateWidget::Construct(const FArguments& InArgs) {

	DialogText = InArgs._DialogText;
	Background = InArgs._Background;

	const FText DialogMissingText = LOCTEXT("FDialogMissingText", "Dialog missing");

	FText QuestionText = DialogMissingText;
	if (DialogText.IsValid())
	{
		QuestionData = DialogText->LoadQuestionData();
		AnswerData = DialogText->LoadAnswerData();
		if (!QuestionData.IsEmpty())
		{
			QuestionText = QuestionData[0].QuestionText;
			QuestionId = 0;
			if (!AnswerData.IsEmpty())
			{
				for (auto& Answer : AnswerData)
				{
					if (Answer == QuestionId)
					{
						FocusedButtonId = 0;
						AnswersVerticalBox = SNew(SVerticalBox);
						AnswersVerticalBox.Get()->AddSlot()[
							SNew(SDialogButton)
								.AnswerData(MakeShareable(new FDialogEditorAnswerData(Answer)))
								.OnClicked(this, &SDialogSlateWidget::OnButtonClicked)
						];
						
					}
				}
			}
		}
	}

	ChildSlot[
		SNew(SGridPanel)
			+ SGridPanel::Slot(1,1)
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Top)[
				SNew(SImage)
				.ColorAndOpacity(FColor::Green)
			]
			+ SGridPanel::Slot(1,2)
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Bottom)
			[
			SNew(SBorder)
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Fill)
				.Padding(0, 500, 0, 0)
				[
					SAssignNew(DialogTextBlock, STextBlock)
					.Text(QuestionText)
					
				]
			]
			+ SGridPanel::Slot(2, 2)[
				AnswersVerticalBox.ToSharedRef()
			]
			//+SOverlay::Slot()
			//	.HAlign(HAlign_Fill)
			//	.VAlign(VAlign_Fill)
			//	.ZOrder(1)
			//	.Padding(0, 500, 0, 0)
			//	[
			//		SNew(SImage)
			//		.ColorAndOpacity(FColor::Blue)
			//	]
			//+SOverlay::Slot()
			//.HAlign(HAlign_Right)
			//.VAlign(VAlign_Center)
			//.ZOrder(3)[
			//]
	];
}

void SDialogSlateWidget::OnButtonClicked(int id) 
{
	const auto QuestionNext = QuestionData.FindByKey(id);
	QuestionId = id;
	if (QuestionNext)
	{
		DialogTextBlock->SetText(QuestionNext->QuestionText);
		AnswersVerticalBox->ClearChildren();

		for (auto& Answer : AnswerData) {
			if (Answer == QuestionId) {
				AnswersVerticalBox.Get()->AddSlot()[
					SNew(SDialogButton)
						.AnswerData(MakeShareable(new FDialogEditorAnswerData(Answer)))
						.OnClicked(this, &SDialogSlateWidget::OnButtonClicked)
				];

			}
		}
	}
}

#undef LOCTEXT_NAMESPACE
