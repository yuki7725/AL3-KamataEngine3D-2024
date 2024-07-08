#pragma once

#include "assert.h"
#include "Model.h"
#include "WorldTransform.h"
#include "ViewProjection.h"

/// <summary>
/// 天球
/// </summary>

class skyDome {
public:

	skyDome();
	~skyDome();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize(Model* model, ViewProjection* viewProjection);
	
	/// <summary>
	/// 更新
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

private:
	//ワールド変換データ
	WorldTransform worldTransform_;
	//モデル
	Model* model_ = nullptr;
	//ビュープロジェクション
	ViewProjection *viewProjection_=nullptr;
	// テクスチャハンドル
	//uint32_t textureHandle_ = 0u;

	// 天球
	/*skyDome* skyDome_ = nullptr;

	Model* modelSkyDome_ = nullptr;*/
	
};

