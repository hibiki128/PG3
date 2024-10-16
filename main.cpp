#include "stdio.h"
#include "windows.h"
#include "random"

void HanChou() {
    int which = 0;

    // ランダムデバイスと乱数生成器の初期化
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 6);

    // サイコロを振る
    int dice = dist(gen);

    // プレイヤーに半か丁かを選択させる
    printf("ディーラー : 半か丁か！！\n半 : 0, 丁 : 1\n");
    scanf_s("%d", &which);

    // プレイヤーの選択に応じて出力
    if (which == 1) {
        printf("自分 : 丁！\n");
    }
    else if (which == 0) {
        printf("自分 : 半！\n");
    }
    else {
        printf("無効な値です\n");
        return;
    }

    // サイコロの目を表示
    printf("サイコロの目 : %d\n", dice);

    // タイムアウト用のラムダ関数を定義して使用
    auto timeout = [](int seconds) {
        Sleep(seconds * 1000);  // 秒単位で待機
        };

    // 奇数か偶数かを判定するラムダ関数
    auto isEven = [](int number) -> bool {
        return number % 2 == 0;
        };

    // 3秒待機
    timeout(3);

    // サイコロの目が偶数か奇数かで結果を判断
    if (isEven(dice)) {
        printf("ディーラー : 丁！！\n");
        timeout(1);  // 1秒待機
        if (which == 1) {
            printf("正解！！\n");
        }
        else {
            printf("不正解...\n");
        }
    }
    else {
        printf("ディーラー : 半！！\n");
        timeout(1);  // 1秒待機
        if (which == 0) {
            printf("正解！！\n");
        }
        else {
            printf("不正解...\n");
        }
    }
}

int main() {
    // HanChou関数を実行
    HanChou();

    return 0;
}