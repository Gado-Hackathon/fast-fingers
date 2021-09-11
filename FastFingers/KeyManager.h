#pragma once

#include <unordered_map>
#include <queue>

#include "Object.h"
#include "Scene.h"
#include "Key.h"
#include "Timer.h"

class KeyManager : public Object {
private:
	float timerDelay = 0;
	Scene* scene;
	std::unordered_map<char, std::queue<Key*>> keys;
	Timer timer;

public:
	KeyManager(Scene* scene);
	~KeyManager();

	void Update();

	inline void Draw() {

	}
};
