// Copyright ExoDragon


#include "AbilitySystem/Data/AttributeInfo.h"

FAuraAttributeInfo UAttributeInfo::FindAttributeInfoForTag(const FGameplayTag& GameplayTag, const bool bLogNotFound)
{
	for (const FAuraAttributeInfo& Info : AttributeInformation)
	{
		if (Info.AttributeTag == GameplayTag)
		{
			return Info;
		}
	}

	if (bLogNotFound)
	{
		UE_LOG(LogTemp, Error, TEXT("Can't find info for AttributeStag [%s] on AttributeInfo [%s]"), *GameplayTag.ToString(), *GetNameSafe(this));
	}
	
	return FAuraAttributeInfo();
}
