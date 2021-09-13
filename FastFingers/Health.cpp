#include <sstream>

#include "Health.h"

using namespace std;

Health::Health(int health) : health(health) {
	for (int i = 0; i <= 10; i++) {
		stringstream stream;
		auto percentage = i * 10;
		stream << "Resources/Health/Health" << percentage << ".png";
		auto fileName = stream.str();
		auto sprite = new Sprite(fileName);
		sprites.push_back(sprite);
	}
	const auto marginTop = 548.0f;
	MoveTo(window->Width() / 2.0f, marginTop + sprites[0]->Height() / 2.0f);
}

Health::~Health() {
	for (auto sprite : sprites) {
		delete sprite;
	}
}

void Health::lose(int ammount) {
	health = max(health - ammount, 0);
}

void Health::Draw() {
	// health está entre 0 e 10%, exibe 10%
	const auto minimumHealth = min(10, health / 10);
	auto percent = health == 0 ? 0 : minimumHealth;
	sprites[percent]->Draw(x, y, Layer::FRONT);
}
