#include "GameWin.h"
#include "Scoreboard.h"
#include "Engine.h"
#include "Menu.h"
#include "Sprite.h"

int GameWin::totalScore = 0;

GameWin::GameWin(int score) {
	sprite = new Sprite("Resources/GameWin.png");

	scoreboard = new Scoreboard(score, window->CenterX(), 353);
}

void GameWin::Update() {
	if (window->KeyDown(VK_SPACE)) {
		GameWin::totalScore = 0;
		Engine::Next<Menu>();
	}
}

void GameWin::Draw() {
	sprite->Draw(window->CenterX(), window->CenterY());
	scoreboard->Draw();
}

void GameWin::Finalize() {
	delete sprite;
	delete scoreboard;
}
