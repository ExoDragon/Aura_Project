// Copyright ExoDragon


#include "AuraAssetManager.h"

#include "AuraGameplayTags.h"
#include "AbilitySystemGlobals.h"

UAuraAssetManager& UAuraAssetManager::Get()
{
	check(GEngine);
	return *Cast<UAuraAssetManager>(GEngine->AssetManager);
}

void UAuraAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();
	FAuraGameplayTags::InitializeNativeGameplayTags();

	//Required to use target data!
	UAbilitySystemGlobals::Get().InitGlobalData();
}
