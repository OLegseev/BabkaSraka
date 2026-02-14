// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"

#include "UMainMenuWidget.generated.h"

UCLASS()
class BABKASRAKA_API UMainMenuWidget : public UUserWidget
{
    GENERATED_BODY()

protected:
    // Виртуальная функция, вызываемая после создания виджета
    virtual void NativeConstruct() override;

    // Функции-обработчики для кнопок
    UFUNCTION()
    void OnStartClicked();

    UFUNCTION()
    void OnSettingsClicked();

    UFUNCTION()
    void OnQuitClicked();

    // Связываем эти переменные с кнопками в Blueprint (по именам)
    UPROPERTY(meta = (BindWidget))
    class UButton* StartButton;

    UPROPERTY(meta = (BindWidget))
    class UButton* SettingsButton;

    UPROPERTY(meta = (BindWidget))
    class UButton* QuitButton;
};