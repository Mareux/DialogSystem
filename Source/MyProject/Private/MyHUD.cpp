// Fill out your copyright notice in the Description page of Project Settings.


#include "MyHUD.h"
#include "Widgets/SWeakWidget.h"
#include "SDialogSlateWidget.h"
#include "Engine/ObjectLibrary.h"

void AMyHUD::BeginPlay()
{
	Super::BeginPlay();

	if (GEngine && GEngine->GameViewport)
	{
		DialogWidget = SNew(SDialogSlateWidget)
		.OwningHUD(this)
		.DialogText(DialogData);
		GEngine->GameViewport->AddViewportWidgetContent(SAssignNew(DialogWidgetContainer, SWeakWidget).PossiblyNullContent(DialogWidget.ToSharedRef()));
	}
}
