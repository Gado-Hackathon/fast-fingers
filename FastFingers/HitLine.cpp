#include "HitLine.h"
#include "Key.h"

HitLine::HitLine() {
	sprite = new Sprite("Resources/HitLine.png");
	const float topMargin = 358;
	MoveTo(window->Width() / 2.0f, topMargin + sprite->Height() / 2.0f);
	BBox(new Rect(-sprite->Width() / 2.0f, -sprite->Height() / 2.0f, sprite->Width() / 2.0f, sprite->Height() / 2.0f));
}

bool HitLine::isKeyBellowAndOut(Key* key) {
	return key->Y() > y + sprite->Height();
}

HitLine::~HitLine() {
	delete sprite;
}
