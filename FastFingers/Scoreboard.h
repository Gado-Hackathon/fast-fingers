#pragma once

#include <vector>

#include "Object.h"
#include "Sprite.h"

enum class DisplayMode { RIGHT_ALIGNED, CENTERED };

class Scoreboard : public Object {
private:
	std::vector<Sprite*> sprites;
	int score;
	DisplayMode mode;

	void DrawDigit(int digit, int digitIndex, size_t digitsCount);

public:
	Scoreboard(int score, DisplayMode mode = DisplayMode::RIGHT_ALIGNED);
	Scoreboard(int score, float x, float y, DisplayMode mode = DisplayMode::CENTERED);

	inline int getScore() {
		return score;
	}

	inline void add(int points) {
		score += points;
	}

	inline void Update() {

	}

	void Draw();
};
