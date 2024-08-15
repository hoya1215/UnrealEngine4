// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Gun.h"
#include "Bullet.h"
#include "Engine/World.h"
#include "EngineUtils.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"
#include "MyEnemy.h"
#include "MyCharacterStatComponent.h"
#include "MyGameModeBase.h"
#include "MyHUD.h"
#include "Components/TextBlock.h"
#include "Money.h"
#include "InventoryComponent.h"
#include "Components/WidgetComponent.h"
#include "InventoryWidget.h"
#include "EquipmentWidget.h"
#include "EnemyController.h"
#include "Pet.h"
#include "Wing.h"
#include "EquipmentSlotWidget.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SM(TEXT("SkeletalMesh'/Game/Mannequin/Character/Mesh/SK_Mannequin.SK_Mannequin'"));
	if (SM.Succeeded())
		GetMesh()->SetSkeletalMesh(SM.Object);

	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	GetMesh()->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, -88.f), FRotator(0.0f, -90.f, 0.f));

 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f);
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	//SpringArm
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->TargetArmLength = 400.0f;
	SpringArm->bUsePawnControlRotation = true;

	SpringArm->SetRelativeLocation(FVector(0.0f, 0.0f, 100.0f));
	//RootComponent = GetCapsuleComponent();
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	//Camera->SetupAttachment(GetMesh(), FName("head"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
	Camera->bUsePawnControlRotation = false;


	Speed = GetCharacterMovement()->MaxWalkSpeed;


	static ConstructorHelpers::FClassFinder<ABullet> ProjectileClassFinder(TEXT("Class'/Script/Game.Bullet'"));
	Bullet = ProjectileClassFinder.Class;
	MuzzleOffset = FVector(100.f, 0.f, 0.f);


	Stat = CreateDefaultSubobject<UMyCharacterStatComponent>(TEXT("Stat"));

	// Inventory
	MyInventory = CreateDefaultSubobject<UInventoryComponent>(TEXT("Inventory"));
	
	//MyInventoryWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("InventoryWidget"));
	ConstructorHelpers::FClassFinder<UInventoryWidget> IW(TEXT("WidgetBlueprint'/Game/Custom/UI/WBP_Inventory.WBP_Inventory_C'"));
	if (IW.Succeeded())
	{
		MyInventoryWidgetClass = IW.Class;
	}

	ConstructorHelpers::FClassFinder<UEquipmentWidget> EW(TEXT("WidgetBlueprint'/Game/Custom/UI/WBP_Equipment.WBP_Equipment_C'"));
	if (EW.Succeeded())
	{
		MyEquipmentWidgetClass = EW.Class;
	}

	
	
	static ConstructorHelpers::FClassFinder<APet> PC(TEXT("Blueprint'/Game/Custom/Blueprint/BP_Pet.BP_Pet_C'"));
	if (PC.Succeeded())
		PetClass = PC.Class;

	static ConstructorHelpers::FClassFinder<AWing> WingClass(TEXT("Blueprint'/Game/Custom/Blueprint/BP_Wing.BP_Wing_C'"));
	if (WingClass.Succeeded())
		MyWingClass = WingClass.Class;


}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	FName GunSocket(TEXT("hand_r_socket"));

	//auto Gun = GetWorld()->SpawnActor<AGun>(FVector::ZeroVector, FRotator::ZeroRotator);

	if (MyInventoryWidgetClass)
	{
		MyInventoryWidget = CreateWidget<UInventoryWidget>(GetWorld(), MyInventoryWidgetClass);
		if (MyInventoryWidget)
		{
			MyInventoryWidget->AddToViewport();
			FVector2D DesiredSize(330, 400);
			MyInventoryWidget->SetDesiredSizeInViewport(DesiredSize);
			
			// 원하는 위치로 설정
			FVector2D DesiredPosition(800, 200); 
			MyInventoryWidget->SetPositionInViewport(DesiredPosition, true); 

			MyInventoryWidget->SetVisibility(ESlateVisibility::Hidden);
		}
	}

	if (MyEquipmentWidgetClass)
	{
		MyEquipmentWidget = CreateWidget<UEquipmentWidget>(GetWorld(), MyEquipmentWidgetClass);
		if (MyEquipmentWidget)
		{
			MyEquipmentWidget->AddToViewport();
			FVector2D EquipmentSize(440, 500);
			MyEquipmentWidget->SetDesiredSizeInViewport(EquipmentSize);

			// 원하는 위치로 설정
			FVector2D EquipmentPosition(0, 0);
			MyEquipmentWidget->SetPositionInViewport(EquipmentPosition, true);

			MyEquipmentWidget->SetVisibility(ESlateVisibility::Hidden);
		}
	}


	if (GetWorld())
	{
		for (TActorIterator<AGun> It(GetWorld()); It; ++It)
		{
			AGun* GunInstance = *It;
			if (GunInstance)
			{
				GunInstance->PickUp.AddUObject(this, &AMyCharacter::PickUpGun);
			}
		}
	}



	MyController = GetWorld()->GetFirstPlayerController();

	if (PetClass)
	{
		FVector PetLocation = FVector(0.f, -100.f, 0.f);
		MyPet = GetWorld()->SpawnActor<APet>(PetClass, GetActorLocation() + PetLocation, GetActorRotation());

		if (MyPet)
		{
			MyPet->SetActorRelativeLocation(PetLocation);
			MyPet->SetActorRelativeRotation(GetActorRotation() + FRotator(0.f, -90.f, 0.f));
			MyPet->SetDefaultRotation(GetActorRotation() + FRotator(0.f, -90.f, 0.f));
			MyPet->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
			MyPet->GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
			MyPet->GetCapsuleComponent()->SetGenerateOverlapEvents(true);
		}
	}

	if (MyWingClass)
	{

		MyWing = GetWorld()->SpawnActor<AWing>(MyWingClass, GetActorLocation(), FRotator(-85.f, 80.f, 81.f));


		AItem* Result = MyWing->EquippedItem();
		if (Result)
		{
			UE_LOG(LogTemp, Warning, TEXT("Wing Failed"));
		}
		
	}
	

}


void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	

	if (bIsWalking)
		GetCharacterMovement()->MaxWalkSpeed = Speed * 0.5f;
	else
		GetCharacterMovement()->MaxWalkSpeed = Speed;

	if (bIsFlyingMode && GetCharacterMovement()->IsFalling())
	{
		bIsFlying = true;
	}
	else
		bIsFlying = false;



	if (Controller)
	{
		FRotator CameraRotation = Camera->GetComponentRotation();
		FRotator NewRotation(0, CameraRotation.Yaw, 0);  // Roll과 Pitch는 무시하고 Yaw만 사용
		SetActorRotation(NewRotation);
	}

	int32 CurrentHp = Stat->GetHp();
	if (CurrentHp <= 0)
	{
		GetMesh()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		SetActorTickEnabled(false);
		CharacterDie.Broadcast();

	}

	if (bIsDragging)
	{
			FVector2D MousePosition;
			MyController->GetMousePosition(MousePosition.X, MousePosition.Y);

			FVector2D NewPosition = MousePosition + DragOffset;
			MyInventoryWidget->SetPositionInViewport(NewPosition, false);
			bIsDragging = false;
	}

	if (MyWeapon == nullptr)
		CurrentWeaponState = 2;

}

void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	check(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, &AMyCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMyCharacter::MoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &AMyCharacter::Turn);
	PlayerInputComponent->BindAxis("LookUp", this, &AMyCharacter::LookUp);

	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &AMyCharacter::Jump);
	PlayerInputComponent->BindAction(TEXT("Walk"), EInputEvent::IE_Pressed, this, &AMyCharacter::Walk);
	PlayerInputComponent->BindAction(TEXT("Walk"), EInputEvent::IE_Released, this, &AMyCharacter::StopWalk);
	PlayerInputComponent->BindAction(TEXT("Attack"), EInputEvent::IE_Pressed, this, &AMyCharacter::Attack);
	//PlayerInputComponent->BindAction(TEXT("Zoom"), EInputEvent::IE_Pressed, this, &AMyCharacter::Zoom);
	PlayerInputComponent->BindAction(TEXT("OpenInventory"), EInputEvent::IE_Pressed, this, &AMyCharacter::OpenInventory);
	PlayerInputComponent->BindAction(TEXT("FlyingMode"), EInputEvent::IE_Pressed, this, &AMyCharacter::FlyingMode);
	PlayerInputComponent->BindAction(TEXT("OpenEquipment"), EInputEvent::IE_Pressed, this, &AMyCharacter::OpenEquipment);

	PlayerInputComponent->BindAction(TEXT("SelectMainWeapon"), EInputEvent::IE_Pressed, this, &AMyCharacter::SelectWeapon);
	PlayerInputComponent->BindAction(TEXT("SelectSubWeapon"), EInputEvent::IE_Pressed, this, &AMyCharacter::SelectWeapon);
	PlayerInputComponent->BindAction(TEXT("SelectOtherWeapon"), EInputEvent::IE_Pressed, this, &AMyCharacter::SelectWeapon);
}

float AMyCharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	Stat->OnAttacked(DamageAmount);

	return DamageAmount;
}

void AMyCharacter::MoveForward(float value)
{
	const FRotator Rotation = Controller->GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);

	const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	AddMovementInput(Direction, value);
}

void AMyCharacter::MoveRight(float value)
{
	if (value == 0.f)
		return;

	const FRotator Rotation = Controller->GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);

	const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	AddMovementInput(Direction, value);

}

void AMyCharacter::Turn(float rate)
{
	AddControllerYawInput(rate * RotateRate * GetWorld()->GetDeltaSeconds());
}

void AMyCharacter::LookUp(float rate)
{
	AddControllerPitchInput(rate * RotateRate * GetWorld()->GetDeltaSeconds());
}

void AMyCharacter::Walk()
{
	bIsWalking = true;
	
}

void AMyCharacter::StopWalk()
{
	bIsWalking = false;
}

void AMyCharacter::Jump()
{
	Super::Jump();
}

bool AMyCharacter::CanJumpInternal_Implementation() const
{
	if (bIsFlying)
		return true;
	

	return Super::CanJumpInternal_Implementation();
}

void AMyCharacter::UpdateUI()
{
	AMyGameModeBase* MyGameMode = Cast<AMyGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	if (MyGameMode && MyWeapon)
	{
		UMyHUD* MyHUD = Cast<UMyHUD>(MyGameMode->Widget);
		if (MyHUD)
		{
			// 총알 갯수 
			const FString BulletString = FString::Printf(TEXT("Bullet %01d / %01d"), MyWeapon->CurrentBulletCount, MyWeapon->MaxBulletCount);
			MyHUD->BulletText->SetText(FText::FromString(BulletString));
		}
	}
}

void AMyCharacter::Attack()
{
	bIsAttacking = true;

	switch (CurrentWeaponState)
	{
	case 2:
		OtherAttack();
		break;
	default:
		MainAttack();
		break;
	}
}

void AMyCharacter::MainAttack()
{
	if (MyWeapon)
	{
		MyWeapon->CurrentBulletCount--;
		UpdateUI();


		auto World = GetWorld();
		// 크로스헤어 위치를 통해 월드 위치와 방향 계산
		FVector2D Center;
		GEngine->GameViewport->GetViewportSize(Center);
		Center /= 2.f;
		FVector WorldLocation, WorldDirection;
		UGameplayStatics::DeprojectScreenToWorld(UGameplayStatics::GetPlayerController(this, 0), Center, WorldLocation, WorldDirection);

		//FVector LaunchDirection = Camera->GetForwardVector();
		FVector LaunchDirection = WorldDirection;
		//DrawDebugLine(World, Camera->GetComponentLocation(), Camera->GetComponentLocation() + LaunchDirection * 1000, FColor::Red, false, 1, 0, 1);
		//CurrentBullet->Shoot(LaunchDirection);
		FVector Start = Camera->GetComponentLocation();
		FVector End = Camera->GetComponentLocation() + LaunchDirection * 10000;

		FHitResult HitResult;
		FCollisionQueryParams CollisionParams;
		CollisionParams.AddIgnoredActor(this);

		bool bHit = World->LineTraceSingleByChannel(HitResult, Start, End, ECC_Visibility, CollisionParams);

		if (bHit)
		{
			DrawDebugLine(GetWorld(), Start, End, FColor::Red, false, 1.0f, 0, 1.0f);

			UE_LOG(LogTemp, Warning, TEXT("Hit: %s"), *HitResult.Actor->GetName());


			if (HitResult.Actor.IsValid())
			{
				FDamageEvent DamageEvent;

				HitResult.Actor->TakeDamage(Stat->GetPower(), DamageEvent, GetController(), this);
			}

			if (MyWeapon->Effect)
			{
				UGameplayStatics::SpawnEmitterAtLocation(World, MyWeapon->Effect, HitResult.Location, FRotator(0.f), true);
			}


		}
		else
		{
			DrawDebugLine(GetWorld(), Start, End, FColor::Green, false, 1.0f, 0, 1.0f);
		}


	}
}

void AMyCharacter::OtherAttack()
{
	FHitResult HitResult;
	FCollisionQueryParams Params(NAME_None, false, this);

	float Range = 100.0f;
	float Radius = 50.f;

	bool bResult = GetWorld()->SweepSingleByChannel(
		OUT HitResult,
		GetActorLocation(),
		GetActorLocation() + GetActorForwardVector() * Range,
		FQuat::Identity,
		ECollisionChannel::ECC_GameTraceChannel3,
		FCollisionShape::MakeSphere(Radius),
		Params
	);

	// 디버거용 그림
	FVector Vec = GetActorForwardVector() * Range;
	FVector Center = GetActorLocation() + Vec * 0.5f;
	float HalfHeight = Range * 0.5f + Radius;
	FQuat Rotation = FRotationMatrix::MakeFromZ(Vec).ToQuat();
	FColor DrawColor;
	if (bResult)
		DrawColor = FColor::Green;
	else
		DrawColor = FColor::Red;

	DrawDebugCapsule(GetWorld(), Center, HalfHeight, Radius, Rotation, DrawColor, false, 2.f);

	if (bResult && HitResult.Actor.IsValid())
	{

		FDamageEvent event;
		HitResult.Actor->TakeDamage(Stat->GetPower(), event, GetController(), this);
	}
}

void AMyCharacter::PickUpGun()
{
	AMyGameModeBase* MyGameMode = Cast<AMyGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	if (MyGameMode)
	{
		if (MyGameMode->Widget->IsInViewport())
			return;

		MyGameMode->Widget->AddToViewport();
	}

	//UpdateUI();
}

void AMyCharacter::Zoom()
{
	if (IsZoom)
	{
		Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
		Camera->SetRelativeLocation(FVector(0.f, 0.f, 100.f));
		SpringArm->TargetArmLength = 400.f;
	}
	else
	{
		Camera->SetRelativeLocation(FVector(0.f, 0.f, 50.f));
		SpringArm->SetRelativeLocation(FVector::ZeroVector);
		SpringArm->TargetArmLength = 0.f;

	}

	IsZoom = !IsZoom;
}

void AMyCharacter::OpenInventory()
{
	

	if (MyInventoryWidget)
	{
		ESlateVisibility Visibility = MyInventoryWidget->GetVisibility();
		if (Visibility == ESlateVisibility::Visible)
		{
			MyInventoryWidget->SetVisibility(ESlateVisibility::Hidden);
			// 현재 플레이어 컨트롤러 가져오기
			//APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
			if (MyController)
			{
				MyController->bShowMouseCursor = false; // 마우스 커서 숨기기
				MyController->SetIgnoreLookInput(false);
				//PlayerController->SetInputMode(FInputModeGameOnly()); // 게임 입력 모드로 전환
			}
		}
		else
		{
			MyInventoryWidget->SetVisibility(ESlateVisibility::Visible);
			// 현재 플레이어 컨트롤러 가져오기
			//APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
			if (MyController)
			{
				MyController->bShowMouseCursor = true; // 마우스 커서 보이기
				MyController->SetIgnoreLookInput(true);
				//FInputModeGameAndUI InputMode;
				//InputMode.SetWidgetToFocus(TakeWidget());
				//PlayerController->SetInputMode(InputMode); // 게임과 UI 입력 모드 설정
			}
		}
	}
}

void AMyCharacter::OpenEquipment()
{
	if (MyEquipmentWidget)
	{
		ESlateVisibility Visibility = MyEquipmentWidget->GetVisibility();
		if (Visibility == ESlateVisibility::Visible)
		{
			MyEquipmentWidget->SetVisibility(ESlateVisibility::Hidden);

			if (MyController)
			{
				MyController->bShowMouseCursor = false; 
				MyController->SetIgnoreLookInput(false);
			
			}
		}
		else
		{
			MyEquipmentWidget->SetVisibility(ESlateVisibility::Visible);
			
			if (MyController)
			{
				MyController->bShowMouseCursor = true; // 마우스 커서 보이기
				MyController->SetIgnoreLookInput(true);
			}
		}
	}
}

void AMyCharacter::DragInventory()
{
	FVector2D MousePosition;
	MyController->GetMousePosition(MousePosition.X, MousePosition.Y);

	FVector2D WidgetPosition = MyInventoryWidget->GetCachedGeometry().GetAbsolutePosition();
	DragOffset = WidgetPosition - MousePosition;

	bIsDragging = true;
}

void AMyCharacter::FlyingMode()
{
	if (MyWing == nullptr)
	{
		bIsFlyingMode = false;
		return;
	}

	if (bIsFlyingMode)
	{
		bIsFlyingMode = false;
		SetAirControl(bIsFlyingMode);
	}
	else
	{
		bIsFlyingMode = true;
		SetAirControl(bIsFlyingMode);
	}
}

void AMyCharacter::SetAirControl(bool Flying)
{
	if (Flying)
	{
		GetCharacterMovement()->AirControl = 1.0f;
		GetCharacterMovement()->AirControlBoostMultiplier = 1.0f;
		GetCharacterMovement()->AirControlBoostVelocityThreshold = 0.f;
		GetCharacterMovement()->FallingLateralFriction = 8.0f;
		GetCharacterMovement()->GravityScale = 0.3f;
	}
	else
	{
		GetCharacterMovement()->AirControl = 0.05f;
		GetCharacterMovement()->AirControlBoostMultiplier = 2.0f;
		GetCharacterMovement()->AirControlBoostVelocityThreshold = 25.f;
		GetCharacterMovement()->FallingLateralFriction = 0.0f;
		GetCharacterMovement()->GravityScale = 1.0f;
	}
}

void AMyCharacter::SelectWeapon(FKey Key)
{


	if (Key == EKeys::One)
	{
		CurrentWeaponState = 0;
		ChangeCurrentWeapon(EEQUIPMENT_TYPE::MAIN);
	}
	else if (Key == EKeys::Two)
	{
		CurrentWeaponState = 1;
		ChangeCurrentWeapon(EEQUIPMENT_TYPE::SUB);
	}
	else if (Key == EKeys::Three)
	{
		CurrentWeaponState = 2;
		ChangeCurrentWeapon(EEQUIPMENT_TYPE::OTHER);
	}

	bIsWeaponSwapping = true;
}

void AMyCharacter::ChangeCurrentWeapon(EEQUIPMENT_TYPE EquipmentType)
{
	AWeapon* NewWeapon = Cast<AWeapon>(MyEquipmentWidget->EquipmentSlots[EquipmentType]->CurrentItem);

	if (NewWeapon != nullptr)
	{
		MyWeapon->SetActorHiddenInGame(true);
		NewWeapon->SetActorHiddenInGame(false);
		SetMyWeapon(NewWeapon);
	}
}

void AMyCharacter::SetMyWeapon(AWeapon* CurrentWeapon)
{
	MyWeapon = CurrentWeapon;
	CurrentWeaponState = CurrentWeapon->WeaponState;
}


