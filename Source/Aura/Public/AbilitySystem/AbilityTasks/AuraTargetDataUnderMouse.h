// Copyright ExoDragon

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Tasks/AbilityTask.h"
#include "AuraTargetDataUnderMouse.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMouseTargetDataSignature, const FGameplayAbilityTargetDataHandle&, DataHandle);

/**
 * 
 */
UCLASS()
class AURA_API UAuraTargetDataUnderMouse : public UAbilityTask
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintAssignable)
	FMouseTargetDataSignature ValidData;

	UFUNCTION(BlueprintCallable, Category="Ability|Tasks", meta=( DisplayName="TargetDataUnderMouse", HidePin="OwningGameplayAbility", DefaultToSelf="OwningGameplayAbility", BlueprintInternalUseOnly="true"))
	static UAuraTargetDataUnderMouse* CreateTargetDataUnderMouse(UGameplayAbility* OwningGameplayAbility);

private:
	
	virtual void Activate() override;
	void SendMouseCursorData();

	void OnTargetDataReplicatedCallback(const FGameplayAbilityTargetDataHandle& DataHandle, FGameplayTag ActivationTag);
};
