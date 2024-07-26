#pragma once
#include "Model.h"
#include "WorldTransform.h"
#include "ViewProjection.h"
#include "cassert"
#include "Input.h"
#include <algorithm>

class Player {
public: 

	Player();
	~Player();

	void Initialize(Model* model, ViewProjection* viewProjection,Vector3& position);

	void Update();

	void Draw();

	enum class LRDirection {
		kRight,
		kLeft,
	};
	
	LRDirection lrDirection_ = LRDirection::kRight;
	
	//接地状態フラグ
	bool onGround_ = true;

private:

	//ワールド変換データ
	WorldTransform worldTransform_;

	//モデル
	Model* model_ = nullptr;

	//テクスチャハンドル
	uint32_t textureHandle_ = 0u;

	//ビュープロジェクション
	ViewProjection* viewProjection_ = nullptr;

	static inline const float kAcceleration = 0.05f;
	static inline const float kAttenuation = 0.05f;
	static inline const float kLimitRunSpeed = 0.05f;

	Vector3 velocity_ = {};

	//旋回開始時の角度
	float turnFirstRotationY_ = 0.0f;
	//旋回タイマー
	float turnTimer_ = 0.0f;

	//旋回時間(秒)
	static inline const float kTimeTurn = 0.3f;

	//重力加速度(下)
	static inline const float kGravityAcceleration = 2.0f;
	//最大落下速度(下)
	static inline const float kLimitFallSpeed = 2.0f;
	//ジャンプ加速(上)
	static inline const float kJumpAcceleration = 2.0f;
	

};