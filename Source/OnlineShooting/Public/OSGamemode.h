

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"

#pragma warning(push)
#pragma warning(disable: 4996)
#include "Steamworks/Steamv153/sdk/public/steam/steam_api.h"
#pragma warning(pop)

#include "OSGamemode.generated.h"

UCLASS()
class ONLINESHOOTING_API AOSGamemode : public AGameModeBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
	TSubclassOf<class UUserWidget> LobbyWidget;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
	FTransform FirstLocation;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
	FTransform SecondLocation;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
	TArray<APlayerController*> players;

public:
	virtual void PostLogin(APlayerController* NewPlayer) override;

	UFUNCTION(BlueprintCallable)
	void GameStartUF();

protected:
	virtual void BeginPlay() override;
	
};