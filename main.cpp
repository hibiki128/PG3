#include"stdio.h"

template<typename Type>
Type Min(Type a, Type b) {
	if (a > b) {
		return b;
	}
	else {
		return a;
	}
}

template<>
char Min(char a, char b) {
	return printf("数字以外は代入できません\n");
}

int main() {

	printf("%d\n", Min<int>(5, 4));
	printf("%f\n", Min<float>(5.31111f, 4.1666f));
	printf("%lf\n", Min<double>(2.333333, 5.111111));
	Min<char>(5, 6);

	return 0;
}