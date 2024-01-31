#include <Novice.h>
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"

const char kWindowTitle[] = "GC1A_09_ソウ_イチョウ";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	Player* player = new Player();
	Enemy* enemy = new Enemy();

	enum Scene {
		TITLE,
		GAME,
		OVER
	};

	Scene scene = TITLE;

	int titleHandle = Novice::LoadTexture("./Resources./title.png");
	int gameOverHandle = Novice::LoadTexture("./Resources./GameOver.png");

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		switch (scene) {
			case TITLE:

				if (keys[DIK_RETURN] && !preKeys[DIK_RETURN]) {
					scene = GAME;

				}
				player->Initialise();
				enemy->Initialise();
				break;
			case GAME:

				player->Move(keys, preKeys);
				enemy->Update();

				for (int i = 0; i < 10; i++) {
					if (player->bullet[i]->GetIsShot())
					{
						int a = enemy->GetPosX() - player->bullet[i]->GetPosX();
						int b = enemy->GetPosY() - player->bullet[i]->GetPosY();
						if (((a * a) + (b * b)) < (enemy->GetRadius() + player->bullet[i]->GetRadius()) * (enemy->GetRadius() + player->bullet[i]->GetRadius())) {
							enemy->SetAlive(false);
						}
					}

				}

				if (enemy->GetAlive() == false) {
					enemy->timer_++;
				}

				if (enemy->timer_ >= 120) {
					enemy->SetAlive(true);
					enemy->timer_ = 0;
				}

				for (int i = 0; i < 10; i++) {
					int a = enemy->GetPosX() - player->GetPosX();
					int b = enemy->GetPosY() - player->GetPosY();
					if (((a * a) + (b * b)) < (enemy->GetRadius() + player->GetRadius()) * (enemy->GetRadius() + player->GetRadius())) {
						scene = OVER;
					}

				}

				break;
			case OVER:

				if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
					scene = TITLE;
				}

				
				break;
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		switch (scene) {
			case TITLE:
				Novice::DrawSprite(0, 0, titleHandle, 1, 1, 0.0f, WHITE);
				break;
			case GAME:

				player->Draw();
				enemy->Draw();
				break;

			case OVER:
				Novice::DrawSprite(0, 0, gameOverHandle, 1, 1, 0.0f, WHITE);
				break;
		}

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	delete player;
	delete enemy;

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}