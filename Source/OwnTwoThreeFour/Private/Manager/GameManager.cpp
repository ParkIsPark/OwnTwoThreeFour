// Fill out your copyright notice in the Description page of Project Settings.


#include "Manager/GameManager.h"
#include "Map/MapManager.h"
#include "Data/StageDataAsset.h"

// Sets default values
AGameManager::AGameManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGameManager::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called every frame
void AGameManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGameManager::SetStageData(const UStageDataAsset* StageDataAsset)
{
	// ��ȿ�� ���� 
	if (StageDataAsset == nullptr) {
		UE_LOG(LogTemp, Error, TEXT("�������� �����Ͱ� �ùٸ��� �ʽ��ϴ�"));
		return;
	}

	//=======================================
	// ���� 1. �Ŵ��� ������ �ʱ�ȭ
	//==========================================
	MapManager->SetMapData(StageDataAsset);	

}

void AGameManager::StartGame()
{
	PlayerState = EPlayerState::EPS_Puzzle; // �÷��̾ ������ Ǫ�� �������� Ȯ���մϴ�. 

	//TODO : �� �Ŵ��� -> ���� ����

}

