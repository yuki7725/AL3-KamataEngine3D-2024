#include "TitleText.h"
#include <numbers>

TitleText::TitleText() {}

TitleText::~TitleText() {}

void TitleText::Initialize(Model* model, ViewProjection* viewProjection, Vector3& position) {
	// nullポインタチェック
	assert(model);
	model_ = model;

	// ワールド変換の初期化
	worldTransform_.Initialize();
	worldTransform_.translation_ = position;
	worldTransform_.scale_ = {10.0f, 10.0f, 10.0f};


	// 引数の内容をメンバ変数に記録
	viewProjection_ = viewProjection;

	// 初期回転
	worldTransform_.rotation_.x = std::numbers::pi_v<float> / 2.0f;
}

void TitleText::Update() 
{
	worldTransform_.translation_.y = 2.0f * std::sin(std::numbers::pi_v<float>);

	// 行列を更新して定数バッファに転送
	worldTransform_.UpdateMatrix();
}

void TitleText::Draw() 
{
	//// 3Dモデルを描画
	model_->Draw(worldTransform_, *viewProjection_);

}
