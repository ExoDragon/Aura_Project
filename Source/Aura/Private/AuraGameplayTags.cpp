// Copyright ExoDragon


#include "AuraGameplayTags.h"
#include "GameplayTagsManager.h"

FAuraGameplayTags FAuraGameplayTags::Instance;

void FAuraGameplayTags::InitializeNativeGameplayTags()
{
	Instance.Attributes_Primary_Strength = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Primary.Strength"),FString(""));
	Instance.Attributes_Primary_Intelligence = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Primary.Intelligence"),FString(""));
	Instance.Attributes_Primary_Resilience = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Primary.Resilience"),FString(""));
	Instance.Attributes_Primary_Vigor = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Primary.Vigor"),FString(""));
	
	Instance.Attributes_Secondary_Armor = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.Armor"),FString("Reduces damage taken, improves Block Chance"));
	Instance.Attributes_Secondary_Armor_Penetration = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.Armor_Penetration"), FString(""));
	Instance.Attributes_Secondary_Block_Chance = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.Block_Chance"), FString(""));
	Instance.Attributes_Secondary_Critical_Hit_Chance = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.Critical_Hit_Chance"), FString(""));
	Instance.Attributes_Secondary_Critical_Hit_Damage = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.Critical_Hit_Damage"), FString(""));
	Instance.Attributes_Secondary_Critical_Hit_Resistance = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.Critical_Hit_Resistance"), FString(""));
	Instance.Attributes_Secondary_Health_Regeneration = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.Health_Regeneration"), FString(""));
	Instance.Attributes_Secondary_Mana_Regeneration = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.Mana_Regeneration"), FString(""));
	Instance.Attributes_Secondary_Max_Health = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.Max_Health"), FString(""));
	Instance.Attributes_Secondary_Max_Mana = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.Max_Mana"), FString(""));
}
