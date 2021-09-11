#pragma once

#include <unordered_map>
#include <queue>
#include <vector>

#include "Object.h"
#include "Scene.h"
#include "Key.h"
#include "Timer.h"
#include "LevelLoader.h"

class KeyManager : public Object {
private:
	float timerDelay = 0;
	Scene* scene;
	std::unordered_map<char, std::queue<Key*>> keys;
	Timer timer;
	std::unordered_map<char, bool> controls;
	bool ctrlKey = false;
	std::queue<Key*> keysToBeSpawned;

	void handleKeyPress();

public:
	KeyManager(Scene* scene);
	~KeyManager();

	void addAll(std::vector<KeyInfo> keysInfo);
	void Update();

	inline void Draw() {

	}
};
