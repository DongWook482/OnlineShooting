


#include "Character/MotherCharacter.h"
#include "Components/WidgetComponent.h"

AMotherCharacter::AMotherCharacter()
{
	HealthBar = CreateDefaultSubobject<UWidgetComponent>(TEXT("HealthWidgetComp"));
	HealthBar->SetupAttachment(RootComponent);
}

void AMotherCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

