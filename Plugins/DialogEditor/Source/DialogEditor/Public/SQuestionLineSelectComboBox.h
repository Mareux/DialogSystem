// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SlateBasics.h"
#include "SlateExtras.h"

/**
 * 
 */
class DIALOGEDITOR_API SQuestionLineSelectComboBox : public SCompoundWidget
{
public:
	using FQuestionMapType = TMap<int32, FText>;
	typedef TSharedPtr<FString> FComboItemType;

	SLATE_BEGIN_ARGS(SQuestionLineSelectComboBox){}
	SLATE_ARGUMENT(FQuestionMapType, QuestionMap)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

	void OnSelectionChanged(const FComboItemType& NewValue, ESelectInfo::Type);
	TSharedRef<SWidget> MakeWidgetForOption(FComboItemType InOption, ESelectInfo::Type);

	FText GetCurrentItemLabel() const;

private:
	FQuestionMapType QuestionMap;

	FComboItemType CurrentItem;

	TArray<FComboItemType> Options;

};
