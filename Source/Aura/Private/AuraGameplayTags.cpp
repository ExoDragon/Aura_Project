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

	Instance.InputTag_LMB = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("InputTag.LMB"), FString(""));
	Instance.InputTag_RMB = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("InputTag.RMB"), FString(""));
	Instance.InputTag_1 = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("InputTag.1"), FString(""));
	Instance.InputTag_2 = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("InputTag.2"), FString(""));
	Instance.InputTag_3 = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("InputTag.3"), FString(""));
	Instance.InputTag_4 = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("InputTag.4"), FString(""));

	Instance.Damage = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Damage"), FString("Damage"));
	Instance.Damage_Fire = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Damage.Fire"), FString("Fire Damage Type"));
	Instance.Damage_Lightning = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Damage.Lightning"), FString("Lightning Damage Type"));
	Instance.Damage_Arcane = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Damage.Arcane"), FString("Arcane Damage Type"));
	Instance.Damage_Physical = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Damage.Physical"), FString("Physical Damage Type"));
	
	Instance.Abilities_Attack = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Abilities.Attack"), FString("Attack Ability"));

	Instance.Attributes_Resistance_Fire = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Resistance.Fire"), FString("Fire Resistance Type"));
	Instance.Attributes_Resistance_Lightning = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Resistance.Lightning"), FString("Lightning Resistance Type"));
	Instance.Attributes_Resistance_Arcane = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Resistance.Arcane"), FString("Arcane Resistance Type"));
	Instance.Attributes_Resistance_Physical = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Resistance.Physical"), FString("Physical Resistance Type"));

	Instance.Montage_Attack_Weapon = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Montage.Attack.Weapon"), FString("Weapon Attack"));
	Instance.Montage_Attack_RightHand = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Montage.Attack.RightHand"), FString("Right Hand Attack"));
	Instance.Montage_Attack_LeftHand = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Montage.Attack.LeftHand"), FString("Left Hand Attack"));
	
	Instance.DamageTypesToResistances.Add(Instance.Damage_Fire, Instance.Attributes_Resistance_Fire);
	Instance.DamageTypesToResistances.Add(Instance.Damage_Lightning, Instance.Attributes_Resistance_Lightning);
	Instance.DamageTypesToResistances.Add(Instance.Damage_Arcane, Instance.Attributes_Resistance_Arcane);
	Instance.DamageTypesToResistances.Add(Instance.Damage_Physical, Instance.Attributes_Resistance_Physical);
	
	Instance.Effects_HitReact = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Effects.HitReact"), FString(""));
}
