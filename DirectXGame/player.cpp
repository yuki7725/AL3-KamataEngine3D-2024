#include "player.h"
#include <assert.h>

Player::Player(){};

Player::~Player(){};

void Player::Initialize(Model* model, uint32_t textureHandle, ViewProjection* viewProjection) {
	//nullポインタチェック
	assert(model); 

	//引数として受け取ったデータをメンバ変数に記録
	model_ = model;
	textureHandle_ = textureHandle;

	//ワールド変換の初期化
	worldTransform_.Initialize();

	//引数の内容をメンバ変数に記録
	viewProjection_ = viewProjection;

}

void Player::Update() {

	//行列を更新して定数バッファに転送
	worldTransform_.UpdateMatrix();
}

void Player::Draw() {
	// 3Dモデルを描画
	model_->Draw(worldTransform_, *viewProjection_, textureHandle_);
}
