#pragma once
#include <iostream>
#include <string>
class Enemy {
public:
	// コンストラクタ
	Enemy();

	// 状態遷移を実行する関数
	void Update();

private:
	// 状態遷移用の関数ポインタ
	 static void (Enemy::*StateFunction[])();

	/// <summary>
	/// 接近
	/// </summary>
	void Approach();
	
	/// <summary>
	/// 射撃
	/// </summary>
	void Shoot();

	/// <summary>
	/// 離脱
	/// </summary>
	void Retreat();
};
