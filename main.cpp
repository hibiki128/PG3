#include "stdio.h"
#include"GameConsole.h"
#include"PS5.h"
#include"NintendoSwitch.h"

int main() {
    GameConsole* consoles[] = { new PS5(), new NintendoSwitch() };

    // 各ゲーム機でPlay()を呼び出す
    for (GameConsole* console : consoles) {
        console->Play();
    }

    // メモリ解放
    for (GameConsole* console : consoles) {
        delete console;
    }

    return 0;
}