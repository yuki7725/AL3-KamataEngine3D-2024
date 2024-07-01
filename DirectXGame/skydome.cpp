#include "skydome.h"
#include "assert.h"


skyDome::skyDome() {}

skyDome::~skyDome() {}

void skyDome::Initialize() {

	//assert(model);

	// skyDomeの生成
	skyDome_ = new skyDome();
	// skyDomeの初期化
	skyDome_->Initialize();
	// skyDome3Dモデルの生成
	modelSkyDome_ = Model::CreateFromOBJ("skydome", true);

	// ワールド変換の初期化
	worldTransform_.Initialize();

	// 引数の内容をメンバ変数に記録
}

void skyDome::Update() {
	
}

void skyDome::Draw() { 
	model_->Draw(worldTransform_, viewProjection_); 
}
