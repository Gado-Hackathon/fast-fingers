#include "Level4.h"
#include "Engine.h"
#include "Menu.h"

int Level4::healthLostPerMistake() {
	return 50;
}

void Level4::Update() {
	if (window->KeyDown(VK_ESCAPE)) {
		Engine::Next<Menu>();
	}
	else {
		Level::Update();
	}
}
