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

	
};