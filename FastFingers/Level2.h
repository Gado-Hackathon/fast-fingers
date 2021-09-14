#pragma once

#include "Level.h"
#include "Level3.h"

class Level2 : public Level {
public:
	Level2() : Level("Level2.txt", new Level3(), 2) {}

	inline Level* copy() {
		return new Level2();
	}
	
	int healthLostPerMistake();
	void Update();
};
