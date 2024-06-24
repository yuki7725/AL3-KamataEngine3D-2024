#pragma once

#include "Model.h"
#include "WorldTransform.h"

/// <summary>
/// 天球
/// </summary>

class skydome {
public:
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();
	
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
	WorldTransform* worldTransform_;
	//モデル
	Model* model_ = nullptr;
	
};

