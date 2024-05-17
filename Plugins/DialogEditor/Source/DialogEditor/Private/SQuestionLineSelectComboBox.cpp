// Fill out your copyright notice in the Description page of Project Settings.


#include "SQuestionLineSelectComboBox.h"

#include "DialogEditorDataAsset.h"
#include "Widgets/Input/SComboBox.h"

#define LOCTEXT_NAMESPACE "SQuestionLineSelectComboBox"

void SQuestionLineSelectComboBox::Construct(const FArguments& InArgs)
{

	Options = InArgs._Options;
	FSelectionChanged = InArgs._OnSelectionChanged;

	if (Options.IsValid() && !Options.Pin().Get()->IsEmpty())
	{
		CurrentItem = *Options.Pin().Get()->begin();
	}

	ChildSlot
		[
			SAssignNew(ComboBox, SComboBox<FComboItemType>)
			.OptionsSource(Options.Pin().Get())
			.OnSelectionChanged(this, &SQuestionLineSelectComboBox::OnComboBoxSelectionChanged)
			.OnGenerateWidget(this, &SQuestionLineSelectComboBox::MakeWidgetForOption)
			.InitiallySelectedItem(CurrentItem)
			[
				SNew(STextBlock)
				.Text(this, &SQuestionLineSelectComboBox::GetCurrentItemLabel)
			]
		];
}

void SQuestionLineSelectComboBox::OnComboBoxSelectionChanged(const FComboItemType NewValue, ESelectInfo::Type)
{
	CurrentItem = NewValue;
	if (FSelectionChanged.IsBound())
	{
		FSelectionChanged.Execute(NewValue);
	}
}

TSharedRef<SWidget> SQuestionLineSelectComboBox::MakeWidgetForOption(FComboItemType InOption)
{
	return SNew(STextBlock).Text(FText::FromString(InOption->QuestionText.ToString()));

}

FText SQuestionLineSelectComboBox::GetCurrentItemLabel() const
{
	if (CurrentItem.IsValid()) {
		return FText::FromString(CurrentItem->QuestionText.ToString());
	}

	return LOCTEXT("InvalidComboEntryText", "<<Invalid option>>");
}

void SQuestionLineSelectComboBox::RefreshOptions()
{
	ComboBox->RefreshOptions();
}

SQuestionLineSelectComboBox::FComboItemType SQuestionLineSelectComboBox::GetCurrentItem()
{
	return ComboBox->GetSelectedItem();
}

void SQuestionLineSelectComboBox::SetSelectedItem(FComboItemType NewItem)
{
	ComboBox->SetSelectedItem(NewItem);
}

void SQuestionLineSelectComboBox::SetDelegateForSelectionChange(const FOnQuestionLineSelectSelectionChanged& Callback)
{
	FSelectionChanged = Callback;
}

#undef LOCTEXT_NAMESPACE

