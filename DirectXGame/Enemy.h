#pragma once

#pragma once
#include "Model.h"
#include "WorldTransform.h"
#include "ViewProjection.h"
#include "cassert"
#include "Input.h"
#include <algorithm>


class Enemy {
public:
	
	Enemy();
	~Enemy();

	void Initialize(Model* model, ViewProjection* viewProjection,  Vector3& position);
	
	void Update();
	
	void Draw();

private:

	// ワールド変換データ
	WorldTransform worldTransform_;


	// ビュープロジェクション
	ViewProjection* viewProjection_ = nullptr;

	// モデル
	Model* model_ = nullptr;

	// テクスチャハンドル
	uint32_t textureHandle_ = 0u;

	//歩行の速さ
	static inline const float kWalkSpeed = 0.03f;

	//速度
	Vector3 velocity_ = {};

	//アニメーション
	//最初の角度
	static inline const float kWalkMotionAngleStart = -0.5f;
	//最後の角度
	static inline const float kWalkMotionAngleEnd = 0.5f;
	//アニメーションの周期(時間、秒)
	static inline const float kWalkMotionTime = 3.0f;
	//経過時間
	float walkTimer_ = 0.0f;

};
