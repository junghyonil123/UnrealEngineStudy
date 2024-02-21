// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Person.h"
#include "Teachre.generated.h"

/**
 * 
 */
UCLASS()
class OBJECTREFLECTION_API UTeachre : public UPerson
{
	GENERATED_BODY()
	
public:
	UTeachre();

	virtual void DoLesson() override;
private:
	UPROPERTY()
	int32 Id; 
};
