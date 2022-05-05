// Fill out your copyright notice in the Description page of Project Settings.


#include "FGAICharacter.h"
#include "AbilitySystemGlobals.h"

// Sets default values
AFGAICharacter::AFGAICharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AbilityComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilityComponent"));
	AttributeSet = AbilityComponent->GetSet<UFGAttributeSet>();

}

UAbilitySystemComponent* AFGAICharacter::GetAbilitySystemComponent() const
{
	return AbilityComponent;
}

// Called when the game starts or when spawned
void AFGAICharacter::BeginPlay()
{
	Super::BeginPlay();

	for (const auto& Ability : Abilities)
	{
		AbilityComponent->GiveAbility(FGameplayAbilitySpec(Ability.GetDefaultObject()));
	}
	AbilityComponent->InitAbilityActorInfo(this, this);
	UAbilitySystemGlobals::Get().InitGlobalData();
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

