

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"

#pragma warning(push)
#pragma warning(disable: 4996)
#include "../Steam/steam_api.h"
#pragma warning(pop)

#include "LobbyGamemode.generated.h"

/**
 * 
 */
UCLASS()
class ONLINESHOOTING_API ALobbyGamemode : public AGameModeBase
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;

};
