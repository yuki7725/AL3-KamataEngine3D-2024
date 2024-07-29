#pragma once
#include "ViewProjection.h"

/// <summary>
/// カメラコントローラ
/// </summary>
class CameraController 
{
public:
	
	void Initialize();

	void Update();

private:
	// ビュープロジェクション
	ViewProjection* viewProjection_ = nullptr;

};
