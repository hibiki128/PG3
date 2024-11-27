#include <cstdio>
#include <list>

void printStations(const std::list<const char*>& stations) {
    for (const auto& station : stations) {
        printf("%s -> ", station);
    }
    printf("終点\n");
}

int main() {
    // 1970年の山手線駅リスト
    std::list<const char*> stations_1970 = {
        "東京", "神田", "秋葉原", "御徒町", "上野", "鶯谷", "日暮里",
        "田端", "駒込", "巣鴨", "大塚", "池袋", "目白", "高田馬場",
        "新大久保", "新宿", "代々木", "原宿", "渋谷", "恵比寿", "目黒",
        "五反田", "大崎", "品川", "田町", "浜松町", "新橋", "有楽町"
    };

    // 2019年の駅リスト
    std::list<const char*> stations_2019 = stations_1970;

    // 西日暮里駅を1971年に追加
    auto it = std::next(stations_2019.begin(), 7);
    stations_2019.insert(it, "西日暮里");

    std::list<const char*> stations_2022 = stations_2019;

    // 2020年に高輪ゲートウェイ駅を追加
    it = std::next(stations_2022.begin(), 21);
    stations_2022.insert(it, "高輪ゲートウェイ");

    // 駅リストを表示
    printf("1970年の山手線駅:\n");
    printStations(stations_1970);

    printf("\n1971年に西日暮里駅開業\n");

    printf("\n2019年の山手線駅:\n");
    printStations(stations_2019);

    printf("\n2020年に高輪ゲートウェイ駅開業\n");

    printf("\n2022年の山手線駅:\n");
    printStations(stations_2022);

    return 0;
}
