#include "Player.h"

void Player::Init()
{
	BaseObject::Init();
	BaseObject::CreateModel("debug/plane.obj");
	BaseObject::SetLighting(false);
	transform_.rotation_.x =degreesToRadians(90.0f);
	transform_.translation_ = { -15.0f,10.0f,0.0f };
}

void Player::Update()
{
	BaseObject::Update();
}

void Player::Draw(const ViewProjection& viewProjection)
{
	BaseObject::Draw(viewProjection);
}

void Player::DebugTransform(std::string className)
{
	BaseObject::DebugTransform(className);
}

void Player::MoveLeft()
{
	this->transform_.translation_.x -= this->speed_.x;
}

void Player::MoveRight()
{
	this->transform_.translation_.x += this->speed_.x;
}
