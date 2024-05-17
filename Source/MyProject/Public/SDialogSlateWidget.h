// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DialogEditorDataAsset.h"
#include "MyHUD.h"

/**
 * 
 */
class AMyHUD;

class MYPROJECT_API SDialogSlateWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SDialogSlateWidget) {}

	SLATE_ARGUMENT(TWeakObjectPtr<AMyHUD>, OwningHUD)
	SLATE_ARGUMENT(TWeakObjectPtr<UDialogEditorDataAsset>, DialogText)
	SLATE_ARGUMENT(TWeakObjectPtr<UTexture2D>, Background)

	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

	void OnButtonClicked(int id) ;

	virtual bool SupportsKeyboardFocus() const override { return true; }
private:
	TWeakObjectPtr<AMyHUD> OwningHUD;
	TWeakObjectPtr<UDialogEditorDataAsset> DialogText;
	TWeakObjectPtr<UTexture2D> Background;

	TSharedPtr<STextBlock> DialogTextBlock;
	TSharedPtr<SVerticalBox> AnswersVerticalBox;

	TArray<FDialogEditorQuestionData> QuestionData;
	TArray<FDialogEditorAnswerData> AnswerData;
	int QuestionId = 0;
	int FocusedButtonId = -1;
};

