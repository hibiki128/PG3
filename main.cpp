#include"stdio.h"

int money(int hour, int normal, int recursive) {

	normal += 1072;
	recursive = (hour == 1) ? 100 : recursive * 2 - 50;

	if (hour <= 24) {
		return printf("%d時間働いて、一般的 : %d円,再帰的 : %d円でした\n",hour,normal,recursive), money(hour + 1, normal, recursive);
	}
	return 0;
}

int hour = 1;
int normal = 0;
int recursive = 0;

int main() {

	money(hour, normal, recursive);

	return 0;
}