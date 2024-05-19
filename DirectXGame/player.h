#pragma once
#include <Model.h>
#include <WorldTransform.h>

class Player {
public:

	void Initialize();

	void Update();

	void Draw();

private:

	//ワールド変換データ
	WorldTransform worldTransform_;

	//モデル
	Model* model_ = nullptr;

	//テクスチャハンドル
	uint32_t textureHandle_ = 0u;

};