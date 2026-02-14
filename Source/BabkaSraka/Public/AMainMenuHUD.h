// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "AMainMenuHUD.generated.h"

UCLASS()
class BABKASRAKA_API AMainMenuHUD : public AHUD
{
    GENERATED_BODY()

protected:
    virtual void BeginPlay() override;

    // Класс нашего виджета меню
    UPROPERTY(EditAnywhere, Category = "Menu")
    TSubclassOf<class UUserWidget> MenuWidgetClass;

    // Экземпляр виджета
    UPROPERTY()
    class UUserWidget* MenuWidgetInstance;

    // Функция для создания и показа меню
    void ShowMainMenu();
};