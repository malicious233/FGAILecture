// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystemComponent.h"
#include "FGAttributeSet.h"
#include "FGAICharacter.generated.h"


class UFGAttributeSet;

UCLASS(Blueprintable)
class AILECTURE_API AFGAICharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFGAICharacter();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	UPROPERTY(EditDefaultsOnly, Category = AbilitySystem)
		TArray<TSubclassOf<class UGameplayAbility>> Abilities;

	UPROPERTY(EditDefaultsOnly)
	UAbilitySystemComponent* AbilityComponent = nullptr;

	UPROPERTY()
	const UFGAttributeSet* AttributeSet;
};
