#pragma once

#include "Level.h"
#include "Level2.h"

class Level2 : public Level {
public:
	Level2() : Level("Level2.txt", nullptr, 2) {}

	inline Level* copy() {
		return new Level2();
	}

	void Update();
};
