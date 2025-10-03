// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "MapSetting.generated.h"

/**
 * 게임의 기본적인 세팅이 기록되어있는 클래스
 */
UCLASS(Config = Game, DefaultConfig)
class UMapSettings : public UDeveloperSettings
{
    GENERATED_BODY()

public:
    // 게임 전체에서 사용될 타일의 기본 사이즈입니다.
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Map Settings")
    float TileSize = 100.0f;
};