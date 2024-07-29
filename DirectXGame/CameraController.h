
#pragma once
#include "ViewProjection.h"
#include "player.h"
#include "WorldTransform.h"


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

	

private:
	// ビュープロジェクション
	ViewProjection* viewProjection_ = nullptr;

	Player* target_ = nullptr;

	//追従対象とカメラの座標の差(オフセット)
	Vector3 targetOffset_ = {0, 0, -30.0f};

	//矩形
	struct Rect {
		float left = 0.0f;//左端
		float right = 1.0f;//右端
		float bottom = 0.0f;//下端
		float top = 1.0f;//上端
	};

};
