// Copyright ExoDragon


#include "Input/AuraInputConfig.h"

const UInputAction* UAuraInputConfig::FindAbilityInputActionForTag(const FGameplayTag InputTag, bool bLogNotFound) const
{
	for (const FAuraInputAction& InputAction : AbilityInputActions)
	{
		if (InputAction.InputAction && InputAction.InputTag == InputTag)
		{
			return InputAction.InputAction;
		}
	}

	if (bLogNotFound)
	{
		UE_LOG(LogTemp, Error, TEXT("Can't find InputAction for AttributeTag [%s] on AttributeInfo [%s]"), *InputTag.ToString(), *GetNameSafe(this));
	}
	
	return nullptr;
}
