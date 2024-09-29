#pragma once

#include "Input.h"
#include "Model.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include "cassert"

#include <array>
#include <numbers>
#include <algorithm>

class DeathParticles 
{
public:

	void Initialize(Model* model, ViewProjection* viewProjection, Vector3& position);

	void Update();

	void Draw();

private:

	WorldTransform worldTransform_;

	ViewProjection* viewProjection_ = nullptr;

	Model* model_ = nullptr;

	//パーティクルの個数
	static inline const uint32_t kNumParticles = 0;

	std::array<WorldTransform, kNumParticles> worldTransforms_;

	//存続時間
	static inline const float kDuration = 1.0f;
	//速さ
	static inline const float kSpeed = 0.1f;
	//分割した1コ分の角度
	static inline const float kAngleUint = std::numbers::pi_v<float> * 2 / kNumParticles;

	//終了フラグ
	bool isFinished_ = false;

	//経過時間カウント
	float counter_ = 0.0f;
};
