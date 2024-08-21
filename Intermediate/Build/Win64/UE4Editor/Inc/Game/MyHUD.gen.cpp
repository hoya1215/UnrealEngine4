// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Game/MyHUD.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyHUD() {}
// Cross Module References
	GAME_API UClass* Z_Construct_UClass_UMyHUD_NoRegister();
	GAME_API UClass* Z_Construct_UClass_UMyHUD();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_Game();
	GAME_API UClass* Z_Construct_UClass_AMyCharacter_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UImage_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UProgressBar_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UTextBlock_NoRegister();
// End Cross Module References
	void UMyHUD::StaticRegisterNativesUMyHUD()
	{
	}
	UClass* Z_Construct_UClass_UMyHUD_NoRegister()
	{
		return UMyHUD::StaticClass();
	}
	struct Z_Construct_UClass_UMyHUD_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MyCharacter_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_MyCharacter;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DefaultTexture_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_DefaultTexture;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CurrentWeapon_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_CurrentWeapon;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Hp_Bar_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Hp_Bar;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_HpText_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_HpText;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BulletText_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_BulletText;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UMyHUD_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_Game,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMyHUD_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "MyHUD.h" },
		{ "ModuleRelativePath", "MyHUD.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMyHUD_Statics::NewProp_MyCharacter_MetaData[] = {
		{ "ModuleRelativePath", "MyHUD.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UMyHUD_Statics::NewProp_MyCharacter = { "MyCharacter", nullptr, (EPropertyFlags)0x0040000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UMyHUD, MyCharacter), Z_Construct_UClass_AMyCharacter_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UMyHUD_Statics::NewProp_MyCharacter_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMyHUD_Statics::NewProp_MyCharacter_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMyHUD_Statics::NewProp_DefaultTexture_MetaData[] = {
		{ "ModuleRelativePath", "MyHUD.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UMyHUD_Statics::NewProp_DefaultTexture = { "DefaultTexture", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UMyHUD, DefaultTexture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UMyHUD_Statics::NewProp_DefaultTexture_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMyHUD_Statics::NewProp_DefaultTexture_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMyHUD_Statics::NewProp_CurrentWeapon_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MyHUD.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UMyHUD_Statics::NewProp_CurrentWeapon = { "CurrentWeapon", nullptr, (EPropertyFlags)0x0010000000080008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UMyHUD, CurrentWeapon), Z_Construct_UClass_UImage_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UMyHUD_Statics::NewProp_CurrentWeapon_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMyHUD_Statics::NewProp_CurrentWeapon_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMyHUD_Statics::NewProp_Hp_Bar_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MyHUD.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UMyHUD_Statics::NewProp_Hp_Bar = { "Hp_Bar", nullptr, (EPropertyFlags)0x0010000000080008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UMyHUD, Hp_Bar), Z_Construct_UClass_UProgressBar_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UMyHUD_Statics::NewProp_Hp_Bar_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMyHUD_Statics::NewProp_Hp_Bar_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMyHUD_Statics::NewProp_HpText_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MyHUD.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UMyHUD_Statics::NewProp_HpText = { "HpText", nullptr, (EPropertyFlags)0x0010000000080008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UMyHUD, HpText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UMyHUD_Statics::NewProp_HpText_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMyHUD_Statics::NewProp_HpText_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMyHUD_Statics::NewProp_BulletText_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MyHUD.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UMyHUD_Statics::NewProp_BulletText = { "BulletText", nullptr, (EPropertyFlags)0x0010000000080008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UMyHUD, BulletText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UMyHUD_Statics::NewProp_BulletText_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMyHUD_Statics::NewProp_BulletText_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UMyHUD_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyHUD_Statics::NewProp_MyCharacter,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyHUD_Statics::NewProp_DefaultTexture,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyHUD_Statics::NewProp_CurrentWeapon,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyHUD_Statics::NewProp_Hp_Bar,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyHUD_Statics::NewProp_HpText,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyHUD_Statics::NewProp_BulletText,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UMyHUD_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMyHUD>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UMyHUD_Statics::ClassParams = {
		&UMyHUD::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UMyHUD_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UMyHUD_Statics::PropPointers),
		0,
		0x00B010A0u,
		METADATA_PARAMS(Z_Construct_UClass_UMyHUD_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UMyHUD_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UMyHUD()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UMyHUD_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UMyHUD, 1630567892);
	template<> GAME_API UClass* StaticClass<UMyHUD>()
	{
		return UMyHUD::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UMyHUD(Z_Construct_UClass_UMyHUD, &UMyHUD::StaticClass, TEXT("/Script/Game"), TEXT("UMyHUD"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UMyHUD);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
