// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CorseInfo.generated.h"

DECLARE_MULTICAST_DELEGATE_TwoParams(FCourseInfOnChangedSignature, const FString&, const FString&);

/**
 * 
 */
UCLASS()
class UNREALDELEGATE_API UCorseInfo : public UObject
{
	GENERATED_BODY()
public:
	UCorseInfo();
	FCourseInfOnChangedSignature OnChanged;
	
	void ChangeCourseInfo(const FString& InSchoolName, const FString& InNewContetns);

private:
	FString Contents;
};
