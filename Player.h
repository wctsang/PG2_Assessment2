#pragma once
#include "Bullet.h"

class Player {
private:
	Transform transform_ = { 680, 600 };
	int speedX_ = 10;
	int speedY_ = 10;
	int radius_ = 10;


public:
	Bullet* bullet[10];
	Player();
	~Player();
	void Initialise();
	void Move(char* keys, char* preKeys);
	int GetPosX() { return transform_.x; };
	int GetPosY() { return transform_.y; };
	int GetRadius() { return radius_; };
	void SetPosX(int x);
	void SetPosY(int y);
	int GetSpeedX() { return speedX_; };
	int GetSpeedY() { return speedY_; };
	void Draw();
};