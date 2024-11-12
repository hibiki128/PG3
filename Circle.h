#pragma once
#include"IShape.h"
class Circle :public IShape
{
	void Size()override;
	void Draw()override;
private:
	float r = 5.0f;
	float pi = 3.14f;
};

