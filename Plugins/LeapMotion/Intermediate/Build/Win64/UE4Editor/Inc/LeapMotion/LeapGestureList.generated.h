// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectBase.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class ULeapGesture;
#ifdef LEAPMOTION_LeapGestureList_generated_h
#error "LeapGestureList.generated.h already included, missing '#pragma once' in LeapGestureList.h"
#endif
#define LEAPMOTION_LeapGestureList_generated_h

#define osu3d_cpp_Plugins_LeapMotion_Source_LeapMotion_Public_LeapGestureList_h_9_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execgetIndex) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_index); \
		P_FINISH; \
		*(ULeapGesture**)Z_Param__Result=this->getIndex(Z_Param_index); \
	}


#define osu3d_cpp_Plugins_LeapMotion_Source_LeapMotion_Public_LeapGestureList_h_9_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execgetIndex) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_index); \
		P_FINISH; \
		*(ULeapGesture**)Z_Param__Result=this->getIndex(Z_Param_index); \
	}


#define osu3d_cpp_Plugins_LeapMotion_Source_LeapMotion_Public_LeapGestureList_h_9_INCLASS_NO_PURE_DECLS \
	private: \
	static void StaticRegisterNativesULeapGestureList(); \
	friend LEAPMOTION_API class UClass* Z_Construct_UClass_ULeapGestureList(); \
	public: \
	DECLARE_CLASS(ULeapGestureList, UObject, COMPILED_IN_FLAGS(0), 0, LeapMotion, NO_API) \
	DECLARE_SERIALIZER(ULeapGestureList) \
	/** Indicates whether the class is compiled into the engine */    enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	virtual UObject* _getUObject() const { return const_cast<ULeapGestureList*>(this); }


#define osu3d_cpp_Plugins_LeapMotion_Source_LeapMotion_Public_LeapGestureList_h_9_INCLASS \
	private: \
	static void StaticRegisterNativesULeapGestureList(); \
	friend LEAPMOTION_API class UClass* Z_Construct_UClass_ULeapGestureList(); \
	public: \
	DECLARE_CLASS(ULeapGestureList, UObject, COMPILED_IN_FLAGS(0), 0, LeapMotion, NO_API) \
	DECLARE_SERIALIZER(ULeapGestureList) \
	/** Indicates whether the class is compiled into the engine */    enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	virtual UObject* _getUObject() const { return const_cast<ULeapGestureList*>(this); }


#define osu3d_cpp_Plugins_LeapMotion_Source_LeapMotion_Public_LeapGestureList_h_9_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ULeapGestureList(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ULeapGestureList) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ULeapGestureList); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ULeapGestureList); \
private: \
	/** Private copy-constructor, should never be used */ \
	NO_API ULeapGestureList(const ULeapGestureList& InCopy); \
public:


#define osu3d_cpp_Plugins_LeapMotion_Source_LeapMotion_Public_LeapGestureList_h_9_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ULeapGestureList(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private copy-constructor, should never be used */ \
	NO_API ULeapGestureList(const ULeapGestureList& InCopy); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ULeapGestureList); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ULeapGestureList); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ULeapGestureList)


#define osu3d_cpp_Plugins_LeapMotion_Source_LeapMotion_Public_LeapGestureList_h_6_PROLOG
#define osu3d_cpp_Plugins_LeapMotion_Source_LeapMotion_Public_LeapGestureList_h_9_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	osu3d_cpp_Plugins_LeapMotion_Source_LeapMotion_Public_LeapGestureList_h_9_RPC_WRAPPERS \
	osu3d_cpp_Plugins_LeapMotion_Source_LeapMotion_Public_LeapGestureList_h_9_INCLASS \
	osu3d_cpp_Plugins_LeapMotion_Source_LeapMotion_Public_LeapGestureList_h_9_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define osu3d_cpp_Plugins_LeapMotion_Source_LeapMotion_Public_LeapGestureList_h_9_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	osu3d_cpp_Plugins_LeapMotion_Source_LeapMotion_Public_LeapGestureList_h_9_RPC_WRAPPERS_NO_PURE_DECLS \
	osu3d_cpp_Plugins_LeapMotion_Source_LeapMotion_Public_LeapGestureList_h_9_INCLASS_NO_PURE_DECLS \
	osu3d_cpp_Plugins_LeapMotion_Source_LeapMotion_Public_LeapGestureList_h_9_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class LeapGestureList."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID osu3d_cpp_Plugins_LeapMotion_Source_LeapMotion_Public_LeapGestureList_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
