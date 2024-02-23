// Copyrigth Exodragon


#include "Character/AuraEnemyCharacter.h"

#include "AbilitySystem/AuraAbilitySystemComponentBase.h"
#include "AbilitySystem/AuraAbilitySystemLibrary.h"
#include "AbilitySystem/AuraAttributeSet.h"
#include "Aura/Aura.h"
#include "Components/WidgetComponent.h"
#include "UI/Widget/AuraUserWidget.h"

AAuraEnemyCharacter::AAuraEnemyCharacter()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
	
	AbilitySystemComponent = CreateDefaultSubobject<UAuraAbilitySystemComponentBase>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);
	
	AttributeSet = CreateDefaultSubobject<UAuraAttributeSet>("AttributeSet");

	HealthBar = CreateDefaultSubobject<UWidgetComponent>("HealthBarComponent");
	HealthBar->SetupAttachment(GetRootComponent());
}

void AAuraEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	InitAbilityActorInfo();
	InitializeDefaultAttributes();
	
	if (UAuraUserWidget* AuraUserWidget = Cast<UAuraUserWidget>(HealthBar->GetUserWidgetObject()))
	{
		AuraUserWidget->SetWidgetController(this);
	}
	
	if (const UAuraAttributeSet* AuraAttributeSet = CastChecked<UAuraAttributeSet>(AttributeSet))
	{
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AuraAttributeSet->GetHealthAttribute())
			.AddLambda([this](const FOnAttributeChangeData& Data)
			{
				OnHealthChanged.Broadcast(Data.NewValue);
			});

		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AuraAttributeSet->GetMaxHealthAttribute())
			.AddLambda([this](const FOnAttributeChangeData& Data)
			{
				OnMaxHealthChanged.Broadcast(Data.NewValue);
			});

		OnHealthChanged.Broadcast(AuraAttributeSet->GetHealth());
		OnMaxHealthChanged.Broadcast(AuraAttributeSet->GetMaxHealth());
	}
}

void AAuraEnemyCharacter::InitAbilityActorInfo()
{
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
	Cast<UAuraAbilitySystemComponentBase>(AbilitySystemComponent)->AbilityActorInfoSet();
	
	InitializeDefaultAttributes();
}

void AAuraEnemyCharacter::InitializeDefaultAttributes() const
{
	UAuraAbilitySystemLibrary::InitializeDefaultAttributes(this, CharacterClass, Level, AbilitySystemComponent);
}

void AAuraEnemyCharacter::HighlightActor()
{
	GetMesh()->SetRenderCustomDepth(true);
	GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
	
	WeaponComponent->SetRenderCustomDepth(true);
	WeaponComponent->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
}

void AAuraEnemyCharacter::UnHighlightActor()
{
	GetMesh()->SetRenderCustomDepth(false);
	
	WeaponComponent->SetRenderCustomDepth(false);
}

int32 AAuraEnemyCharacter::GetPlayerLevel()
{
	return Level;
}
