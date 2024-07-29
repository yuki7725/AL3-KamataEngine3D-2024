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

	WorldTransform& GetWorldTransform();

	

private:

	//ワールド変換データ
	WorldTransform worldTransform_;

	//ビュープロジェクション
	ViewProjection* viewProjection_ = nullptr;

	//モデル
	Model* model_ = nullptr;

	Vector3 velocity_ = {};

	//テクスチャハンドル
	uint32_t textureHandle_ = 0u;

	static inline const float kAcceleration = 0.1f;
	static inline const float kAttenuation = 0.1f;
	static inline const float kLimitRunSpeed = 1.0f;

	enum class LRDirection {
			kRight,
			kLeft,
		};
	
	LRDirection lrDirection_ = LRDirection::kRight;
	

	//旋回開始時の角度
	float turnFirstRotationY_ = 0.0f;
	//旋回タイマー
	float turnTimer_ = 0.0f;

	//旋回時間(秒)
	static inline const float kTimeTurn = 0.3f;

	//重力加速度(下)
	static inline const float kGravityAcceleration = 0.1f;
	//最大落下速度(下)
	static inline const float kLimitFallSpeed = 7.0f;
	//ジャンプ加速(上)
	static inline const float kJumpAcceleration = 0.5f;
	
	//接地状態フラグ
	bool onGround_ = true;
};