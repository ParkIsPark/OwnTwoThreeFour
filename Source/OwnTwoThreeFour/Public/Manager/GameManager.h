// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Data/CameraPuzzleTypes.h"
#include "GameManager.generated.h"

class AMapManager;
class UStageDataAsset;

/**
* ������ �������� ��Ȳ�� �Ѱ��մϴ�.
*/
UCLASS()
class OWNTWOTHREEFOUR_API AGameManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGameManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	
	/** ������ �����մϴ�*/
	void StartGame();


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY()
	EPlayerState PlayerState; // �÷��̾��� �����Դϴ�.

	//�� �Ŵ���
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Manager")
	AMapManager* MapManager;

	//TODO : �������� ������ �޴� ���� ������ ��.


	UFUNCTION()
	/**
	* �������� �����͸� �޾Ƽ� ������ �غ� �մϴ�.
	*/
	void SetStageData(const UStageDataAsset* StageDataAsset);

};
