#include "WorldTransform.h"

void WorldTransform::UpdateMatrix() {
	matWorld_ = WorldTransform::UpdateMatrix(scale_, rotation_, translation_); 
	TransferMatrix();
}