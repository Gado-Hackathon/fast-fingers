#include "GameOver.h"
#include "Scoreboard.h"
#include "Engine.h"
#include "Menu.h"
#include "Sprite.h"
#include "GameWin.h"

GameOver::GameOver(int score, Level* level) : level(level) {
	sprite = new Sprite("Resources/GameOver.png");
	scoreboard = new Scoreboard(GameWin::totalScore, float(window->Width()) / 2, float(window->Height()) / 2);
	GameWin::totalScore = 0;
}

void GameOver::Update() {
	if (window->KeyDown(VK_SPACE)) {
		Engine::Next(level);
	}
	else if (window->KeyDown(VK_ESCAPE)) {
		Engine::Next<Menu>();
	}
}

void GameOver::Draw() {
	sprite->Draw(float(window->Width()) / 2, float(window->Height()) / 2);
	scoreboard->Draw();
}

void GameOver::Finalize() {
	delete sprite;
	delete scoreboard;
}
