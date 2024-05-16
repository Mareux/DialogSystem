// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */

class UUDialogEditorCustomSettings;

struct FAnswerData {

		UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
		FText Text;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
		int IdAnswer;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
		int IdQuestionNext;

	bool operator==(const int& Id) const { return IdAnswer == Id; }
};

class DIALOGEDITOR_API UDialogEditorSubsystem
{
public:

	static TSharedPtr<UDialogEditorSubsystem> GeInstance() {
		static TSharedPtr<UDialogEditorSubsystem> Instance = MakeShareable(new UDialogEditorSubsystem());
		return Instance;
	}

	UDialogEditorSubsystem(UDialogEditorSubsystem const&) = delete;
	void operator=(UDialogEditorSubsystem const&) = delete;
private:
	UDialogEditorSubsystem() { Questions = MakeShareable(new TMap<int, FText>()); };

public:

	void AddQuestionLine(const FText& Question);

	int AddAnswerLine(const FText Answer, const int CurrentQuestionId, const int NextQuestionId);

	void UpdateAnswerLine(const FText Answer, const int CurrentQuestionId, const int NextQuestionId, const int64 Id);

	void UpdateAnswerIndex(const int CurrentIndex, const int NewIndex);

	TSharedPtr<TMap<int, FText>> GetQuestions() const;

	int GetQuestionsLastIndex() const { return Questions->Num() - 1; }

	TArray<FAnswerData>& GetAnswerArrayForIndex(const int QuestionIndex);

	TSharedPtr <UUDialogEditorCustomSettings> CustomSettings;

private:
	TSharedPtr<TMap<int, FText>>  Questions;

	TMap<int, TArray<FAnswerData>> Answers;

};
