#include "skydome.h"

void skyDome::Initialize() {}

void skyDome::Update() {}

void skyDome::Draw() { 
	model_->Draw(worldTransform_, viewProjection_); 
}
