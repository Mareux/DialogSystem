// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MyHUD.generated.h"

class UDialogData;
class SDialogSlateWidget;
/**
 * 
 */
UCLASS()
class MYPROJECT_API AMyHUD : public AHUD
{
	GENERATED_BODY()

protected:
	TSharedPtr<SDialogSlateWidget> DialogWidget;
	TSharedPtr<SWidget> DialogWidgetContainer;

	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Dialog")
		UDialogData* DialogData;

private:
	//static UTexture2D* GetBackgroundByName(const FString& AssetName);
	
};
