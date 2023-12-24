

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MotherCharacter.generated.h"

UCLASS()
class ONLINESHOOTING_API AMotherCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AMotherCharacter();

	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
	class UWidgetComponent* HealthBar;

protected:
	virtual void BeginPlay() override;
};
