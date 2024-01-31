#include "Novice.h"
#include "Bullet.h"

Bullet::Bullet() {

}
void Bullet::SetPosX(int x)
{
	transform_.x = x;
}
void Bullet::SetPosY(int y)
{
	transform_.y = y;
}
void Bullet::SetIsShot(bool isShot)
{
	isShot_ = isShot;
}
;

void Bullet::Update() {
	transform_.y -= speed_;
}

void Bullet::Draw() {
	if (isShot_ == true) {
		Novice::DrawEllipse(transform_.x, transform_.y, radius_, radius_, 0.0f, WHITE, kFillModeSolid);
	}
}
