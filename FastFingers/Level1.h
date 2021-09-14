#pragma once

#include "Level.h"
#include "Level2.h"

class Level1 : public Level {
public:
	Level1() : Level("Level1.txt", new Level2(), 1) {}

	inline Level* copy() {
		return new Level1();
	}

	void Update();
};
