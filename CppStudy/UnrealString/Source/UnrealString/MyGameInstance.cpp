// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"

void UMyGameInstance::Init()
{
	Super::Init();

	TCHAR logCharArray[] = TEXT("Hello Unreal");
	UE_LOG(LogTemp, Log, logCharArray);

	FString LogCharString = logCharArray;
	UE_LOG(LogTemp, Log,TEXT("%s"), *LogCharString);
	
	const TCHAR* LongCharPtr = *LogCharString;
	
	//UE_LOG(LogTemp, Log,TEXT("%s"), LongCharPtr);
	//UE_LOG(LogTemp, Log,TEXT("%s"), *LongCharPtr);

	FString left, Right;
	if (LogCharString.Split(TEXT(" "), &left, &Right))
	{
		UE_LOG(LogTemp, Log,TEXT("Split Test: %s 와 %s"), *left, *Right);
	}

}