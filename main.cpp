#include "stdio.h"

int money(int hour, int normal, int recursive, int prev_wage) {

    normal += 1072;
    recursive += (hour == 1) ? 100 : (prev_wage * 2 - 50); // 前回の時給 + (前回の時給 * 2 - 50)

    if (hour <= 24) {
        return printf("%d時間働いて、一般的 : %d円, 再帰的 : %d円でした\n", hour, normal, recursive),
            money(hour + 1, normal, recursive, (hour == 1) ? 100 : prev_wage * 2 - 50);
    }
    return 0;
}

int main() {
    money(1, 0, 0, 0);
    return 0;
}
