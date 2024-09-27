#pragma once

#include "Audio.h"
#include "DirectXCommon.h"
#include "Input.h"
#include "Model.h"
#include "Sprite.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include "player.h"
#include <vector>
#include "DebugCamera.h"
#include "skydome.h"
#include "MapChipField.h"
#include "CameraController.h"
#include "Enemy.h"

/// <summary>
/// ゲームシーン
/// </summary>
class GameScene {

public: // メンバ関数
	/// <summary>
	/// コンストクラタ
	/// </summary>
	GameScene();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~GameScene();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

private: // メンバ変数
	DirectXCommon* dxCommon_ = nullptr;
	Input* input_ = nullptr;
	Audio* audio_ = nullptr;
	DebugCamera* debugCamera_ = nullptr;


	// テクスチャハンドル
	uint32_t textureHandle_ = 0;

	// 3Dモデルデータ
	Model* model_ = nullptr;
	Model* modelSkyDome_ = nullptr;//天球

	Model* modelPlayer_ = nullptr;
	Model* modelEnemy_ = nullptr;

	// ワールドトランスフォーム
	WorldTransform worldTransform_;

	// ビュープロジェクション
	ViewProjection viewProjection_;

	std::vector<std::vector<WorldTransform*>> worldTransformBlocks_;

	// 自キャラ
	Player* player_ = nullptr;
	
	//敵
	//Enemy* enemy_ = nullptr;
	std::list<Enemy*> enemies_;
	static inline const uint32_t enemyMapCount = 3;

	Model* modelBlock_ = nullptr;

	//デバッグカメラ
	bool isDebugCameraActive_ = false;

	// 天球
	skyDome* skyDome_ = nullptr;

	//マップチップフィールド
	MapChipField* mapChipField_ = nullptr;

	void GenerateBlocks();

	//カメラコントローラ
	CameraController* cameraController_=nullptr;
	
	

	/// <summary>
	/// ゲームシーン用
	/// </summary>
};
