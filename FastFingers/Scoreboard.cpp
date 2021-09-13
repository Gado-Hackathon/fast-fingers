#include <sstream>

#include "Key.h"
#include "Scoreboard.h"

using std::stringstream;

Scoreboard::Scoreboard(int score, DisplayMode mode) : score(score), mode(mode) {
	for (int i = 0; i <= 9; i++) {
		stringstream stream;
		stream << "Resources/Score/" << i << ".png";
		sprites.push_back(new Sprite(stream.str()));
	}
	const auto marginTop = 96.0f;
	const auto marginRight = 48.0f;
	MoveTo(window->Width() - marginRight, marginTop);
}

Scoreboard::Scoreboard(int score, float x, float y, DisplayMode mode) : Scoreboard(score, mode) {
	MoveTo(x, y);
}

static std::vector<int> allDigits(int number) {
	std::vector<int> result;
	int currentNumber = number;
	int digitIndex = 0;
	if (currentNumber == 0) {
		result.push_back(0);
	}
	while (currentNumber) {
		int digit = currentNumber % 10;
		result.push_back(digit);
		currentNumber /= 10;
		digitIndex++;
	}
	return result;
}

void Scoreboard::Draw() {
	auto digits = allDigits(score);
	const auto digitsCount = digits.size();
	for (auto i = 0; i < digitsCount; i++) {
		DrawDigit(digits[i], i, digitsCount);
	}
}

void Scoreboard::DrawDigit(int digit, int digitIndex, size_t digitsCount) {
	const auto spriteWidth = sprites[0]->Width();
	float offsetX = 0;
	if (mode == DisplayMode::CENTERED) {
		offsetX = float(spriteWidth) * (digitsCount / 2);
	}
	sprites[digit]->Draw(x - digitIndex * spriteWidth + offsetX, y);
}
