#pragma once

#include "Object.h"
#include "Sprite.h"

class Background : public Object {
private:
	Sprite* sprite = nullptr;

public:
	Background();
	~Background();

	inline void Update() {

	}

	inline void Draw() {
		sprite->Draw(x, y, Layer::BACK);
	}
};

