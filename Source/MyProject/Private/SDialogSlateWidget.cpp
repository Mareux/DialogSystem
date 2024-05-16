// Fill out your copyright notice in the Description page of Project Settings.


#include "SDialogSlateWidget.h"

#define LOCTEXT_NAMESPACE "DialogMenu"

void SDialogSlateWidget::Construct(const FArguments& InArgs) {
	DialogText = InArgs._DialogText;


	ChildSlot[
		SNew(SOverlay)
			+SOverlay::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)[
				SNew(SImage)
				.ColorAndOpacity(FColor::Green)
			]
			+ SOverlay::Slot()
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Bottom)
			.ZOrder(2)[
			SNew(SBorder)
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Fill)
				.ColorAndOpacity(FColor::Black)
				.Padding(0, 500, 0, 0)
				[
					SNew(STextBlock)
					.Text(DialogText)
				]
			]
			+SOverlay::Slot()
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Fill)
				.ZOrder(1)
				.Padding(0, 500, 0, 0)
				[
					SNew(SImage)
					.ColorAndOpacity(FColor::Blue)
				]
			+SOverlay::Slot()
			.HAlign(HAlign_Right)
			.VAlign(VAlign_Center)
			.ZOrder(3)[
				SNew(SVerticalBox)
			]
	];
}

#undef LOCTEXT_NAMESPACE
