#pragma once
#include "Transform.h"

class Bullet {
private:
	Transform transform_ = { 1400, 1000 };
	int radius_ = 5;
	int speed_ = 20;
	bool isShot_ = false;

public:
	Bullet();
	int GetPosX() { return transform_.x; };
	int GetPosY() { return transform_.y; };
	void SetPosX(int x);
	void SetPosY(int y);
	void SetIsShot(bool isShot);
	int GetSpeed() { return speed_; };
	int GetRadius() { return radius_; };
	bool GetIsShot() { return isShot_; };
	void Update();
	void Draw();
};