// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Containers/Queue.h"
#include "MyCharacter.generated.h"

class AGun;
class ABullet;
class UInventoryComponent;
class UWidgetComponent;
class UUserWidget;
class UInventoryWidget;
class UEquipmentWidget;
class APet;
class AWeapon;
class AWing;

DECLARE_MULTICAST_DELEGATE(FCharacterDie)
UCLASS()
class GAME_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

	// 이동
	void MoveForward(float value);
	void MoveRight(float value);
	void Turn(float rate);
	void LookUp(float rate);

	void Walk();
	void StopWalk();
	virtual void Jump() override;
	virtual bool CanJumpInternal_Implementation() const override;

	// 행동
	void Attack();
	void PickUpGun();
	void Zoom();
	void OpenInventory();
	void OpenEquipment();
	void FlyingMode();
	void SetAirControl(bool Flying);


	// Get Set
	void SetMyWeapon(AWeapon* CurrentWeapon) { MyWeapon = CurrentWeapon; }
	AWeapon* GetMyWeapon() { return MyWeapon; }
	void SetMyWing(AWing* CurrentWing) { MyWing = CurrentWing; }
	AWing* GetMyWing() { return MyWing; }
	UInventoryComponent* GetInventory() { return MyInventory; }
	UInventoryWidget* GetInventoryWidget() { return MyInventoryWidget; }
	UEquipmentWidget* GetEquipmentWidget() { return MyEquipmentWidget; }
	APet* GetMyPet() { return MyPet; }

	// Util
	void UpdateUI();
	void DragInventory();

	FCharacterDie CharacterDie;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

public:
	UPROPERTY()
		class USpringArmComponent* SpringArm;

	UPROPERTY()
		class UCameraComponent* Camera;


	// Gun , Bullet
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Stat)
		float Speed = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		bool IsWalking = false;

	UPROPERTY()
		FVector MuzzleOffset;

	UPROPERTY(EditDefaultsOnly, Category = Projectile)
		TSubclassOf<ABullet> Bullet;

	/** Gun mesh: 1st person view (seen only by self) */
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		class USkeletalMeshComponent* FP_Gun;

	/** Location on gun mesh where projectiles should spawn. */
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		class USceneComponent* FP_MuzzleLocation;

	// Util
	UPROPERTY()
		float RotateRate = 180.f; // Sensitivity

	UPROPERTY()
		bool IsZoom = false;

	UPROPERTY(VisibleAnywhere)
		class UMyCharacterStatComponent* Stat;

	// Flying

	UPROPERTY()
		bool bIsFlyingMode = false;

	UPROPERTY()
		bool bIsFlying = false;




private:

	// Gun
	UPROPERTY()
	AWeapon* MyWeapon = nullptr;

	UPROPERTY()
	TArray<ABullet*> Magazine;

	UPROPERTY(VisibleAnywhere, Category = Bullet)
		int MaxBulletSize = 0;

	UPROPERTY(VisibleAnywhere, Category = Bullet)
		int BulletIndex = 0;

	// Inventory
	UPROPERTY(VisibleAnywhere)
		 UInventoryComponent* MyInventory;

	UPROPERTY(EditAnywhere, Category = "UI")
		TSubclassOf<UUserWidget> MyInventoryWidgetClass;

	UPROPERTY()
		UInventoryWidget* MyInventoryWidget;

	UPROPERTY(EditAnywhere, Category = "UI")
		TSubclassOf<UUserWidget> MyEquipmentWidgetClass;

	UPROPERTY()
		UEquipmentWidget* MyEquipmentWidget;

	FVector2D DragOffset;
	bool bIsDragging = false;

	// Controller
	UPROPERTY()
		class APlayerController* MyController;

	UPROPERTY(EditAnywhere, Category = "UI")
		TSubclassOf<AWing> MyWingClass;

	// Wing
	UPROPERTY()
		class AWing* MyWing = nullptr;

	// Pet
	UPROPERTY()
		TSubclassOf<APet> PetClass;

	UPROPERTY()
	APet* MyPet = nullptr;

};
