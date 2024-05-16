// Fill out your copyright notice in the Description page of Project Settings.


#include "SQuestionLineSelectComboBox.h"
#include "Widgets/Input/SComboBox.h"

#define LOCTEXT_NAMESPACE "SQuestionLineSelectComboBox"

void SQuestionLineSelectComboBox::Construct(const FArguments& InArgs)
{

	QuestionMap = InArgs._QuestionMap;

	for (auto Question : QuestionMap)
	{
		Options.Add(MakeShareable(new FString( Question.Value.ToString())));
	}

	CurrentItem = Options[0];


	ChildSlot
		[
			SNew(SComboBox<FComboItemType>)
			.OptionsSource(&Options)
			//.OnSelectionChanged (this, &SQuestionLineSelectComboBox::OnSelectionChanged)
			//.OnGenerateWidget(this, &SQuestionLineSelectComboBox::MakeWidgetForOption)
			.InitiallySelectedItem(CurrentItem)
			[
				SNew(STextBlock)
				.Text(this, &SQuestionLineSelectComboBox::GetCurrentItemLabel)
			]
		];
}

TSharedRef<SWidget> SQuestionLineSelectComboBox::MakeWidgetForOption(FComboItemType InOption, ESelectInfo::Type)
{
	return SNew(STextBlock).Text(FText::FromString(*InOption));

}

void SQuestionLineSelectComboBox::OnSelectionChanged(const FComboItemType& NewValue, ESelectInfo::Type)
{
	CurrentItem = NewValue;
}

FText SQuestionLineSelectComboBox::GetCurrentItemLabel() const
{
	if (CurrentItem.IsValid()) {
		return FText::FromString(*CurrentItem);
	}

	return LOCTEXT("InvalidComboEntryText", "<<Invalid option>>");
}

#undef LOCTEXT_NAMESPACE

