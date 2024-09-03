// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Containers/Queue.h"
#include "Item.h"
#include "MyCharacter.generated.h"

class AGun;
class ABullet;
class UInventoryComponent;
class UWidgetComponent;
class UUserWidget;
class UInventoryWidget;
class UEquipmentWidget;
class UEnhanceWidget;
class APet;
class AWeapon;
class AWing;
class AShoes;
class AHelmet;
class UMyHUD;
class USoundCue;

USTRUCT()
struct FSounds
{
	GENERATED_BODY()

	UPROPERTY()
	USoundCue* DieSound;

	UPROPERTY()
	USoundCue* JumpSound;

	UPROPERTY()
	USoundCue* MoveSound;

	UPROPERTY()
	USoundCue* AttackSound;
};



DECLARE_MULTICAST_DELEGATE(FCharacterDie)
DECLARE_MULTICAST_DELEGATE(FCharacterRevive)
DECLARE_MULTICAST_DELEGATE(FHpChange)
DECLARE_MULTICAST_DELEGATE(FWeaponChange)
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
	void MouseClick();
	void Attack();
	void LeftMouseNonClick();
	void PickUpGun();
	void Zoom();
	void OpenInventory();
	void OpenEquipment();
	void OpenEnhance();
	void FlyingMode();
	void SetAirControl(bool Flying);
	void SelectWeapon(FKey Key);
	void ChangeCurrentWeapon(EEQUIPMENT_TYPE EquipmentType);
	void MainAttack();
	void SubAttack();
	void OtherAttack();
	void Die();
	void Revive();
	void ChangeSpeed();


	// Get Set
	void SetMyWeapon(AWeapon* CurrentWeapon);
	AWeapon* GetMyWeapon() { return MyWeapon; }
	void SetMyWing(AWing* CurrentWing) { MyWing = CurrentWing; }
	void SetMyShoes(AShoes* CurrentShoes) { MyShoes = CurrentShoes; }
	void SetMyHelmet(AHelmet* CurrentHelmet) { MyHelmet = CurrentHelmet; }
	AWing* GetMyWing() { return MyWing; }
	AHelmet* GetMyHelmet() { return MyHelmet; }
	AShoes* GetMyShoes() { return MyShoes; }
	UInventoryComponent* GetInventory() { return MyInventory; }
	UInventoryWidget* GetInventoryWidget() { return MyInventoryWidget; }
	UEquipmentWidget* GetEquipmentWidget() { return MyEquipmentWidget; }
	UEnhanceWidget* GetEnhanceWidget() { return MyEnhanceWidget; }
	APet* GetMyPet() { return MyPet; }

	// Util
	void UpdateUI();
	void DragInventory();

	FCharacterDie CharacterDie;
	FCharacterRevive CharacterRevive;
	FHpChange HpChange;
	FWeaponChange WeaponChange;

protected:
	virtual void BeginPlay() override;


public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

public:

	// Camera
	UPROPERTY()
		class USpringArmComponent* SpringArm;

	UPROPERTY()
		class UCameraComponent* Camera;





	// Gun , Bullet
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

	UPROPERTY()
		int CurrentWeaponState = 2;

	UPROPERTY()
		bool bIsWeaponSwapping = false;

	UPROPERTY(VisibleAnywhere)
		class UMyCharacterStatComponent* Stat;

	UPROPERTY()
		float ForwardValue;

	UPROPERTY()
		float SideValue;

	UPROPERTY()
		float DefaultSpeed;

	// State
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Stat)
		float Speed = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		bool bIsWalking = false;

	UPROPERTY()
		bool bIsFlyingMode = false;

	UPROPERTY()
		bool bIsFlying = false;

	UPROPERTY()
		bool bIsAttacking = false;

	UPROPERTY()
		bool bCanPickUp = true;

	UPROPERTY()
		bool bIsInventoryOn = false;

	UPROPERTY()
		bool bIsEquipmentOn = false;

	UPROPERTY()
		bool bIsEnhanceOn = false;

	// Sound
	UPROPERTY()
		FSounds Sounds;

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

	UPROPERTY(EditAnywhere, Category = "UI")
		UEnhanceWidget* MyEnhanceWidget;

	UPROPERTY()
		TSubclassOf<UEnhanceWidget> MyEnhanceWidgetClass;

	FVector2D DragOffset;
	bool bIsDragging = false;




	// Controller
	UPROPERTY()
		class APlayerController* MyController;

	UPROPERTY(EditAnywhere, Category = "UI")
		TSubclassOf<AWing> MyWingClass;

	// Wing
	UPROPERTY()
		AWing* MyWing = nullptr;

	// Shoes
	UPROPERTY()
		AShoes* MyShoes = nullptr;

	// Helmet
	UPROPERTY()
		AHelmet* MyHelmet = nullptr;



	// Pet
	UPROPERTY()
		TSubclassOf<APet> PetClass;

	UPROPERTY()
	APet* MyPet = nullptr;

	// Timer
	UPROPERTY()
		FTimerHandle MouseTimerHandle;


};
