


#include "Character/MainCharacter.h"

#include "UI/GameLobbyWidget.h"

#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"

AMainCharacter::AMainCharacter()
{
 	
}

void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMainCharacter::AddWidget_Implementation(TSubclassOf<class UUserWidget> _widget)
{
	CreatedLobbyWidget = CreateWidget<UGameLobbyWidget>(GetWorld(), _widget);
	if (CreatedLobbyWidget)
		CreatedLobbyWidget->AddToViewport();
}

void AMainCharacter::AddPlayerInLobby_Implementation()
{

}

void AMainCharacter::OnGameStart_Implementation()
{
	CreatedLobbyWidget->RemoveFromViewport();
	CreatedLobbyWidget->RemoveFromParent();

	GameStartDynamic.Broadcast();
}

void AMainCharacter::OnGameStartMulticast_Implementation(FVector Loc, FRotator Rot)
{
	SetActorLocation(Loc);
	auto con = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	con->SetControlRotation(Rot);
}