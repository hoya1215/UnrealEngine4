// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Game/MyCharacterWidget.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyCharacterWidget() {}
// Cross Module References
	GAME_API UClass* Z_Construct_UClass_UMyCharacterWidget_NoRegister();
	GAME_API UClass* Z_Construct_UClass_UMyCharacterWidget();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_Game();
// End Cross Module References
	void UMyCharacterWidget::StaticRegisterNativesUMyCharacterWidget()
	{
	}
	UClass* Z_Construct_UClass_UMyCharacterWidget_NoRegister()
	{
		return UMyCharacterWidget::StaticClass();
	}
	struct Z_Construct_UClass_UMyCharacterWidget_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UMyCharacterWidget_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_Game,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMyCharacterWidget_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "MyCharacterWidget.h" },
		{ "ModuleRelativePath", "MyCharacterWidget.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UMyCharacterWidget_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMyCharacterWidget>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UMyCharacterWidget_Statics::ClassParams = {
		&UMyCharacterWidget::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x00B010A0u,
		METADATA_PARAMS(Z_Construct_UClass_UMyCharacterWidget_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UMyCharacterWidget_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UMyCharacterWidget()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UMyCharacterWidget_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UMyCharacterWidget, 3630599625);
	template<> GAME_API UClass* StaticClass<UMyCharacterWidget>()
	{
		return UMyCharacterWidget::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UMyCharacterWidget(Z_Construct_UClass_UMyCharacterWidget, &UMyCharacterWidget::StaticClass, TEXT("/Script/Game"), TEXT("UMyCharacterWidget"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UMyCharacterWidget);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
