

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MainCharacter.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDele_Dynamic);

UCLASS()
class ONLINESHOOTING_API AMainCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AMainCharacter();

	UFUNCTION(Reliable, Client)
	void AddWidget(TSubclassOf<class UUserWidget> _widget);
	UFUNCTION(Reliable, Client)
	void AddPlayerInLobby();

	UFUNCTION(Reliable, Client)
	void OnGameStart();
	UFUNCTION(Reliable, NetMulticast)
	void OnGameStartMulticast(FVector Loc, FRotator Rot);

protected:
	virtual void BeginPlay() override;

public:
	class UGameLobbyWidget* CreatedLobbyWidget;

	UPROPERTY(BlueprintAssignable)
	FDele_Dynamic GameStartDynamic;

};
