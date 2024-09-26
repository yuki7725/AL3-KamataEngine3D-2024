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

	void Initialize(Model* model, ViewProjection* viewProjection, const Vector3& position);
	
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

};
