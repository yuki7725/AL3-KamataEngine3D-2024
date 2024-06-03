#include "cameraController.h"
#include "WorldTransform.h"

void CameraController::Initialize() {

	viewProjection_.Initialize();

}

void CameraController::Update() { 
	//追従対象のワールドトランスフォームを参照
	const WorldTransform& targetWorldTransform = target_->GetWorldTransform();
	//追従対象をオフセット空カメラの座標を計算
	viewProjection_.translation_ = targetWorldTransform.translation_ + targetOffset_;
	//行列を更新する
	viewProjection_.UpdateMatrix();
}

void CameraController::Reset() {
	const WorldTransform& TargetWorldTransform = target_->GetWorldTransform();

	viewProjection_.translation_ = TargetWorldTransform.translation_ + targetOffset_;

}





























































