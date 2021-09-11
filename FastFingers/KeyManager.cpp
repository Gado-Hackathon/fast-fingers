#include <algorithm>

#include "KeyManager.h"

using namespace std;

KeyManager::KeyManager(Scene* scene) : scene(scene) {
	timer.Start();
}

KeyManager::~KeyManager() {

}

void KeyManager::Update() {
	auto seconds = timer.Elapsed();
	if (seconds - timerDelay >= 1) {
		timerDelay = seconds - 1;
		timer.Reset();
		auto key = new Key('W', window->Width() / 2.0f - 150, 100, 300.0f, scene);
		key->setOnDeletedCallback([this]() {
			keys['W'].pop();
		});
		keys['W'].push(key);
		scene->Add(key, MOVING);
	}
}
