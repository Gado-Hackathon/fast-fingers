#pragma once

#include "Game.h"
#include "Sprite.h"
#include "Level.h"
#include "Scoreboard.h"

class GameOver : public Game {
private:
	Level* level = nullptr;
	Sprite* sprite = nullptr;
	Scoreboard* scoreboard = nullptr;
public:
	GameOver(int score, Level* level);

	inline void Init() override {

	}

	void Update() override;
	void Draw() override;
	void Finalize() override;
};

