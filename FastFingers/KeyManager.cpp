#include <algorithm>
#include <vector>
#include <sstream>

#include "KeyManager.h"
#include "LevelLoader.h"
#include "GameOver.h"
#include "Engine.h"
#include "Level1.h"
#include "Menu.h"

using namespace std;

KeyManager::KeyManager(Level* level, Scene* scene, Scoreboard* scoreboard, HitLine* hitLine, Health* health, std::function<void()> onGameOver)
	: level(level), scene(scene), scoreboard(scoreboard), hitLine(hitLine), health(health), onGameOver(onGameOver) {
	for (uint i = 0; i < 256; i++) {
		controls[i] = false;
	}
	timer.Stop();
}

void KeyManager::addAll(vector<KeyInfo> keysInfo) {
	sort(keysInfo.begin(), keysInfo.end(), [](const KeyInfo& a, const KeyInfo& b) {
		return a.time < b.time;
	});
	for (const auto& keyInfo : keysInfo) {
		auto key = new Key(keyInfo.ch, keyInfo.x, keyInfo.y, keyInfo.time, keyInfo.velocity, scene, [this, keyInfo](bool success) {
			keys[keyInfo.ch].pop();
			if (!success) {
				health->lose(level->healthLostPerMistake());
				if (health->isDead()) {
					onGameOver();
				}
			}
		});
		keysToBeSpawned.push(key);
	}
}

void KeyManager::Update() {
	if (timer.Stopped()) {
		timer.Reset();
	}
#if _DEBUG
	stringstream stream;
	stream << timer.Elapsed() << endl;
	OutputDebugString(stream.str().c_str());
#endif
	while (!keysToBeSpawned.empty()) {
		auto key = keysToBeSpawned.front();
		auto keyTime = key->getTime();
		auto currentTime = timer.Elapsed();
		if (currentTime >= keyTime) {
			keysToBeSpawned.pop();
			keys[key->getCharacter()].push(key);
			scene->Add(key, MOVING);
		}
		else {
			break;
		}
	}
	handleKeyPress();
}

void KeyManager::handleKeyPress() {
	for (const auto& [ch, _] : keys) {
		if (controls[ch] && window->KeyDown(ch)) {
			controls[ch] = false;
			auto keysWithSameCharAsPressedKey = keys[ch];
			bool hasKeyToDelete = !keysWithSameCharAsPressedKey.empty();
			if (hasKeyToDelete) {
				auto key = keysWithSameCharAsPressedKey.front();
				auto keyAndHitLineAreColliding = scene->Collision(key, hitLine);
				if (keyAndHitLineAreColliding) {
					auto points = key->getScore();
					scoreboard->add(points);
					key->markForDeletionWithSuccess();
				}
				else {
					key->markForDeletionWithFailure();
				}
			}
		}
		else if (window->KeyUp(ch)) {
			controls[ch] = true;
		}
	}
}