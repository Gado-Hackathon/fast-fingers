#include "Level3.h"
#include "Engine.h"
#include "Menu.h"

int Level3::healthLostPerMistake() {
	return 34;
}

void Level3::Update() {
	if (window->KeyDown(VK_ESCAPE)) {
		Engine::Next<Menu>();
	}
	else {
		Level::Update();
	}
}
