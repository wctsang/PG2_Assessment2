#pragma once
#include "Bullet.h"

class Enemy {
private:
	Transform transform_ = { 680, 200 };
	int speedX_ = 5;
	int speedY_ = 5;
	int radius_ = 30;
	bool isAlive_ = true;
	

public:
	int timer_ = 0;
	Enemy();
	~Enemy();
	void Initialise();
	void Update();
	int GetPosX() { return transform_.x; };
	int GetPosY() { return transform_.y; };
	int GetSpeedX() { return speedX_; };
	int GetSpeedY() { return speedY_; };
	void SetAlive(bool isAlive);
	bool GetAlive(){ return isAlive_; };
	int GetRadius(){ return radius_; };
	void SetTimer(int timer);
	int GetTimer(){ return timer_; };
	void Draw();
};