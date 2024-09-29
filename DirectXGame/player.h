#pragma once
#include "Model.h"
#include "WorldTransform.h"
#include "ViewProjection.h"
#include "cassert"
#include "Input.h"
#include <algorithm>
#include <numbers>


//マップとの当たり判定
struct CollisionMapInfo {
	bool isCeiling = false; //天井
	bool isLanding = false;
	bool hitWall = false; //壁
	Vector3 movement; //移動量
};

class MapChipField;

class Enemy;

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
	void MapCollisionBottom(CollisionMapInfo& info);
	void MapCollisionRight(CollisionMapInfo& info);
	void MapCollisionLeft(CollisionMapInfo& info);

	//角
	enum Corner { 
		kRightBottom, //右下
		kLeftBottom, //左下
		kRightTop, //右上
		kLeftTop, //左上

		kNumCorner //要素数
	};

	Vector3 CornerPosition(const Vector3& center, Corner corner);

	//判定結果を反映させて移動
	void CollisionResult(CollisionMapInfo& info);

	//天井に接触している場合の処理
	void isCeilingCollision(CollisionMapInfo& info);

	//地面に接触している時の処理(接地状態の切り替え処理)
	void isLandingCollision(CollisionMapInfo& info);

	//壁に接触している場合の処理
	void isWallCollision(CollisionMapInfo& info);

	//ワールド座標を取得
	Vector3 GetWorldPosition();

	AABB GetAABB();

	void OnCollision(const Enemy* enemy);

	bool cameraStop = false;

	//デスフラグ
	bool isDead_ = false;
	//デスフラグのgetter
	bool IsDead() const { return isDead_; }

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

	static inline const float kAcceleration = 0.09f;
	static inline const float kAttenuation = 0.08f;
	static inline const float kLimitRunSpeed = 0.3f;

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
	static inline const float kTimeTurn = 0.1f;

	//重力加速度(下)
	static inline const float kGravityAcceleration = 0.01f;
	//最大落下速度(下)
	static inline const float kLimitFallSpeed = 0.3f;
	//ジャンプ加速(上)
	static inline const float kJumpAcceleration = 0.4f;
	
	//接地状態フラグ
	bool onGround_ = true;

	//マップチップフィールド
	MapChipField* mapChipField_ = nullptr;

	//キャラクターの当たり判定サイズ
	static inline const float kWidth = 1.8f;
	static inline const float kHeight = 1.8f;

	static inline const float kBlank = 0.01f;

	//着地時の速度減衰率
	static inline const float kAttenuationLanding = 0.1f;

	//壁にぶつかった時の速度減衰
	static inline const float kAttenuationWall = 0.09f;

	

};