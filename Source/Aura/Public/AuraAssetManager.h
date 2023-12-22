// Copyright ExoDragon

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "AuraAssetManager.generated.h"

/**
 *  Custom AssetManager
 *
 *  Setup in DefaultEngine.ini File under "/Script/Engine.Engine" with:
 *  AssetManagerClassName=/Script/Aura.AuraAssetManager
 */
UCLASS()
class AURA_API UAuraAssetManager : public UAssetManager
{
	GENERATED_BODY()
public:
	static UAuraAssetManager& Get();

protected:
	virtual void StartInitialLoading() override;
	
};
