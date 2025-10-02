// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawn/Performer.h"

// Sets default values
APerformer::APerformer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APerformer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APerformer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APerformer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

