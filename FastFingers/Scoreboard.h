#pragma once

#include <vector>

#include "Object.h"
#include "Sprite.h"

class Scoreboard : public Object {
private:
	std::vector<Sprite*> sprites;
	int score;
	void DrawDigit(int digit, int digitIndex);

public:
	Scoreboard(int score);
	Scoreboard(int score, float x, float y);

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
