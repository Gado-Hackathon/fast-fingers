#ifndef _PROGJOGOS_KEYMAN_H_
#define _PROGJOGOS_KEYMAN_H_

#include <unordered_map>
#include <queue>
#include <vector>
#include <functional>

#include "Object.h"
#include "Scene.h"
#include "Key.h"
#include "Timer.h"
#include "LevelLoader.h"
#include "Scoreboard.h"
#include "HitLine.h"
#include "Health.h"
#include "Level.h"

class KeyManager : public Object {
private:
	float timerDelay = 0;
	Level* level;
	Scene* scene;
	Scoreboard* scoreboard;
	std::unordered_map<char, std::vector<Key*>> keys;
	Timer timer;
	std::unordered_map<char, bool> controls;
	bool ctrlKey = false;
	std::queue<Key*> keysToBeSpawned;
	HitLine* hitLine;
	Health* health;
	std::function<void()> onGameOver;

	void handleKeyPress();

public:
	static KeyManager* keyManager;
	KeyManager(Level* level, Scene* scene, Scoreboard* scoreboard, HitLine* hitline, Health* health, std::function<void()> onGameOver);

	void addAll(std::vector<KeyInfo> keysInfo);
	void Update();

	bool isEmpty();

	inline void Draw() {

	}
};

#endif