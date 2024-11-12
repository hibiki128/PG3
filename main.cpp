#include "stdio.h"
#include"Template.h"

int main() {
    Template<int, int> num1(1, 3);
    Template<int, float> num2(14, 1.5f);
    Template<int, double> num3(10, 12.847);
    Template<float, float> num4(2.5f, 4.3f);
    Template<float, double> num5(6.5f, 5.7487);
    Template<double, double> num6(10.8421, 10.2457);

    printf("Min(int, int): %d\n", num1.Min());
    printf("Min(int, float): %.1f\n", num2.Min());
    printf("Min(int, double): %.1f\n", num3.Min());
    printf("Min(float, float): %.1f\n", num4.Min());
    printf("Min(float, double): %.1f\n", num5.Min());
    printf("Min(double, double): %.1f\n", num6.Min());

	return 0;
}