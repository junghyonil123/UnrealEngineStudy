// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameData/ABCharacterStat.h"
#include "ABCharacterStatComponent.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnHpZeroDelegate);
DECLARE_MULTICAST_DELEGATE_OneParam(FOnHpChangedDelegate, float);
DECLARE_MULTICAST_DELEGATE_TwoParams(FOnStatChangedDelegate, const FABCharacterStat&, const FABCharacterStat&);


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ARENABATTLE_API UABCharacterStatComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UABCharacterStatComponent();

protected:
	// Called when the game starts
	virtual void InitializeComponent() override;

public:
	FOnHpZeroDelegate OnHpZero;
	FOnHpChangedDelegate OnHpChanged;
	FOnStatChangedDelegate OnStatChanged;

	void SetLevelStat(int32 InNewLevel);
	
	FORCEINLINE float GetCurrentLevel() const {return CurrentLevel;}
	FORCEINLINE void SetBaseStat(const FABCharacterStat& InBaseStat) { BaseStat = InBaseStat;  OnStatChanged.Broadcast(BaseStat, ModifierStat); }
	FORCEINLINE void AddBaseStat(const FABCharacterStat& InStat) { SetBaseStat(BaseStat + InStat); }
	FORCEINLINE void SetModifierStat(const FABCharacterStat& InModifierStat) { ModifierStat = InModifierStat;  OnStatChanged.Broadcast(BaseStat, ModifierStat); }
	FORCEINLINE FABCharacterStat GetBaseStat() const { return BaseStat; }
	FORCEINLINE FABCharacterStat GetModiferStat() const { return ModifierStat; }
	FORCEINLINE FABCharacterStat GetTotalStat() const { return BaseStat + ModifierStat; }
	FORCEINLINE float GetCurrentHp(){return CurrentHp;}
	FORCEINLINE void HealHp(float InHp) { CurrentHp = FMath::Clamp(CurrentHp + InHp, 0, GetTotalStat().MaxHp); OnHpChanged.Broadcast(CurrentHp); };
	FORCEINLINE float GetAttackRadius() const { return AttackRadius; }
	
	//FORCEINLINE float GetMaxHp(){return MaxHp;}
	float ApplyDamage(float InDamage);

protected:
	void SetHp(float NewHp);

	//UPROPERTY(VisibleInstanceOnly, Category = Stat)
	//float MaxHp;

	UPROPERTY(Transient, VisibleInstanceOnly, Category = Stat)
	float CurrentHp;
		
	UPROPERTY(Transient, VisibleInstanceOnly, Category = Stat)
	float CurrentLevel;

	UPROPERTY(VisibleInstanceOnly, Category = Stat, Meta = (AllowPrivateAccess = "true"))
	float AttackRadius;

	UPROPERTY(Transient, VisibleInstanceOnly, Category = Stat, Meta = (AllowPrivateAccess = "true"))
	FABCharacterStat BaseStat;
	UPROPERTY(Transient, VisibleInstanceOnly, Category = Stat, Meta = (AllowPrivateAccess = "true"))
	FABCharacterStat ModifierStat;
	
};
