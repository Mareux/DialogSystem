// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DialogEditorDataAsset.generated.h"

/**
 * 
 */
USTRUCT()
struct FDialogEditorQuestionData
{
	GENERATED_BODY()

	UPROPERTY(VisibleDefaultsOnly)
	int Id;

	UPROPERTY(VisibleDefaultsOnly)
	FText QuestionText;

	bool operator==(const int QuestionId) const { return QuestionId == Id; }
};

USTRUCT()
struct FDialogEditorAnswerData {
	GENERATED_BODY()

	UPROPERTY(VisibleDefaultsOnly)
		int Id;

	UPROPERTY(VisibleDefaultsOnly)
		FText AnswerText;

	UPROPERTY(VisibleDefaultsOnly)
		int CurrentQuestionId;

	UPROPERTY(VisibleDefaultsOnly)
		int NextQuestionId;

	bool operator==(const int QuestionId) const { return QuestionId == CurrentQuestionId; }
};

UCLASS()
class DIALOGEDITOR_API UDialogEditorDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	const TArray<FDialogEditorQuestionData>& LoadQuestionData() { return QuestionDialogEditorData; }

	const TArray<FDialogEditorAnswerData>& LoadAnswerData() { return AnswerDialogEditorData;  }

	void UpdateQuestionData(const TSharedPtr<TArray<TSharedPtr<FDialogEditorQuestionData>>>& QuestionData);

	void UpdateAnswerData(TMap<int, TSharedPtr<TArray<FDialogEditorAnswerData>>> AnswerData);

private:
	UPROPERTY(VisibleDefaultsOnly)
		TArray<FDialogEditorQuestionData> QuestionDialogEditorData;

	UPROPERTY(VisibleDefaultsOnly)
		TArray<FDialogEditorAnswerData> AnswerDialogEditorData;
	
};
