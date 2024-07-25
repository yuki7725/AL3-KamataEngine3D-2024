#include "player.h"
#include <assert.h>
#include <numbers>

Player::Player(){};

Player::~Player() {}
void Player::Initialize(Model* model, ViewProjection* viewProjection, Vector3& position)
{

	//nullポインタチェック
	assert(model); 

	//引数として受け取ったデータをメンバ変数に記録
	model_ = model;
	//textureHandle_ = textureHandle;

	//ワールド変換の初期化
	worldTransform_.Initialize();
	worldTransform_.translation_ = position;

	//引数の内容をメンバ変数に記録
	viewProjection_ = viewProjection;

	//初期回転
	worldTransform_.rotation_.y = std::numbers::pi_v<float> / 2.0f;

}

void Player::Update() {

	//移動入力
	//左右移動操作
	Vector3 acceleration = {};
	if (Input::GetInstance()->PushKey(DIK_RIGHT)) {
		//左移動中の右入力
		if (velocity_.x < 0.0f) {
			velocity_.x *= (1.0f - kAttenuation);
		}

		//向き変更
		if (lrDirection_ != LRDirection::kRight) {
			lrDirection_ = LRDirection::kRight;
		}

		acceleration.x += kAcceleration;

	} else if (Input::GetInstance()->PushKey(DIK_LEFT)) {
		//右移動中の左入力
		if (velocity_.x > 0.0f) {
			velocity_.x *= (1.0f - kAttenuation);
		}

		//向き変更
		if (lrDirection_ != LRDirection::kLeft) {
			lrDirection_ = LRDirection::kLeft;
		}

		acceleration.x -= kAcceleration;

	} else {
		//移動減衰
		velocity_.x *= (1.0f - kAttenuation);
	}

	//加速と減速
	velocity_.x += acceleration.x;
	velocity_.y += acceleration.y;
	velocity_.z += acceleration.z;

	//移動
	worldTransform_.translation_.x += velocity_.x;
	worldTransform_.translation_.y += velocity_.y;
	worldTransform_.translation_.z += velocity_.z;

	//最大速度制限
	velocity_.x = std::clamp(velocity_.x, -kLimitRunSpeed, kLimitRunSpeed);

	//行列を更新して定数バッファに転送
	worldTransform_.UpdateMatrix();
}

void Player::Draw() {
	// 3Dモデルを描画
	model_->Draw(worldTransform_, *viewProjection_, textureHandle_);
}
