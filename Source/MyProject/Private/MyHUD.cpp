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
		DialogWidget = SNew(SDialogSlateWidget).OwningHUD(this).DialogText(FText::AsCultureInvariant(FString("FUCK")));
		GEngine->GameViewport->AddViewportWidgetContent(SAssignNew(DialogWidgetContainer, SWeakWidget).PossiblyNullContent(DialogWidget.ToSharedRef()));
	}
}
//TODO:LATER
//UTexture2D* AMyHUD::GetBackgroundByName(const FString& AssetName) {
//	static auto TextureLibrary = UObjectLibrary::CreateLibrary(UTexture2D::StaticClass(), true, GIsEditor);
//
//	const FString TextPath = "/Content/Assets/VN_backgrounds";
//	TextureLibrary->LoadAssetDataFromPath(TextPath);
//
//	TArray<FAssetData> Assets;
//	TextureLibrary->GetAssetDataList(Assets);
//	for (auto& Asset : Assets) {
//		if (Asset.AssetName.ToString() == AssetName) {
//			if (UTexture2D* Found = Cast<UTexture2D>(Asset.GetAsset())) {
//				return Found;
//			}
//		}
//	}
//
//	return nullptr;
//}
