#pragma once
#include "Model.h"
#include "WorldTransform.h"
#include "ViewProjection.h"
#include "cassert"
#include "Input.h"
#include <algorithm>
#include <numbers>
#include <TitleText.h>

class TitleScene 
{
public:

	TitleScene();
	~TitleScene();

	void Initialize();

	void Update();

	void Draw();

	bool IsFinished() const { return finished_; }

private:

	//Model* model_ = nullptr;

	bool finished_ = false;

	

	// ワールドトランスフォーム
	WorldTransform worldTransform_;

	// ビュープロジェクション
	ViewProjection viewProjection_;

	TitleText* titleText_ = nullptr;

	Model* modelTitle_ = nullptr;
};

