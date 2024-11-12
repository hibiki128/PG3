#include "Circle.h"

void Circle::Size()
{
	area = r * r * pi;
}

void Circle::Draw()
{
	Size();
	printf("円の面積 = %.1f\n", area);
}
