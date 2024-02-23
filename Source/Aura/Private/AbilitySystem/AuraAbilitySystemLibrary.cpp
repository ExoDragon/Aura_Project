// Copyright ExoDragon


#include "AbilitySystem/AuraAbilitySystemLibrary.h"

#include "Game/AuraGameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "Player/AuraPlayerState.h"
#include "UI/HUD/AuraHUD.h"
#include "UI/WidgetController/AuraWidgetController.h"

UOverlayWidgetController* UAuraAbilitySystemLibrary::GetOverlayWidgetController(const UObject* WorldContextObject)
{
	if (APlayerController* PlayerController = UGameplayStatics::GetPlayerController(WorldContextObject, 0))
	{
		if (AAuraHUD* AuraHUD = Cast<AAuraHUD>(PlayerController->GetHUD()))
		{
			AAuraPlayerState* AuraPlayerState = PlayerController->GetPlayerState<AAuraPlayerState>();
			UAbilitySystemComponent* AbilitySystemComponent = AuraPlayerState->GetAbilitySystemComponent();
			UAttributeSet* AttributeSet = AuraPlayerState->GetAttributeSet();
			const FWidgetControllerParams WidgetControllerParams(PlayerController, AuraPlayerState, AbilitySystemComponent, AttributeSet);
			return AuraHUD->GetOverlayWidgetController(WidgetControllerParams);
		}
	}

	return nullptr;
}

UAttributeMenuWidgetController* UAuraAbilitySystemLibrary::GetAttributeMenuWidgetController(const UObject* WorldContextObject)
{
	if (APlayerController* PlayerController = UGameplayStatics::GetPlayerController(WorldContextObject, 0))
	{
		if (AAuraHUD* AuraHUD = Cast<AAuraHUD>(PlayerController->GetHUD()))
		{
			AAuraPlayerState* AuraPlayerState = PlayerController->GetPlayerState<AAuraPlayerState>();
			UAbilitySystemComponent* AbilitySystemComponent = AuraPlayerState->GetAbilitySystemComponent();
			UAttributeSet* AttributeSet = AuraPlayerState->GetAttributeSet();
			const FWidgetControllerParams WidgetControllerParams(PlayerController, AuraPlayerState, AbilitySystemComponent, AttributeSet);
			return AuraHUD->GetAttributeWidgetController(WidgetControllerParams);
		}
	}

	return nullptr;
}

void UAuraAbilitySystemLibrary::InitializeDefaultAttributes(const UObject* WorldContextObject, ECharacterClass CharacterClass, float Level, UAbilitySystemComponent* AbilitySystemComponent)
{
	const AAuraGameModeBase* AuraGameModeBase = Cast<AAuraGameModeBase>(UGameplayStatics::GetGameMode(WorldContextObject));
	if (AuraGameModeBase == nullptr) return;

	//When applying Effects always have a SourceObject defined...
	const AActor* AvatarActor = AbilitySystemComponent->GetAvatarActor();
	
	UAuraCharacterClassInfo* CharacterClassInfo = AuraGameModeBase->CharacterClassInfo;
	const FCharacterClassDefaultInfo ClassDefaultInfo = CharacterClassInfo->GetClassDefaultInfo(CharacterClass);

	FGameplayEffectContextHandle PrimaryContextHandle = AbilitySystemComponent->MakeEffectContext();
	PrimaryContextHandle.AddSourceObject(AvatarActor);
	const FGameplayEffectSpecHandle PrimarySpecHandle = AbilitySystemComponent->MakeOutgoingSpec(ClassDefaultInfo.PrimaryAttributes, Level, PrimaryContextHandle);
	AbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*PrimarySpecHandle.Data.Get());

	FGameplayEffectContextHandle SecondaryContextHandle = AbilitySystemComponent->MakeEffectContext();
	SecondaryContextHandle.AddSourceObject(AvatarActor);
	const FGameplayEffectSpecHandle SecondarySpecHandle = AbilitySystemComponent->MakeOutgoingSpec(CharacterClassInfo->SecondaryAttributes, Level, SecondaryContextHandle);
	AbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*SecondarySpecHandle.Data.Get());

	FGameplayEffectContextHandle VitalContextHandle = AbilitySystemComponent->MakeEffectContext();
	VitalContextHandle.AddSourceObject(AvatarActor);
	const FGameplayEffectSpecHandle VitalSpecHandle = AbilitySystemComponent->MakeOutgoingSpec(CharacterClassInfo->VitalAttributes, Level, VitalContextHandle);
	AbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*VitalSpecHandle.Data.Get());
}
