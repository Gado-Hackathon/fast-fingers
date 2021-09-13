#pragma once

#include "Game.h"
#include "Scene.h"
#include "Background.h"
#include "Scoreboard.h"

using namespace std;

class Level : public Game
{
private:
	Scene* scene = nullptr;         // gerenciador de cena
	Scoreboard* scoreboard = nullptr;
	string fileName;
	bool isGameOver = false;

	bool viewBBox = false;          // habilita visualiza��o da bounding box
	bool ctrlKeyB = false;          // controle da tecla B

public:
	Level(const string& fileName);

	inline virtual int healthLostPerMistake() {
		return 10;
	}

	virtual Level* copy() = 0;
	void Init();                    // inicializa jogo
	virtual void Update();          // atualiza l�gica do jogo
	void Draw();                    // desenha jogo
	void Finalize();                // finaliza jogo

	inline void markGameOver() {
		isGameOver = true;
	}
};
