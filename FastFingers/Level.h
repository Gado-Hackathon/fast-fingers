#ifndef _PROGJOGOS_LEVEL_H_
#define _PROGJOGOS_LEVEL_H_

#include "Game.h"
#include "Scene.h"
#include "Background.h"
#include "Scoreboard.h"
#include "Level.h"

using namespace std;

class Level : public Game
{
private:
	Scene* scene = nullptr;         // gerenciador de cena
	Scoreboard* scoreboard = nullptr;
	string fileName;
	Level* nextLevel = nullptr;
	bool isGameOver = false;
	int level = 0;

	bool viewBBox = false;          // habilita visualiza��o da bounding box
	bool ctrlKeyB = false;          // controle da tecla B

public:
	Level(const string& fileName, Level* nextLevel, int level);

	inline virtual int healthLostPerMistake() {
		return 10;
	}

	virtual Level* copy() = 0;
	void Init();                    // inicializa jogo
	virtual void Update();          // atualiza l�gica do jogo
	void Draw();                    // desenha jogo
	void Finalize();                // finaliza jogo

	inline Level* getNextLevel() {
		return nextLevel;
	}

	inline int getLevel() {
		return level;
	}

	inline void markGameOver() {
		isGameOver = true;
	}
};

#endif