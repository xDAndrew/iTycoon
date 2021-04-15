#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "CPP_Farm.generated.h"

UCLASS()
class ITYCOON_API ACPP_Farm : public APawn
{
	GENERATED_BODY()

public:
	ACPP_Farm();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite, Category = Geometry)
	UStaticMeshComponent* Model;

	UPROPERTY(BlueprintReadWrite, Category = Geometry)
	UStaticMesh* FarmModel;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(BlueprintReadOnly)
	int Power;

	UPROPERTY(BlueprintReadWrite)
	int Product;

	UPROPERTY(BlueprintReadOnly)
	int Capacity;

	UPROPERTY()
	float DurationInSeconds;

	UPROPERTY()
	bool isBuilding;

	UPROPERTY()
	float BuildingTimeInSeconds;

	void UpdateBuilding(float deltaTime);

	void UpdateProdaction(float deltaTime);
};
