// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameStructs.h"
#include "GameFramework/Actor.h"
#include "Cannon.generated.h"

UCLASS()
class TANKI_API ACannon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACannon();
	void Fire();
	void FireSpecial();
	void Reload();
	bool IsReadyToFire();
	void Shoot();
	void ShootSpecial();
	FTimerHandle ReloadTimer;
	FTimerHandle SerialTimer;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	class UStaticMeshComponent* CannonMesh;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	class UArrowComponent* ProjectileSpawnPoint;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	ECannonType CannonType = ECannonType::FireProjectile;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fire Params")
	float FireRate = 1.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fire Params")
	float FireRange = 1000.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fire Params")
	float FireDamage = 1.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fire Params")
	uint8 FireSerialAmount = 3;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fire Params")
	uint8 FireSpecialSerialAmount = 3; 
private:
	bool bReadyToFire = false;

};
