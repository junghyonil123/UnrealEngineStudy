// Fill out your copyright notice in the Description page of Project Settings.


#include "CorseInfo.h"

UCorseInfo::UCorseInfo()
{
	Contents = TEXT("기존 학사 정보");
}

void UCorseInfo::ChangeCourseInfo(const FString& InSchoolName, const FString& InNewContetns)
{

	Contents = InNewContetns;

	UE_LOG(LogTemp, Log, TEXT("[CourseInfo] 학사 정보가 변경되어 알림을 발송합니다."));
	OnChanged.Broadcast(InSchoolName, Contents);
}
