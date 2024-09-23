#pragma once
#include "Model.h"
#include "WorldTransform.h"
#include "ViewProjection.h"
#include "cassert"
#include "Input.h"
#include <algorithm>

//マップとの当たり判定
struct CollisionMapInfo {
	bool isCeiling = false;
	bool isLanding = false;
	bool isWall = false;
	Vector3 movement;
};

class MapChipField;


class Player {
public: 

	Player();
	~Player();

	void Initialize(Model* model, ViewProjection* viewProjection,Vector3& position);

	void Update();

	void Draw();

	WorldTransform& GetWorldTransform();

	const Vector3& GetVelocity() const { return velocity_; }

	void SetMapChipField(MapChipField* mapChipField) { mapChipField_ = mapChipField; }
	
	//動き
	void Movement();

	//マップ衝突判定
	void MapCollision(CollisionMapInfo& info);

	//各方向の衝突判定
	void MapCollisionTop(CollisionMapInfo& info);
	/*void MapCollisionBottom(CollisionMapInfo& info);
	void MapCollisionRight(CollisionMapInfo& info);
	void MapCollisionLeft(CollisionMapInfo& info);*/

	//角
	enum Corner { 
		kRightBottom, //右下
		kLeftBottom, //左下
		kRightTop, //右上
		kLeftTop, //左上

		kNumCorner //要素数
	};

	Vector3 CornerPosition(const Vector3& center, Corner corner);

private:

	//ワールド変換データ
	WorldTransform worldTransform_;

	//ビュープロジェクション
	ViewProjection* viewProjection_ = nullptr;

	//モデル
	Model* model_ = nullptr;

	Vector3 velocity_ = {};

	//テクスチャハンドル
	uint32_t textureHandle_ = 0u;

	static inline const float kAcceleration = 0.1f;
	static inline const float kAttenuation = 0.1f;
	static inline const float kLimitRunSpeed = 1.0f;

	enum class LRDirection {
			kRight,
			kLeft,
		};
	
	LRDirection lrDirection_ = LRDirection::kRight;
	

	//旋回開始時の角度
	float turnFirstRotationY_ = 0.0f;
	//旋回タイマー
	float turnTimer_ = 0.0f;

	//旋回時間(秒)
	static inline const float kTimeTurn = 0.3f;

	//重力加速度(下)
	static inline const float kGravityAcceleration = 0.1f;
	//最大落下速度(下)
	static inline const float kLimitFallSpeed = 7.0f;
	//ジャンプ加速(上)
	static inline const float kJumpAcceleration = 0.5f;
	
	//接地状態フラグ
	bool onGround_ = true;

	//マップチップフィールド
	MapChipField* mapChipField_ = nullptr;

	//キャラクターの当たり判定サイズ
	static inline const float kWidth = 0.8f;
	static inline const float kHeight = 0.8f;
};