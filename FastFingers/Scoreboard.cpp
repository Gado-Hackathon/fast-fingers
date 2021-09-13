#include <sstream>
#include <vector>

#include "Image.h"
#include "Key.h"
#include "Scoreboard.h"

using namespace std;;

Scoreboard::Scoreboard(int score, DisplayMode mode) : score(score), mode(mode) {
	for (int i = 0; i <= 9; i++) {
		stringstream stream;
		stream << "Resources/Score/" << i << ".png";
		images.push_back(new Image(stream.str()));
	}
	const auto marginTop = 96.0f;
	const auto marginRight = 48.0f;
	MoveTo(window->Width() - marginRight, marginTop);
	updateDigits();
}

void Scoreboard::updateDigits() {
	for (auto sprite : sprites) {
		delete sprite;
	}
	sprites.clear();
	auto digits = allDigits(score);
	const auto digitsCount = digits.size();
	sprites.reserve(digitsCount);
	for (auto i = 0; i < digitsCount; i++) {
		auto digit = digits[i];
		auto image = images[digit];
		sprites.push_back(new Sprite(image));
	}
}

Scoreboard::Scoreboard(int score, float x, float y, DisplayMode mode) : Scoreboard(score, mode) {
	MoveTo(x, y);
}

vector<int> Scoreboard::allDigits(int number) {
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
	const auto digitsCount = sprites.size();
	for (auto i = 0; i < digitsCount; i++) {
		DrawDigit(i, digitsCount);
	}
}

void Scoreboard::DrawDigit(int digitIndex, size_t digitsCount) {
	const auto spriteWidth = sprites[0]->Width();
	float offsetX = 0;
	if (mode == DisplayMode::CENTERED) {
		offsetX = float(spriteWidth) * (digitsCount / 2);
	}
	sprites[digitIndex]->Draw(x - digitIndex * spriteWidth + offsetX, y);
}
