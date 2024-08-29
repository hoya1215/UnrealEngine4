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
#include "Shoes.h"
#include "Helmet.h"
#include "EquipmentSlotWidget.h"
#include "Sound/SoundCue.h"
#include "Util.h"

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

	GetCharacterMovement()->bOrientRotationToMovement = false; // Character moves in the direction of input...	
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

	DefaultSpeed = GetCharacterMovement()->MaxWalkSpeed;

	// Sound
	Sounds.DieSound = LoadObject<USoundCue>(nullptr, TEXT("SoundCue'/Game/Custom/Sound/voice_male_d_death_06_Cue.voice_male_d_death_06_Cue'"));
	Sounds.JumpSound = LoadObject<USoundCue>(nullptr, TEXT("SoundCue'/Game/Custom/Sound/voice_male_c_effort_short_jump_01_Cue.voice_male_c_effort_short_jump_01_Cue'"));



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
			
			// ���ϴ� ��ġ�� ����
			FVector2D DesiredPosition(800, 100); 
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

			// ���ϴ� ��ġ�� ����
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


		MyWing->EquippedItem();
		
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
		FRotator NewRotation(0, CameraRotation.Yaw, 0);  // Roll�� Pitch�� �����ϰ� Yaw�� ���
		SetActorRotation(NewRotation);
	}

	float CurrentHp = Stat->GetHp();
	if (CurrentHp <= 0.0)
	{
		GetMesh()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		SetActorTickEnabled(false);
		CharacterDie.Broadcast();
		Util::PlaySound(this, Sounds.DieSound, GetActorLocation());
		//UGameplayStatics::PlaySoundAtLocation(this, DieSound, GetActorLocation());
	}

	if (bIsDragging)
	{
			FVector2D MousePosition;
			MyController->GetMousePosition(MousePosition.X, MousePosition.Y);

			FVector2D NewPosition = MousePosition + DragOffset;
			MyInventoryWidget->SetPositionInViewport(NewPosition, false);
			bIsDragging = false;
	}

	//if (MyWeapon == nullptr)
	//	CurrentWeaponState = 2;
	//else
	//{
	//	// ����
	//	FName GunSocket(TEXT("middle_r_socket"));

	//	MyWeapon->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale,
	//		GunSocket);
	//	SetActorRotation(FRotator(0.f, 0.f, 0.f));
	//}


	// Tick �� �ƴϰ� ���� �������ٶ����� �ϸ� ���� �ӵ��� ��ȭ x -> ����
	if (MyWeapon == nullptr)
		CurrentWeaponState = 2;

	GetCharacterMovement()->MaxWalkSpeed = DefaultSpeed;
	//ChangeSpeed();
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
	PlayerInputComponent->BindAction(TEXT("Attack"), EInputEvent::IE_Released, this, &AMyCharacter::LeftMouseNonClick);
	//PlayerInputComponent->BindAction(TEXT("Zoom"), EInputEvent::IE_Pressed, this, &AMyCharacter::Zoom);
	PlayerInputComponent->BindAction(TEXT("OpenInventory"), EInputEvent::IE_Pressed, this, &AMyCharacter::OpenInventory);
	PlayerInputComponent->BindAction(TEXT("FlyingMode"), EInputEvent::IE_Pressed, this, &AMyCharacter::FlyingMode);
	PlayerInputComponent->BindAction(TEXT("OpenEquipment"), EInputEvent::IE_Pressed, this, &AMyCharacter::OpenEquipment);

	PlayerInputComponent->BindAction(TEXT("SelectMainWeapon"), EInputEvent::IE_Pressed, this, &AMyCharacter::SelectWeapon);
	PlayerInputComponent->BindAction(TEXT("SelectSubWeapon"), EInputEvent::IE_Pressed, this, &AMyCharacter::SelectWeapon);
	PlayerInputComponent->BindAction(TEXT("SelectOtherWeapon"), EInputEvent::IE_Pressed, this, &AMyCharacter::SelectWeapon);
	PlayerInputComponent->BindAction(TEXT("Revive"), EInputEvent::IE_Pressed, this, &AMyCharacter::Revive);
}

float AMyCharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	Stat->OnAttacked(DamageAmount);
	HpChange.Broadcast();

	return DamageAmount;
}

void AMyCharacter::MoveForward(float value)
{
	ForwardValue = value;

	if (value == 0.f)
		return;

	const FRotator Rotation = Controller->GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);

	const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	AddMovementInput(GetActorForwardVector(), value);
}

void AMyCharacter::MoveRight(float value)
{
	SideValue = value;

	if (value == 0.f)
		return;

	const FRotator Rotation = Controller->GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);
	
	const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	AddMovementInput(GetActorRightVector(), value);

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

	if (!GetMovementComponent()->IsFalling())
	{
		Util::PlaySound(this, Sounds.JumpSound, GetActorLocation());
	}
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
			// �Ѿ� ���� 
			const FString BulletString = FString::Printf(TEXT("Bullet %01d / %01d"), MyWeapon->CurrentBulletCount, MyWeapon->MaxBulletCount);
			//MyHUD->BulletText->SetText(FText::FromString(BulletString));
		}
	}
}

void AMyCharacter::MouseClick()
{
	GetWorldTimerManager().SetTimer(MouseTimerHandle, this, &AMyCharacter::Attack, 0.1f, true);
}

void AMyCharacter::Attack()
{
	if (bIsInventoryOn || bIsEquipmentOn)
		return;


	if (MyWeapon != nullptr)
	{
		bIsAttacking = true;


		switch (CurrentWeaponState)
		{
		case 1:
			GetWorldTimerManager().SetTimer(MouseTimerHandle, this, &AMyCharacter::SubAttack, 0.1f, true);
			//SubAttack();
			break;
		case 2:
			break;
		default:
			MainAttack();
			break;
		}

		// ���� Anim Notify ��
	}

	if (Sounds.AttackSound)
	{
		Util::PlaySound(this, Sounds.AttackSound, GetActorLocation());
	}

}

void AMyCharacter::MainAttack()
{
	if (MyWeapon)
	{
		MyWeapon->CurrentBulletCount--;
		//UpdateUI();


		auto World = GetWorld();
		// ũ�ν���� ��ġ�� ���� ���� ��ġ�� ���� ���
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

	bIsAttacking = false;
}

void AMyCharacter::SubAttack()
{
	if (!MyWeapon)
		return;

	bIsAttacking = true;
	MyWeapon->EffectComponent->Activate();

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

	// ����ſ� �׸�
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
		// Fire Gun damage per second
		AMyEnemy* CurrentEnemy = Cast<AMyEnemy>(HitResult.Actor);
		if (CurrentEnemy && CurrentEnemy->FireGunDamageTime > 60.f)
		{
			CurrentEnemy->FireGunDamageTime = 0.f;
			FDamageEvent event;
			HitResult.Actor->TakeDamage(Stat->GetPower(), event, GetController(), this);
		}


	}

}

void AMyCharacter::OtherAttack()
{
	if (!MyWeapon)
		return;

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

	// ����ſ� �׸�
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
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), MyWeapon->Effect, HitResult.Actor->GetActorLocation(), FRotator(0.f), true);


		FDamageEvent event;
		HitResult.Actor->TakeDamage(Stat->GetPower(), event, GetController(), this);
	}

	bIsAttacking = false;
}

void AMyCharacter::LeftMouseNonClick()
{


	if (MyWeapon && CurrentWeaponState == 1)
	{
		GetWorldTimerManager().ClearTimer(MouseTimerHandle);

		bIsAttacking = false;

		MyWeapon->EffectComponent->Deactivate();
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
	bIsInventoryOn = !bIsInventoryOn;

	if (MyInventoryWidget)
	{
		ESlateVisibility Visibility = MyInventoryWidget->GetVisibility();
		if (Visibility == ESlateVisibility::Visible)
		{
			MyInventoryWidget->SetVisibility(ESlateVisibility::Hidden);
			// ���� �÷��̾� ��Ʈ�ѷ� ��������
			//APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
			if (MyController)
			{
				MyController->bShowMouseCursor = false; // ���콺 Ŀ�� �����
				MyController->SetIgnoreLookInput(false);
				//PlayerController->SetInputMode(FInputModeGameOnly()); // ���� �Է� ���� ��ȯ
			}
		}
		else
		{
			MyInventoryWidget->SetVisibility(ESlateVisibility::Visible);
			// ���� �÷��̾� ��Ʈ�ѷ� ��������
			//APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
			if (MyController)
			{
				MyController->bShowMouseCursor = true; // ���콺 Ŀ�� ���̱�
				MyController->SetIgnoreLookInput(true);
				//FInputModeGameAndUI InputMode;
				//InputMode.SetWidgetToFocus(TakeWidget());
				//PlayerController->SetInputMode(InputMode); // ���Ӱ� UI �Է� ��� ����
			}
		}
	}
}

void AMyCharacter::OpenEquipment()
{
	bIsEquipmentOn = !bIsEquipmentOn;

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
				MyController->bShowMouseCursor = true; // ���콺 Ŀ�� ���̱�
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
		
		FName Name = MyEquipmentWidget->EquipmentSlots[EEQUIPMENT_TYPE::MAIN]->ItemName;
		if (Name == FName(TEXT("NULL")) || (MyWeapon != nullptr && CurrentWeaponState == 0))
			return;
		CurrentWeaponState = 0;
		//ChangeCurrentWeapon(EEQUIPMENT_TYPE::MAIN);
	}
	else if (Key == EKeys::Two)
	{
		
		FName Name = MyEquipmentWidget->EquipmentSlots[EEQUIPMENT_TYPE::SUB]->ItemName;
		if (Name == FName(TEXT("NULL")) || (MyWeapon != nullptr && CurrentWeaponState == 1))
			return;
		CurrentWeaponState = 1;
		//ChangeCurrentWeapon(EEQUIPMENT_TYPE::SUB);
	}
	else if (Key == EKeys::Three)
	{
		
		FName Name = MyEquipmentWidget->EquipmentSlots[EEQUIPMENT_TYPE::OTHER]->ItemName;
		if (Name == FName(TEXT("NULL")) || (MyWeapon != nullptr && CurrentWeaponState == 2))
			return;
		CurrentWeaponState = 2;
		//ChangeCurrentWeapon(EEQUIPMENT_TYPE::OTHER);
	}

	bIsWeaponSwapping = true;

	//WeaponChange.Broadcast();
}

void AMyCharacter::ChangeCurrentWeapon(EEQUIPMENT_TYPE EquipmentType)
{
	FName Name = MyEquipmentWidget->EquipmentSlots[EquipmentType]->ItemName;

	if (Name != FName(TEXT("NULL")))
	{
		UMyGameInstance* GameInstance = Cast<UMyGameInstance>(GetGameInstance());
		auto ItemData = GameInstance->GetItemData(Name);

		bCanPickUp = false;
		auto NewWeapon = GetWorld()->SpawnActor<AWeapon>(ItemData->ItemClass);

		if (MyWeapon != nullptr)
		{
			MyWeapon->Destroy();
			MyWeapon = nullptr;
		}
		NewWeapon->AttachToCharacter();

		bCanPickUp = true;

		WeaponChange.Broadcast();
		ChangeSpeed();

		//MyWeapon->SetActorHiddenInGame(true);
		//NewWeapon->SetActorHiddenInGame(false);
		//SetMyWeapon(NewWeapon);
	}

	
}

void AMyCharacter::SetMyWeapon(AWeapon* CurrentWeapon)
{
	MyWeapon = CurrentWeapon;
	if (MyWeapon)
	{
		CurrentWeaponState = MyWeapon->WeaponState;
		Sounds.AttackSound = MyWeapon->AttackSound;
	}
	else
	{
		CurrentWeaponState = 2;
		Sounds.AttackSound = nullptr;
	}


}

void AMyCharacter::Revive()
{
	int32 MaxHp = Stat->GetMaxHp();
	Stat->SetHp(MaxHp);
	GetMesh()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	SetActorTickEnabled(true);
	GetCharacterMovement()->MaxWalkSpeed = MyWeapon != nullptr ? DefaultSpeed + MyWeapon->WeaponInfo.Speed
		: DefaultSpeed;

	CharacterRevive.Broadcast();
}

void AMyCharacter::ChangeSpeed()
{
	// Speed
	switch (CurrentWeaponState)
	{
	case 0:
		GetCharacterMovement()->MaxWalkSpeed = DefaultSpeed + MyWeapon->GetWeaponInfo().Speed;
		break;
	case 1:
		GetCharacterMovement()->MaxWalkSpeed = DefaultSpeed + MyWeapon->GetWeaponInfo().Speed;
		break;
	case 2:
		if (MyWeapon != nullptr)
		{
			GetCharacterMovement()->MaxWalkSpeed = DefaultSpeed + MyWeapon->GetWeaponInfo().Speed;
		}
		else
		{
			GetCharacterMovement()->MaxWalkSpeed = DefaultSpeed;
		}
		break;
	}

	//UE_LOG(LogTemp, Warning, TEXT("Current Speed : %f"), GetCharacterMovement()->MaxWalkSpeed);
}

void AMyCharacter::SetClothesStat(FName Name, bool Plus)
{
	UMyGameInstance* GameInstance = Cast<UMyGameInstance>(GetWorld()->GetGameInstance());
	auto ClothesData = GameInstance->GetClothesData(Name);

	if (Plus)
	{
		if (ClothesData)
		{
			DefaultSpeed += ClothesData->Speed;
			int32 NewPower = Stat->GetPower() + ClothesData->Power;
			Stat->SetPower(NewPower);
			int32 NewDefense = Stat->GetDefense() + ClothesData->Defense;
			Stat->SetDefense(NewDefense);
		}

		
	}
	else
	{
		if (ClothesData)
		{
			DefaultSpeed -= ClothesData->Speed;
			int32 NewPower = Stat->GetPower() - ClothesData->Power;
			Stat->SetPower(NewPower);
			int32 NewDefense = Stat->GetDefense() - ClothesData->Defense;
			Stat->SetDefense(NewDefense);
		}


	}




}

void AMyCharacter::SetWeaponStat(FName Name, bool Plus)
{
	UMyGameInstance* GameInstance = Cast<UMyGameInstance>(GetWorld()->GetGameInstance());
	auto WeaponData = GameInstance->GetWeaponData(Name);

	if (Plus)
	{
		if (WeaponData)
		{
			DefaultSpeed += WeaponData->Speed;
			int32 NewPower = Stat->GetPower() + WeaponData->Power;
			Stat->SetPower(NewPower);
		}

	}
	else
	{
		if (WeaponData)
		{
			DefaultSpeed -= WeaponData->Speed;
			int32 NewPower = Stat->GetPower() - WeaponData->Power;
			Stat->SetPower(NewPower);
		}

	}

}

void AMyCharacter::UnDressedWing()
{
	if (MyWing != nullptr)
	{
		MyWing->SetActorHiddenInGame(true);
		MyWing = nullptr;
	}

}

void AMyCharacter::UnDressedShoes()
{
	TArray<UStaticMeshComponent*> StaticMeshComponents;
	GetComponents<UStaticMeshComponent>(StaticMeshComponents);

	for (UStaticMeshComponent* Comp : StaticMeshComponents)
	{
		if (Comp->GetFName() == FName(TEXT("Shoes_l")) || Comp->GetFName() == FName(TEXT("Shoes_r")))
		{
			Comp->SetStaticMesh(nullptr);
		}
	}

	if (MyShoes)
	{
		SetClothesStat(MyShoes->ItemName, false);

		MyShoes->Destroy();
		MyShoes = nullptr;
	}
}

void AMyCharacter::UnDressedHelmet()
{
	TArray<UStaticMeshComponent*> StaticMeshComponents;
	GetComponents<UStaticMeshComponent>(StaticMeshComponents);

	for (UStaticMeshComponent* Comp : StaticMeshComponents)
	{
		if (Comp->GetFName() == FName(TEXT("Helmet")))
		{
			Comp->SetStaticMesh(nullptr);
		}
	}

	if (MyHelmet)
	{
		SetClothesStat(MyHelmet->ItemName, false);

		MyHelmet->Destroy();
		MyHelmet = nullptr;
	}
}

void AMyCharacter::UnEquippedWeapon(FName ItemName)
{
	if (GetMyWeapon() != nullptr && GetMyWeapon()->ItemName == ItemName)
	{
		SetWeaponStat(ItemName, false);

		GetMyWeapon()->Destroy();

		SetMyWeapon(nullptr);

		// ���� ���� ������ ���� 

	}
}

