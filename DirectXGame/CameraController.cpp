#define NOMINMAX
#include "CameraController.h"
#include "player.h"
#include "iostream"
#include "algorithm"

void CameraController::Initialize(ViewProjection* viewProjection) 
{ 
	viewProjection_ = viewProjection;
}

void CameraController::Update() 
{
	//追従対象のワールドトランスフォームを参照
	const WorldTransform& targetWorldTransform = target_->GetWorldTransform();

	//追従対象とオフセットからカメラの座標を計算
	viewProjection_->translation_ = Add(targetWorldTransform.translation_ ,targetOffset_);

	//移動範囲制限
	viewProjection_->translation_.x = std::max(viewProjection_->translation_.x, movableArea_.left);
	viewProjection_->translation_.x = std::min(viewProjection_->translation_.x, movableArea_.right);
	viewProjection_->translation_.y = std::max(viewProjection_->translation_.y, movableArea_.bottom);
	viewProjection_->translation_.y = std::min(viewProjection_->translation_.y, movableArea_.top);

	//行列を更新する
	viewProjection_->UpdateMatrix();
}

void CameraController::Reset() 
{
	//追従対象のワールドトランスフォームを参照
	const WorldTransform& targetWorldTransform = target_->GetWorldTransform();

	//追従対象とオフセットからカメラの座標を計算
	viewProjection_->translation_ = Add(targetWorldTransform.translation_, targetOffset_);

}
