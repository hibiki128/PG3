#pragma once
#include"GameConsole.h"
class PS5 : public GameConsole {
public:
    void Play() const override {
        printf("PS5でゲームをプレイ中\n");
    }
};


