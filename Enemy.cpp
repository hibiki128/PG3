#include "Enemy.h"
#include "cstdio"         
#include "thread"         
#include "chrono"         

Enemy::Enemy(){
}

void(Enemy::* Enemy::StateFunction[])() {
	&Enemy::Approach,
	& Enemy::Shoot,
	& Enemy::Retreat
};

void Enemy::Update() {
	for (int i = 0; i < 3; i++) {
		(this->*StateFunction[i])();
		std::this_thread::sleep_for(std::chrono::seconds(2));
	}
}

void Enemy::Approach()
{
	printf("接近中\n");
}

void Enemy::Shoot()
{
	printf("射撃中\n");
}

void Enemy::Retreat()
{
	printf("離脱中\n");
}
