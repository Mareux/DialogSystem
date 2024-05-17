// Fill out your copyright notice in the Description page of Project Settings.


#include "DialogEditorDataAsset.h"

void UDialogEditorDataAsset::UpdateQuestionData(
	const TSharedPtr<TArray<TSharedPtr<FDialogEditorQuestionData>>>& QuestionData)
{
	QuestionDialogEditorData.Empty();
	TArray<TSharedPtr<FDialogEditorQuestionData>> Data = *QuestionData;
	for (auto Element : Data)
	{
		QuestionDialogEditorData.Add(*Element);
	}
}

void UDialogEditorDataAsset::UpdateAnswerData(TMap<int, TSharedPtr<TArray<FDialogEditorAnswerData>>> AnswerData)
{
	AnswerDialogEditorData.Empty();
	for (auto Question : AnswerData)
	{
		if (Question.Value)
		{
			const TArray<FDialogEditorAnswerData> Data = *Question.Value;
			for (auto Element : Data)
			{
				AnswerDialogEditorData.Add(Element);
				
			}
		}
	}
}
