// Fill out your copyright notice in the Description page of Project Settings.


#include "SDialogButton.h"

void SDialogButton::Construct(const FArguments& InArgs)
{
	AnswerData = InArgs._AnswerData;
	OnButtonClickedDelegate = InArgs._OnClicked;

	ChildSlot[
		SNew(SButton)
			.OnClicked(this, &SDialogButton::OnButtonClicked)
			[
				SNew(STextBlock)
				.Text(AnswerData->AnswerText)
			]
	];
}

FReply SDialogButton::OnButtonClicked() const
{
	if (OnButtonClickedDelegate.IsBound())
	{
		OnButtonClickedDelegate.Execute(AnswerData->NextQuestionId);
	}

	return FReply::Handled();
}
