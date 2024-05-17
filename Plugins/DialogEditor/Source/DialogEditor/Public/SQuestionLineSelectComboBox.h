// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

struct FDialogEditorQuestionData;
/**
 * 
 */

class DIALOGEDITOR_API SQuestionLineSelectComboBox : public SCompoundWidget
{
typedef TSharedPtr<FDialogEditorQuestionData> FComboItemType;
DECLARE_DELEGATE_OneParam(
	FOnQuestionLineSelectSelectionChanged,
	/** param: The newly selected value */
	FComboItemType
)
public:
	using FQuestionMapType = TMap<int32, FText>;

	SLATE_BEGIN_ARGS(SQuestionLineSelectComboBox){}
	SLATE_ARGUMENT(TWeakPtr<TArray<FComboItemType>>, Options)
	SLATE_EVENT(FOnQuestionLineSelectSelectionChanged, OnSelectionChanged)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

	void OnComboBoxSelectionChanged(const FComboItemType NewValue, ESelectInfo::Type);
	TSharedRef<SWidget> MakeWidgetForOption(FComboItemType InOption);

	FText GetCurrentItemLabel() const;

	void RefreshOptions();
	FComboItemType GetCurrentItem();
	void SetSelectedItem(FComboItemType NewItem);

	void SetDelegateForSelectionChange(const FOnQuestionLineSelectSelectionChanged& Callback);

private:
	FQuestionMapType QuestionMap;

	FComboItemType CurrentItem;

	TWeakPtr<TArray<FComboItemType>> Options;

	TSharedPtr<SComboBox<FComboItemType>> ComboBox;

	FOnQuestionLineSelectSelectionChanged FSelectionChanged;

};
