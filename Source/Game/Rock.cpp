// Fill out your copyright notice in the Description page of Project Settings.


#include "Rock.h"
#include "Components/BoxComponent.h"

// Sets default values
ARock::ARock()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RockMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Rock"));
	Trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("TRIGGER"));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM(TEXT("StaticMesh'/Game/Fantastic_Village_Pack/meshes/props/food/SM_PROP_food_bread_04.SM_PROP_food_bread_04'"));
	if (SM.Succeeded())
		RockMesh->SetStaticMesh(SM.Object);

	Trigger->SetCollisionProfileName(TEXT("InteractObject"));
	Trigger->SetBoxExtent(FVector(10.f, 10.f, 10.f));

	RootComponent = RockMesh;
	Trigger->SetupAttachment(RockMesh);

	//SetActorLabel(TEXT("Rock"));
}

// Called when the game starts or when spawned
void ARock::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARock::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

