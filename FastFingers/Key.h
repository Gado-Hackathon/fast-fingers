#pragma once

#include <functional>

#include "Scene.h"
#include "Object.h"
#include "ObjectType.h"
#include "Sprite.h"

enum class KeyState { ALIVE, REACHED_HITLINE, MARKED_FOR_DELETION };

class Key : public Object {
private:
	char ch;
	KeyState state;
	Sprite* sprite = nullptr;
	Scene* scene = nullptr;
	float velocity;
	std::function<void()> onDeletedCallback;
	float time;

	void HandleKeyPress();
	bool IsOutOfTheScreen();

public:
	Key(char ch, float x, float y, float time, float velocity, Scene* scene, std::function<void()> onDeletedCallback);
	~Key();

	inline float getTime() {
		return time;
	}

	inline char getCharacter() {
		return ch;
	}

	inline void markForDeletion() {
		state = KeyState::MARKED_FOR_DELETION;
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
