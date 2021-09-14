#pragma once

#include "Level.h"
#include "Level4.h"

class Level3 : public Level {
public:
	Level3() : Level("Level3.txt", new Level4(), 3) {}

	inline Level* copy() {
		return new Level3();
	}

	int healthLostPerMistake();
	void Update();
};
