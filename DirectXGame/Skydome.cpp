#include "Skydome.h"
#include "ViewProjection.h"
#include "WorldTransform.h"

SkyDome::SkyDome() {}

SkyDome::~SkyDome() {
	delete model_;
}

void SkyDome::Initialize() { 
	
	//ワールドトランスフォーム
	worldTransform_.Initialize();

	//ビュープロジェクション
	viewProjection_.Initialize();

	//モデル生成
	model_ = Model::Create();
}

void SkyDome::Update() {}

void SkyDome::Draw() {model_->Draw(worldTransform_, viewProjection_);}
