// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "DialogCreatorSubsystem.generated.h"

/**
 * 
 */

class UEditorUtilityScrollBox;
class UEditorUtilityComboBoxString;
class UDataTable;
class UDialogLineUtilityWidget;

USTRUCT(BlueprintType)
struct FAnswerData {
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FText Text;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int IdAnswer;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int IdQuestionNext;

	bool operator==(const int& Id) const { return IdAnswer == Id;  }
};

USTRUCT(BlueprintType)
struct FQuestionDialogData : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FText Text;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int IdQuestion;
};

USTRUCT(BlueprintType)
struct FAnswerDialogData : public FTableRowBase {
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	FText Text;

	UPROPERTY(EditDefaultsOnly)
	int QuestionCurrent;

	UPROPERTY(EditDefaultsOnly)
	int QuestionNext;
};

UCLASS()
class MYPROJECT_API UDialogCreatorSubsystem : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable)
	void AddQuestionLine(FText Question);

	UFUNCTION(BlueprintCallable)
	int AddAnswerLine(const FText Answer, const int CurrentQuestionId, const int NextQuestionId);

	UFUNCTION(BlueprintCallable)
	void UpdateAnswerLine(const FText Answer, const int CurrentQuestionId, const int NextQuestionId, const int64 Id);

	void UpdateAnswerIndex(const int CurrentIndex, const int NewIndex);

	UFUNCTION(BlueprintCallable)
		void UpdateComboBox(UEditorUtilityComboBoxString* ComboBox) const;

	UFUNCTION(BlueprintCallable)
		int GetQuestionsLastIndex() const { return Questions.Num() - 1;  }

	UFUNCTION(BlueprintCallable)
		TArray<FAnswerData>& GetAnswerArrayForIndex(const int QuestionIndex);

	UFUNCTION(BlueprintCallable)
		void SaveToDataTable(UDataTable* QuestionDataTable, UDataTable* AnswerDataTable);

	UFUNCTION(BlueprintCallable)
		void ReadFromDataTable(UDataTable* QuestionDataTable, UDataTable* AnswerDataTable);

private:
	TMap<int, FText> Questions;

	TMap<int, TArray<FAnswerData>> Answers;

};
