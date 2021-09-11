#include <sstream>

#include "Key.h"
#include "Scoreboard.h"

using std::stringstream;

Scoreboard::Scoreboard(int score) : score(score) {
	for (int i = 0; i <= 9; i++) {
		stringstream stream;
		stream << "Resources/Score/" << i << ".png";
		sprites.push_back(new Sprite(stream.str()));
	}
}

Scoreboard::~Scoreboard() {

}

void Scoreboard::Draw() {
	int currentScore = score;
	int digitIndex = 0;
	if (currentScore == 0) {
		DrawDigit(0, 0);
	}
	while (currentScore) {
		int digit = currentScore % 10;
		DrawDigit(digit, digitIndex);
		currentScore /= 10;
		digitIndex++;
	}
}

void Scoreboard::DrawDigit(int digit, int digitIndex) {
	const auto marginTop = 96.0f;
	const auto marginRight = 48.0f;
	const auto spriteWidth = sprites[0]->Width();
	sprites[digit]->Draw(window->Width() - marginRight - digitIndex * spriteWidth, marginTop);
}
