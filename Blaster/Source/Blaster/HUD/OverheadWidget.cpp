// Fill out your copyright notice in the Description page of Project Settings.


#include "OverheadWidget.h"
#include "Components/TextBlock.h"
#include "GameFramework/PlayerState.h"

void UOverheadWidget::SetDisplayText(FString TextToDisplay)
{
	if (DisplayText)
	{
		DisplayText->SetText(FText::FromString(TextToDisplay));
	}
}

void UOverheadWidget::ShowPlayerNetRole(APawn* InPawn)
{
	FString Name;
	UWorld* World = GetWorld();
	if (World)
	{
		APlayerController* NewPlayer = GetWorld()->GetFirstPlayerController();
		APlayerState* PlayerState = NewPlayer->GetPlayerState<APlayerState>();
		if (PlayerState)
		{
			Name = PlayerState->GetPlayerName();
		}
	}

	ENetRole LocalRole = InPawn->GetLocalRole();
	FString Role;
	switch (LocalRole)
	{
		case ENetRole::ROLE_Authority:
			Role = FString("Authority");
			break;

		case ENetRole::ROLE_AutonomousProxy:
			Role = FString("Autonomous Proxy");
			break;

		case ENetRole::ROLE_SimulatedProxy:
			Role = FString("Simulated Proxy");
			break;

		case ENetRole::ROLE_None:
			Role = FString("None");
			break;
	}

	FString LocalRoleString = FString::Printf(TEXT("Name: %s\nLocal Role: %s"), *Name, *Role);
	SetDisplayText(LocalRoleString);
}

void UOverheadWidget::NativeDestruct()
{
	RemoveFromParent();
	Super::NativeDestruct();
}

//Deprecated after v5.0
/*
void UOverheadWidget::OnLevelRemovedFromWorld(ULevel* InLevel, UWorld* InWorld)
{
	RemoveFromParent();
	Super::OnLevelRemovedFromWorld(InLevel, InWorld);
}*/
