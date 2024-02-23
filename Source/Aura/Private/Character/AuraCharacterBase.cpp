// Copyrigth Exodragon


#include "Character/AuraCharacterBase.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystem/AuraAbilitySystemComponentBase.h"
#include "Aura/Aura.h"
#include "Components/CapsuleComponent.h"

AAuraCharacterBase::AAuraCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;

	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);
	GetCapsuleComponent()->SetGenerateOverlapEvents(false);
	
	GetMesh()->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);
	GetMesh()->SetCollisionResponseToChannel(ECC_Projectile, ECR_Overlap);
	GetMesh()->SetGenerateOverlapEvents(true);
	
	WeaponComponent = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	WeaponComponent->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	WeaponComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

FVector AAuraCharacterBase::GetCombatSocketLocation()
{
	check(WeaponComponent);
	return WeaponComponent->GetSocketLocation(WeaponTipSocketName);
}

void AAuraCharacterBase::BeginPlay()
{
	Super::BeginPlay();
}

void AAuraCharacterBase::ApplyEffectToSelf(const TSubclassOf<UGameplayEffect> GameplayEffect, const float Level) const
{
	check(IsValid(GetAbilitySystemComponent()));
	check(IsValid(GameplayEffect));
	
	FGameplayEffectContextHandle ContextHandle = GetAbilitySystemComponent()->MakeEffectContext();
	ContextHandle.AddSourceObject(this);
	
	const FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(GameplayEffect, Level, ContextHandle);
	GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(), GetAbilitySystemComponent());
}

void AAuraCharacterBase::InitializeDefaultAttributes() const
{
	ApplyEffectToSelf(DefaultPrimaryAttribute, 1.f);
	ApplyEffectToSelf(DefaultSecondaryAttribute, 1.f);
	ApplyEffectToSelf(DefaultVitalAttribute, 1.f);
}

void AAuraCharacterBase::AddCharacterAbilities() const
{
	UAuraAbilitySystemComponentBase* AuraAbilitySystemComponentBase = CastChecked<UAuraAbilitySystemComponentBase>(AbilitySystemComponent);
	if (!HasAuthority()) return;

	AuraAbilitySystemComponentBase->AddCharacterAbilities(StartupAbilities);
}

void AAuraCharacterBase::InitAbilityActorInfo()
{
	
}
