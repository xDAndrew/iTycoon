#include "CPP_Farm.h"
#include "Components/WidgetComponent.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"

ACPP_Farm::ACPP_Farm()
{
	PrimaryActorTick.bCanEverTick = true;

	this->Capacity = (rand() % 100) + 30;
	this->Power = 2;
	this->Product = 0;
	this->DurationInSeconds = 2.f;

	this->isBuilding = true;
	this->BuildingTimeInSeconds = 5.f;

	Model = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FarmModel"));
	Model->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> farmMesh(TEXT("/Game/Geometry/farm.farm"));
	FarmModel = farmMesh.Object;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> buildingMesh(TEXT("/Game/Geometry/Building.Building"));

	if (buildingMesh.Succeeded()) {
		Model->SetStaticMesh(buildingMesh.Object);
		Model->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
		Model->SetWorldScale3D(FVector(1.f, 1.f, 1.f));
	}
}

void ACPP_Farm::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACPP_Farm::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (isBuilding) {
		UpdateBuilding(DeltaTime);
	}

	UpdateProdaction();
}

void ACPP_Farm::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ACPP_Farm::UpdateBuilding(float deltaTime) {
	if (isBuilding && BuildingTimeInSeconds >= 0) {
		BuildingTimeInSeconds -= deltaTime;
	}
	else {
		isBuilding = false;
		Model->SetStaticMesh(FarmModel);
	}
}

void ACPP_Farm::UpdateProdaction() {
	FTimerHandle UnusedHandle;
	GetWorldTimerManager().UnPauseTimer(UnusedHandle);
	GetWorldTimerManager().SetTimer(UnusedHandle, [this]() {

		if (!isBuilding && Product != Capacity) {
			if (Product + Power > Capacity) {
				Product = Capacity;
			}
			else
			{
				Product += Power;
			}
		}

	}, DurationInSeconds, false);
}