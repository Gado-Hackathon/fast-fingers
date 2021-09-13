#pragma once

#include "Level.h"

class Level1 : public Level {
public:
	Level1() : Level("Level1.txt") {}

	inline Level* copy() {
		return new Level1();
	}

	void Update();
};
