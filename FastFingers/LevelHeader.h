#pragma once

#include "Object.h"
#include "Sprite.h"

class LevelHeader : public Object
{
private:
	Sprite* sprite = nullptr;

public:
	LevelHeader(int level);
	~LevelHeader();
	inline void Update() {}
	inline void Draw() {
		sprite->Draw(x, y);
	}
};
