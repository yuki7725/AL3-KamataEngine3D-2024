#include "cameraController.h"
#include "WorldTransform.h"
#include <cmath>
#include "player.h"

void CameraController::Initialize() {

	//ビュープロジェクションの初期化
	viewProjection_.Initialize();

}

void CameraController::Update() { 
	//追従対象のワールドトランスフォームを参照
	const WorldTransform& targetWorldTransform = target_->GetWorldTransform();
	//追従対象をオフセット空カメラの目標座標を計算
	a.x = targetWorldTransform.translation_ + targetOffset_;
	
	//座標保管二よりゆったり追従
	viewProjection_.translation_ = Lerp /*Lerp関数は自作する*/ (viewProjection_.translation_, a, kInterpolationRate);

	//移動範囲制限
	viewProjection_.translation_.x = std::min(viewProjection_.translation_.x, movableArea_.left);
	viewProjection_.translation_.x = std::max(viewProjection_.translation_.x, movableArea_.right);
	viewProjection_.translation_.y = std::min(viewProjection_.translation_.y, movableArea_.bottom);
	viewProjection_.translation_.y = std::max(viewProjection_.translation_.y, movableArea_.top);

	//行列を更新する
	viewProjection_.UpdateMatrix();
}

void CameraController::Reset() {
	const WorldTransform& TargetWorldTransform = target_->GetWorldTransform();

	viewProjection_.translation_ = TargetWorldTransform.translation_ + targetOffset_;

}





























































