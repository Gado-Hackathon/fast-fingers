#pragma once

#include <vector>

#include "Sprite.h"
#include "Object.h"

class Health : public Object {
private:
	std::vector<Sprite*> sprites;
	int health;

public:
	Health(int health = 100);
	~Health();

	inline bool isDead() {
		return health == 0;
	}

	void lose(int health);

	inline void Update() {

	}

	void Draw();
};
