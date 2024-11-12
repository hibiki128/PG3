#include "Rectangle.h"

void Rectangle::Size()
{
	area = height * width;
}

void Rectangle::Draw()
{
	Size();
	printf("矩形の面積 = %.1f\n", area);
}
