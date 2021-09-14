#include "Level2.h"
#include "Engine.h"
#include "Menu.h"

int Level2::healthLostPerMistake() {
	return 20;
}

void Level2::Update() {
	if (window->KeyDown(VK_ESCAPE)) {
		Engine::Next<Menu>();
	}
	else {
		Level::Update();
	}
}
