#include "Novice.h"
#include "Player.h"
#include "Bullet.h"

void Player::Move(char* keys, char* preKeys) {
	if (keys[DIK_W]) {
		transform_.y -= speedY_;
	}
	if (keys[DIK_S]) {
		transform_.y += speedY_;
	}
	if (keys[DIK_A]) {
		transform_.x -= speedX_;
	}
	if (keys[DIK_D]) {
		transform_.x += speedX_;
	}

	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
		for (int i = 0; i < 10; i++) {
			if (bullet[i]->GetIsShot() == false) {
				bullet[i]->SetPosX(transform_.x);
				bullet[i]->SetPosY(transform_.y);
				bullet[i]->SetIsShot(true);
				break;
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		if (bullet[i]->GetIsShot() == true) {
			bullet[i]->Update();

		}
	}
	for (int i = 0; i < 10; i++) {
		if (bullet[i]->GetPosY() < -20) {
			bullet[i]->SetIsShot(false);
		}
	}
}

void Player::SetPosX(int x)
{
	transform_.x = x;
}

void Player::SetPosY(int y)
{
	transform_.y = y;
}


void Player::Draw() {
	Novice::DrawEllipse(transform_.x, transform_.y, radius_, radius_, 0.0f, RED, kFillModeSolid);
	for (int i = 0; i < 10; i++) {
		if (bullet[i]->GetIsShot() == true) {
			bullet[i]->Draw();
		}
	}
}


Player::Player() {
	for (int i = 0; i < 10; i++)
	{
		bullet[i] = new Bullet;
	}
}


Player::~Player() {
	delete *bullet;
	//for (int i = 0; i < 10; i++)
	//{
	//	delete bullet[i];
	//}
}

void Player::Initialise() {
	transform_ = { 680, 600 };
	speedX_ = 10;
	speedY_ = 10;
	radius_ = 10;
}