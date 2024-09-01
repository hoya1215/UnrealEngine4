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
	HELMET UMETA(DisplayName = "Helmet")
};


UENUM()
enum class EITEM_TYPE : uint8
{
	MONEY UMETA(DisplayName = "Money"),
	POTION UMETA(DisplayName = "Potion")
};

USTRUCT()
struct FItemInfo
{
	GENERATED_BODY()

public:
	FItemInfo()
	{
		ItemName = FName(TEXT("NULL"));
		Level = 0;
	}

	FItemInfo& operator=(const FItemInfo& NewInfo)
	{
		if (this != &NewInfo)
		{
			this->ItemName = NewInfo.ItemName;
			this->Level = NewInfo.Level;
		}
		return *this;
	}

	UPROPERTY()
	FName ItemName;

	UPROPERTY()
	int Level;
};

UCLASS()
class GAME_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	AItem();

	virtual void EquippedItem(FItemInfo Item);
	virtual void UnEquippedItem();
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
		int Level = 0;

	UPROPERTY()
		FItemInfo ItemInfo;

	UPROPERTY()
		FRotator RelativeRotation = FRotator(0.f, 0.f, 0.f);

	////UPROPERTY(EditAnywhere, BlueprintReadWrite)
	//TSharedPtr<class UTexture2D> ItemTexture;

	bool bCanMagnet = true;

};
