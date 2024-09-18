// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/UIManager.h"
#include "InventoryWidget.h"
#include "EquipmentWidget.h"
#include "EnhanceWidget.h"
#include "AbilityWidget.h"
#include "EnhanceSlotWidget.h"
#include "Util.h"
#include "MyHUD.h"

UUIManager* UUIManager::UIManager = nullptr;

UUIManager::UUIManager()
{
	ConstructorHelpers::FClassFinder<UMyHUD> UI_HUD(TEXT("WidgetBlueprint'/Game/Custom/UI/WBP_HUD.WBP_HUD_C'"));
	if (UI_HUD.Succeeded())
	{
		HUDClass = UI_HUD.Class;


	}

	ConstructorHelpers::FClassFinder<UInventoryWidget> IW(TEXT("WidgetBlueprint'/Game/Custom/UI/WBP_Inventory.WBP_Inventory_C'"));
	if (IW.Succeeded())
	{
		InventoryWidgetClass = IW.Class;
	}

	ConstructorHelpers::FClassFinder<UEquipmentWidget> EW(TEXT("WidgetBlueprint'/Game/Custom/UI/WBP_Equipment.WBP_Equipment_C'"));
	if (EW.Succeeded())
	{
		EquipmentWidgetClass = EW.Class;
	}

	ConstructorHelpers::FClassFinder<UEnhanceWidget> EhW(TEXT("WidgetBlueprint'/Game/Custom/UI/WBP_Enhance.WBP_Enhance_C'"));
	if (EhW.Succeeded())
	{
		EnhanceWidgetClass = EhW.Class;
	}
}

UUIManager* UUIManager::Get()
{
	if (UIManager == nullptr)
	{
		UIManager = NewObject<UUIManager>();
		UIManager->AddToRoot();
	}

	return UIManager;


}

void UUIManager::BeginPlay(AMyCharacter* Character)
{
	MyCharacter = Character;
	World = MyCharacter->GetWorld();

	//AMyCharacter* MyCharacter = Cast<AMyCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	
	HUD = CreateWidget<UMyHUD>(World, HUDClass);
	if (HUD)
	{
		HUD->AddToViewport();
		//Widget->RemoveFromViewport(); ���� 
	}


	HUD->SetCharacter(MyCharacter);

	if (World)
	{
		if (InventoryWidgetClass)
		{
			InventoryWidget = CreateWidget<UInventoryWidget>(World, InventoryWidgetClass);
			if (InventoryWidget)
			{
				InventoryWidget->AddToViewport();
				FVector2D DesiredSize(330, 400);
				InventoryWidget->SetDesiredSizeInViewport(DesiredSize);

				// ���ϴ� ��ġ�� ����
				FVector2D DesiredPosition(800, 100);
				InventoryWidget->SetPositionInViewport(DesiredPosition, true);

				InventoryWidget->SetVisibility(ESlateVisibility::Hidden);
			}
		}

		if (EquipmentWidgetClass)
		{
			EquipmentWidget = CreateWidget<UEquipmentWidget>(World, EquipmentWidgetClass);
			if (EquipmentWidget)
			{
				EquipmentWidget->AddToViewport();
				FVector2D EquipmentSize(440, 500);
				EquipmentWidget->SetDesiredSizeInViewport(EquipmentSize);

				// ���ϴ� ��ġ�� ����
				FVector2D EquipmentPosition(0, 0);
				EquipmentWidget->SetPositionInViewport(EquipmentPosition, true);

				EquipmentWidget->SetVisibility(ESlateVisibility::Hidden);
			}
		}

		if (EnhanceWidgetClass)
		{
			EnhanceWidget = CreateWidget<UEnhanceWidget>(World, EnhanceWidgetClass);
			if (EnhanceWidget)
			{
				EnhanceWidget->AddToViewport();
				FVector2D EquipmentSize(440, 500);
				EnhanceWidget->SetDesiredSizeInViewport(EquipmentSize);

				// ���ϴ� ��ġ�� ����
				FVector2D Position(0, 0);
				EnhanceWidget->SetPositionInViewport(Position, true);

				EnhanceWidget->SetVisibility(ESlateVisibility::Hidden);
			}
		}
	}

}

void UUIManager::OpenInventory()
{
	if (InventoryWidget)
	{
		ESlateVisibility Visibility = InventoryWidget->GetVisibility();
		if (Visibility == ESlateVisibility::Visible)
		{
			PresentUICount--;
			InventoryWidget->SetVisibility(ESlateVisibility::Hidden);
			// ���� �÷��̾� ��Ʈ�ѷ� ��������
			//APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
			if (Util::GetMyCharacter(World)->MyController)
			{
				Util::GetMyCharacter(World)->MyController->bShowMouseCursor = false; // ���콺 Ŀ�� �����
				Util::GetMyCharacter(World)->MyController->SetIgnoreLookInput(false);
				//PlayerController->SetInputMode(FInputModeGameOnly()); // ���� �Է� ���� ��ȯ
			}
		}
		else
		{
			PresentUICount++;
			InventoryWidget->SetVisibility(ESlateVisibility::Visible);
			// ���� �÷��̾� ��Ʈ�ѷ� ��������
			//APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
			if (Util::GetMyCharacter(World)->MyController)
			{
				Util::GetMyCharacter(World)->MyController->bShowMouseCursor = true; // ���콺 Ŀ�� ���̱�
				Util::GetMyCharacter(World)->MyController->SetIgnoreLookInput(true);
				//FInputModeGameAndUI InputMode;
				//InputMode.SetWidgetToFocus(TakeWidget());
				//PlayerController->SetInputMode(InputMode); // ���Ӱ� UI �Է� ��� ����
			}
		}
	}
}

void UUIManager::OpenEquipment()
{
	if (EquipmentWidget)
	{
		ESlateVisibility Visibility = EquipmentWidget->GetVisibility();
		if (Visibility == ESlateVisibility::Visible)
		{
			PresentUICount--;

			EquipmentWidget->SetVisibility(ESlateVisibility::Hidden);
			EquipmentWidget->AbilityWidget->SetVisibility(ESlateVisibility::Hidden);

			if (Util::GetMyCharacter(World)->MyController)
			{
				Util::GetMyCharacter(World)->MyController->bShowMouseCursor = false;
				Util::GetMyCharacter(World)->MyController->SetIgnoreLookInput(false);

			}
		}
		else
		{
			PresentUICount++;

			EquipmentWidget->SetVisibility(ESlateVisibility::Visible);

			if (Util::GetMyCharacter(World)->MyController)
			{
				Util::GetMyCharacter(World)->MyController->bShowMouseCursor = true; // ���콺 Ŀ�� ���̱�
				Util::GetMyCharacter(World)->MyController->SetIgnoreLookInput(true);
			}
		}
	}
}

void UUIManager::OpenEnhance()
{
	if (EnhanceWidget)
	{
		ESlateVisibility Visibility = EnhanceWidget->GetVisibility();
		if (Visibility == ESlateVisibility::Visible)
		{
			PresentUICount--;

			EnhanceWidget->ItemSlot->Reset();
			EnhanceWidget->SetVisibility(ESlateVisibility::Hidden);

			if (Util::GetMyCharacter(World)->MyController)
			{
				Util::GetMyCharacter(World)->MyController->bShowMouseCursor = false;
				Util::GetMyCharacter(World)->MyController->SetIgnoreLookInput(false);

			}
		}
		else
		{
			PresentUICount++;

			EnhanceWidget->SetVisibility(ESlateVisibility::Visible);

			if (Util::GetMyCharacter(World)->MyController)
			{
				Util::GetMyCharacter(World)->MyController->bShowMouseCursor = true; // ���콺 Ŀ�� ���̱�
				Util::GetMyCharacter(World)->MyController->SetIgnoreLookInput(true);
			}
		}
	}
}


