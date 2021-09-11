#include <algorithm>

#include "KeyManager.h"

using namespace std;

KeyManager::KeyManager(Scene* scene) : scene(scene) {
	for (uint i = 0; i < 256; i++) {
		controls[i] = false;
	}
	timer.Start();
}

KeyManager::~KeyManager() {

}

void KeyManager::Update() {
	float secondsBetweenSpawns = 1.0f;
	float seconds = timer.Elapsed();
	if (seconds >= secondsBetweenSpawns) {
		timer.Reset();
		auto key = new Key('W', window->Width() / 2.0f - 150, 100, 300.0f, scene);
		key->setOnDeletedCallback([this]() {
			keys['W'].pop();
		});
		keys['W'].push(key);
		scene->Add(key, MOVING);
	}
	handleKeyPress();
}

void KeyManager::handleKeyPress() {
	for (const auto& [ch, _] : keys) {
		int lowercaseKey = tolower(ch);
		if (controls[ch] && window->KeyDown(ch)) {
			controls[ch] = false;
			auto keysWithSameCharAsPressedKey = keys[ch];
			bool hasKeyToDelete = !keysWithSameCharAsPressedKey.empty();
			if (hasKeyToDelete) {
				keysWithSameCharAsPressedKey.front()->markForDeletion();
			}
		}
		else if (window->KeyUp(ch)) {
			controls[ch] = true;
		}
	}
}