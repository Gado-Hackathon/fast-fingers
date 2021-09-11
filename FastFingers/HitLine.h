#pragma once

#include "Object.h"
#include "Sprite.h"
#include "ObjectType.h"
#include "Key.h"

class HitLine : public Object {
private:
	Sprite* sprite = nullptr;

public:
	HitLine();
	~HitLine();

	inline int Height() {
		return sprite->Height();
	}

	inline void Update() {

	}

	inline uint Type() const {
		return ObjectType::HITLINE;
	}

	inline void Draw() {
		sprite->Draw(x, y);
	}
};

