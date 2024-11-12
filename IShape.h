#pragma once
#include"cstdio"
class IShape
{
public:
	virtual void Size() = 0;
	virtual void Draw() = 0;
protected:
	float area = 0;
};

