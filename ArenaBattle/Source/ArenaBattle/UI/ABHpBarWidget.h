// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ABUserWidget.h"
#include "GameData/ABCharacterStat.h"
#include "ABHpBarWidget.generated.h"

/**
 * 
 */
UCLASS()
class ARENABATTLE_API UABHpBarWidget : public UABUserWidget
{
	GENERATED_BODY()
	
public:
	UABHpBarWidget(const FObjectInitializer& ObjectInitializer);
public:
	//FORCEINLINE void SetMaxHp(float NewMaxHp) { MaxHp = NewMaxHp; }
	void UpdateStat(const FABCharacterStat& BaseStat, const FABCharacterStat& ModifierStat);
	void UpdateHpBar(float NewCurrentHp);
	FString GetHpStatText();

protected:
	virtual void NativeConstruct() override;

protected:
	UPROPERTY()
	TObjectPtr<class UProgressBar> HpProgtressBar;

	UPROPERTY()
	TObjectPtr<class UTextBlock> HpStat;
	
	UPROPERTY()
	float CurrentHp;

	UPROPERTY()
	float MaxHp;
};

