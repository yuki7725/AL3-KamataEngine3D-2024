#pragma once
#include <ViewProjection.h>
#include <WorldTransform.h>
#include "player.h"

class Player;

class CameraController {
public:
	void Initialize();

	void Update();

	void Reset();

	void SetTarget(Player* target) { target_ = target; }

	void SetMovableArea(Vector3* Area) { movableArea_ = Area; }

private:

	ViewProjection viewProjection_;
	WorldTransform worldTransform_;

	Player* target_ = nullptr;

	Vector3 targetOffset_ = {0, 0, -15.0f};

	//矩形
	struct Rectangle {
		float left = 0.0f;
		float right = 1.0f;
		float bottom = 0.0f;
		float top = 1.0f;
	};

	//カメラ移動範囲
	Rectangle movableArea_ = {0, 100, 0, 100};
	
	//カメラの目標座標(後で変更する)
	Vector3 a /*目標座標*/ = {0.0f, 0.0f, 0.0f};

	//座標保管割合
	static inline const float kInterpolationRate = 0.5f;

};
