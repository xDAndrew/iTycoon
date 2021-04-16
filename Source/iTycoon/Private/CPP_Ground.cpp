#include "CPP_Ground.h"
#include <Runtime\Engine\Classes\Kismet\GameplayStatics.h>

ACPP_Ground::ACPP_Ground()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ACPP_Ground::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACPP_Ground::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACPP_Ground::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ACPP_Ground::Decrease(int NeedRes) {

	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACPP_Farm::StaticClass(), FoundActors);

	for (auto i = 0; i < FoundActors.Num(); ++i)
	{
		auto farm = Cast<ACPP_Farm>(FoundActors[i]);

		if (farm->Product >= NeedRes) {
			farm->Product -= NeedRes;
			break;
		}
		else {
			NeedRes -= farm->Product;
			farm->Product = 0;
		}
	}
}
