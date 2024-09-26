#include "Enemy.h"
#include <assert.h>
#include <numbers>
#include <MapChipField.h>
#include <DebugText.h>

Enemy::Enemy(){};

Enemy::~Enemy() {}



void Enemy::Initialize(Model* model, ViewProjection* viewProjection, Vector3& position) 
{
	//nullポインタチェック
	assert(model);
	model_ = model;

	// ワールド変換の初期化
	worldTransform_.Initialize();
	worldTransform_.translation_ = position;


	// 初期回転
	worldTransform_.rotation_.y = std::numbers::pi_v<float> * 3.0f / 2.0f;

	// 引数の内容をメンバ変数に記録
	viewProjection_ = viewProjection;

	//速度を設定
	velocity_ = {-kWalkSpeed, 0, 0};

	//タイマー初期化
	walkTimer_ = 0.0f;
}

void Enemy::Update() 
{
	//移動
	worldTransform_.translation_ = Add(worldTransform_.translation_, velocity_);

	//タイマーを加算
	walkTimer_ += 1.0f / 60.0f;

	// 行列を更新して定数バッファに転送
	worldTransform_.UpdateMatrix();
}

void Enemy::Draw() 
{
	// 3Dモデルを描画
	model_->Draw(worldTransform_, *viewProjection_);
}
