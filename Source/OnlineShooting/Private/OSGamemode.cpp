


#include "OSGamemode.h"
#include "Character/MainCharacter.h"
#include "Steamworks/Steamv153/sdk/public/steam/steam_api.h"

void AOSGamemode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

	players.Add(NewPlayer);

	auto character = Cast<AMainCharacter>(NewPlayer->GetPawn());
	if (character)
		character->AddWidget(LobbyWidget);
}

void AOSGamemode::GameStartUF()
{
	int32 Index = 0;
	for (auto ForPlayer : players)
	{
		auto character = Cast<AMainCharacter>(ForPlayer->GetPawn());
		if (character)
		{
			character->OnGameStart();
			if (Index == 0)
				character->OnGameStartMulticast(FirstLocation.GetLocation(), FirstLocation.GetRotation().Rotator());
			else
				character->OnGameStartMulticast(SecondLocation.GetLocation(), SecondLocation.GetRotation().Rotator());

			Index++;
		}
	}
}

void AOSGamemode::BeginPlay()
{
	Super::BeginPlay();

	FFileHelper::SaveStringToFile(TEXT("480"), TEXT("steam_appid.txt"));

	SteamAPI_RestartAppIfNecessary(atoi("480"));

	if (SteamAPI_Init())
		auto id = SteamUser()->GetSteamID();
}
