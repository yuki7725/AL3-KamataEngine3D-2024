#include "Enemy.h"
#include <assert.h>
#include <numbers>
#include <MapChipField.h>
#include <DebugText.h>

Enemy::Enemy() {}

Enemy::~Enemy() {}



void Enemy::Initialize(Model* model, ViewProjection* viewProjection, const Vector3& position) 
{
	//nullポインタチェック
	assert(model);

	// ワールド変換の初期化
	worldTransform_.Initialize();
	worldTransform_.translation_;

	// 初期回転
	worldTransform_.rotation_.y = std::numbers::pi_v<float> * 3.0f / 2.0f;

	// 引数の内容をメンバ変数に記録
	viewProjection_ = viewProjection;
}

void Enemy::Update() {}

void Enemy::Graw() {}
