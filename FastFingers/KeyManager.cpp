#include <algorithm>
#include <vector>

#include "KeyManager.h"
#include "LevelLoader.h"

using namespace std;

KeyManager::KeyManager(Scene* scene, Scoreboard* scoreboard, HitLine* hitLine) : scene(scene), scoreboard(scoreboard), hitLine(hitLine) {
	for (uint i = 0; i < 256; i++) {
		controls[i] = false;
	}
	timer.Start();
}

KeyManager::~KeyManager() {

}

void KeyManager::addAll(vector<KeyInfo> keysInfo) {
	sort(keysInfo.begin(), keysInfo.end(), [](const KeyInfo& a, const KeyInfo& b) {
		return a.time < b.time;
	});
	for (const auto& keyInfo : keysInfo) {
		auto key = new Key(keyInfo.ch, keyInfo.x, keyInfo.y, keyInfo.time, keyInfo.velocity, scene, [this, keyInfo]() {
			keys[keyInfo.ch].pop();
		});
		keysToBeSpawned.push(key);
	}
}

void KeyManager::Update() {
	/*
	float secondsBetweenSpawns = 1.0f;
	float seconds = timer.Elapsed();
	if (seconds >= secondsBetweenSpawns) {
		timer.Reset();
		auto key = new Key('W', 150, 100, 300.0f, scene, [this]() {
			keys['W'].pop();
		});
		keys['W'].push(key);
		scene->Add(key, MOVING);
	}
	*/
	while (!keysToBeSpawned.empty() && keysToBeSpawned.front()->getTime() >= timer.Elapsed()) {
		auto key = keysToBeSpawned.front();
		keysToBeSpawned.pop();
		keys[key->getCharacter()].push(key);
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
				auto key = keysWithSameCharAsPressedKey.front();
				if (!hitLine->isKeyBellowAndOut(key)) {
					auto points = key->getScore();
					scoreboard->add(points);
				}
				key->markForDeletion();
			}
		}
		else if (window->KeyUp(ch)) {
			controls[ch] = true;
		}
	}
}