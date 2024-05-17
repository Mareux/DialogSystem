// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DialogEditorDataAsset.h"

/**
 * 
 */
class DIALOGEDITOR_API SDialogButton : public SCompoundWidget
{
	DECLARE_DELEGATE_OneParam(FOnButtonClicked, int)

public:
	SLATE_BEGIN_ARGS(SDialogButton) { }

	SLATE_ARGUMENT(TSharedPtr<FDialogEditorAnswerData> , AnswerData)
	SLATE_EVENT(FOnButtonClicked, OnClicked)

	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

	FReply OnButtonClicked() const;

	virtual bool SupportsKeyboardFocus() const override { return true; }

private:
	TSharedPtr<FDialogEditorAnswerData> AnswerData;

	FOnButtonClicked OnButtonClickedDelegate;
};
