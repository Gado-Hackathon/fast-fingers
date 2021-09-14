#pragma once

#include "Game.h"
#include "Sprite.h"
#include "Level.h"
#include "Scoreboard.h"

class GameWin : public Game {
private:
	Sprite* sprite = nullptr;
	Scoreboard* scoreboard = nullptr;
public:
	static int totalScore;

	GameWin(int score);

	inline void Init() override {

	}

	void Update() override;
	void Draw() override;
	void Finalize() override;
};

