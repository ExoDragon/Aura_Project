// Copyright ExoDragon

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

/*
 *	AuraGameplayTags
 *
 *	Singleton containing native Gameplay Tags
 */

struct FAuraGameplayTags
{

public:
	static const FAuraGameplayTags& Get() { return Instance; }
	static void InitializeNativeGameplayTags();

	FGameplayTag Attributes_Primary_Strength;
	FGameplayTag Attributes_Primary_Intelligence;
	FGameplayTag Attributes_Primary_Resilience;
	FGameplayTag Attributes_Primary_Vigor;
	
	FGameplayTag Attributes_Secondary_Armor;
	FGameplayTag Attributes_Secondary_Armor_Penetration;
	FGameplayTag Attributes_Secondary_Block_Chance;
	FGameplayTag Attributes_Secondary_Critical_Hit_Chance;
	FGameplayTag Attributes_Secondary_Critical_Hit_Damage;
	FGameplayTag Attributes_Secondary_Critical_Hit_Resistance;
	FGameplayTag Attributes_Secondary_Health_Regeneration;
	FGameplayTag Attributes_Secondary_Mana_Regeneration;
	FGameplayTag Attributes_Secondary_Max_Health;
	FGameplayTag Attributes_Secondary_Max_Mana;

	FGameplayTag InputTag_LMB;
	FGameplayTag InputTag_RMB;
	FGameplayTag InputTag_1;
	FGameplayTag InputTag_2;
	FGameplayTag InputTag_3;
	FGameplayTag InputTag_4;
	
	
private:
	static FAuraGameplayTags Instance;
};
