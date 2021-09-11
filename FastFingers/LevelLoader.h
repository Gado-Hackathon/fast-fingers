#pragma once
#include <string>
#include <string>

#include "Key.h"

struct KeyInfo {
	char ch;
	float velocity;
	float time;
	float x, y;

	KeyInfo(char ch, float time, float x, float y, float velocity) :
		ch(ch), time(time), x(x), y(y), velocity(velocity) {}
};

std::vector<KeyInfo> loadLevel(const string& level);