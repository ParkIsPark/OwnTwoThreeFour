// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "MapSetting.generated.h"

/**
 * ������ �⺻���� ������ ��ϵǾ��ִ� Ŭ����
 */
UCLASS(Config = Game, DefaultConfig)
class UMapSettings : public UDeveloperSettings
{
    GENERATED_BODY()

public:
    // ���� ��ü���� ���� Ÿ���� �⺻ �������Դϴ�.
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Map Settings")
    float TileSize = 100.0f;
};