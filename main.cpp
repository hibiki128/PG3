#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <thread>
#include <mutex>

std::vector<std::vector<int>> mapData;
std::mutex mapMutex;

// CSVファイルを読み込む関数
void loadCSV(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "CSVファイルが開けません: " << filename << std::endl;
        return;
    }

    std::vector<std::vector<int>> tempData;
    std::string line;

    while (std::getline(file, line)) {
        std::vector<int> row;
        std::stringstream ss(line);
        std::string cell;

        while (std::getline(ss, cell, ',')) {
            row.push_back(std::stoi(cell));
        }

        tempData.push_back(row);
    }

    std::lock_guard<std::mutex> lock(mapMutex);
    mapData = std::move(tempData);
    std::cout << "CSVの読み込み完了" << std::endl;
}

void drawMap() {
    std::lock_guard<std::mutex> lock(mapMutex);
    for (const auto& row : mapData) {
        for (int cell : row) {
            if (cell == 1) std::cout << "1 ";
            else std::cout << "0 "; 
        }
        std::cout << std::endl;
    }
}

int main() {
    std::string filename = "map.csv";
    std::cout << "マップデータをバックグラウンドで読み込み中...\n";

    std::thread loadThread(loadCSV, filename);

    loadThread.join(); 

    std::cout << "マップを描画\n";
    drawMap();

    return 0;
}
