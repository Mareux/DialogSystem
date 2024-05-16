// Fill out your copyright notice in the Description page of Project Settings.


#include "DialogEditorSubsystem.h"

void UDialogEditorSubsystem::AddQuestionLine(const FText& Question)
{
	if (!Questions) {
		Questions = MakeShareable(new TMap< int, FText >);
		Questions->Add(0, Question);
	} else {
		Questions->Add(Questions->Num(), Question);
	}
}

int UDialogEditorSubsystem::AddAnswerLine(const FText Answer, const int CurrentQuestionId, const int NextQuestionId)
{
	FAnswerData NewData;
	NewData.Text = Answer;
	NewData.IdQuestionNext = NextQuestionId;
	if (TArray<FAnswerData>* Array = Answers.Find(CurrentQuestionId)) {
		NewData.IdAnswer = Array->Num();
		Array->Add(NewData);
	} else {
		TArray<FAnswerData> NewArray;
		NewData.IdAnswer = 0;
		NewArray.Add(NewData);
		Answers.Add(CurrentQuestionId, NewArray);
	}
	return NewData.IdAnswer;
}

void UDialogEditorSubsystem::UpdateAnswerLine(const FText Answer, const int CurrentQuestionId, const int NextQuestionId,
	const int64 Id)
{
	TArray<FAnswerData>* Array = Answers.Find(CurrentQuestionId);
	if (FAnswerData* CurrentData = Array->FindByKey(Id)) {
		CurrentData->IdQuestionNext = NextQuestionId;
		CurrentData->Text = Answer;
	}
}

void UDialogEditorSubsystem::UpdateAnswerIndex(const int CurrentIndex, const int NewIndex)
{
	const TArray<FAnswerData> CurrentData = Answers.FindAndRemoveChecked(CurrentIndex);
	if (TArray<FAnswerData>* DataAtNewIndex = Answers.Find(NewIndex)) {
		for (auto& Data : CurrentData) {
			DataAtNewIndex->Add(Data);
		}
	} else {
		Answers.Add(NewIndex, CurrentData);
	}
}

TSharedPtr<TMap<int, FText>> UDialogEditorSubsystem::GetQuestions() const
{
	return Questions;
}

TArray<FAnswerData>& UDialogEditorSubsystem::GetAnswerArrayForIndex(const int QuestionIndex)
{
	return Answers.FindOrAdd(QuestionIndex);

}
