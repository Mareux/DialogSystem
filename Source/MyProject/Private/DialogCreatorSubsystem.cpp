// Fill out your copyright notice in the Description page of Project Settings.


#include "DialogCreatorSubsystem.h"

#include "Editor/Blutility/Classes/EditorUtilityWidgetComponents.h"


void UDialogCreatorSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	
}

void UDialogCreatorSubsystem::AddQuestionLine(FText Question)
{
	if (Questions.Num() < 1) {
		Questions.Add(0, Question);
	} else
	{
		Questions.Add(Questions.Num(), Question);
	}
}

int UDialogCreatorSubsystem::AddAnswerLine(const FText Answer, const int CurrentQuestionId, const int NextQuestionId)
{
	FAnswerData NewData;
	NewData.Text = Answer;
	NewData.IdQuestionNext = NextQuestionId;
	if (TArray<FAnswerData> *Array = Answers.Find(CurrentQuestionId))
	{
		NewData.IdAnswer = Array->Num();
		Array->Add(NewData);
	}
	else
	{
		TArray<FAnswerData> NewArray;
		NewData.IdAnswer = 0;
		NewArray.Add(NewData);
		Answers.Add(CurrentQuestionId, NewArray);
	}
	return NewData.IdAnswer;
}

void UDialogCreatorSubsystem::UpdateAnswerLine(const FText Answer, const int CurrentQuestionId, const int NextQuestionId, const int64 Id)
{
	TArray<FAnswerData>* Array = Answers.Find(CurrentQuestionId);
	if (FAnswerData* CurrentData = Array->FindByKey(Id))
	{
		CurrentData->IdQuestionNext = NextQuestionId;
		CurrentData->Text = Answer;
	}
}


void UDialogCreatorSubsystem::UpdateAnswerIndex(const int CurrentIndex, const int NewIndex)
{
	const TArray<FAnswerData> CurrentData = Answers.FindAndRemoveChecked(CurrentIndex);
	if (TArray<FAnswerData>* DataAtNewIndex = Answers.Find(NewIndex)) {
		for (auto& Data : CurrentData)
		{
			DataAtNewIndex->Add(Data);
		}
	} else
	{
		Answers.Add(NewIndex, CurrentData);
	}

}

void UDialogCreatorSubsystem::UpdateComboBox(UEditorUtilityComboBoxString* ComboBox) const
{
	ComboBox->ClearOptions();
	for (auto Question : Questions)
	{
		ComboBox->AddOption(Question.Value.ToString());
	}
}

TArray<FAnswerData>& UDialogCreatorSubsystem::GetAnswerArrayForIndex(const int QuestionIndex)
{
	return Answers.FindOrAdd(QuestionIndex);
}

void UDialogCreatorSubsystem::SaveToDataTable(UDataTable* QuestionDataTable, UDataTable* AnswerDataTable)
{
	for (const auto Element : Questions)
	{
		FQuestionDialogData NewData;
		NewData.IdQuestion = Element.Key;
		NewData.Text = Element.Value;
		QuestionDataTable->AddRow(FName(FString::FromInt(Element.Key)), NewData);
	}
}

void UDialogCreatorSubsystem::ReadFromDataTable(UDataTable* QuestionDataTable, UDataTable* AnswerDataTable) {
	TArray<FQuestionDialogData*> QuestionData;
	QuestionDataTable->GetAllRows<FQuestionDialogData>(TEXT("Test"), QuestionData);
	for (const auto Data : QuestionData)
	{
		Questions.Add(Data->IdQuestion, Data->Text);
	}
}
