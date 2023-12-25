// Copyrigth Exodragon

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AuraPlayerController.generated.h"

class USplineComponent;
struct FGameplayTag;
class UAuraInputConfig;
class UInputMappingContext;
class UInputAction;
class IEnemyInterface;
class UAuraAbilitySystemComponentBase;
struct FInputActionValue;

/**
 * AuraPlayerController.
 */
UCLASS()
class AURA_API AAuraPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	AAuraPlayerController();
	virtual void PlayerTick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
	
private:
	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputMappingContext> AuraInputMappingContextContext;

	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(EditDefaultsOnly, Category="Input")
	TObjectPtr<UAuraInputConfig> InputConfig;

	UPROPERTY()
	TObjectPtr<UAuraAbilitySystemComponentBase> AuraAbilitySystemComponent;

	FVector CachedDestination = FVector::ZeroVector;
	float FollowTime = 0.f;
	float ShortPressThreshold = 0.5f;
	bool bAutoRunning = false;
	bool bTargeting = false;

	FHitResult CursorHit;

	UPROPERTY(VisibleAnywhere, Category="Movement")
	TObjectPtr<USplineComponent> MovementSplineComponent;

	UPROPERTY(EditDefaultsOnly, Category="Movement")
	float AutoRunAcceptanceRadius = 50.f;

	void Move(const FInputActionValue& InputActionValue);
	void CursorTrace();

	void AbilityInputTagPressed(FGameplayTag InputTag);
	void AbilityInputTagReleased(FGameplayTag InputTag);
	void AbilityInputTagHeld(FGameplayTag InputTag);

	void AutoRun();

	UAuraAbilitySystemComponentBase* GetAbilitySystemComponent();
	
	IEnemyInterface* LastActor;
	IEnemyInterface* ThisActor;
};
