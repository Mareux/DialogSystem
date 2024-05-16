// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class DIALOGEDITOR_API SAnswerLineEditWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SAnswerLineEditWidget) { }
	SLATE_ARGUMENT(int32, QuestionID)
	SLATE_ARGUMENT(int8, AnswerID)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

	virtual bool SupportsKeyboardFocus() const override { return true; }

private:
	int32 QuestionID;
	int8 AnswerID;
};
