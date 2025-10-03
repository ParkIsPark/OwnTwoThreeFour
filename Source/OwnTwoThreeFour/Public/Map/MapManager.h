// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Data/CameraPuzzleTypes.h"
#include "MapManager.generated.h"

class UStageDataAsset;
class ATile;

UCLASS()
class OWNTWOTHREEFOUR_API AMapManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMapManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/** ������ ���۵� ���� ��ġ�Դϴ�*/
	UPROPERTY(EditAnywhere, Category = "Property")
	FVector SpawnPoint;
	/** �� �������� �׸����� ���� ũ���Դϴ�. */
	UPROPERTY(EditAnywhere, Category = "Property")
	int32 GridWidth;

	/** �� �������� �׸����� ���� ũ���Դϴ�. */
	UPROPERTY(EditAnywhere, Category = "Property")
	int32 GridHeight;

	/** * �׸��� ���̾ƿ� �������Դϴ�. (GridWidth * GridHeight)���� ���Ҹ� ������ �մϴ�.
	* �迭�� ù ��° ���Ҵ� (0,0), ������ ���Ҵ� (Width-1, Height-1)�� �ش��մϴ�.
	*/
	UPROPERTY(EditAnywhere, Category = "Grid")
	TArray<FTileSpawnData> TileSpawnData;

	/** 
	* ���� ������ Ÿ�� ���͸� ������ �ֽ��ϴ�..
	* 2���� �迭�� 1�������� �÷� �� ��ġ���� ������ �״�� ������ �ֽ��ϴ�.
	*/
	UPROPERTY(EditAnywhere, Category = "Grid")
	TArray<ATile*> TileArray;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	/** ���� ����� �����մϴ�*/
	UFUNCTION()
	void SetMapSize(const FIntPoint& Size);
	/**���� Ÿ�� ���� �����͸� �����մϴ�*/
	UFUNCTION()
	void SetTileSpawnData(const TArray<FTileSpawnData>& InTileSpawnData);

	/**���� �����մϴ�*/
	UFUNCTION()
	void SpawnMap();
	

	//TODO : �׸��� ��� ������ ��. 
	//TODO : ������ ������� �ٴ� ����ϴ°� ������ ��.

};
