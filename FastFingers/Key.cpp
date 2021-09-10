#include <sstream>

#include "Key.h"
#include "Scene.h"
#include "HitLine.h"

using std::stringstream;

Key::Key(char ch, float x, float y, float velocity, Scene* scene) : ch(ch), velocity(velocity), scene(scene) {
	state = KeyState::ALIVE;
	stringstream stream;
	stream << "Resources/Keys/" << ch << ".png";
	sprite = new Sprite(stream.str());
	BBox(new Rect(-sprite->Width() / 2.0f, -sprite->Height() / 2.0f, sprite->Width() / 2.0f, sprite->Height() / 2.0f));
	MoveTo(x, y);
}

Key::~Key() {
	delete sprite;
}

bool Key::IsOutOfTheScreen() {
	return y >= window->Height() + sprite->Height() / 2;
}

void Key::HandleKeyPress() {
	int lowercaseKey = tolower(ch);
	if (ctrlKey && window->KeyDown(ch)) {
		ctrlKey = false;
		scene->Delete();
	}
	else if (window->KeyUp(ch)) {
		ctrlKey = true;
	}
}

void Key::Update() {
	Translate(0, velocity * gameTime);
	HandleKeyPress();
	if (IsOutOfTheScreen()) {
		scene->Delete();
	}
}

void Key::OnCollision(Object* obj) {
	if (obj->Type() == ObjectType::HITLINE) {
		state = KeyState::REACHED_HITLINE;
		auto hitline = static_cast<HitLine*>(obj);
	}
}
