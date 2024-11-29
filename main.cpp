#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

// 学籍番号を抽出する関数
std::string extractStudentNumber(const std::string& email) {
    size_t start = email.find("g");
    if (start != std::string::npos && start + 5 <= email.size()) {
        return email.substr(start, 5);
    }
    return "";
}

int main() {
    // 読み込むファイル名
    std::ifstream inputFile("PG3_2024_03_02.txt");
    if (!inputFile) {
        std::cout << "Error: ファイルを開けませんでした。" << std::endl;
        return 1;
    }

    // ファイルから読み込んだデータを格納する変数
    std::vector<std::string> studentNumList;
    std::string studentNum;

    // ファイルを読み込む
    if (std::getline(inputFile, studentNum)) {
        if (!studentNum.empty() && studentNum.front() == '[') {
            studentNum.erase(0, 1);
        }
        if (!studentNum.empty() && studentNum.back() == ']') {
            studentNum.pop_back();
        }

        std::stringstream ss(studentNum);
        std::string email;

        // カンマで区切られたメールアドレスを読み取る
        while (std::getline(ss, email, ',')) {
            if (!email.empty()) {
                studentNumList.push_back(email);
            }
        }
    }
    inputFile.close();

    // 学籍番号部分でソート
    std::sort(studentNumList.begin(), studentNumList.end(), [](const std::string& a, const std::string& b) {
        return extractStudentNumber(a) < extractStudentNumber(b);
        });

    // ソートされたメールアドレスを表示
    std::cout << "Sorted studentNum List:" << std::endl;
    for (const auto& sortedNumber : studentNumList) {
        std::cout << sortedNumber << std::endl;
    }

    return 0;
}
