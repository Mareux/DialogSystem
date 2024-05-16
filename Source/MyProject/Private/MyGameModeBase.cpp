// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"

#include "MyHUD.h"

AMyGameModeBase::AMyGameModeBase()
{
	HUDClass = AMyHUD::StaticClass();
}
