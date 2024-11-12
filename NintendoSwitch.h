#pragma once
#include"GameConsole.h"
class NintendoSwitch : public GameConsole {
public:
    void Play() const override {
        printf("Nintendo Switchでゲームをプレイ中\n");
    }
};
