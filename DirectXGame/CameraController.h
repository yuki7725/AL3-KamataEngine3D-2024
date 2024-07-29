#pragma once
#include "ViewProjection.h"
#include "player.h"
#include "WorldTransform.h"
#include "Input.h"
#include <algorithm>
#include "string.h"
#include "clac.h"

//前方宣言
class Player;

/// <summary>
/// カメラコントローラ
/// </summary>
class CameraController 
{
public:
	
	void Initialize(ViewProjection* viewProjection);

	void Update();

	void SetTarget(Player* target) { target_ = target; }

	void Reset();

	//矩形
	struct Rect {
		float left = 0.0f;//左端
		float right = 1.0f;//右端
		float bottom = 0.0f;//下端
		float top = 1.0f;//上端
	};

	void SetMovableArea(Rect area) { movableArea_ = area; }

private:
	// ビュープロジェクション
	ViewProjection* viewProjection_ = nullptr;

	Player* target_ = nullptr;

	//追従対象とカメラの座標の差(オフセット)
	Vector3 targetOffset_ = {0, 0, -20.0f};

	//カメラ移動範囲
	Rect movableArea_ = {0, 100, 0, 100};

	//カメラの目標座標
	Vector3 cameraMarkPos_{};

	//座標補間割合
	static inline const float kInterpolationRate = 2.0f;

	//速度掛け率
	/*static inline const*/ float kVelocityBias = 3.0f;
};
