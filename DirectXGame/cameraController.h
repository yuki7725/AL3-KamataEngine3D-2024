#pragma once
#include <ViewProjection.h>
#include "player.h"

class Player;

class CameraController {
public:
	void Initialize();

	void Update();

	void Reset();

	void SetTarget(Player* target) { target_ = target; }

private:

	ViewProjection viewProjection_;

	Player* target_ = nullptr;

	Vector3 targetOffset_ = {0, 0, -15.0f};

};
