// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"
#include "Student.h"
#include "Teachre.h"

UMyGameInstance::UMyGameInstance()
{
	SchoolName = TEXT("기본학교");
	UE_LOG(LogTemp, Log, TEXT("학교 이름 : %s"), *SchoolName);
}

void UMyGameInstance::Init()
{
	Super::Init();

	UE_LOG(LogTemp, Log, TEXT("==============================="));
	UClass* ClassRuntime = GetClass();
	UClass* ClassCompile = UMyGameInstance::StaticClass();
	check(ClassRuntime == ClassCompile);

	UE_LOG(LogTemp, Log, TEXT("학교를 담당하는 클래스 이름 : %s"), *ClassRuntime -> GetName());

	SchoolName = TEXT("인천전자마이스터고등학교");
	UE_LOG(LogTemp, Log, TEXT("학교 이름 : %s"), *SchoolName);
	UE_LOG(LogTemp, Log, TEXT("학교 이름 : %s"), *GetClass()->GetDefaultObject<UMyGameInstance>()->SchoolName);

	UE_LOG(LogTemp, Log, TEXT("==============================="));

	UStudent* Student = NewObject<UStudent>();
	UTeachre* Teacher = NewObject<UTeachre>();

	Student->SetName(TEXT("정현일"));
	UE_LOG(LogTemp, Log, TEXT("새로운 학생 이름 %s"), *Student->GetName());
	FString CurrentTeacherName;
	FProperty* NameProp = UTeachre::StaticClass()->FindPropertyByName(TEXT("Name"));
	if (NameProp)
	{
		NameProp->GetValue_InContainer(Teacher, &CurrentTeacherName);
		UE_LOG(LogTemp, Log, TEXT("현재 선생님 이름 %s"), *CurrentTeacherName);
	}

	Student->DoLesson();

}
