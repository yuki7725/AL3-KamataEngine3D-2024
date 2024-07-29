#define NOMINMAX
#include "CameraController.h"
#include "player.h"

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
