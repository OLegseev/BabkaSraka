// Fill out your copyright notice in the Description page of Project Settings.

#include "AMainMenuHUD.h"
#include "UMainMenuWidget.h"
#include "Blueprint/UserWidget.h"

void AMainMenuHUD::BeginPlay()
{
    Super::BeginPlay();
    ShowMainMenu();
}

void AMainMenuHUD::ShowMainMenu()
{
    if (!MenuWidgetClass)
    {
        // Если класс не назначен, используем наш UMainMenuWidget по умолчанию
        MenuWidgetClass = UMainMenuWidget::StaticClass();
    }

    if (MenuWidgetClass)
    {
        // Создаем виджет
        MenuWidgetInstance = CreateWidget<UUserWidget>(GetWorld(), MenuWidgetClass);

        if (MenuWidgetInstance)
        {
            // Добавляем на экран
            MenuWidgetInstance->AddToViewport();

            // Настраиваем ввод для UI
            APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
            if (PlayerController)
            {
                PlayerController->SetShowMouseCursor(true);
                PlayerController->SetInputMode(FInputModeUIOnly());
            }
        }
    }
}