#include "DeathParticles.h"
#include <algorithm>

void DeathParticles::Initialize(Model* model, ViewProjection* viewProjection, Vector3& position) 
{
	assert(model);
	model_ = model;
	viewProjection_ = viewProjection;

	//ワールド変換の初期化
	for (auto& worldTransform : worldTransforms_) {
		worldTransform.Initialize();
		worldTransform.translation_ = position;
	}

	objectColor_.Initialize();
	color_ = {1.0f, 1.0f, 1.0f, 1.0f};

}

void DeathParticles::Update() 
{
	//カウンターを1フレーム分の秒数進める
	counter_ += 1.0f / 60.0f;
	
	//存続時間の上限に達したら
	if (counter_ > kDuration) {
		counter_ = kDuration;
		//終了
		isFinished_ = true;
	}
	

	if (isFinished_) {
		return;
	}

	//
	for (uint32_t i = 0; i < kNumParticles; ++i) {
		
		//基本となる速度ベクトル
		Vector3 velocity = {kSpeed, 0, 0};
		//回転角を計算
		float angle = kAngleUint * i;
		//z周りの回転行列
		Matrix4x4 matrixRotation = MakeRotateZMatrix(angle);
		//基本ベクトルを回転させて速度ベクトルを得る
		velocity = Transform(velocity, matrixRotation);
		//移動処理
		worldTransforms_[i].translation_ = Add(worldTransforms_[i].translation_, velocity);
	}

	for (auto& worldTransform : worldTransforms_) {
		worldTransform.UpdateMatrix();
	}

	color_.w = std::clamp(1.0f - counter_ / kDuration, 0.0f, 1.0f);
	objectColor_.SetColor(color_);
	objectColor_.TransferMatrix();
}

void DeathParticles::Draw() {

	if (isFinished_) {
		return;
	}

	for (auto& worldTransform : worldTransforms_) {
		// 3Dモデルを描画
		model_->Draw(worldTransform,*viewProjection_,&objectColor_);
	}
}