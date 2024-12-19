#pragma once
#include"application/Base/BaseObject.h"
class Player:public BaseObject
{
public:
	void Init()override;
	void Update()override;
	void Draw(const ViewProjection& viewProjection)override;
	void DebugTransform(std::string className)override;
	void MoveLeft();
	void MoveRight();

private:
	Vector2 speed_ = { 0.1f,0.1f };
};

