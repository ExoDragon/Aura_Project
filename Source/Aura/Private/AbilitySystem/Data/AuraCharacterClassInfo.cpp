// Copyright ExoDragon


#include "AbilitySystem/Data/AuraCharacterClassInfo.h"

FCharacterClassDefaultInfo UAuraCharacterClassInfo::GetClassDefaultInfo(ECharacterClass CharacterClass)
{
	return CharacterClassInformation.FindChecked(CharacterClass);
}
