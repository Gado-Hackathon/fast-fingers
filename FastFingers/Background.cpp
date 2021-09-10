#include "Background.h"

Background::Background() {
	MoveTo(window->CenterX(), window->CenterY());
	sprite = new Sprite("Resources/Background.png");
}

Background::~Background() {
	delete sprite;
}
