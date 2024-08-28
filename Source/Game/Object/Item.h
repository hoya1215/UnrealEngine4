// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/DataTable.h"
#include "Item.generated.h"



UENUM()
enum class EINVENTORY_TYPE : uint8
{
	EQUIPMENT UMETA(DisplayName = "EquipMent"),
	CONSUMPTION UMETA(DisplayName = "Consumption"),
	ETC UMETA(DisplayName = "Etc")
};

UENUM()
enum class EEQUIPMENT_TYPE : uint8
{
	MAIN UMETA(DisplayName = "Main"),
	SUB UMETA(DisplayName = "Sub"),
	OTHER UMETA(DisplayName = "Other"),
	WING UMETA(DisplayName = "Wing"),
	SHOES UMETA(DisplayName = "Shoes"),
	HEAD UMETA(DisplayName = "Head")
};


UENUM()
enum class EITEM_TYPE : uint8
{
	MONEY UMETA(DisplayName = "Money")
};

UCLASS()
class GAME_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	AItem();

	virtual FName EquippedItem();
	virtual void AttachToCharacter();
	virtual void UseItem();

protected:
	virtual void BeginPlay() override;

	virtual void PostInitializeComponents() override;

	

private:
	UFUNCTION()
	virtual	void OnCharacterOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
			UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

public:	

	UPROPERTY(VisibleAnywhere)
		class UBoxComponent* Trigger;

	UPROPERTY(VisibleAnywhere)
		FName ItemName;

	UPROPERTY(VisibleAnywhere)
		EINVENTORY_TYPE InventoryType;

	UPROPERTY(VisibleAnywhere)
		EITEM_TYPE ItemType;

	UPROPERTY()
		EEQUIPMENT_TYPE EquipmentType;

	UPROPERTY()
		TSubclassOf<AItem> ItemClass;

	UPROPERTY()
		FRotator RelativeRotation = FRotator(0.f, 0.f, 0.f);

	////UPROPERTY(EditAnywhere, BlueprintReadWrite)
	//TSharedPtr<class UTexture2D> ItemTexture;

	bool bCanMagnet = true;

};
