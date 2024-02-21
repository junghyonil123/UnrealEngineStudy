// Fill out your copyright notice in the Description page of Project Settings.


#include "Teachre.h"

UTeachre::UTeachre()
{
	Name = TEXT("이선생");
	Year = 3;
	Id = 1;
}

void UTeachre::DoLesson()
{
	Super::DoLesson();

	UE_LOG(LogTemp, Log, TEXT("%d년차 선생님 %s님이 수업을 듣습니다."), Year, *Name);

}
