#pragma once

#include <functional>

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
	Scene* scene = nullptr;
	float velocity;
	bool ctrlKey = false;
	std::function<void()> onDeletedCallback;

	void HandleKeyPress();
	bool IsOutOfTheScreen();

public:
	Key(char ch, float x, float y, float velocity, Scene* scene);
	~Key();

	void setOnDeletedCallback(std::function<void()> onDeletedCallback) {
		this->onDeletedCallback = onDeletedCallback;
	}

	void Update();

	void OnCollision(Object* obj);

	inline uint Type() const {
		return ObjectType::KEY;
	}

	inline void Draw() {
		sprite->Draw(x, y, Layer::FRONT);
	}
};
