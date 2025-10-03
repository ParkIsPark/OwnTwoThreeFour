// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CameraPuzzleGameMode.generated.h"

/**
 * 
 */
UCLASS()
class OWNTWOTHREEFOUR_API ACameraPuzzleGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:

protected:
	virtual void BeginPlay() override;
private:
	
};
