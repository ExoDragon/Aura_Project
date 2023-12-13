// Copyrigth Exodragon


#include "AbilitySystem/AuraAbilitySystemComponentBase.h"

void UAuraAbilitySystemComponentBase::AbilityActorInfoSet()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UAuraAbilitySystemComponentBase::EffectApplied);
}

void UAuraAbilitySystemComponentBase::EffectApplied(
	UAbilitySystemComponent* AbilitySystemComponent,
	const FGameplayEffectSpec& EffectSpec,
	FActiveGameplayEffectHandle GameplayEffectHandle)
{
	FGameplayTagContainer TagContainer;
	EffectSpec.GetAllAssetTags(TagContainer);

	for(const FGameplayTag Tag : TagContainer)
	{
		//TODO Broadcast tag to widget controller...
		const FString Msg = FString::Printf(TEXT("Ge Tag: %s"), *Tag.ToString());
		GEngine->AddOnScreenDebugMessage(-1, 8.f, FColor::Blue, Msg);
	}
}
