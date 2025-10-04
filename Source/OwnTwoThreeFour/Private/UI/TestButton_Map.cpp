// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/TestButton_Map.h"
#include "Components/Button.h"
#include "CameraPuzzleGameMode.h"
#include "Manager/GameManager.h"

void UTestButton_Map::LoadButtonClicked()
{
	auto* GameMode = Cast<ACameraPuzzleGameMode>(GetWorld()->GetAuthGameMode());

	TObjectPtr<AGameManager> GameManager = GameMode->GetGameManager();

	GameManager->LoadStageData(TestStageData);
}

void UTestButton_Map::NativeConstruct()
{
	Super::NativeConstruct();

	//¹ÙÀÎµù
	LoadButton->OnClicked.AddDynamic(this, &UTestButton_Map::LoadButtonClicked);
}
