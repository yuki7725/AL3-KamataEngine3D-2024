#pragma once
#include "Model.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include "cassert"

class Player {
public:
	Player();
	~Player();

	void Initialize(Model* model, uint32_t textureHandle, ViewProjection* viewProjection);

	void Update();

	void Draw();

private:
	// ワールド変換データ
	WorldTransform worldTransform_;

	// モデル
	Model* model_ = nullptr;

	// テクスチャハンドル
	uint32_t textureHandle_ = 0u;

	// ビュープロジェクション
	ViewProjection* viewProjection_ = nullptr;
};
