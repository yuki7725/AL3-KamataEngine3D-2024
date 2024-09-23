#define NOMINMAX

#include "player.h"
#include <assert.h>
#include <numbers>
#include <MapChipField.h>
#include <DebugText.h>


Player::Player(){};

Player::~Player() {}
void Player::Initialize(Model* model, ViewProjection* viewProjection, Vector3& position)
{

	//nullポインタチェック
	assert(model); 

	//引数として受け取ったデータをメンバ変数に記録
	model_ = model;
	
	//ワールド変換の初期化
	worldTransform_.Initialize();
	worldTransform_.translation_ = position;

	//初期回転
	worldTransform_.rotation_.y = std::numbers::pi_v<float> / 2.0f;

	//引数の内容をメンバ変数に記録
	viewProjection_ = viewProjection;
}

///////////////////////////////////////////////////////////

void Player::Update() {
	//着地フラグ
	bool landing = false;

	//地面との当たり判定
	//下降中か
	if (velocity_.y < 0) {
		//Y座標が地面以下になったら着地
		if (worldTransform_.translation_.y <= 2.0f) {
			landing = true;
		}
	}

	//接地判定
	if (onGround_) {
		//ジャンプ開始
		if (velocity_.y > 0.0f) {
			//空中状態に移行
			onGround_ = false;
		}
	 
		Movement();
		
		if (Input::GetInstance()->PushKey(DIK_UP)) {
				// ジャンプ初速
				velocity_ = Add(velocity_, {0.0f, kJumpAcceleration, 0.0f});
		}

	} else {
			
		velocity_ = Add(velocity_, Vector3(0, -kGravityAcceleration, 0));

		velocity_.y = std::max(velocity_.y, -1 * kLimitFallSpeed);

		// 着地
		if (landing) {
			// めり込み排斥
			worldTransform_.translation_.y = 2.0f;
			// 摩擦で横方向速度減衰
			velocity_.x *= (1.0f - kAttenuation);
			// 下方向速度リセット
			velocity_.y = 0.0f;
			// 接地状態に移行
			onGround_ = true;
		}
	}
	
	
	//旋回制御
	if (turnTimer_ > 0.0f) {
		turnTimer_ -= 1.0f / 60.0f;

		float destinationRotationYTable[] = {
			std::numbers::pi_v<float> / 2.0f, 
			std::numbers::pi_v<float> * 3.0f / 2.0f
		};

		// 状態に応じた角度を取得
		float destinationRotationY = destinationRotationYTable[static_cast<uint32_t>(lrDirection_)];
		// 自キャラの角度を設定
		float rate = 1 - turnTimer_ / kTimeTurn;
		worldTransform_.rotation_.y = std::lerp(turnFirstRotationY_ ,destinationRotationY ,rate);
	}

	
	//衝突
	//衝突情報を初期化
	CollisionMapInfo collisionMapInfo;
	//移動量に速度の値をコピー
	collisionMapInfo.movement = velocity_;
	
	//マップ衝突チェック
	MapCollision(collisionMapInfo);

	worldTransform_.translation_ = Add(worldTransform_.translation_, velocity_);



	if (worldTransform_.translation_.x > 30) {
		worldTransform_.translation_.x = 30;
	}
	if (worldTransform_.translation_.x < 2) {
		worldTransform_.translation_.x = 2;
	}

	//行列を更新して定数バッファに転送
	worldTransform_.UpdateMatrix();
}

void Player::Draw() {
	// 3Dモデルを描画
	model_->Draw(worldTransform_, *viewProjection_);

	/*WorldTransform& Player::GetWorldTransform()
	{
		return worldTransform;
	}*/
}

WorldTransform& Player::GetWorldTransform() {
	// TODO: return ステートメントをここに挿入
	return worldTransform_;
}

void Player::Movement() 
{

	//移動入力
	// 接地状態
	if (Input::GetInstance()->PushKey(DIK_RIGHT) || Input::GetInstance()->PushKey(DIK_LEFT)) {

		// 左右移動操作
		Vector3 acceleration = {};
		if (Input::GetInstance()->PushKey(DIK_RIGHT)) {
			// 左移動中の右入力
			if (velocity_.x < 0.0f) {
				velocity_.x *= (1.0f - kAttenuation);
			}

			acceleration.x += kAcceleration;

			// 向き変更
			if (lrDirection_ != LRDirection::kRight) {
				lrDirection_ = LRDirection::kRight;

				// 角度記録
				turnFirstRotationY_ = worldTransform_.rotation_.y;
				// タイマー
				turnTimer_ = kTimeTurn;
			}

		} else if (Input::GetInstance()->PushKey(DIK_LEFT)) {
			// 右移動中の左入力
			if (velocity_.x > 0.0f) {
				velocity_.x *= (1.0f - kAttenuation);
			}

			acceleration.x -= kAcceleration;

			// 向き変更
			if (lrDirection_ != LRDirection::kLeft) {
				lrDirection_ = LRDirection::kLeft;

				// 角度記録
				turnFirstRotationY_ = worldTransform_.rotation_.y;
				// タイマー
				turnTimer_ = kTimeTurn;
			}
		}

		velocity_ = Add(velocity_, acceleration);
		velocity_.x = std::clamp(velocity_.x, -kLimitRunSpeed, kLimitRunSpeed);

	} else {
		// 移動減衰
		velocity_.x *= (1.0f - kAttenuation);
	}
	////
}

/////////////////////////////////////////////////////

void Player::MapCollision(CollisionMapInfo& info) { MapCollisionTop(info); }

/////////////////////////////////////////////////////

//マップ衝突判定上方向
void Player::MapCollisionTop(CollisionMapInfo& info) 
{
	//移動後の四つの座標
	std::array<Vector3, kNumCorner> positionsNew;

	for (uint32_t i = 0; i < positionsNew.size(); ++i) {
		positionsNew[i] = CornerPosition(Add(worldTransform_.translation_, info.movement), static_cast<Corner>(i));
	}

	//上昇ありか
	if (info.movement.y <= 0) {
		return;
	}

	MapChipType mapChipType;

	//真上の当たり判定
	bool hit = false;

	MapChipField::IndexSet indexSet;
	
	//左上点の判定
	
	indexSet = mapChipField_->GetMapChipIndexSetByPosition(positionsNew[kLeftTop]);
	mapChipType = mapChipField_->GetMapChipTypeByIndex(indexSet.xIndex, indexSet.yIndex);
	if (mapChipType == MapChipType::kBlock) {
		hit = true;
	}

	//右上点の判定
	indexSet = mapChipField_->GetMapChipIndexSetByPosition(positionsNew[kRightTop]);
	mapChipType = mapChipField_->GetMapChipTypeByIndex(indexSet.xIndex, indexSet.yIndex);
	if (mapChipType == MapChipType::kBlock) {
		hit = true;
	}

	//ヒットしたか
	if (hit) {
		//めり込みを排除する方向に移動量を設定
		indexSet = mapChipField_->GetMapChipIndexSetByPosition(Add(worldTransform_.translation_, info.movement));
		//めり込み先ブロックの範囲矩形
		MapChipField::Rect rect = mapChipField_->GetRectByIndex(indexSet.xIndex, indexSet.yIndex);
		info.movement.y = std::max(0.0f, info.movement.y);
		//天井に当たった事を確認する
		info.isCeiling = true;
	}

	CollisionResult(info);
	isCeilingCollision(info);
}

/////////////////////////////////////////////////////

void Player::MapCollisionBottom(CollisionMapInfo& info) 
{
	//下降ありか
	if (info.movement.y >= 0) {
		return;
	}

}

//void Player::MapCollisionRight(CollisionMapInfo& info) {}
//
//void Player::MapCollisionLeft(CollisionMapInfo& info) {}

/////////////////////////////////////////////////////


Vector3 Player::CornerPosition(const Vector3& center, Corner corner) 
{ 
	Vector3 offsetTable[kNumCorner] = {
	    {+kWidth / 2.0f, -kHeight / 2.0f, 0},
        {-kWidth / 2.0f, -kHeight / 2.0f, 0},
        {+kWidth / 2.0f, +kHeight / 2.0f, 0},
        {-kWidth / 2.0f, -kHeight / 2.0f, 0}
    };
	return Add(center, offsetTable[static_cast<uint32_t>(corner)]);
}


/////////////////////////////////////////////////////

void Player::CollisionResult(CollisionMapInfo& info) 
{
	//移動
	worldTransform_.translation_ = Add(worldTransform_.translation_, info.movement);
}


/////////////////////////////////////////////////////

void Player::isCeilingCollision(CollisionMapInfo& info)
{
	//天井に当たったか
	if (info.isCeiling) {
		velocity_.y = 0;
	}
}
