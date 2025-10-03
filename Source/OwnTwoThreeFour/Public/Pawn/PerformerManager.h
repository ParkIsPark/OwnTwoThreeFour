// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Data/CameraPuzzleTypes.h"
#include "PerformerManager.generated.h"

class UStageDataAsset;

UCLASS()
class OWNTWOTHREEFOUR_API APerformerManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APerformerManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/** 이 스테이지에 스폰될 Performer들의 정보 목록입니다. */
	UPROPERTY(EditAnywhere, Category = "Performer", meta = (AllowPrivateAccess = "true"))
	TArray<FPerformerSpawnData> PerformerSpawnData;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void SetPerformerData(const TArray<FPerformerSpawnData>& InPerformerSpawnData);

};
