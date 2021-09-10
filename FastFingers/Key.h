#pragma once

#include "Scene.h"
#include "Object.h"
#include "ObjectType.h"
#include "Sprite.h"

enum class KeyState { ALIVE, REACHED_HITLINE };

class Key : public Object {
private:
	char ch;
	KeyState state;
	Sprite* sprite = nullptr;
	Scene* scene;
	float velocity;
	bool ctrlKey = false;

	void handleKeyPress();
	bool isOutOfTheScreen();

public:
	Key(char ch, float x, float y, float velocity, Scene* scene);
	~Key();

	void Update();

	void OnCollision(Object* obj);

	inline uint Type() const {
		return ObjectType::KEY;
	}

	inline void Draw() {
		sprite->Draw(x, y, Layer::FRONT);
	}
};
