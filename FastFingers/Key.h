#pragma once

#include <functional>

#include "Scene.h"
#include "Object.h"
#include "ObjectType.h"
#include "Sprite.h"

enum class KeyState { ALIVE, REACHED_HITLINE, MARKED_FOR_DELETION_BY_SUCCESS, MARKED_FOR_DELETION_BY_FAILURE };

struct Deletion;

class Key : public Object {
private:
	char ch;
	KeyState state;
	Sprite* sprite = nullptr;
	Scene* scene = nullptr;
	float velocity;
	std::function<void(Deletion)> onDeletedCallback;
	float time;
	float score = 0;

	bool shouldBeDeleted();
	void HandleKeyPress();
	bool IsOutOfTheScreen();

public:
	Key(char ch, float x, float y, float time, float velocity, Scene* scene, std::function<void(Deletion)> onDeletedCallback);
	~Key();

	inline int getScore() {
		return int(score);
	}

	inline float getTime() {
		return time;
	}

	inline char getCharacter() {
		return ch;
	}

	inline void markForDeletionWithSuccess() {
		state = KeyState::MARKED_FOR_DELETION_BY_SUCCESS;
	}

	inline void markForDeletionWithFailure() {
		state = KeyState::MARKED_FOR_DELETION_BY_FAILURE;
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

struct Deletion {
	bool success;
	Key* key;

	Deletion(bool success, Key* key) : success(success), key(key) {}
};