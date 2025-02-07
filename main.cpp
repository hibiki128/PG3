#include <iostream>
#include <string>
#include <chrono>

// 時間計測用のエイリアス
using namespace std::chrono;

int main() {
    // 100,000文字の文字列を作成
    std::string long_string(1000000, 'a');

    std::cout << "100,000文字を移動とコピーで比較しました。\n";

    // コピーにかかる時間を計測
    auto start_copy = high_resolution_clock::now();
    std::string copy_string = long_string;  // コピー
    auto end_copy = high_resolution_clock::now();
    auto duration_copy = duration_cast<microseconds>(end_copy - start_copy);
    std::cout << "コピー : " << duration_copy.count() << " μs\n";

    // 移動にかかる時間を計測
    auto start_move = high_resolution_clock::now();
    std::string move_string = std::move(long_string);  // 移動
    auto end_move = high_resolution_clock::now();
    auto duration_move = duration_cast<microseconds>(end_move - start_move);
    std::cout << "移動 : " << duration_move.count() << " μs\n";

    return 0;
}