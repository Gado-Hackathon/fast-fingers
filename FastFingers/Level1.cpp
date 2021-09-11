#include "Level1.h"
#include "Engine.h"
#include "Home.h"

void Level1::Update() {
	if (window->KeyDown(VK_ESCAPE)) {
		Engine::Next<Menu>();
	}
	else {
		Level::Update();
	}
}
