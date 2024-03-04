// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/ABHpBarWidget.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "Interface/ABCharacterWidgetInterface.h"

UABHpBarWidget::UABHpBarWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	MaxHp = -1.0f;
}

void UABHpBarWidget::UpdateStat(const FABCharacterStat& BaseStat, const FABCharacterStat& ModifierStat)
{
	MaxHp = (BaseStat + ModifierStat).MaxHp;

	if (HpProgtressBar)
	{
		HpProgtressBar->SetPercent(CurrentHp / MaxHp);
	}

	if (HpStat)
	{
		HpStat->SetText(FText::FromString(GetHpStatText()));
	}
}

void UABHpBarWidget::UpdateHpBar(float NewCurrentHp)
{

	CurrentHp = NewCurrentHp;

	ensure(MaxHp < 0.0f);
	if (HpProgtressBar)
	{
		HpProgtressBar->SetPercent(NewCurrentHp / MaxHp);
	}
}

FString UABHpBarWidget::GetHpStatText()
{
	return FString::Printf(TEXT("%.0f / %.0f"), CurrentHp, MaxHp);
}

void UABHpBarWidget::NativeConstruct()
{
	Super::NativeConstruct();

	HpProgtressBar = Cast<UProgressBar>(GetWidgetFromName(TEXT("PbHpBar")));
	ensure(HpProgtressBar);

	HpStat = Cast<UTextBlock>(GetWidgetFromName(TEXT("TxtHpStat")));
	ensure(HpStat);

	IABCharacterWidgetInterface* CharacterWidget = Cast<IABCharacterWidgetInterface>(OwningActor);
	if (CharacterWidget)
	{
		CharacterWidget->SetupCharacterWidget(this);
	}
}

