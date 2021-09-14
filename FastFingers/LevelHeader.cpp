#include <sstream>

#include "LevelHeader.h"

using namespace std;

LevelHeader::LevelHeader(int level) {
	stringstream ss;
	ss << "Resources/Levels/Level" << level << ".png";
	sprite = new Sprite(ss.str());
	MoveTo(window->CenterX(), 27);
}

LevelHeader::~LevelHeader() {
	delete sprite;
}