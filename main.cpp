#include "stdio.h"
#include "windows.h"
#include "random"

// 関数ポインタの定義（int型の引数を取り、void型を返す関数を指す）
typedef void (*PFunc)(int);

// タイムアウトを設定する関数
void setTimeout(int second) {
    Sleep(second * 1000); // 秒単位で待機
}

// 半丁ゲーム関数
void HanChou(PFunc callback) {
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

    // コールバック関数を使ってタイムアウトを設定
    callback(3);  // 3秒待機

    // サイコロの目が偶数か奇数かで結果を判断
    if (dice % 2 == 0) {
        printf("ディーラー : 丁！！\n");
        callback(1);  // 1秒待機
        if (which == 1) {
            printf("正解！！\n");
        }
        else {
            printf("不正解...\n");
        }
    }
    else {
        printf("ディーラー : 半！！\n");
        callback(1);  // 1秒待機
        if (which == 0) {
            printf("正解！！\n");
        }
        else {
            printf("不正解...\n");
        }
    }
}

int main() {
    // setTimeout関数をコールバック関数として渡す
    HanChou(setTimeout);

    return 0;
}