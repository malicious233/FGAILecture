// Fill out your copyright notice in the Description page of Project Settings.


#include "FGAICharacter.h"

// Sets default values
AFGAICharacter::AFGAICharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFGAICharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFGAICharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFGAICharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

