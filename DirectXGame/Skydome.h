#pragma once

#include <Model.h>

//天球
class SkyDome {
public:
	
	//初期化
	void Initialize();

	//更新
	void Update();

	//描画
	void Draw();

private:
	
	//ワールド変換データ
	WorldTransform worldTransform_;
	ViewProjection viewProjection_;
	//モデル
	Model* model_ = nullptr;
};
