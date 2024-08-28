// Fill out your copyright notice in the Description page of Project Settings.


#include "Bullet.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"

// Sets default values
ABullet::ABullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;

	CollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Collision"));
	CollisionSphere->InitSphereRadius(5.0f);
	CollisionSphere->BodyInstance.SetCollisionProfileName("Bullet");
	CollisionSphere->OnComponentHit.AddDynamic(this, &ABullet::OnHit);
	RootComponent = CollisionSphere;

	CollisionSphere->SetWalkableSlopeOverride(FWalkableSlopeOverride(WalkableSlope_Unwalkable, 0.f));
	CollisionSphere->CanCharacterStepUpOn = ECB_No;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BULLET"));
	
	static ConstructorHelpers::FObjectFinder<UStaticMesh> BL(TEXT("StaticMesh'/Game/FPS_Weapon_Bundle/Weapons/Meshes/Ammunition/SM_Shell_762x51.SM_Shell_762x51'"));
	if (BL.Succeeded())
		Mesh->SetStaticMesh(BL.Object);

	Mesh->SetupAttachment(CollisionSphere);
	Mesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileComp"));
	ProjectileMovement->SetUpdatedComponent(CollisionSphere);
	//ProjectileMovement->UpdatedComponent = CollisionSphere;
	ProjectileMovement->InitialSpeed = 3000.f;
	ProjectileMovement->MaxSpeed = 3000.f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = true;
	ProjectileMovement->Bounciness = 0.3f;

	// Die after 3 seconds by default
	InitialLifeSpan = 3.0f;
	//// tick ½ÇÇà x
	//PrimaryActorTick.bCanEverTick = false;
	SetActorScale3D(FVector(10.f, 10.f, 10.f));
}

void ABullet::Shoot(const FVector ShootDirection)
{
ProjectileMovement->Velocity = ShootDirection * ProjectileMovement->InitialSpeed;
}

void ABullet::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if ((OtherActor != NULL) && (OtherActor != this) && (OtherComp != NULL) && OtherComp->IsSimulatingPhysics())
	{
		OtherComp->AddImpulseAtLocation(GetVelocity() * 100.0f, GetActorLocation());

		Destroy();
	}
}




