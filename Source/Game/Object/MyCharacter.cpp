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
#include "EnhanceWidget.h"
#include "EnemyController.h"
#include "Pet.h"
#include "Wing.h"
#include "Shoes.h"
#include "Helmet.h"
#include "EquipmentSlotWidget.h"
#include "Sound/SoundCue.h"
#include "Util.h"
#include "ItemPool.h"
#include "EnhanceSlotWidget.h"
#include "AbilityWidget.h"
#include "Skill_Tag.h"
#include "SkillSlotWidget.h"
#include "SkillManager.h"
#include "UIManager.h"

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


	//UUIManager::Get()->BeginPlay(this);


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
	Stat->MyCharacter = this;
	Stat->Ability.Speed = DefaultSpeed;

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

		FSlotData SlotData;
		SlotData.ItemInfo = MyWing->ItemInfo;
		//MyEquipmentWidget->EquipmentSlots[EEQUIPMENT_TYPE::WING]->PushEquipment(SlotData);
		UUIManager::Get()->GetEquipmentWidget()->EquipmentSlots[EEQUIPMENT_TYPE::WING]->PushEquipment(SlotData);
		MyWing->EquippedItem(MyWing->ItemInfo);
		
	}



	//Skill
	auto SkillManager = USkillManager::Get();
	SkillManager->BeginPlay(GetWorld(), this);
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




	// Tick 이 아니고 무기 변경해줄때마다 하면 실제 속도는 변화 x -> 개선
	//if (MyWeapon == nullptr)
	//	CurrentWeaponState = 2;

	//GetCharacterMovement()->MaxWalkSpeed = DefaultSpeed;
	ChangeSpeed();


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
	PlayerInputComponent->BindAction(TEXT("OpenInventory"), EInputEvent::IE_Pressed, UUIManager::Get(), &UUIManager::OpenInventory);
	PlayerInputComponent->BindAction(TEXT("FlyingMode"), EInputEvent::IE_Pressed, this, &AMyCharacter::FlyingMode);
	PlayerInputComponent->BindAction(TEXT("OpenEquipment"), EInputEvent::IE_Pressed, UUIManager::Get(), &UUIManager::OpenEquipment);
	PlayerInputComponent->BindAction(TEXT("OpenEnhance"), EInputEvent::IE_Pressed, UUIManager::Get(), &UUIManager::OpenEnhance);

	PlayerInputComponent->BindAction(TEXT("SelectMainWeapon"), EInputEvent::IE_Pressed, this, &AMyCharacter::SelectWeapon);
	PlayerInputComponent->BindAction(TEXT("SelectSubWeapon"), EInputEvent::IE_Pressed, this, &AMyCharacter::SelectWeapon);
	PlayerInputComponent->BindAction(TEXT("SelectOtherWeapon"), EInputEvent::IE_Pressed, this, &AMyCharacter::SelectWeapon);
	PlayerInputComponent->BindAction(TEXT("Revive"), EInputEvent::IE_Pressed, this, &AMyCharacter::Revive);

	PlayerInputComponent->BindAction(TEXT("Skill_Tag"), EInputEvent::IE_Pressed, this, &AMyCharacter::TabSkill);
}

float AMyCharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	float Damage = Stat->GetDamageIncludeDefense(DamageAmount, Stat->GetDefense());
	Stat->OnAttacked(Damage);
	HpChange.Broadcast();

	return Damage;
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
			// 총알 갯수 
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
	if (UUIManager::Get()->GetPresentUICount() > 0)
	{
		return;
	}


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

		// 검은 Anim Notify 로
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



			if (HitResult.Actor.IsValid())
			{
				FDamageEvent DamageEvent;
				AMyEnemy* Enemy = Cast<AMyEnemy>(HitResult.Actor);
				int32 Power = Stat->GetPower();
				if (Enemy)
				{
					Power = Stat->GetPowerIncludeLevel(Stat->GetLevel(), Enemy->GetEnemyInfo().Level, Stat->GetPower());
				}
				HitResult.Actor->TakeDamage(Power, DamageEvent, GetController(), this);
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
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), MyWeapon->Effect, HitResult.Actor->GetActorLocation(), FRotator(0.f), true);


		FDamageEvent event;
		HitResult.Actor->TakeDamage(Stat->GetPower(), event, GetController(), this);
	}

	bIsAttacking = false;
}

void AMyCharacter::Die()
{
	GetMesh()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	SetActorTickEnabled(false);
	CharacterDie.Broadcast();
	Util::PlaySound(this, Sounds.DieSound, GetActorLocation());
	//UGameplayStatics::PlaySoundAtLocation(this, DieSound, GetActorLocation());
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

//void AMyCharacter::DragInventory()
//{
//	FVector2D MousePosition;
//	MyController->GetMousePosition(MousePosition.X, MousePosition.Y);
//
//	FVector2D WidgetPosition = MyInventoryWidget->GetCachedGeometry().GetAbsolutePosition();
//	DragOffset = WidgetPosition - MousePosition;
//
//	bIsDragging = true;
//}

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
		
		FName Name = UUIManager::Get()->GetEquipmentWidget()->EquipmentSlots[EEQUIPMENT_TYPE::MAIN]->SlotData.ItemInfo.ItemName;
		if (Name == FName(TEXT("NULL")) || (MyWeapon != nullptr && CurrentWeaponState == 0))
			return;
		CurrentWeaponState = 0;
		//ChangeCurrentWeapon(EEQUIPMENT_TYPE::MAIN);
	}
	else if (Key == EKeys::Two)
	{
		
		FName Name = UUIManager::Get()->GetEquipmentWidget()->EquipmentSlots[EEQUIPMENT_TYPE::SUB]->SlotData.ItemInfo.ItemName;
		if (Name == FName(TEXT("NULL")) || (MyWeapon != nullptr && CurrentWeaponState == 1))
			return;
		CurrentWeaponState = 1;
		//ChangeCurrentWeapon(EEQUIPMENT_TYPE::SUB);
	}
	else if (Key == EKeys::Three)
	{
		
		FName Name = UUIManager::Get()->GetEquipmentWidget()->EquipmentSlots[EEQUIPMENT_TYPE::OTHER]->SlotData.ItemInfo.ItemName;
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
	FName Name = UUIManager::Get()->GetEquipmentWidget()->EquipmentSlots[EquipmentType]->SlotData.ItemInfo.ItemName;

	if (Name != FName(TEXT("NULL")))
	{
		UMyGameInstance* GameInstance = Cast<UMyGameInstance>(GetGameInstance());
		auto ItemData = GameInstance->GetItemData(Name);

		bCanPickUp = false;
		auto NewWeapon = GetWorld()->SpawnActor<AWeapon>(ItemData->ItemClass);

		if (MyWeapon != nullptr)
		{
			MyWeapon->UnEquippedItem();
			//MyWeapon->Destroy();
			//MyWeapon = nullptr;
		}
		NewWeapon->SetItemInfo(UUIManager::Get()->GetEquipmentWidget()->EquipmentSlots[EquipmentType]->SlotData.ItemInfo);
		NewWeapon->AttachToCharacter();

		bCanPickUp = true;

		WeaponChange.Broadcast();
		ChangeSpeed();

		//MyWeapon->SetActorHiddenInGame(true);
		//NewWeapon->SetActorHiddenInGame(false);
		//SetMyWeapon(NewWeapon);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No Weapon Swap"));
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

	CharacterRevive.Broadcast();
}

void AMyCharacter::ChangeSpeed()
{

	GetCharacterMovement()->MaxWalkSpeed = Stat->Ability.Speed;

}

void AMyCharacter::TabSkill()
{
	auto HUD = UUIManager::Get()->GetHUD();
	if (HUD->TabSkill->CurrentTime > 0.f)
		return;
	HUD->TabSkill->CurrentTime += 0.001f;

	HUD->TabSkill->Skill->Play();
	//USkillManager::Get()->Skill_Tag->Play();
}

ACharacter_Tag* AMyCharacter::GetTagCharacter()
{
	return TagSkill->TagCharacter;
}






