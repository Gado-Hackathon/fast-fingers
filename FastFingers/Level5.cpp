#include "Level5.h"
#include "Engine.h"
#include "Menu.h"

int Level5::healthLostPerMistake() {
	return 100;
}

void Level5::Update() {
	if (window->KeyDown(VK_ESCAPE)) {
		Engine::Next<Menu>();
	}
	else {
		Level::Update();
	}
}
