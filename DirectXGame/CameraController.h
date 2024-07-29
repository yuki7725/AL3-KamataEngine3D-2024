#pragma once
#include "ViewProjection.h"
#include "player.h"

//前方宣言
class Player;

/// <summary>
/// カメラコントローラ
/// </summary>
class CameraController 
{
public:
	
	void Initialize();

	void Update();

	void SetTarget(Player* target) { target_ = target; }

private:
	// ビュープロジェクション
	ViewProjection* viewProjection_ = nullptr;

	Player* target_ = nullptr;

};
