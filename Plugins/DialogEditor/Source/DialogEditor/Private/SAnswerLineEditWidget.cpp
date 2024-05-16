// Fill out your copyright notice in the Description page of Project Settings.


#include "SAnswerLineEditWidget.h"

void SAnswerLineEditWidget::Construct(const FArguments& InArgs)
{
	QuestionID = InArgs._QuestionID;
	AnswerID = InArgs._AnswerID;
}
