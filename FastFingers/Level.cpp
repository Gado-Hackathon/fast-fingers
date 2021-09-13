#include <string>

#include "Level.h"
#include "HitLine.h"
#include "Key.h"
#include "Scoreboard.h"
#include "KeyManager.h"
#include "LevelLoader.h"
#include "Health.h"
#include "Engine.h"
#include "Menu.h"
#include "GameOver.h"
#include "Level1.h"

using namespace std;

Level::Level(const string& fileName) : fileName(fileName) {

}

void Level::Init() {
	mt = mt19937(rd());
	distributionX = uniform_real_distribution<float>(0.0f, float(window->Width()));
	distributionY = uniform_real_distribution<float>(-200.0f, 0);
	distributionVelocity = uniform_real_distribution<float>(100.0f, 150.0f);

	scene = new Scene();
	scene->Add(new Background(), STATIC);
	auto hitLine = new HitLine();
	scene->Add(hitLine, STATIC);
	// scene->Add(new Key('Q', window->Width() / 2.0f, 200.0f, 100.0f, scene), MOVING);
	// scene->Add(new Key('R', window->Width() / 2.0f - 100, 100.0f, 100.0f, scene), MOVING);
	scoreboard = new Scoreboard(0);
	scene->Add(scoreboard, STATIC);
	auto health = new Health();
	scene->Add(health, STATIC);
	auto keyManager = new KeyManager(this, scene, scoreboard, hitLine, health, [this]() {
		markGameOver();
	});
	keyManager->addAll(loadLevel(fileName));
	scene->Add(keyManager, STATIC);
}

void Level::Finalize() {
	delete scene;
}

void Level::Update() {
	if (isGameOver) {
		auto level = copy();
		auto gameOver = new GameOver(scoreboard->getScore(), level);
		Engine::Next(gameOver);
		return;
	}
	if (ctrlKeyB && window->KeyDown('B')) {
		viewBBox = !viewBBox;
		ctrlKeyB = false;
	}
	else if (window->KeyUp('B')) {
		ctrlKeyB = true;
	}

	scene->Update();
	scene->CollisionDetection();
}

void Level::Draw() {
	scene->Draw();

	if (viewBBox) {
		scene->DrawBBox();
	}
}
