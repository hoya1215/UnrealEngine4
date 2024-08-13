// Fill out your copyright notice in the Description page of Project Settings.


#include "Gun.h"
#include "Components/BoxComponent.h"
#include "Particles/ParticleSystem.h"
#include "Particles/ParticleSystemComponent.h"
#include "MyCharacter.h"
#include "InventoryWidget.h"

// Sets default values
AGun::AGun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MyGun = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("GUN"));
	//Trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("TRIGGER"));
	//GunEffect = CreateDefaultSubobject<UParticleSystem>(TEXT("Effect"));

	ConstructorHelpers::FObjectFinder<UStaticMesh> SM(TEXT("StaticMesh'/Game/FPS_Weapon_Bundle/Weapons/Meshes/Ka47/SM_KA47_X.SM_KA47_X'"));
	if (SM.Succeeded())
		MyGun->SetStaticMesh(SM.Object);

	ConstructorHelpers::FObjectFinder<UParticleSystem> PS(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Explosion.P_Explosion'"));
	if (PS.Succeeded())
		Effect = PS.Object;

	// 충돌
	MyGun->SetCollisionProfileName(TEXT("Gun"));
	Trigger->SetCollisionProfileName(TEXT("Gun"));
	Trigger->SetBoxExtent(FVector(30.f, 30.f, 30.f));

	RootComponent = MyGun;
	Trigger->SetupAttachment(MyGun);

	SetActorLocation(FVector(0.f, 10.f, 200.f));

	EquipmentType = EEQUIPMENT_TYPE::MAIN;

	UTexture2D* MainGunTexture = LoadObject<UTexture2D>(nullptr, TEXT("Texture2D'/Game/Custom/Resources/KA47.KA47'"));
	ItemTexture = MainGunTexture;

	MaxBulletCount = 5;
	CurrentBulletCount = 0;

}

// Called when the game starts or when spawned
void AGun::BeginPlay()
{
	Super::BeginPlay();
	

}

void AGun::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	Trigger->OnComponentBeginOverlap.AddDynamic(this, &AGun::OnCharacterOverlap);
}

void AGun::OnCharacterOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//UE_LOG(LogTemp, Warning, TEXT("Gun Overlap"));
	if (bContainInventory)
		return;

	AMyCharacter* MyCharacter = Cast<AMyCharacter>(OtherActor);
	if (MyCharacter)
	{
		// 인벤토리 추가 or 장비창 추가 (자동 장착 or not)
		if (MyCharacter->GetInventoryWidget())
		{
			MyCharacter->GetInventoryWidget()->AddItemToInventory(this);
			SetActorTickEnabled(false);
			SetActorEnableCollision(false);
			SetActorHiddenInGame(true);
			bContainInventory = true;
		}

		// 장착
		//FName GunSocket(TEXT("middle_r_socket"));

		//AttachToComponent(MyCharacter->GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale,
		//	GunSocket);
		//SetActorRotation(FRotator(0.f, 0.f, 0.f));
		//MyCharacter->SetMyGun(this);
		//PickUp.Broadcast();

		

	}
}

// Called every frame
void AGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//SetActorRelativeRotation(FRotator(0.f, 0.f, 0.f));
}


