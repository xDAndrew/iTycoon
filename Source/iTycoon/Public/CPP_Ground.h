#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "CPP_Farm.h"
#include "CPP_Ground.generated.h"

UCLASS()
class ITYCOON_API ACPP_Ground : public APawn
{
	GENERATED_BODY()

private:
	int needRes;

public:
	ACPP_Ground();

	UFUNCTION(BlueprintCallable, Category = "Output")
	virtual void Decrease(int NeedRes);

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
