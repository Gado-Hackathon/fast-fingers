#pragma once

#include "Level.h"
#include "Level5.h"

class Level4 : public Level {
public:
	Level4() : Level("Level4.txt", new Level5(), 4) {}

	inline Level* copy() {
		return new Level4();
	}

	int healthLostPerMistake();
	void Update();
};
