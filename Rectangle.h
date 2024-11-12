#pragma once
#include"IShape.h"
class Rectangle :public IShape
{
	void Size() override;
	void Draw() override;
private:
	float height = 2.5f;
	float width = 4.0f;
};

