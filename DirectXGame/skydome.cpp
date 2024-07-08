#include "skydome.h"

skyDome::skyDome() {}

skyDome::~skyDome() {}

void skyDome::Initialize(Model*model,ViewProjection*viewProjection) {

	assert(model);
	model_ = model;

	//// skyDomeの生成
	//skyDome_ = new skyDome();
	//// skyDomeの初期化
	//skyDome_->Initialize();
	 
	worldTransform_.Initialize();
	viewProjection_=viewProjection;

	// skyDome3Dモデルの生成
	//modelSkyDome_ = Model::CreateFromOBJ("skydome", true);

	worldTransform_.scale_ = {1, 1, 1};

	// 引数の内容をメンバ変数に記録
}

void skyDome::Update() {
	
}

void skyDome::Draw() { 
	model_->Draw(worldTransform_, *viewProjection_); 
}
