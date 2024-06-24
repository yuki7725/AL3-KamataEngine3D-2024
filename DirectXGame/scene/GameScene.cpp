#include "GameScene.h"
#include "TextureManager.h"
#include <cassert>

GameScene::GameScene() {}

GameScene::~GameScene() {
	delete model_;
	delete player_;
	delete modelBlock_;
	delete debugCamera_;
	delete skydome_;

	for (std::vector<WorldTransform*>& worldTransferBlockLine : worldTransformBlocks_) {
		for (WorldTransform* worldTransformBlock : worldTransferBlockLine) {
			delete worldTransformBlock;
		}	
	}
	worldTransformBlocks_.clear();
}

void GameScene::Initialize() {

	dxCommon_ = DirectXCommon::GetInstance();
	input_ = Input::GetInstance();
	audio_ = Audio::GetInstance();

	//ファイル名を指定してテクスチャを読み込む
	textureHandle_ = TextureManager::Load("cube/cube.jpeg");

	//3Dモデルの生成
	model_ = Model::Create();

	//ワールドトランスフォームの初期化
	worldTransform_.Initialize();

	//ビュープロジェクションの初期化
	viewProjection_.Initialize();

	//自キャラの生成
	player_ = new Player();

	//自キャラの初期化
	player_->Initialize(model_,textureHandle_,&viewProjection_);

	modelBlock_ = new Model();

	//要素数
	const uint32_t kNumBlockHorizontal = 20;
	const uint32_t kNumBlockVertical = 10;
	//横幅
	const float kBlockWidth = 2.0f;
	//縦幅
	const float kBlockHeight = 2.0f;
	//要素数を変更する
	worldTransformBlocks_.resize(kNumBlockVertical);
	for (uint32_t i = 0; i < kNumBlockVertical; ++i) {
		//一列の要素数を設定
		worldTransformBlocks_[i].resize(kNumBlockHorizontal);
	}

	//キューブの生成
	for (uint32_t i = 0; i < kNumBlockHorizontal; ++i) {
		for (uint32_t j = 0; j < kNumBlockVertical; ++i) {

			worldTransformBlocks_[i][j] = new WorldTransform();
			worldTransformBlocks_[i][j]->Initialize();
			worldTransformBlocks_[i][j]->translation_.x = kBlockWidth * i;
			worldTransformBlocks_[i][j]->translation_.y = kBlockHeight * i;
		}
	}

	//画面縦幅
	const int kWindowWidth = 1280;
	const int kWindowHeight = 720;

	//デバッグカメラの生成
	debugCamera_ = new DebugCamera(kWindowWidth, kWindowHeight);

	//skydomeの生成
	skydome_ = new skydome();
	//skydomeの初期化
	skydome_->Initialize();
}

void GameScene::Update() {

	#ifdef _DEBUG
	if (input_->TriggerKey(DIK_SPACE)) {
		isDebugCameraActive_ = !isDebugCameraActive_;
	}
#endif // _DEBUG


	//自キャラの更新
	player_->Update();

	//ブロックの更新
	for (std::vector<WorldTransform*>& worldTransferBlockLine : worldTransformBlocks_) {
		for (WorldTransform* worldTransformBlock : worldTransferBlockLine) {
			if (!worldTransformBlock)
				continue;
			worldTransformBlock->UpdateMatrix();
		}
	}

	//カメラの処理
	if (isDebugCameraActive_) {
		debugCamera_->Update();
		viewProjection_.matView = debugCamera_->GetViewProjection().matView;
		viewProjection_.matProjection = debugCamera_->GetViewProjection().matProjection;
		//ビュープロジェクション行列の更新と転送
		viewProjection_.UpdateMatrix();
	}

	//skydomeの処理
	skydome_->Update();
}

void GameScene::Draw() {

	// コマンドリストの取得
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();

#pragma region 背景スプライト描画
	// 背景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに背景スプライトの描画処理を追加できる
	/// </summary>

	// スプライト描画後処理
	Sprite::PostDraw();
	// 深度バッファクリア
	dxCommon_->ClearDepthBuffer();
#pragma endregion

#pragma region 3Dオブジェクト描画
	// 3Dオブジェクト描画前処理
	Model::PreDraw(commandList);

	/// <summary>
	/// ここに3Dオブジェクトの描画処理を追加できる
	/// </summary>
	
	//自キャラの描画
	player_->Draw();


	// 3Dオブジェクト描画後処理
	Model::PostDraw();
#pragma endregion

#pragma region 前景スプライト描画
	// 前景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに前景スプライトの描画処理を追加できる
	/// </summary>
	
	//ブロックの描画
	for (std::vector<WorldTransform*>& worldTransferBlockLine : worldTransformBlocks_) {
		for (WorldTransform* worldTransformBlock : worldTransferBlockLine) {
			if (!worldTransformBlock) {
				continue;
			}
			model_->Draw(*worldTransformBlock, viewProjection_);
		}
	}

	//skydomeの描画
	skydome_->Draw();

	// スプライト描画後処理
	//Sprite::PostDraw();

	
#pragma endregion
}
