// Copyright ExoDragon


#include "AbilitySystem/AbilityTasks/AuraTargetDataUnderMouse.h"
#include "AbilitySystemComponent.h"

UAuraTargetDataUnderMouse* UAuraTargetDataUnderMouse::CreateTargetDataUnderMouse(UGameplayAbility* OwningGameplayAbility)
{
	UAuraTargetDataUnderMouse* MyObj = NewAbilityTask<UAuraTargetDataUnderMouse>(OwningGameplayAbility);
	return MyObj;
}

void UAuraTargetDataUnderMouse::Activate()
{
	if (Ability->GetCurrentActorInfo()->IsLocallyControlled())
	{
		SendMouseCursorData();
	}
	else
	{
		const FGameplayAbilitySpecHandle SpecHandle = GetAbilitySpecHandle();
		const FPredictionKey ActivationKey = GetActivationPredictionKey();
		AbilitySystemComponent.Get()->AbilityTargetDataSetDelegate(SpecHandle, ActivationKey)
			.AddUObject(this, &UAuraTargetDataUnderMouse::OnTargetDataReplicatedCallback);
		if (!AbilitySystemComponent.Get()->CallReplicatedTargetDataDelegatesIfSet(SpecHandle, ActivationKey))
		{
			SetWaitingOnRemotePlayerData();	
		}
	}
}

void UAuraTargetDataUnderMouse::SendMouseCursorData()
{
	FScopedPredictionWindow ScopedPrediction(AbilitySystemComponent.Get());
	
	const APlayerController* PlayerController = Ability->GetCurrentActorInfo()->PlayerController.Get();
	FHitResult CursorHit;
	PlayerController->GetHitResultUnderCursor(ECC_Visibility, false, CursorHit);

	FGameplayAbilityTargetDataHandle DataHandle;
	FGameplayAbilityTargetData_SingleTargetHit* Data = new FGameplayAbilityTargetData_SingleTargetHit();
	Data->HitResult = CursorHit;
	DataHandle.Add(Data);

	AbilitySystemComponent->ServerSetReplicatedTargetData(
		GetAbilitySpecHandle(),
		GetActivationPredictionKey(),
		DataHandle,
		FGameplayTag(),
		AbilitySystemComponent->ScopedPredictionKey);

	if(ShouldBroadcastAbilityTaskDelegates())
	{
		ValidData.Broadcast(DataHandle);
	}
}

void UAuraTargetDataUnderMouse::OnTargetDataReplicatedCallback(const FGameplayAbilityTargetDataHandle& DataHandle, FGameplayTag ActivationTag)
{
	AbilitySystemComponent->ConsumeClientReplicatedTargetData(GetAbilitySpecHandle(), GetActivationPredictionKey());
	if(ShouldBroadcastAbilityTaskDelegates())
	{
		ValidData.Broadcast(DataHandle);
	}
}
