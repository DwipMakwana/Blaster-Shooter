// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "Menu.generated.h"

/**
 * 
 */
UCLASS()
class MULTIPLAYERSESSIONS_API UMenu : public UUserWidget
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	void MenuSetup(int32 NumberPublicConnections = 4, FString TypeOfMatch = FString(TEXT("FreeForAll")), FString LobbyPath = FString(TEXT("/Game/ThirdPerson/Maps/Lobby")));

protected:

	virtual bool Initialize() override;
	virtual void NativeDestruct() override;
	//Deprecated after v5.0
	//virtual void OnLevelRemovedFromWorld(ULevel* InLevel, UWorld* InWorld) override;

	//
	//	Callback for the custom delegates on the MultiplayerSessionsSubsystem
	//
	UFUNCTION()
	void OnCreateSession(bool bWasSuccessfull);
	void OnFindSessions(const TArray<FOnlineSessionSearchResult>& SessionResults, bool bWasSuccessfull);
	void OnJoinSession(EOnJoinSessionCompleteResult::Type Result);
	UFUNCTION()
	void OnDestroySession(bool bWasSuccessfull);
	UFUNCTION()
	void OnStartSession(bool bWasSuccessfull);

private:

	UPROPERTY(meta  = (BindWidget))
	class UButton* HostButton;

	UPROPERTY(meta = (BindWidget))
	UButton* JoinButton;

	void MenuTearDown();

	UFUNCTION()
	void HostButtonClicked();

	UFUNCTION()
	void JoinButtonClicked();

	//The subsytem desinged to handle all online sessions functionality
	class UMultiplayerSessionsSubsystem* MultiplayerSessionsSubsystem;

	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	int32 NumPublicConnections{4};

	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	FString MatchType{ TEXT("FreeForAll") };

	FString PathToLobby{ TEXT("") };
	
};
