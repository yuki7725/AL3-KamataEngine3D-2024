#include "player.h"
#include <assert.h>

void Player::Initialize(Model* model, uint32_t textureHandle, ViewProjection* viewProjection) {
	//nullポインタチェック
	assert(model); 

	//引数の内容をメンバ変数に記録
	viewProjection_ = viewProjection;

}

void Player::Update() {

	//行列を定数バッファに転送
	worldTransform_.TransferMatrix();
}

void Player::Draw() {}
