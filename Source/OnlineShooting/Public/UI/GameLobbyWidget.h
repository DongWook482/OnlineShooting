

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameLobbyWidget.generated.h"

UCLASS()
class ONLINESHOOTING_API UGameLobbyWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY()
	class UVerticalBox* PlayerVertical;


	
};
