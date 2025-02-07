// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MyHUD.generated.h"

class UDialogEditorDataAsset;
class UDialogData;
class SDialogSlateWidget;
/**
 * 
 */
UCLASS()
class MYPROJECT_API AMyHUD : public AHUD
{
	GENERATED_BODY()

public:
	void SetBackground(UTexture2D* NewBackbround) {}

protected:
	TSharedPtr<SDialogSlateWidget> DialogWidget;
	TSharedPtr<SWidget> DialogWidgetContainer;

	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Dialog")
		UDialogEditorDataAsset* DialogData;

	UPROPERTY(EditDefaultsOnly, Category = "Dialog")
		UTexture2D* Background;
	
};
