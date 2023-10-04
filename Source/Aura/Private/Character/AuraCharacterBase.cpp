// Copyrigth Exodragon


#include "Character/AuraCharacterBase.h"

AAuraCharacterBase::AAuraCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;

	WeaponComponent = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	WeaponComponent->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	WeaponComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void AAuraCharacterBase::BeginPlay()
{
	Super::BeginPlay();
}
