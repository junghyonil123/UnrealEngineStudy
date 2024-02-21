// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Person.h"

#include "Student.generated.h" //generated 파일은 항상 최 하단에

/**
 * 
 */
UCLASS()
class OBJECTREFLECTION_API UStudent : public UPerson
{
	GENERATED_BODY()
public:
	UStudent();
	
	virtual void DoLesson() override;

private:
	UPROPERTY()
	int32 Id;
};
