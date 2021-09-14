#include <algorithm>
#include <vector>
#include <sstream>

#include "KeyManager.h"
#include "LevelLoader.h"
#include "GameOver.h"
#include "Engine.h"
#include "Level1.h"
#include "Menu.h"
#include "Key.h"

using namespace std;

KeyManager* KeyManager::keyManager = nullptr;

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
		auto key = new Key(keyInfo.ch, keyInfo.x, keyInfo.y, keyInfo.time, keyInfo.velocity, scene, [this, keyInfo](Deletion deletion) {
			for (int i = 0; i < keys[keyInfo.ch].size(); ++i) {
				auto key = keys[keyInfo.ch][i];

				if (key != deletion.key) {
					continue;
				}

				if (!deletion.success) {
					health->lose(level->healthLostPerMistake());

					if (health->isDead()) {
						onGameOver();
					}
				}

				keys[keyInfo.ch].erase(keys[keyInfo.ch].begin() + i);
				break;
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
			keys[key->getCharacter()].push_back(key);
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
				for (const auto& key : keysWithSameCharAsPressedKey) {
					auto isBellowHitline = key->Y() > (hitLine->Y() + hitLine->Height());
					auto keyAndHitLineAreColliding = scene->Collision(key, hitLine);

					if (isBellowHitline) {
						continue;
					}
					
					if (keyAndHitLineAreColliding) {
						auto points = key->getScore();
						scoreboard->add(points);
						key->markForDeletionWithSuccess();
					}
					else {
						key->markForDeletionWithFailure();
					}

					break;
				}
			}
		}
		else if (window->KeyUp(ch)) {
			controls[ch] = true;
		}
	}
}

bool KeyManager::isEmpty() {
	bool isKeysEmpty = true;

	for (auto [_, vector] : keys) {
		if (!vector.empty()) {
			isKeysEmpty = false;
			break;
		}
	}

	return keysToBeSpawned.empty() && isKeysEmpty;
}
