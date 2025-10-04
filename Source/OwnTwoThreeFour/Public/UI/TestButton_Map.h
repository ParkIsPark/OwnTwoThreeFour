// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TestButton_Map.generated.h"
class UButton;
class UStageDataAsset;
/**
 * 테스트용으로 사용하는 버튼입니다.
 */
UCLASS()
class OWNTWOTHREEFOUR_API UTestButton_Map : public UUserWidget
{

	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UButton* LoadButton;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UStageDataAsset> TestStageData;

	UFUNCTION()
	void LoadButtonClicked();

	virtual void NativeConstruct() override;
};
