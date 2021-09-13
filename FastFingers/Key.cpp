#include <sstream>

#include "Key.h"
#include "Scene.h"
#include "HitLine.h"

using std::stringstream;

Key::Key(char ch, float x, float y, float time, float velocity, Scene* scene, std::function<void(Deletion)> onDeletedCallback)
	: ch(ch), time(time), velocity(velocity), scene(scene), onDeletedCallback(onDeletedCallback) {
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

bool Key::shouldBeDeleted() {
	return IsOutOfTheScreen()
		|| state == KeyState::MARKED_FOR_DELETION_BY_FAILURE
		|| state == KeyState::MARKED_FOR_DELETION_BY_SUCCESS;
}

void Key::Update() {
	Translate(0, velocity * gameTime);
	if (shouldBeDeleted()) {
		scene->Delete();
		auto deletion = Deletion(state == KeyState::MARKED_FOR_DELETION_BY_SUCCESS, this);
		this->onDeletedCallback(deletion);
	}
}

void Key::OnCollision(Object* obj) {
	if (obj->Type() == ObjectType::HITLINE) {
		state = KeyState::REACHED_HITLINE;
		auto hitline = static_cast<HitLine*>(obj);
		auto distance = abs(hitline->Y() - y);
		// o score é inversamente proporcional à distância do centro do HitLine
		// porém a distância pode ser 0, então setamos 0.01 *just in case
		// além disso exatamente no centro ele chegaria a números altos como 572
		// então limitamos a [maximumScore]
		const auto maximumScore = 50.0f;
		const auto minimumDistance = 0.01f;
		const auto scoreFactor = 100;
		score = min(maximumScore, scoreFactor / max(minimumDistance, distance));
#if _DEBUG
		stringstream debug;
		debug << ch << ": " << score << "\n";
		OutputDebugString(debug.str().c_str());
#endif
	}
}
