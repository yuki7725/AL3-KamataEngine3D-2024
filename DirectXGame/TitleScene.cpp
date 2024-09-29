#include "TitleScene.h"

TitleScene::TitleScene() {}

TitleScene::~TitleScene() { 
	//delete model_;
	delete modelTitle_; 
	delete titleText_;
}

void TitleScene::Initialize() {
//
	modelTitle_ = Model::CreateFromOBJ("title", true);

	// 3Dモデルの生成
	//model_ = Model::Create();

	// ワールドトランスフォームの初期化
	worldTransform_.Initialize();

	// ビュープロジェクションの初期化
	viewProjection_.farZ = 5000;
	viewProjection_.Initialize();

	titleText_ = new TitleText();

	Vector3 titlePos = {40.0f, 40.0f, 10.0f};

	titleText_->Initialize(modelTitle_, &viewProjection_, titlePos);
}

void TitleScene::Update() 

{	titleText_->Update();
	//
	if (Input::GetInstance()->PushKey(DIK_SPACE)) {
		finished_ = true;
	}

	

	// 行列を更新して定数バッファに転送
	//worldTransform_.UpdateMatrix();
}

void TitleScene::Draw() 
{
		//
	titleText_->Draw();
}
