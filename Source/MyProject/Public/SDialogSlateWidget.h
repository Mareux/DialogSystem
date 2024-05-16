// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyHUD.h"
#include "SlateBasics.h"
#include "SlateExtras.h"

/**
 * 
 */
class AMyHUD;

class MYPROJECT_API SDialogSlateWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SDialogSlateWidget) {}

	SLATE_ARGUMENT(TWeakObjectPtr<AMyHUD>, OwningHUD)
	SLATE_ARGUMENT(FText, DialogText)

	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

	virtual bool SupportsKeyboardFocus() const override { return true; }
private:
	TWeakObjectPtr<AMyHUD> OwningHUD;
	FText DialogText;

};

