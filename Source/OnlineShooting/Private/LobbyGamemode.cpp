

#include "LobbyGamemode.h"

void ALobbyGamemode::BeginPlay()
{
	Super::BeginPlay();

	FFileHelper::SaveStringToFile(TEXT("480"), TEXT("steam_appid.txt"));

	SteamAPI_RestartAppIfNecessary(atoi("480"));

	if (SteamAPI_Init())
	{
		auto id = SteamUser()->GetSteamID();
	}
}
