#include "Enemy.h"
#include "Novice.h"
#include "Player.h"

Enemy::Enemy() {}
Enemy::~Enemy()
{
}
;

void Enemy::Update() {
	transform_.x += speedX_;
	transform_.y += speedY_;

	if (transform_.x - radius_ <= 0 || transform_.x + radius_ >= 1280) {
		speedX_ *= -1;
	}
	if (transform_.y - radius_ <= 0 || transform_.y + radius_ >= 720) {
		speedY_ *= -1;
	}
}

void Enemy::SetAlive(bool isAlive)
{
	isAlive_ = isAlive;
}

void Enemy::SetTimer(int timer)
{
	timer_ = timer;
}

void Enemy::Draw() {
	if (isAlive_ == true) {
		Novice::DrawEllipse(transform_.x, transform_.y, radius_, radius_, 0.0f, BLUE, kFillModeSolid);
	}
}

void Enemy::Initialise() {
	transform_ = { 680, 200 };
	speedX_ = 5;
	speedY_ = 5;
	radius_ = 30;
	isAlive_ = true;
}