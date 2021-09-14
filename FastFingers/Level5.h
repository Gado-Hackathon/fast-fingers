#pragma once

#include "Level.h"

class Level5 : public Level {
public:
	Level5() : Level("Level5.txt", nullptr, 5) {}

	inline Level* copy() {
		return new Level5();
	}

	int healthLostPerMistake();
	void Update();
};
